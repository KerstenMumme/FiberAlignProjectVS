
// FiberAlignProjectVSDlg.cpp: Implementierungsdatei
//

#include "pch.h"
#include "framework.h"
#include "FiberAlignProjectVS.h"
#include "FiberAlignProjectVSDlg.h"
#include "afxdialogex.h"
#include <string> 
#include <atlstr.h>
#include <vector>
#include <tchar.h>
#include <stdio.h>
#include <iostream>
#include "SerialPort.h"
#include <cstring>  
#include <sstream>
#include <fstream>
#include <iterator>
#include <boost/algorithm/string.hpp>
#include <algorithm>
#include <numeric>
#include <direct.h> 






typedef std::basic_string<TCHAR> tstring;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//Creating Variables for the Serial Port.
CSerialPort serial = CSerialPort::CSerialPort();

LPCTSTR ComPortName = L"Com3";
DWORD BaudRate = 9600;
bool Overlap = false;
CSerialPort2::Parity Parity = CSerialPort2::Parity::NoParity;
BYTE DataBits = 8;
CSerialPort2::StopBits StopBits = CSerialPort2::StopBits::OneStopBit;
CSerialPort2::FlowControl FlowControl = CSerialPort2::FlowControl::NoFlowControl;

				
float Range = 6.144; //Range of the AD converter, 2^16 values are linearly divided from -Range to Range

long ChanID = 0;

float MinPosX = -1; //Making sure the stage does not damadge itself
float MaxPosX = 3.8;

float MinPosY = -1;
float MaxPosY = 3.8;

float MinPosZ = -1;
float MaxPosZ = 3.8;

float MinPosGonio = -7;
float MaxPosGonio = 6;
										//Determine Backreflections from Fiber to Air interface
float RefractiveIndexAir = 1.00027798; //https://refractiveindex.info/?shelf=other&book=air&page=Ciddor
float RefractiveIndexFiberCore = 1.5;    //Equation https://en.wikipedia.org/wiki/Fresnel_equations#:~:text=%5Bedit%5D-,Normal%20incidence,-%5Bedit%5D
float Transmissivity = 1 - pow( abs((RefractiveIndexFiberCore - RefractiveIndexAir)/(RefractiveIndexFiberCore + RefractiveIndexAir)), 2);
int NumberOfDataPoints = 35; //Number Of Measurements Made per run in the Homing Function
float LimitMultiplicator = 1;
float StartEfficiency = 40; //Used to start the Homing Process, Value will need to change

bool StopLoop = false; //Used to stop homing, when the condition for too little improvement is met 
float ImprovementLimit = 0.02; //Stops the Homing process if 1 - (NewCouplingEfficiency / OldCouplingEfficiency) < ImprovementLimit  



std::vector<float> Optimum = {0,0,0,0}; //Used for the return to Optimum button

float XStepperPosition = 1; //Used to keep tracks of the stepper positions
float YStepperPosition = 1;
float ZStepperPosition = 1;
float GonioStepperPosition = 0;

float XPiezoPosition = 0;
float YPiezoPosition = 0;
float ZPiezoPosition = 0;

bool Error = false; //Used to stop programm in case of a limit error or simular situations

int MaxNumberOfItteration = 10; //Used to stop programm should too many itterations have happend
int MinNumberOfItteration = 5; //The Homing process should at least do this many itterations bevor the condition StopLoop comes into play
float Fraction = static_cast<float>(1) / 2; //Used for detecting the Plateaus edges


std::vector<float> PeakCouplingEfficiencyX(MaxNumberOfItteration); //Used to track the coupling efficiency of the axis over time
std::vector<float> PeakCouplingEfficiencyY(MaxNumberOfItteration);
std::vector<float> PeakCouplingEfficiencyZ(MaxNumberOfItteration);
std::vector<float> PeakCouplingEfficiencyGonio(MaxNumberOfItteration);

std::vector<float> XHighestEfficiencyPosition(MaxNumberOfItteration);
std::vector<float> YHighestEfficiencyPosition(MaxNumberOfItteration);
std::vector<float> ZHighestEfficiencyPosition(MaxNumberOfItteration);
std::vector<float> GonioHighestEfficiencyPosition(MaxNumberOfItteration);


std::vector<float> XLowerLimit(MaxNumberOfItteration); //Track The Lower and Upper Limits per axes 
std::vector<float> XUpperLimit(MaxNumberOfItteration);
std::vector<float> YLowerLimit(MaxNumberOfItteration);
std::vector<float> YUpperLimit(MaxNumberOfItteration);
std::vector<float> ZLowerLimit(MaxNumberOfItteration);
std::vector<float> ZUpperLimit(MaxNumberOfItteration);
std::vector<float> GonioLowerLimit(MaxNumberOfItteration);
std::vector<float> GonioUpperLimit(MaxNumberOfItteration);



// CAboutDlg-Dialogfeld für Anwendungsbefehl "Info"

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung

// Implementierung
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


//Converting a String to a LPCTSTR, used to input Captions into Labels
LPCTSTR CFiberAlignProjectVSDlg::StringToLPCTSTR(std::string ToConvertString) {

	CString BufferCString((ToConvertString.c_str()));
	TCHAR TCharResult[1024];
	lstrcpy(TCharResult, BufferCString);

	return TCharResult;
}

//Convert measured Voltage into Optical Power, as calibrated beforhand
float MeaurementArmVoltageToPower(float Voltage) {
	float OpticalPowerFromVoltage;
	float OpticalPowerBeamSplitterCorrected;
	float TrueOpticalPower;

	OpticalPowerFromVoltage = (0.1963 * Voltage)  + 0.0968;

	OpticalPowerBeamSplitterCorrected = (1.12889 * OpticalPowerFromVoltage) - 0.0156953; //Correction for the unequal splitting from the beamsplitter

	TrueOpticalPower = OpticalPowerBeamSplitterCorrected / Transmissivity; //Corrected for Backreflections on the Fiber to Air medium interface
	return TrueOpticalPower;
}

//Convert measured Voltage into Optical Power, as calibrated beforhand
float ReferenceArmVoltageToPower(float Voltage) {
	float OpticalPower;
	float TrueOpticalPower;
	OpticalPower = (Voltage * 0.1988) + 0.129;

	TrueOpticalPower = 920 * OpticalPower / 910; //Correction for the lense, as measured.

	return TrueOpticalPower;
}

//Converts the Angle from the Goniometer to the length of the actuator 
float GonioAngleToLength(float Angle) {
	float Length;

	Length = 0.661641 * Angle + 0.0986658; //From Matlab fit 

	return Length;
}


//Converts the Length of the actuator to the angle of the goniometer
float GonioLengthToAngle(float Length) {
	float Angle;

	Angle = 1.51053 * Length - 0.149123; //From Matlab fit 

	return Angle;
}


//Creates std::vector<float> Lists filled with NumberOfPoints equidistant Points from LowerLimit to UpperLimit, Limits included
std::vector<float> NumberListFunction(float LowerLimit, float UpperLimit, long NumberOfPoints) {

	float Difference = UpperLimit - LowerLimit;
	float Increments = Difference / (NumberOfPoints - 1);

	std::vector<float> List(NumberOfPoints);

	for (size_t i = 0; i < NumberOfPoints; i++)
	{
		List[i] = LowerLimit + (Increments * i);
	}

	return List;
}

//Detecting the Edges of the Plateau
long FindEdgeIndices(std::vector<float> List, float EdgeValue, float Fraction, bool FromLeft) {

	long Result = 0;

	if (FromLeft) //Detecting the left edge
	{
		for (long i = 0; i < List.size(); i++)
		{
			if (List[i] > (EdgeValue * Fraction))
			{
				Result = i;
				break;
			}


		}

	}
	else { //Detecting the right edge


		for (long i = (List.size() - 1); i >= 0; i--)
		{
			if (List[i] > (EdgeValue * Fraction))
			{
				Result = i;
				break;
			}
		}

	}

	return Result;
}

//Detects the Plateau, depending on the Voltage List, the Position List, the Maxima and the Fraction
//The First Value is the lower Plateau Edge, the Second is the Higher Plateau Edge, 
// and the Third is the Position in the middle.
std::vector<float> DetectPlateau(std::vector<float> VoltageList, std::vector<float> PositionList, float Maxima, float Fraction, int AxisIndex) {

	std::vector<float> Result(4);
	auto Maximum = std::max_element(std::begin(VoltageList), std::end(VoltageList));
	int LowerLimitIndex = FindEdgeIndices(VoltageList, *Maximum, Fraction, true);
	int UpperLimitIndex = FindEdgeIndices(VoltageList, *Maximum, Fraction, false);
	float AllowedLowerLimit;
	float AllowedUpperLimit;
	
	switch (AxisIndex) {
	case 0: {
		AllowedLowerLimit = 0;
		AllowedUpperLimit = MaxPosX;
		break;
	}
	case 1: {
		AllowedLowerLimit = 0;
		AllowedUpperLimit = MaxPosY;
		break;
	}
	case 2: {
		AllowedLowerLimit = 0;
		AllowedUpperLimit = MaxPosZ;
		break;
	}
	case 3: {
		AllowedLowerLimit = -9;
		AllowedUpperLimit = 9;
		break;
	}
	default: {}
	}

	if (LowerLimitIndex == 0 && PositionList[LowerLimitIndex] - 0.1 > AllowedLowerLimit)
	{
		Result[0] = PositionList[LowerLimitIndex] - 0.1;
	}
	else {
		Result[0] = PositionList[LowerLimitIndex];
	}

	if (UpperLimitIndex == (NumberOfDataPoints - 1) && (PositionList[UpperLimitIndex] + 0.1) < AllowedUpperLimit)
	{
		Result[1] = PositionList[UpperLimitIndex] + 0.1;
	}
	else {
		Result[1] = PositionList[UpperLimitIndex];
	}


		   //Result[2] = (Result[0] + Result[1]) / 2;


		   auto it = std::find(VoltageList.begin(), VoltageList.end(), *Maximum);
		   int Index = it - VoltageList.begin();
		   Result[2] = PositionList[Index];
		   Result[3] = *Maximum;

		   if (Result[0] == Result[1]) //Broaden Measurement Area should only one point be above the threshhold
		   {
			   if (Result[2] - 0.2 > AllowedLowerLimit)
			   {
				   Result[0] = Result[2] - 0.2;
			   }
			   else
			   {
				   Result[0] = Result[2];
			   }
			   
			   if (Result[2] + 0.2 < AllowedUpperLimit)
			   {
				   Result[1] = Result[2] + 0.2;
			   }
			   else
			   {
				   Result[1] = Result[2];
			   }
			   
		   }
	
		   return(Result);
	
}

//Splits the Position Value into the Value for the Stepper Motor and the Piezo
//Position is given in mm, while the Results are in mm and micrometer for the stepper and the piezo respectively
std::vector<float> SplitPosition(float Position) {

	std::vector<float> Results(2);

	float TwentyMicroMeter = 0.02;

	Results[0] = floor(Position / TwentyMicroMeter) * TwentyMicroMeter;
	Results[1] = roundf((Position - Results[0]) * 1000);
	return Results;
}


//Reads the float value of the Go To Pos Edit Box
float CFiberAlignProjectVSDlg::ReadGoToPosValue() {

	CString cs1;
	GetDlgItemText(IDC_EDIT1, cs1);

	CT2CA pszConvertedAnsiString(cs1);
	std::string strStd(pszConvertedAnsiString);
	float Value = std::stof(strStd);
	return Value;

}

//Reads the float value of the LowerLimit Edit Box
float CFiberAlignProjectVSDlg::ReadLowerLimitValue() {

	CString cs1;
	GetDlgItemText(IDC_EDIT3, cs1);

	CT2CA pszConvertedAnsiString(cs1);
	std::string strStd(pszConvertedAnsiString);
	float Value = std::stof(strStd);
	return Value;

}

//Reads the float value of the UpperLimit Edit Box
float CFiberAlignProjectVSDlg::ReadUpperLimitValue() {

	CString cs1;
	GetDlgItemText(IDC_EDIT4, cs1);

	CT2CA pszConvertedAnsiString(cs1);
	std::string strStd(pszConvertedAnsiString);
	float Value = std::stof(strStd);
	return Value;

}

//Reads the float value of the NumberOfPoints Edit Box
float CFiberAlignProjectVSDlg::ReadNumberOfPointsValue() {

	CString cs1;
	GetDlgItemText(IDC_EDIT5, cs1);

	CT2CA pszConvertedAnsiString(cs1);
	std::string strStd(pszConvertedAnsiString);
	float Value = std::stof(strStd);
	return Value;

}

//Moves the Actuators of a Axis to a specified position.
//The Axis Index is the same as in the drop down menu of the AxisSelector
//0:X,1:Y,2:Z,3:Gonio

float CFiberAlignProjectVSDlg::StepperCorrection(long AxisIndex, float StepperMotorShouldBePosition) {

	float CorrectedPosition = 0;
	std::vector<float> XCorrectionValues = { -0.0087, 1.0318, -0.0403};
	std::vector<float> YCorrectionValues = { -0.0072, 1.0388, -0.0100};
	std::vector<float> ZCorrectionValues = { -0.0400, 1.1898, -0.1001};
	switch (AxisIndex) {
	case 0: {

		CorrectedPosition = (-XCorrectionValues[1] + sqrt(pow(XCorrectionValues[1], 2) - 4 * XCorrectionValues[0] * (XCorrectionValues[2] - StepperMotorShouldBePosition))) / (2 * XCorrectionValues[0]);

		DebugNum1.put_Caption(StringToLPCTSTR(std::to_string(CorrectedPosition)));
		break;
	}


	case 1: {
		CorrectedPosition = (-YCorrectionValues[1] + sqrt(pow(YCorrectionValues[1], 2) - 4 * YCorrectionValues[0] * (YCorrectionValues[2] - StepperMotorShouldBePosition))) / (2 * YCorrectionValues[0]);

		DebugNum1.put_Caption(StringToLPCTSTR(std::to_string(CorrectedPosition)));
		break;
	}
	case 2: {
		CorrectedPosition = (-ZCorrectionValues[1] + sqrt(pow(ZCorrectionValues[1], 2) - 4 * ZCorrectionValues[0] * (ZCorrectionValues[2] - StepperMotorShouldBePosition))) / (2 * ZCorrectionValues[0]);

		DebugNum1.put_Caption(StringToLPCTSTR(std::to_string(CorrectedPosition)));
		break;
	}
	default: {

		DebugNum1.put_Caption(StringToLPCTSTR("Error in Switch Case"));
	}
	}
	
	

	return CorrectedPosition;
}



float CFiberAlignProjectVSDlg::MoveActuatorToPosition(long AxisIndex, float Position) {



	switch (AxisIndex) {
	case 0: {

		XStepperPosition = Position;
		StepperX.SetAbsMovePos(ChanID, StepperCorrection(AxisIndex, Position));
		StepperX.MoveAbsolute(ChanID, true);
		//PiezoX.SetPosOutput(ChanID, Positions[1]);

	}
		  break;

	case 1: {

		YStepperPosition = Position;
		StepperY.SetAbsMovePos(ChanID, StepperCorrection(AxisIndex, Position));
		StepperY.MoveAbsolute(ChanID, true);
		//PiezoY.SetPosOutput(ChanID, Positions[1]);

		break;
	}
	case 2: {

		ZStepperPosition = Position;
		StepperZ.SetAbsMovePos(ChanID, StepperCorrection(AxisIndex, Position));
		StepperZ.MoveAbsolute(ChanID, true);
		//PiezoZ.SetPosOutput(ChanID, Positions[1]);
		

		break;
	}
	case 3: {

		GonioStepperPosition = Position;
		StepperGonio.SetAbsMovePos(ChanID,GonioAngleToLength(Position));
		StepperGonio.MoveAbsolute(ChanID, true);

		break;
	}
	default: {

		DebugNum1.put_Caption(StringToLPCTSTR("Error in Switch Case"));
	}

	}

	return Position;
}


void SaveToFile(std::vector<float> VectorToBeSaved, std::string Folder, std::string Name) {

	std::ofstream output_file("./" + Folder + "/" + Name + ".txt");
	std::ostream_iterator<float> output_iterator(output_file, "\n");
	std::copy(VectorToBeSaved.begin(), VectorToBeSaved.end(), output_iterator);

}

//Setting the correct labels for the Upper and Lower Limit, depending on the Axis selected
	//ToDo: Add ° symbol, without weird A being added
void CFiberAlignProjectVSDlg::OnCbnSelchangeCombo1()
{
	int i = AxisSelectorDropDownMenu.GetCurSel();


	if (i >= 0 && i < 3) {
		LowerLimitUnitLabel.put_Caption(L"mm");
		UpperLimitUnitLabel.put_Caption(L"mm");
		GoToPosUnitLabel.put_Caption(L"mm");


	}
	else if (i == 3) {
		LowerLimitUnitLabel.put_Caption(L"Deg");
		UpperLimitUnitLabel.put_Caption(L"Deg");
		GoToPosUnitLabel.put_Caption(L"Deg");
	}
	else {
		LowerLimitUnitLabel.put_Caption(L"Error");
		UpperLimitUnitLabel.put_Caption(L"Error");
		GoToPosUnitLabel.put_Caption(L"Error");
	}

}


CFiberAlignProjectVSDlg::CFiberAlignProjectVSDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FIBERALIGNPROJECTVS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFiberAlignProjectVSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MGPIEZOCTRL1, PiezoX);
	DDX_Control(pDX, IDC_MGPIEZOCTRL2, PiezoY);
	DDX_Control(pDX, IDC_MGPIEZOCTRL3, PiezoZ);

	DDX_Control(pDX, IDC_MGMOTORCTRL1, StepperX);
	DDX_Control(pDX, IDC_MGMOTORCTRL2, StepperY);
	DDX_Control(pDX, IDC_MGMOTORCTRL3, StepperZ);
	DDX_Control(pDX, IDC_MGMOTORCTRL4, StepperGonio);

	DDX_Control(pDX, IDC_LABEL1, DebugNum1);
	DDX_Control(pDX, IDC_LABEL2, DebugNum2);
	DDX_Control(pDX, IDC_LABEL3, MeasuredVoltagesLabel);
	DDX_Control(pDX, IDC_LABEL4, MeasurementArmOpticalPowerLabel);
	DDX_Control(pDX, IDC_LABEL5, ReferenceArmOpticalPowerLabel);
	DDX_Control(pDX, IDC_LABEL6, CouplingEfficiencyLabel);
	DDX_Control(pDX, IDC_LABEL7, DebugNum3);
	DDX_Control(pDX, IDC_LABEL11, LowerLimitUnitLabel);
	DDX_Control(pDX, IDC_LABEL12, UpperLimitUnitLabel);
	DDX_Control(pDX, IDC_LABEL14, GoToPosUnitLabel);


	DDX_Control(pDX, IDC_COMMANDBUTTON1, StartHomingButton);
	DDX_Control(pDX, IDC_COMMANDBUTTON2, ManualVoltageMeasurementButton);
	DDX_Control(pDX, IDC_COMMANDBUTTON3, ReturnToOptimumButton);
	DDX_Control(pDX, IDC_COMMANDBUTTON4, StartCouplingSensitivityMeasurementButton);
	DDX_Control(pDX, IDC_COMMANDBUTTON6, InitializeArdunio);
	DDX_Control(pDX, IDC_COMMANDBUTTON7, TestButton);
	DDX_Control(pDX, IDC_COMMANDBUTTON8, GoToPositionButton);

	DDX_Control(pDX, IDC_MG17LOGGERCTRL1, CommunicationLogger);

	DDX_Control(pDX, IDC_COMBO1, AxisSelectorDropDownMenu);
	DDX_Control(pDX, IDC_COMBO2, RelativeAndAbsoluteSelector);


	DDX_Control(pDX, IDC_EDIT3, LowerPositionInputField);
	DDX_Control(pDX, IDC_EDIT4, UpperPositionInputField);
	DDX_Control(pDX, IDC_EDIT5, NumberOfMeasurementPointsNumberField);
	DDX_Control(pDX, IDC_EDIT1, GoToPosValue);



}

BEGIN_MESSAGE_MAP(CFiberAlignProjectVSDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_EN_CHANGE(IDC_EDIT3, &CFiberAlignProjectVSDlg::OnEnChangeEdit3)
//	ON_CBN_EDITCHANGE(IDC_COMBO1, &CFiberAlignProjectVSDlg::OnCbnEditchangeCombo1)
//ON_CBN_EDITCHANGE(IDC_COMBO1, &CFiberAlignProjectVSDlg::OnCbnEditchangeCombo1)
ON_CBN_SELCHANGE(IDC_COMBO1, &CFiberAlignProjectVSDlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CFiberAlignProjectVSDlg-Meldungshandler




BOOL CFiberAlignProjectVSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Hinzufügen des Menübefehls "Info..." zum Systemmenü.

	// IDM_ABOUTBOX muss sich im Bereich der Systembefehle befinden.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Symbol für dieses Dialogfeld festlegen.  Wird automatisch erledigt
	//  wenn das Hauptfenster der Anwendung kein Dialogfeld ist
	SetIcon(m_hIcon, TRUE);			// Großes Symbol verwenden
	SetIcon(m_hIcon, FALSE);		// Kleines Symbol verwenden

	// TODO: Hier zusätzliche Initialisierung einfügen

	PiezoX.StartCtrl();
	PiezoY.StartCtrl();
	PiezoZ.StartCtrl();
	StepperX.StartCtrl();
	StepperY.StartCtrl();
	StepperZ.StartCtrl();
	StepperGonio.StartCtrl();

	AxisSelectorDropDownMenu.SetCurSel(0);
	RelativeAndAbsoluteSelector.SetCurSel(0);

	LowerLimitUnitLabel.put_Caption(L"mm");
	UpperLimitUnitLabel.put_Caption(L"mm");
	GoToPosUnitLabel.put_Caption(L"mm");

	return TRUE;  // TRUE zurückgeben, wenn der Fokus nicht auf ein Steuerelement gesetzt wird
}


void CFiberAlignProjectVSDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Wenn Sie dem Dialogfeld eine Schaltfläche "Minimieren" hinzufügen, benötigen Sie
//  den nachstehenden Code, um das Symbol zu zeichnen.  Für MFC-Anwendungen, die das 
//  Dokument/Ansicht-Modell verwenden, wird dies automatisch ausgeführt.

void CFiberAlignProjectVSDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Gerätekontext zum Zeichnen

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Symbol in Clientrechteck zentrieren
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Symbol zeichnen
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Die System ruft diese Funktion auf, um den Cursor abzufragen, der angezeigt wird, während der Benutzer
//  das minimierte Fenster mit der Maus zieht.
HCURSOR CFiberAlignProjectVSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}








BEGIN_EVENTSINK_MAP(CFiberAlignProjectVSDlg, CDialogEx)
	ON_EVENT(CFiberAlignProjectVSDlg, IDC_COMMANDBUTTON1, DISPID_CLICK, CFiberAlignProjectVSDlg::ClickCommandbutton1, VTS_NONE)
	ON_EVENT(CFiberAlignProjectVSDlg, IDC_COMMANDBUTTON6, DISPID_CLICK, CFiberAlignProjectVSDlg::ClickCommandbutton6, VTS_NONE)
	ON_EVENT(CFiberAlignProjectVSDlg, IDC_COMMANDBUTTON5, DISPID_CLICK, CFiberAlignProjectVSDlg::ClickCommandbutton5, VTS_NONE)
//	ON_EVENT(CFiberAlignProjectVSDlg, IDC_COMMANDBUTTON7, DISPID_CLICK, CFiberAlignProjectVSDlg::ClickCommandbutton7, VTS_NONE)
ON_EVENT(CFiberAlignProjectVSDlg, IDC_COMMANDBUTTON7, DISPID_CLICK, CFiberAlignProjectVSDlg::ClickCommandbutton7, VTS_NONE)
ON_EVENT(CFiberAlignProjectVSDlg, IDC_COMMANDBUTTON8, DISPID_CLICK, CFiberAlignProjectVSDlg::ClickCommandbutton8, VTS_NONE)
ON_EVENT(CFiberAlignProjectVSDlg, IDC_COMMANDBUTTON8, DISPID_CLICK, CFiberAlignProjectVSDlg::ClickCommandbutton8, VTS_NONE)
ON_EVENT(CFiberAlignProjectVSDlg, IDC_COMMANDBUTTON2, DISPID_CLICK, CFiberAlignProjectVSDlg::ClickCommandbutton2, VTS_NONE)
ON_EVENT(CFiberAlignProjectVSDlg, IDC_COMMANDBUTTON4, DISPID_CLICK, CFiberAlignProjectVSDlg::ClickCommandbutton4, VTS_NONE)
ON_EVENT(CFiberAlignProjectVSDlg, IDC_COMMANDBUTTON3, DISPID_CLICK, CFiberAlignProjectVSDlg::ClickCommandbutton3, VTS_NONE)
END_EVENTSINK_MAP()

//Checking if the difference in the coupling efficiency is sufficiently small to stop the homing process
bool CheckCouplingEfficiencyIncrease(float OldEfficiency, float NewEfficiency) {

	bool Output = false;

	Output = abs(1 - (NewEfficiency / OldEfficiency)) < ImprovementLimit ;

	return Output;
}


//StartHoming button
bool CFiberAlignProjectVSDlg::ClickCommandbutton1()
{
	float LowerMeasurementLimit;
	float UpperMeasurementLimit;
	float PeakEfficiency;
	std::vector<float> TempVector(4);


	for (int i = 0; i < MaxNumberOfItteration; i++) //Main Loop for the itterative process of finding the peak 
	{
		if (i >= MinNumberOfItteration) //If sufficently many itterations were made, the ending condition is determined
		{								// Only if all axis have low enough improvements is the programm halted
			StopLoop =	CheckCouplingEfficiencyIncrease(PeakCouplingEfficiencyX[i - 2], PeakCouplingEfficiencyX[i - 1]) &&
						CheckCouplingEfficiencyIncrease(PeakCouplingEfficiencyY[i - 2], PeakCouplingEfficiencyY[i - 1]) && 
						CheckCouplingEfficiencyIncrease(PeakCouplingEfficiencyZ[i - 2], PeakCouplingEfficiencyZ[i - 1]) &&
						CheckCouplingEfficiencyIncrease(PeakCouplingEfficiencyGonio[i - 2], PeakCouplingEfficiencyGonio[i - 1]);
		}

		if (i >= MinNumberOfItteration && StopLoop) //Check if the ImprovementLimit is met
		{
			DebugNum2.put_Caption(L"Stopped Homing because of StopLoop, not enough improvements");
			Optimum[0] = XStepperPosition; //The Optimum Prameter are written to the Optimum List, enabling the user to use the 
			Optimum[1] = YStepperPosition; //return to Optimum Button and the Relative Measurement function
			Optimum[2] = ZStepperPosition;
			Optimum[3] = GonioStepperPosition;

			break;
		}

		for (int j = 0; j < 4; j++) //Looping over the axes, order being X,Y,Z,Gonio
		{

			switch (j) {
			case 0: {
				if (i == 0)
				{
					LowerMeasurementLimit = 0;
					UpperMeasurementLimit = 3.7; 
					PeakEfficiency = StartEfficiency;

				}
				else {
					LowerMeasurementLimit = XLowerLimit[i - 1] * LimitMultiplicator;
					UpperMeasurementLimit = XUpperLimit[i - 1] * LimitMultiplicator;
					PeakEfficiency = PeakCouplingEfficiencyX[i - 1];
				}

				TempVector = MeasurementRun(j, LowerMeasurementLimit, UpperMeasurementLimit, NumberOfDataPoints, PeakEfficiency, i);

				if (Error) //If a Limit is out of bounds, stop the homing function
				{
					DebugNum1.put_Caption(L"HomingProcess stopped because of Error");
					return false;
				}

				XLowerLimit[i] = TempVector[0];
				XUpperLimit[i] = TempVector[1];
				PeakCouplingEfficiencyX[i] = TempVector[3];
				XHighestEfficiencyPosition[i] = TempVector[2];
				MoveActuatorToPosition(j,TempVector[2]);

				break;
			}
			case 1: {

				if (i == 0)
				{
					LowerMeasurementLimit = 0;
					UpperMeasurementLimit = 3.7;
					PeakEfficiency = StartEfficiency;

				}
				else {
					LowerMeasurementLimit = YLowerLimit[i - 1] * LimitMultiplicator;
					UpperMeasurementLimit = YUpperLimit[i - 1] * LimitMultiplicator;
					PeakEfficiency = PeakCouplingEfficiencyY[i - 1];
				}

				TempVector = MeasurementRun(j, LowerMeasurementLimit, UpperMeasurementLimit, NumberOfDataPoints, PeakEfficiency, i);

				if (Error) //If a Limit is out of bounds, stop the homing function
				{
					DebugNum1.put_Caption(L"HomingProcess stopped because of Error");
					return false;
				}

				YLowerLimit[i] = TempVector[0];
				YUpperLimit[i] = TempVector[1];
				PeakCouplingEfficiencyY[i] = TempVector[3];
				YHighestEfficiencyPosition[i] = TempVector[2];
				MoveActuatorToPosition(j, TempVector[2]);

				break;
			}
			case 2: {

				if (i == 0)
				{
					LowerMeasurementLimit = 0;
					UpperMeasurementLimit = 3.7;
					PeakEfficiency = StartEfficiency;

				}
				else {
					LowerMeasurementLimit = ZLowerLimit[i - 1] * LimitMultiplicator;
					UpperMeasurementLimit = ZUpperLimit[i - 1] * LimitMultiplicator;
					PeakEfficiency = PeakCouplingEfficiencyZ[i - 1];
				}

				TempVector = MeasurementRun(j, LowerMeasurementLimit, UpperMeasurementLimit, NumberOfDataPoints, PeakEfficiency, i);

				if (Error) //If a Limit is out of bounds, stop the homing function
				{
					DebugNum1.put_Caption(L"HomingProcess stopped because of Error");
					return false;
				}

				ZLowerLimit[i] = TempVector[0];
				ZUpperLimit[i] = TempVector[1];
				PeakCouplingEfficiencyZ[i] = TempVector[3];
				ZHighestEfficiencyPosition[i] = TempVector[2];
				MoveActuatorToPosition(j, TempVector[2]);

				break;
			}
			case 3: {

				if (i == 0)
				{
					LowerMeasurementLimit = -5.5;
					UpperMeasurementLimit = 5.5;
					PeakEfficiency = StartEfficiency;

				}
				else {
					LowerMeasurementLimit = GonioLowerLimit[i - 1] * LimitMultiplicator;
					UpperMeasurementLimit = GonioUpperLimit[i - 1] * LimitMultiplicator;
					PeakEfficiency = PeakCouplingEfficiencyGonio[i - 1];
				}

				TempVector = MeasurementRun(j, LowerMeasurementLimit, UpperMeasurementLimit, NumberOfDataPoints, PeakEfficiency, i);

				if (Error) //If a Limit is out of bounds, stop the homing function
				{
					DebugNum1.put_Caption(L"HomingProcess stopped because of Error");
					return false;
				}

				GonioLowerLimit[i] = TempVector[0];
				GonioUpperLimit[i] = TempVector[1];
				PeakCouplingEfficiencyGonio[i] = TempVector[3];
				GonioHighestEfficiencyPosition[i] = TempVector[2];
				MoveActuatorToPosition(j, TempVector[2]);

				break;
			}
			default: {DebugNum3.put_Caption(L"Axis Index Error"); }
			}

			//Save all Lists used in the Loop into textfiles
			SaveToFile(PeakCouplingEfficiencyX, "OutputVectors", "PeakCouplingEfficiencyX");
			SaveToFile(PeakCouplingEfficiencyY, "OutputVectors", "PeakCouplingEfficiencyY");
			SaveToFile(PeakCouplingEfficiencyZ, "OutputVectors", "PeakCouplingEfficiencyZ");
			SaveToFile(PeakCouplingEfficiencyGonio, "OutputVectors", "PeakCouplingEfficiencyGonio");
			SaveToFile(XLowerLimit, "OutputVectors", "XLowerLimit");
			SaveToFile(XUpperLimit, "OutputVectors", "XUpperLimit");
			SaveToFile(YLowerLimit, "OutputVectors", "YLowerLimit");
			SaveToFile(YUpperLimit, "OutputVectors", "YUpperLimit");
			SaveToFile(ZLowerLimit, "OutputVectors", "ZLowerLimit");
			SaveToFile(ZUpperLimit, "OutputVectors", "ZUpperLimit");
			SaveToFile(GonioLowerLimit, "OutputVectors", "GonioLowerLimit");
			SaveToFile(GonioUpperLimit, "OutputVectors", "GonioUpperLimit");
			SaveToFile(XHighestEfficiencyPosition, "OutputVectors", "XHighestEfficiencyPosition");
			SaveToFile(YHighestEfficiencyPosition, "OutputVectors", "YHighestEfficiencyPosition");
			SaveToFile(ZHighestEfficiencyPosition, "OutputVectors", "ZHighestEfficiencyPosition");
			SaveToFile(GonioHighestEfficiencyPosition, "OutputVectors", "GonioHighestEfficiencyPosition");



		}
		



	}
	





}



std::vector<float> CFiberAlignProjectVSDlg::GetVoltageValues(float Range) {

	serial.CSerialPort::Open(ComPortName, BaudRate, Parity, DataBits, StopBits, FlowControl, Overlap);
	//serial.SetConfig();
	std::vector<float> Results = {1, 1, 1};
	serial.ClearReadBuffer();

	Sleep(3000);
	const int BUFFER_SIZE = 1023;

		
	char input_buffer[BUFFER_SIZE] = { NULL };

	
	serial.Read(input_buffer, BUFFER_SIZE-1);


	std::string SerialOutputString = input_buffer;

	//DebugNum3.put_Caption(StringToLPCTSTR(SerialOutputString));

	//std::string SerialOutputString = "001345!001345!001345!001345&001345!001345!001345!001345&001345!001345!001345!001345&001345!001345!001345!001345&001345!001345!001345!001345&001345!001345!001345!001345&001345!001345!001345!001345&001345!001345!001345!001345";
	std::vector<std::string> FaultyString = { "Failed", "to", "Initialize", "ADS"};

	
	//Check if the ADC is connected correctly, if not, restart connection
	if (boost::algorithm::contains(SerialOutputString, FaultyString[0]) ||
		boost::algorithm::contains(SerialOutputString, FaultyString[1]) ||
		boost::algorithm::contains(SerialOutputString, FaultyString[2]) ||
		boost::algorithm::contains(SerialOutputString, FaultyString[3]))
	{
		//DebugNum3.put_Caption(StringToLPCTSTR("Failed To Inizialize ADS!"));
		serial.Close();
		Sleep(1000);

		return GetVoltageValues(Range);
		//return Results;

	}


	//Split the String read from the Arduino into the Datasets
	std::vector<std::string> FirstTimeSplit;
	boost::split(FirstTimeSplit, SerialOutputString, boost::algorithm::is_any_of("&"), boost::algorithm::token_compress_mode_type::token_compress_on);

	//DebugNum3.put_Caption(StringToLPCTSTR(SerialOutputString));
	//DebugNum1.put_Caption(StringToLPCTSTR(FirstTimeSplit[0]));
		
	
	//Check for and Remove Faulty Datasets
	for (int i = 0; i < FirstTimeSplit.size(); i++)
	{
		std::vector<std::string> TempString;
		boost::split(TempString, FirstTimeSplit[i], boost::algorithm::is_any_of("!"), boost::algorithm::token_compress_mode_type::token_compress_on);

		if (FirstTimeSplit[i].length() != 27 || std::count(FirstTimeSplit[i].begin(), FirstTimeSplit[i].end(), '!') != 3 || TempString.size() != 4)
		{
			FirstTimeSplit.erase(FirstTimeSplit.begin() + i);
			i--;
		}

	}
	

	//Check if high enough number of Datasets still remain
	if (FirstTimeSplit.size() < 5)
	{
		serial.Close();
		Sleep(1000);
		//DebugNum1.put_Caption(L"Too Few Values");
		return GetVoltageValues(Range);
		//return Results;
	}
	//DebugNum1.put_Caption(StringToLPCTSTR(std::to_string(FirstTimeSplit.size())));


	//Once all Faulty Datasets are removed and enough made it through, they are split into 4 vectors containing the values for all ADS Inputs
	std::vector<long> VoltageListZero(FirstTimeSplit.size());
	std::vector<long> VoltageListOne(FirstTimeSplit.size());
	std::vector<long> VoltageListTwo(FirstTimeSplit.size());
	std::vector<long> VoltageListThree(FirstTimeSplit.size());

	std::vector<std::string> TempVoltageList;

	for (long i = 0; i < FirstTimeSplit.size(); i++)
	{
		boost::split(TempVoltageList, FirstTimeSplit[i], boost::algorithm::is_any_of("!"), boost::algorithm::token_compress_mode_type::token_compress_on);
		VoltageListZero[i] = stol(TempVoltageList[0]);
		VoltageListOne[i] = stol(TempVoltageList[1]);
		VoltageListTwo[i] = stol(TempVoltageList[2]);
		VoltageListThree[i] = stol(TempVoltageList[3]);
	}

	long VoltageSumZero = std::accumulate(VoltageListZero.begin(), VoltageListZero.end(), 0);
	long VoltageSumOne = std::accumulate(VoltageListOne.begin(), VoltageListOne.end(), 0);
	long VoltageSumTwo= std::accumulate(VoltageListTwo.begin(), VoltageListTwo.end(), 0);
	long VoltageSumThree = std::accumulate(VoltageListThree.begin(), VoltageListThree.end(), 0);

	Results[0] = (VoltageSumZero / (static_cast<float>(2) * VoltageListZero.size()) * Range + VoltageSumOne / (static_cast<float>(2) * VoltageListZero.size()) * Range) / 32768;
	Results[1] = (VoltageSumTwo / (static_cast<float>(2) * VoltageListZero.size()) * Range + VoltageSumThree / (static_cast<float>(2) * VoltageListZero.size()) * Range) / 32768;
	Results[2] = (MeaurementArmVoltageToPower(Results[1]) * 100 / ReferenceArmVoltageToPower(Results[0])) - 10;

	serial.Close();

	MeasuredVoltagesLabel.put_Caption(StringToLPCTSTR("Measurement Arm Voltage = " + std::to_string(Results[1]) + " V " + "Reference Arm Voltage      = " + std::to_string(Results[0]) + " V "));
	ReferenceArmOpticalPowerLabel.put_Caption(StringToLPCTSTR("PMeasurement = " + std::to_string(MeaurementArmVoltageToPower(Results[1])) + " mW " + "PReference      = " + std::to_string(ReferenceArmVoltageToPower(Results[0])) + " mW "));
	CouplingEfficiencyLabel.put_Caption(StringToLPCTSTR("Coupling Efficiency = " + std::to_string(MeaurementArmVoltageToPower(Results[1]) * 100 / ReferenceArmVoltageToPower(Results[0])) + " %"));
	return Results;
	
}



//Initializing the Arduino Connection and reading a number of values
void CFiberAlignProjectVSDlg::ClickCommandbutton6()
{




}



// Homing The Actuators and Moving them to the middle of their allowed positions.
void CFiberAlignProjectVSDlg::ClickCommandbutton5()
{

	//Create Constants for Homing and Velocity Behavior
	long HomeDirection = 2;
	long HomeLimitSwitch = 1;
	float HomeVelocity = 0.5;
	long StageUnits = 1;
	float PitchXYZ = 0.5;
	float PitchGonio = 1;
	long DirectionSense = 1;
	long ReverseLimitSwitch = 2;
	long ForwardLimitSwitch = 1;
	float MinVelo = 0;
	float AccelerationXYZ = 4;
	float AccelerationGonio = 1.5;
	float MaxVelo = 2;
	float StepperMiddlePosition = 1.9; 
	long SoftwareLimitSwitchBehavior = 2;

	//Determined Experimentally, these values determine the offset between the limit switch in the actuators and the zero point
	float ZeroOffsetX = 2.65;
	float ZeroOffsetY = 2.525;
	float ZeroOffsetZ = 2.45;
	float ZeroOffsetGonio = 7.55;

	long PiezoControlMode = 4; //Closed Loop Mode, using strain gauges to determine the position and a PI controller to counteract any errors
	float PiezoMiddlePosition = 10;
	long VoltMicronOutputMode = 2;

	//Sets the Constants for the PI controller. This does not seem to work, as no behavior as expected from a Integral Controller is visable
	long PConstant = 50;
	long IConstant = 100;

 
	//Set Hardware Switch behavior
	StepperX.SetHWLimSwitches(ChanID, ReverseLimitSwitch, ForwardLimitSwitch);
	StepperY.SetHWLimSwitches(ChanID, ReverseLimitSwitch, ForwardLimitSwitch);
	StepperZ.SetHWLimSwitches(ChanID, ReverseLimitSwitch, ForwardLimitSwitch);
	StepperGonio.SetHWLimSwitches(ChanID, ReverseLimitSwitch, ForwardLimitSwitch);



	//Overriding standard Settings for Software Limits, Pitch and Direction Sense
	StepperX.SetStageAxisInfo(ChanID, MinPosX, MaxPosX, StageUnits, PitchXYZ, DirectionSense);
	StepperY.SetStageAxisInfo(ChanID, MinPosY, MaxPosY, StageUnits, PitchXYZ, DirectionSense);
	StepperZ.SetStageAxisInfo(ChanID, MinPosZ, MaxPosZ, StageUnits, PitchXYZ, DirectionSense);
	StepperGonio.SetStageAxisInfo(ChanID, MinPosGonio, MaxPosGonio, StageUnits, PitchGonio, DirectionSense);

	
	//Setting Homing Parameters
	StepperX.SetHomeParams(ChanID, HomeDirection, HomeLimitSwitch, HomeVelocity, ZeroOffsetX);
	StepperY.SetHomeParams(ChanID, HomeDirection, HomeLimitSwitch, HomeVelocity, ZeroOffsetY);
	StepperZ.SetHomeParams(ChanID, HomeDirection, HomeLimitSwitch, HomeVelocity, ZeroOffsetZ);
	StepperGonio.SetHomeParams(ChanID, HomeDirection, HomeLimitSwitch, 5*HomeVelocity, ZeroOffsetGonio);


	Sleep(1000);
	//Homing the Stepper Motors
	StepperX.MoveHome(ChanID, false);
	StepperY.MoveHome(ChanID, false);
	StepperZ.MoveHome(ChanID, false);
	StepperGonio.MoveHome(ChanID, false);

	//Setting the Movement Characteristics of the Stepper Motors
	StepperX.SetVelParams(ChanID, MinVelo, AccelerationXYZ, MaxVelo);
	StepperY.SetVelParams(ChanID, MinVelo, AccelerationXYZ, MaxVelo);
	StepperZ.SetVelParams(ChanID, MinVelo, 1*AccelerationXYZ, 1*MaxVelo);
	StepperGonio.SetVelParams(ChanID, MinVelo, AccelerationGonio, MaxVelo);

	//Setting the Displayed Units to Micrometer
	PiezoX.SetVoltPosDispMode(ChanID, VoltMicronOutputMode);
	PiezoY.SetVoltPosDispMode(ChanID, VoltMicronOutputMode);
	PiezoZ.SetVoltPosDispMode(ChanID, VoltMicronOutputMode);

	//Setting the PI Constants of the Piezo Controlers to favor the I behavior
	PiezoX.SetPIConsts(ChanID, PConstant, IConstant);
	PiezoY.SetPIConsts(ChanID, PConstant, IConstant);
	PiezoZ.SetPIConsts(ChanID, PConstant, IConstant);

	//Homing the Piezo Actuators
	PiezoX.ZeroPosition(ChanID);
	PiezoY.ZeroPosition(ChanID);
	PiezoZ.ZeroPosition(ChanID);

	//ReSetting Control Mode to Close-Loop
	PiezoX.SetControlMode(ChanID, PiezoControlMode);
	PiezoY.SetControlMode(ChanID, PiezoControlMode);
	PiezoZ.SetControlMode(ChanID, PiezoControlMode);

	Sleep(20000);

	//Moving every Actuator to Halve their movement Range, for Manual Adjustment of the Setup,
	//	To ensure the focal point is within the movement Range of the Stage
	//Set Absolute Move Position
	StepperX.SetAbsMovePos(ChanID, StepperMiddlePosition);
	StepperY.SetAbsMovePos(ChanID, StepperMiddlePosition);
	StepperZ.SetAbsMovePos(ChanID, StepperMiddlePosition);

	StepperX.SetSWPosLimits(ChanID, MinPosX, MaxPosX, SoftwareLimitSwitchBehavior);
	StepperY.SetSWPosLimits(ChanID, MinPosY, MaxPosY, SoftwareLimitSwitchBehavior);
	StepperZ.SetSWPosLimits(ChanID, MinPosZ, MaxPosZ, SoftwareLimitSwitchBehavior);
	StepperGonio.SetSWPosLimits(ChanID, MinPosGonio, MaxPosGonio, SoftwareLimitSwitchBehavior);

	//Do the Absolute Movement
	StepperX.MoveAbsolute(ChanID, false);
	StepperY.MoveAbsolute(ChanID, false);
	StepperZ.MoveAbsolute(ChanID, false);

	Sleep(5000);
	//Go To Middle Position of the Piezos
	PiezoX.SetPosOutput(ChanID, PiezoMiddlePosition);
	PiezoY.SetPosOutput(ChanID, PiezoMiddlePosition);
	PiezoZ.SetPosOutput(ChanID, PiezoMiddlePosition);


	Sleep(13000);

}

//GoToPositionButton
void CFiberAlignProjectVSDlg::ClickCommandbutton8()
{

	float Position = ReadGoToPosValue();
	long AxisIndex = AxisSelectorDropDownMenu.GetCurSel();

	float CurrentPosition = MoveActuatorToPosition(AxisIndex, Position);

	DebugNum2.put_Caption(StringToLPCTSTR(std::to_string(CurrentPosition)));
}





//Manual Voltage Measurement Button
void CFiberAlignProjectVSDlg::ClickCommandbutton2()
{
	GetVoltageValues(Range);
}



//TestButton
void CFiberAlignProjectVSDlg::ClickCommandbutton7() {


}




//Go from point to point, Measuring the Coupling Efficiency at every point, then evaluate where the maximum point is and returning the Lower and Upper Plateau edge, the middle and highest coupling efficiency.
std::vector<float> CFiberAlignProjectVSDlg::MeasurementRun(int AxisIndex, float LowerLimit, float UpperLimit, int NumberOfPoints, float OldMaximum, int Itterator) {
	


	std::vector<float> PositionList = NumberListFunction(LowerLimit, UpperLimit, NumberOfPoints);
	std::vector<float> VoltageList(NumberOfPoints);
	std::vector<float> TempVoltList(3);
	std::string AxisString;

	//Add the Axis to the File Name
	switch (AxisIndex) {
	case 0: {
		AxisString = "X";

		break;
	}
	case 1: {
		AxisString = "Y";

		break;
	}
	case 2: {
		AxisString = "Z";

		break;
	}
	case 3: {
		AxisString = "Gonio";
			
		break;
	}
	default: {DebugNum3.put_Caption(L"Axis Index Error"); }
	}

	float AllowedLowerLim = 0;
	float AllowedUpperLim = 0;

	//Check if the limits are within the allowed limits set by the stages physical limitations
	switch (AxisIndex) {
	case 0: {
		AllowedLowerLim = 0;
		AllowedUpperLim = MaxPosX;
		break;
	}
	case 1: {
		AllowedLowerLim = 0;
		AllowedUpperLim = MaxPosY;
		break;
	}
	case 2: {
		AllowedLowerLim = 0;
		AllowedUpperLim = MaxPosZ;
		break;
	}
	case 3: {
		AllowedLowerLim = -9;
		AllowedUpperLim = 9;
		break;
	}
	default: {}
	}
	//Stop run from starting if the stage would go out of limits
	if (LowerLimit < AllowedLowerLim || UpperLimit > AllowedUpperLim)
	{
		DebugNum1.put_Caption(L"Limits for Measurement Run Out of Bounds");
		std::vector<float> Results = {0,0,0,0};
		Error = true;
		return Results;

	}


	MoveActuatorToPosition(AxisIndex, PositionList[0]);
	Sleep(2);
	for (long i = 0; i < NumberOfPoints; i++)
	{
		MoveActuatorToPosition(AxisIndex, PositionList[i]);
		//Sleep(1500);
		TempVoltList = GetVoltageValues(Range);
		VoltageList[i] = TempVoltList[2];

	}
	

	std::string FolderStartString = "OutputVectors//Itteration";
	std::string FolderAppendage = std::to_string(Itterator);
	std::string FolderAppendedString = FolderStartString + FolderAppendage;
	const char* FolderDirChar = FolderAppendedString.c_str();
	_mkdir(FolderDirChar);

	std::string FileTitlePosition = "Position";
	std::string FileTitelEfficiency = "Efficiency";

	SaveToFile(PositionList, FolderDirChar, FileTitlePosition + AxisString);
	SaveToFile(VoltageList, FolderDirChar, FileTitelEfficiency + AxisString);
	


	auto Maximum = std::max_element(std::begin(VoltageList), std::end(VoltageList));
	std::vector<float> Results(4);
	std::vector<float> PlateauResults;
	//float Fraction = static_cast<float>(1) / 2;
	PlateauResults = DetectPlateau(VoltageList, PositionList, OldMaximum, Fraction,AxisIndex);
	Results[0] = PlateauResults[0];
	Results[1] = PlateauResults[1];
	Results[2] = PlateauResults[2];
	Results[3] = *Maximum;


	DebugNum1.put_Caption(StringToLPCTSTR(std::to_string(Results[0])));
	DebugNum2.put_Caption(StringToLPCTSTR(std::to_string(Results[1])));
	DebugNum3.put_Caption(StringToLPCTSTR(std::to_string(Results[3])));
	return Results;
}





//Start Coupling Efficiency Measurement Button
bool CFiberAlignProjectVSDlg::ClickCommandbutton4()
{
	int RelativOrAbsolute = RelativeAndAbsoluteSelector.GetCurSel();
	int Axis = AxisSelectorDropDownMenu.GetCurSel();
	float Max = 100;
	float LowerLim = ReadLowerLimitValue();
	float UpperLim = ReadUpperLimitValue();
	long Numb = ReadNumberOfPointsValue();
	

	//Differentiate between relative and absolute measurements
	if (RelativOrAbsolute == 0) 
	{//Absolute Measurement
		MeasurementRun(Axis, LowerLim, UpperLim, Numb, Max, 1);

	} else { 
	//Relative Measurement, only possible if a optimum finding run was successfull 

		MeasurementRun(Axis, Optimum[Axis] + LowerLim, Optimum[Axis] + UpperLim, Numb, Max, 0);

	}


	return true;

}




//Return to the point of highest coupling efficiency
void CFiberAlignProjectVSDlg::ClickCommandbutton3()
{
	MoveActuatorToPosition(0, Optimum[0]);
	MoveActuatorToPosition(1, Optimum[1]);
	MoveActuatorToPosition(2, Optimum[2]);
	MoveActuatorToPosition(3, Optimum[3]);

	//Add fine Peak Detection
}
