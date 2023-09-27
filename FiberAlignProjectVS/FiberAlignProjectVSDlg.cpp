
/*
CFiberAlignProjectVS
Author: Kersten Mumme
Date: 23.03.2023
E-Mail Adress: kersten.mumme@uni-oldenburg.de or kersten.mumme@ewe.net	
License: Feel free to use it for educational purposes, but contact me befor using it to make money, directly or indirectly. 

This programm was created for my bachelors projects and consists of a simple user interface, a custom alghorithm to maximize the 
coupling efficiency of a free space laser beam into an optical fiber. 
The theory behind the coupling is further explained in my thesis, but I can reiterate the main points here again.
Problem: The coupling of a beam into a fiber is highly position dependent, on the scale of micrometer in accuracy. 
	But exactly how sensitive is it and how do specially shaped fibers fare in comparison. 
Solution: Build a setup that measures the coupling efficiency based on the position.
Requirements: Automation of the Peak finding process, which maximizes the coupling efficiency. 
	Also automation of the measurements that follow. 
Implementation: Using a NanoMax stage, made by Thorlabs, create a programm that handles the actuator movements to 
	maximize the coupling efficiency. For this, a set of stepper motors was bought, with their respective 
	control unit. As the NanoMax stage and the Piezo control unit was already availabe, the programm needed to also 
	be able to talk with that. As the piezo controller was older then the newer software that Thorlabs uses
	to communicate with the controllers, called "Kinesis", the old system needed to be used, which uses ActiveX control elements. 

Adaptation Guide: 
	1: Calibrate sensors and actuators. The transfer function used in this programm are specially chosen for the equipment used. 
	2: Change IDs. The ActiveX control uses UUIDs to talk to specific controllers. The values filled in in the gui 
		are the ones used in the original setup. If the controllers by Thorlabs do not have the UUIDs on the back of the box,
		you can download the APT User software from their website, which automatically detects all connected controllers. 
		Change the values in the Dialog page, to ensure that the programm is communicating with the correct controllers.
	3: Flash the script to the Arduino. The library I used to decode the ADS1115 signal was helpfull, as in they 
		provided the script I based mine on in the examples. For easiest adaptation, 
		use the format of six digit values, split by !, with a & at the end of a dataset. An Example: 
		001345!001345!001345!001345&001345!001345!001345!001345&001345!001345!001345!001345&
	4: 

Startup Guide:
	0: General rules. Never press Enter, Space, Escape or any other button except the number buttons and . (dot).
		This will instantly close the program, with no way to return. 
		Make sure that every edit field is filled out with appropirate values befor pressing the coresponding button. 
		If you do not, or make any other mistake and get a Debug Error, a complete restart of the controller and the 
		PC running the script is required. 
		The drop down menues are only used for selecting options, not writing in them. 
		While the script does something, that takes longer then 10 seconds, the program will show no feedback, while still being 
		completely operational. No further inputs will be accepted until the script is done. 
	1: Complete the setup. Make sure a fiber is loaded into the holder, connect (and turn on if required) the sensors 
		to the AD converter, turn on the laser.   
	2: Connect the gonio controller, the piezo controller and the stepper controller to the PC running the programm. 
		(And turn them on)
	3: Connect arduino to PC and flash the script, if not already in memory.
	4: Start programm and calibrate the actuators, using the corresponding button. After that, move the actuators 
		(using the GoToPosition Button) to a point where some coupling occurs. While this takes some time,
		roughly 10 minutes for me, this is a time saving measure. I could have programmed it to make a mesh of the measurement 
		range and find the rough position, it would have taken to long to make the mesh tight enough, that it would have extend the 
		runtime extensively. 
		This can be done by eye in most cases. To check if you have some coupling, use the Manual Voltage Measurement Button. 
		Note that as of the 23.03.2023, the baseline coupling efficiency is 10%. Once at least Efficiency * Fraction > 10% is reached,
		you can start the Peak finding process. 
	5: During the Peak finding process, the programm will start to create folders in the OutputVectors folder. In the first 
		itteration of the Peak finding process, monitor if at least one point with coupling efficiency over 10% is measured,
		as no such point will result in a broken Peak finding process. After the first itteration is done and each axis has 
		found a point of sufficient efficiency, the process can be left unattended. 
	6: After some time, on the scale of one to three hours, the Peak finding process should come to a halt, when either the 
		MaxNumberOfItterations is met, or the improvements are sufficiently small to declare a successfull peak finding.
		On the other hand, it may crash should the measurements range of an axis goes out of bounds, but that should not 
		happen and has not in all previous attempts. 
		All relevant data will be dumped into the OutputVectors folder, with some number of subfolders named ItterationX, 
		where X is the current itteration variable, from 0 to MaxNumberOfItterations. 
		There the Efficiency and Position Lists can be found, which were used by the programm to find the peak coupling efficiencies.
		The files are all dimensionless, but are internally consistent. The efficiency files all contain percentage values,
		where the position files contain mm values for the X,Y,Z axes and degree for the goniometer.
		The other files created by the script are meant for bugfixing and also logging of parameters. 
		The LowerLimit and UpperLimit files contain the positions of the measurement range per itteration in mm and degree respectively.
		The PeakCouplingEfficiency files contain the highest coupling efficiency per axis per itteration in percent.
		The HighestCouplingEfficiencyPosition denotes the position where the Peak Coupling Efficiency was reached, in mm and degree respectively.

		7: Once the Peak finding process is done, the Return To Optimum button and relative Measurement Runs become available 
		to the user. This is usefull when doing the final measurements, used to measure the coupling efficiency 
		of the fiber per axis. Between each measurement run, press the return to Optimum button, as this is not done 
		automatically. Otherwise the measurement will show the coupling efficiency outside of the beam, which is of no 
		great interst. 
	8: Using the provided Matlab script, the Position- and Efficiency Lists are used to create a number of plots, 
		showing the coupling efficiency measurements change over the itterations. 


Should any question reguarding this code or the setup come up, I am happy to attempt to answer them, which may or 
may not happen as I am not a software developer, but more an engineer who also does programming from time to time. 

*/

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
#include <ctime> 
#include <cstdio>







typedef std::basic_string<TCHAR> tstring;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//Creating Variables for the Serial Port. Specific Values Depend on the arduino board used. 
CSerialPort serial = CSerialPort::CSerialPort();
LPCTSTR ComPortName = L"Com3";
DWORD BaudRate = 9600;
bool Overlap = false;
CSerialPort2::Parity Parity = CSerialPort2::Parity::NoParity;
BYTE DataBits = 8;
CSerialPort2::StopBits StopBits = CSerialPort2::StopBits::OneStopBit;
CSerialPort2::FlowControl FlowControl = CSerialPort2::FlowControl::NoFlowControl;

				
float Range = 6.144; //Range of the AD converter, 2^16 values are linearly divided from -Range to Range
					//IMPORTANT NOTE: This value needs to be the same as the one set in the arduino script, to ensure correct conversion between bit values and voltage, as the ADS1115 features variable measurement ranges.

long ChanID = 0; //Channel ID is used by Thorlabs for their two Channel units, as they behave differently from the three Channel Unit. 
				//This variable is of no interest for this script, as the three channel units do not use it and the one channel unit requires a 
				//Value of 0.

float MinPosX = -1; //Setting the physical boundries of the stage, to ensure that the stepper motors do not crash into the housing of the stage,
float MaxPosX = 3.8;// Damaging both parts 

float MinPosY = -1;
float MaxPosY = 3.8;

float MinPosZ = -1;
float MaxPosZ = 3.8;

float MinPosGonio = -7; //The Limits for the gonio are set in mm, as thats the units the stage uses. In the rest of this programm the unit for the gonio is always in degree, only converted to mm for moving the stage.
float MaxPosGonio = 6;

										//Determine Backreflections from Fiber to Air interface
float RefractiveIndexAir = 1.00027798; //https://refractiveindex.info/?shelf=other&book=air&page=Ciddor
float RefractiveIndexFiberCore = 1.5;    //Equation https://en.wikipedia.org/wiki/Fresnel_equations#:~:text=%5Bedit%5D-,Normal%20incidence,-%5Bedit%5D
float Transmissivity = 1 - pow( abs((RefractiveIndexFiberCore - RefractiveIndexAir)/(RefractiveIndexFiberCore + RefractiveIndexAir)), 2);


int NumberOfDataPoints = 35; //Number Of Measurements Made per run in the Peak finding Function
int MaxNumberOfItteration = 20; //Used to stop programm should too many itterations have happend
int MinNumberOfItteration = 5; //The Peak finding process should at least do this many itterations bevor the condition StopLoop comes into play
float Fraction = static_cast<float>(1) / 2; //Used for detecting the Plateaus edges
bool Error = false; //Used to stop programm in case of a limit error or simular situations
bool StopLoop = false; //Used to stop Peak finding, when the condition for too little improvement is met 
float ImprovementLimit = 0.02; //Stops the Peak finding process if 1 - (NewCouplingEfficiency / OldCouplingEfficiency) < ImprovementLimit  


std::vector<float> Optimum = {0,0,0,0}; //Used for the return to Optimum button


float XStepperPosition = 1; //Used to keep tracks of the stepper positions
float YStepperPosition = 1;
float ZStepperPosition = 1;
float GonioStepperPosition = 0;

float XPiezoPosition = 0; //Used to keep tracks of the piezo positions
float YPiezoPosition = 0;
float ZPiezoPosition = 0;


std::vector<float> PeakCouplingEfficiencyX(MaxNumberOfItteration); //Used to track the coupling efficiency of the axis over itterations
std::vector<float> PeakCouplingEfficiencyY(MaxNumberOfItteration);
std::vector<float> PeakCouplingEfficiencyZ(MaxNumberOfItteration);
std::vector<float> PeakCouplingEfficiencyGonio(MaxNumberOfItteration);

std::vector<float> XHighestEfficiencyPosition(MaxNumberOfItteration); //Used to track the point of highest coupling efficiency over itterations
std::vector<float> YHighestEfficiencyPosition(MaxNumberOfItteration);
std::vector<float> ZHighestEfficiencyPosition(MaxNumberOfItteration);
std::vector<float> GonioHighestEfficiencyPosition(MaxNumberOfItteration);


std::vector<float> XLowerLimit(MaxNumberOfItteration); //Track The Lower and Upper Limits per axes over itterations
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


//Converting a String to a LPCTSTR, used to input Captions into labels
//While L"SomeString" would do the same, this does not work for variables 
LPCTSTR CFiberAlignProjectVSDlg::StringToLPCTSTR(std::string ToConvertString) {

	CString BufferCString((ToConvertString.c_str()));
	TCHAR TCharResult[1024];
	lstrcpy(TCharResult, BufferCString);

	return TCharResult;
}

//Convert measured Voltage into Optical Power on the measurement arm, as calibrated beforhand
float MeaurementArmVoltageToPower(float Voltage) {
	float OpticalPowerFromVoltage;
	float OpticalPowerBeamSplitterCorrected;
	float TrueOpticalPower;

	OpticalPowerFromVoltage = (0.1963 * Voltage)  + 0.0968; //From calibration using Thorlabs PM 160 and a voltage measurement system consisting of an arduino and the ADS1115.

	OpticalPowerBeamSplitterCorrected = (1.12889 * OpticalPowerFromVoltage) - 0.0156953; //Correction for the unequal splitting from the beamsplitter, which 50% Reflection and 45% Transmittion at 543nm

	TrueOpticalPower = OpticalPowerBeamSplitterCorrected / Transmissivity; //Corrected for Backreflections on the Fiber to Air medium interface, based on the refractive indices.
	return TrueOpticalPower;
}

//Convert measured Voltage into Optical Power on the reference arm, as calibrated beforhand
float ReferenceArmVoltageToPower(float Voltage) {
	float OpticalPower;
	float TrueOpticalPower;
	OpticalPower = (Voltage * 0.1988) + 0.129; //From calibration using Thorlabs PM 160 and a voltage measurement system consisting of an arduino and the ADS1115.

	TrueOpticalPower = 920 * OpticalPower / 910; //Correction for the lense, as measured.

	return TrueOpticalPower;
}

//Converts the Angle from the Goniometer to the length of the actuator 
float GonioAngleToLength(float Angle) {
	float Length;

	Length = 0.661641 * Angle + 0.0986658; //Measured by setting a motor distance, and reading of the angle using the scale and nonius and fit in Matlab

	return Length;
}


//Converts the Length of the actuator to the angle of the goniometer
float GonioLengthToAngle(float Length) {
	float Angle;

	Angle = 1.51053 * Length - 0.149123; //Measured by setting a motor distance, and reading of the angle using the scale and nonius and fit in Matlab 

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
long FindEdgeIndices(std::vector<float> List, float Maximum, float Fraction, bool FromLeft) {

	long Result = 0;

	if (FromLeft) //Detecting the left edge
	{
		for (long i = 0; i < List.size(); i++)
		{
			if (List[i] > (Maximum * Fraction)) //Finding the index for which the corresponding value is the first that excedes the product of the maximum and the fraction, from the left side
			{
				Result = i;
				break;
			}


		}

	}
	else { //Detecting the right edge


		for (long i = (List.size() - 1); i >= 0; i--)
		{
			if (List[i] > (Maximum * Fraction)) //Finding the index for which the corresponding value is the first that excedes the product of the maximum and the fraction, from the right side
			{
				Result = i;
				break;
			}
		}

	}

	return Result;
}

//Detects the Plateau, depending on the Efficiency List, the Position List, the Maxima and the Fraction
//The First Value is the lower Plateau Edge, the Second is the Higher Plateau Edge, 
//the Third is the Position of highest Efficiency and the fourth is the maximum coupling efficiency.
std::vector<float> DetectPlateau(std::vector<float> EfficiencyList, std::vector<float> PositionList, int AxisIndex) {

	std::vector<float> Result(4);
	auto Maximum = std::max_element(std::begin(EfficiencyList), std::end(EfficiencyList)); //Finding the highest coupling efficiency in the EfficiencyList 
	int LowerLimitIndex = FindEdgeIndices(EfficiencyList, *Maximum, Fraction, true);
	int UpperLimitIndex = FindEdgeIndices(EfficiencyList, *Maximum, Fraction, false);
	float AllowedLowerLimit = 0;
	float AllowedUpperLimit = 0;
	

	switch (AxisIndex) { //Setting the physical limits for the stage, to ensure the stepper motors do not crash into the housing 
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

	if (LowerLimitIndex == 0 && PositionList[LowerLimitIndex] - 0.1 > AllowedLowerLimit) //If the edge of the plateau is at the lower end of the measurement region, extend the region further in that direction
	{
		Result[0] = PositionList[LowerLimitIndex] - 0.1;
	}
	else { //if it is not out of bounds, get the regular edge position
		Result[0] = PositionList[LowerLimitIndex];
	}

	if (UpperLimitIndex == (NumberOfDataPoints - 1) && (PositionList[UpperLimitIndex] + 0.1) < AllowedUpperLimit) //If the edge of the plateau is at the higher end of the measurement region, extend the region further in that direction
	{
		Result[1] = PositionList[UpperLimitIndex] + 0.1;
	}
	else { //if it is not out of bounds, get the regular edge position
		Result[1] = PositionList[UpperLimitIndex];
	}

	auto it = std::find(EfficiencyList.begin(), EfficiencyList.end(), *Maximum); //Get the index for the highest coupling efficiency
	int Index = it - EfficiencyList.begin();


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


//Corrects for the inaccuracies of the stepper motors by using the parabolic nature of the inaccuracies to use the quadratic equation to solve for the corrected position, that when 
// put into the MoveActuators function will move the stepper motor to the true position
float CFiberAlignProjectVSDlg::StepperCorrection(long AxisIndex, float StepperMotorShouldBePosition) {

	float CorrectedPosition = 0;
	std::vector<float> XCorrectionValues = { -0.0087, 1.0318, -0.0403}; //Parameter for the quadratic nature of the inaccuracies.
	std::vector<float> YCorrectionValues = { -0.0072, 1.0388, -0.0100};	//First Parameter is a, second b and third c, with the equation being y(x) = ax^2 + bx + c for the inaccuracies
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


//Moves the Actuators of a Axis to a specified position.
//The Axis Index is the same as in the drop down menu of the AxisSelector
//0:X,1:Y,2:Z,3:Gonio
float CFiberAlignProjectVSDlg::MoveActuatorToPosition(long AxisIndex, float Position) {
	
	if (Position > 10) { //Stop Function if value is to large, everything above a certain value will break the SW limits, due 
		DebugNum1.put_Caption(L"Too Large Input Value!");			 //to the position correcton curve I use
		return 0;
	}

	switch (AxisIndex) {
	case 0: {	

		XStepperPosition = Position; //Kept for future changes, to enable the piezos to also be moved
		StepperX.SetAbsMovePos(ChanID, StepperCorrection(AxisIndex, Position));
		StepperX.MoveAbsolute(ChanID, true); //the second argument of the MoveAbsolute function depicts the time when the method returns
											// true means that it returns once the movement is completed, false directly after the movement
											// was initiated.
	}
		  break;

	case 1: {

		YStepperPosition = Position;
		StepperY.SetAbsMovePos(ChanID, StepperCorrection(AxisIndex, Position));
		StepperY.MoveAbsolute(ChanID, true);
		break;
	}
	case 2: {

		ZStepperPosition = Position;
		StepperZ.SetAbsMovePos(ChanID, StepperCorrection(AxisIndex, Position));
		StepperZ.MoveAbsolute(ChanID, true);		

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

//Function to Save a std::vector<float> into a .txt file, which is in the folder Folder and named Name
//Note that the folder is not created automatically, this needs to be done either manually or where this function is called
void SaveToFile(std::vector<float> VectorToBeSaved, std::string Folder, std::string Name) {

	std::ofstream output_file("./" + Folder + "/" + Name + ".txt");
	std::ostream_iterator<float> output_iterator(output_file, "\n");
	std::copy(VectorToBeSaved.begin(), VectorToBeSaved.end(), output_iterator);

}

//Setting the correct labels for the Upper and Lower Limit and the GoToPosition Label, depending on the Axis selected
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
		LowerLimitUnitLabel.put_Caption(L"Error in Unit Selector");
		UpperLimitUnitLabel.put_Caption(L"Error in Unit Selector");
		GoToPosUnitLabel.put_Caption(L"Error in Unit Selector");
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
	

	//On start up, these functions are called.
	//This is the only place where the .StartCtrl() function will work properly.
	PiezoX.StartCtrl();
	PiezoY.StartCtrl();
	PiezoZ.StartCtrl();
	StepperX.StartCtrl();
	StepperY.StartCtrl();
	StepperZ.StartCtrl();
	StepperGonio.StartCtrl();

	AxisSelectorDropDownMenu.SetCurSel(0); //The default axis and measurement run setting are set
	RelativeAndAbsoluteSelector.SetCurSel(0);

	LowerLimitUnitLabel.put_Caption(L"mm"); //Units for the positions is set
	UpperLimitUnitLabel.put_Caption(L"mm");
	GoToPosUnitLabel.put_Caption(L"mm");

	return TRUE;  
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



//Checking if the difference in the coupling efficiency is sufficiently small to stop the Peak finding process
bool CheckCouplingEfficiencyIncrease(float OldEfficiency, float NewEfficiency) {

	bool Output = false;

	Output = abs(1 - (NewEfficiency / OldEfficiency)) < ImprovementLimit ;

	return Output;
}


//StartPeakFinding button
//This function results in a series of movements which will systematically maximize the coupling efficiency, until either the improvement limit is met, the number of allowed itterations is met or 
//the measurement run function encounters an error. 
//IMPORTANT NOTE: Should the Peak finding function not find at least one value with some amount of coupling per axis in the first itteration, this function will not work. 
//As it is a gradual improvement, the initial values are important to the outcome.
//So to ensure proper function, set the stage to a point of at least some coupling efficiency, at least Coupling efficiency * Fraction > 10%, bevor starting the Peak finding process.
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
			DebugNum2.put_Caption(L"Stopped Peak finding because of StopLoop, not enough improvements");
			Optimum[0] = XStepperPosition; //The Optimum Prameter are written to the Optimum List, enabling the user to use the 
			Optimum[1] = YStepperPosition; //return to Optimum Button and the Relative Measurement function
			Optimum[2] = ZStepperPosition;
			Optimum[3] = GonioStepperPosition;
			DebugNum1.put_Caption(L"Peak Found! ");

			break;
		}

		for (int j = 0; j < 4; j++) //Looping over the axes, order being X,Y,Z,Gonio
		{

			switch (j) {
			case 0: {
				if (i == 0) //The first itteration needs initial values for the lower and upper limit. This is in this case the entire measurement range, but could also be made smaller, if the 
				{			// region where the coupling occurs is already somewhat known
					LowerMeasurementLimit = XStepperPosition - 0.5;
					UpperMeasurementLimit = XStepperPosition + 0.5;
				}
				else {
					LowerMeasurementLimit = XLowerLimit[i - 1];
					UpperMeasurementLimit = XUpperLimit[i - 1];
				}

				TempVector = MeasurementRun(j, LowerMeasurementLimit, UpperMeasurementLimit, NumberOfDataPoints, i);

				if (Error) //If a Limit is out of bounds, stop the Peak finding function. 
				{
					DebugNum1.put_Caption(L"Peak finding stopped because of Error");
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
					LowerMeasurementLimit = YStepperPosition - 0.3;
					UpperMeasurementLimit = YStepperPosition + 0.3;

				}
				else {
					LowerMeasurementLimit = YLowerLimit[i - 1];
					UpperMeasurementLimit = YUpperLimit[i - 1];
				}

				TempVector = MeasurementRun(j, LowerMeasurementLimit, UpperMeasurementLimit, NumberOfDataPoints, i);

				if (Error) //If a Limit is out of bounds, stop the Peak finding function
				{
					DebugNum1.put_Caption(L"Peak finding stopped because of Error");
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
					LowerMeasurementLimit = ZStepperPosition - 0.3;
					UpperMeasurementLimit = XStepperPosition + 0.3;
				}
				else {
					LowerMeasurementLimit = ZLowerLimit[i - 1];
					UpperMeasurementLimit = ZUpperLimit[i - 1];
				}



				TempVector = MeasurementRun(j, LowerMeasurementLimit, UpperMeasurementLimit, NumberOfDataPoints, i);

				if (Error) //If a Limit is out of bounds, stop the Peak finding function
				{
					DebugNum1.put_Caption(L"Peak finding stopped because of Error");
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
					LowerMeasurementLimit = GonioStepperPosition - 1;
					UpperMeasurementLimit = GonioStepperPosition + 1;
				}
				else {
					LowerMeasurementLimit = GonioLowerLimit[i - 1];
					UpperMeasurementLimit = GonioUpperLimit[i - 1];
				}

				TempVector = MeasurementRun(j, LowerMeasurementLimit, UpperMeasurementLimit, NumberOfDataPoints, i);

				if (Error) //If a Limit is out of bounds, stop the Peak finding function
				{
					DebugNum1.put_Caption(L"Peak finding stopped because of Error");
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

			//Save all Lists used in the Loop into textfiles. This is usefull for debugging the programm and keeping track of the stage over time 
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



std::vector<float> CFiberAlignProjectVSDlg::GetVoltageValues() {

	serial.CSerialPort::Open(ComPortName, BaudRate, Parity, DataBits, StopBits, FlowControl, Overlap); //Open the serial connection with the arduino 
	//serial.SetConfig();
	std::vector<float> Results = {1, 1, 1};
	serial.ClearReadBuffer(); //Clear the buffer of any older data, which would screw with the accuracy

	Sleep(3000);
	const int BUFFER_SIZE = 512; //The amount of data to be read. Can go up to 1023, but will crash above. While 1023 bytes would result in better averaging, the values are so close together that it is 
								//not necessary and would increase the runtime by a factor of two.

	char input_buffer[BUFFER_SIZE] = { NULL };

	serial.Read(input_buffer, BUFFER_SIZE-1);

	std::string SerialOutputString = input_buffer;

	//DebugNum3.put_Caption(StringToLPCTSTR(SerialOutputString));

	//An exemplary string of what the SerialOutputString looks like. The Datasets are divided by !, while the data in a dataset is divided by &
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

		return GetVoltageValues();
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
		{	//Super simple detection if the string is faulty, counting the number of characters and counting the number of !. While simple, this detection has so far not let any faulty lines through. 
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
		return GetVoltageValues();
		//return Results;
	}
	DebugNum1.put_Caption(StringToLPCTSTR(std::to_string(FirstTimeSplit.size())));


	//Once all Faulty Datasets are removed and enough made it through, they are split into 4 vectors containing the values for all ADS Inputs
	std::vector<long> VoltageListZero(FirstTimeSplit.size());
	std::vector<long> VoltageListOne(FirstTimeSplit.size());
	std::vector<long> VoltageListTwo(FirstTimeSplit.size());
	std::vector<long> VoltageListThree(FirstTimeSplit.size());

	std::vector<std::string> TempVoltageList;

	for (long i = 0; i < FirstTimeSplit.size(); i++) //Split the Datasets into the the data they consist of, then save them in seperate lists.
	{
		boost::split(TempVoltageList, FirstTimeSplit[i], boost::algorithm::is_any_of("!"), boost::algorithm::token_compress_mode_type::token_compress_on);
		VoltageListZero[i] = stol(TempVoltageList[0]);
		VoltageListOne[i] = stol(TempVoltageList[1]);
		VoltageListTwo[i] = stol(TempVoltageList[2]);
		VoltageListThree[i] = stol(TempVoltageList[3]);
	}

	long VoltageSumZero = std::accumulate(VoltageListZero.begin(), VoltageListZero.end(), 0); //The vectors are summed up 
	long VoltageSumOne = std::accumulate(VoltageListOne.begin(), VoltageListOne.end(), 0);
	long VoltageSumTwo= std::accumulate(VoltageListTwo.begin(), VoltageListTwo.end(), 0);
	long VoltageSumThree = std::accumulate(VoltageListThree.begin(), VoltageListThree.end(), 0);

	//The sum is then divided by the length of the lists, resulting in the mean value being divided by two and the number of bits(2^15) and multiplied by the Range. Then the two lists per arm are added up.
	//This results in two lists of bit values being converted to a single float value which represents the mean voltage corresponding to the bit values.
	Results[0] = (VoltageSumZero / (static_cast<float>(2) * VoltageListZero.size()) * Range + VoltageSumOne / (static_cast<float>(2) * VoltageListZero.size()) * Range) / 32768; 
	Results[1] = (VoltageSumTwo / (static_cast<float>(2) * VoltageListZero.size()) * Range + VoltageSumThree / (static_cast<float>(2) * VoltageListZero.size()) * Range) / 32768;

	//From the two optical powers, the coupling efficiency is then calculated. 
	Results[2] = (MeaurementArmVoltageToPower(Results[1]) * 100 / ReferenceArmVoltageToPower(Results[0]));

	serial.Close(); //Closing the serial connection to the arduino properly increases the odds of a successfull connection to the ADS1115 in the future.

	//The results from the Voltage measurement is then written to the Labels on the gui
	MeasuredVoltagesLabel.put_Caption(StringToLPCTSTR("Measurement Arm Voltage = " + std::to_string(Results[1]) + " V " + "Reference Arm Voltage      = " + std::to_string(Results[0]) + " V "));
	ReferenceArmOpticalPowerLabel.put_Caption(StringToLPCTSTR("PMeasurement = " + std::to_string(MeaurementArmVoltageToPower(Results[1])) + " mW " + "PReference      = " + std::to_string(ReferenceArmVoltageToPower(Results[0])) + " mW "));
	CouplingEfficiencyLabel.put_Caption(StringToLPCTSTR("Coupling Efficiency = " + std::to_string(MeaurementArmVoltageToPower(Results[1]) * 100 / ReferenceArmVoltageToPower(Results[0])) + " %"));
	return Results;
	
}



//Performs long time stability measurement to check how stable the coupling efficiency calculation is in respect to the fluctuations of the laser
void CFiberAlignProjectVSDlg::ClickCommandbutton6()
{

	std::vector<long int> Time;
	std::vector<float> MeasurementArmPower;
	std::vector<float> ReferenceArmPower;
	std::vector<float> CouplingEfficiency;
	size_t NumberOfMeasurements = 700;
	float DelayBetweenMeasurements = 7; //Seconds
	std::vector<float> TempVector;


	for (size_t i = 0; i < NumberOfMeasurements; i++)
	{

		TempVector = GetVoltageValues();
		MeasurementArmPower[i] = MeaurementArmVoltageToPower(TempVector[1]);
		ReferenceArmPower[i] = ReferenceArmVoltageToPower(TempVector[0]);
		CouplingEfficiency[i] = TempVector[2];
		Sleep(DelayBetweenMeasurements * 1000);
	}

	SaveToFile(MeasurementArmPower,"OutputVectors//StabilityMeasurement","MeasurementArmPower");
	SaveToFile(ReferenceArmPower, "OutputVectors//StabilityMeasurement", "ReferenceArmPower");
	SaveToFile(CouplingEfficiency, "OutputVectors//StabilityMeasurement", "CouplingEfficiency");

	Sleep(1000);

	std::ofstream output_file("OutputVectors//StabilityMeasurement/Time.txt");
	std::ostream_iterator<long int> output_iterator(output_file, "\n");
	std::copy(Time.begin(), Time.end(), output_iterator);


}



// Homing The Actuators and Moving them to the middle of their allowed positions.
//This needs to be done at the start of the process, as otherwise the actuators do not behave properly. 
void CFiberAlignProjectVSDlg::ClickCommandbutton5()
{
	
	//Create Constants for Homing and Velocity Behavior
	long HomeDirection = 2; //Enumarator for the Homing direction, 1 meaning forward direction, 2 meaning reverse direction
	long HomeLimitSwitch = 1; //Enumerator for the swtich position, 1 for reverse direction, 4 for forward direction
	float HomeVelocity = 0.5; //Sets homing speed
	long StageUnits = 1; //Enumerator for actuator units, 1 for mm, 2 for degree
	float PitchXYZ = 0.5; 
	float PitchGonio = 1; 
	long DirectionSense = 1; //Enumerator for direction sense, 1 meaning forward direction, 2 meaning reverse direction
	long ReverseLimitSwitch = 2; //Sets Limit Switch behavior, 1 = ignore, 2 = switch closes on contact
	long ForwardLimitSwitch = 1;
	float MinVelo = 0; //Sets minimum velocity for the motors in mm / s
	float AccelerationXYZ = 4; //Sets maximum acceleration for the motors in mm / s^2
	float AccelerationGonio = 1.5;	//Sets maximum acceleration for the gonio stage in mm / s^2
	float MaxVelo = 2;	//Sets maximum velocity for the motors in mm / s
	float StepperMiddlePosition = 1.9; //Sets middle position 
	long SoftwareLimitSwitchBehavior = 2; //Stops motor instantly, should a software limit switch be engaged

	//Determined Experimentally, these values determine the offset between the limit switch in the actuators and the zero point
	//Measured by jogging the actuator forwards until the gauge shows a distance change
	float ZeroOffsetX = 2.65;
	float ZeroOffsetY = 2.525;
	float ZeroOffsetZ = 2.45;
	float ZeroOffsetGonio = 7.55;

	long PiezoControlMode = 4; //Enumerator for Piezo control mode, 1 = open loop, 2 = closed loop, 3 = open loop smooth, 4 = closed loop smooth
	float PiezoMiddlePosition = 10;
	long VoltMicronOutputMode = 2; //Enumerator for the display mode, 1 = position, 2 = voltage, 3 = force 

	//Sets the Constants for the PI controller. This does not seem to work, as no behavior as expected from either a proportional or integral control unit
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
	StepperZ.SetVelParams(ChanID, MinVelo, 1*AccelerationXYZ, 1*MaxVelo); //Without the 1*, this function call does not work properly. 
	StepperGonio.SetVelParams(ChanID, MinVelo, AccelerationGonio, MaxVelo);

	//Setting the Displayed Units to Micrometer
	PiezoX.SetVoltPosDispMode(ChanID, VoltMicronOutputMode);
	PiezoY.SetVoltPosDispMode(ChanID, VoltMicronOutputMode);
	PiezoZ.SetVoltPosDispMode(ChanID, VoltMicronOutputMode);

	//Setting the PI Constants of the Piezo Controlers to favor the integral behavior
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

	Sleep(20000); //Wait for the homing of the actuators to finish 

	//Moving every Actuator to Halve their movement Range, for Manual Adjustment of the Setup,
	//	To ensure the focal point is within the movement Range of the Stage
	//Set Absolute Move Position
	StepperX.SetAbsMovePos(ChanID, StepperMiddlePosition);
	StepperY.SetAbsMovePos(ChanID, StepperMiddlePosition);
	StepperZ.SetAbsMovePos(ChanID, StepperMiddlePosition);

	//Set SoftWare behavior again, as it was lost since the first time setting it 
	StepperX.SetSWPosLimits(ChanID, MinPosX, MaxPosX, SoftwareLimitSwitchBehavior);
	StepperY.SetSWPosLimits(ChanID, MinPosY, MaxPosY, SoftwareLimitSwitchBehavior);
	StepperZ.SetSWPosLimits(ChanID, MinPosZ, MaxPosZ, SoftwareLimitSwitchBehavior);
	StepperGonio.SetSWPosLimits(ChanID, MinPosGonio, MaxPosGonio, SoftwareLimitSwitchBehavior);

	//Do the Absolute Movement to the middle position
	StepperX.MoveAbsolute(ChanID, false);
	StepperY.MoveAbsolute(ChanID, false);
	StepperZ.MoveAbsolute(ChanID, false);

	Sleep(5000);
	//Go To Middle Position of the Piezos
	PiezoX.SetPosOutput(ChanID, PiezoMiddlePosition);
	PiezoY.SetPosOutput(ChanID, PiezoMiddlePosition);
	PiezoZ.SetPosOutput(ChanID, PiezoMiddlePosition);

	//Set SoftWare behavior again, as it was lost since the first time setting it 
	StepperX.SetSWPosLimits(ChanID, MinPosX, MaxPosX, SoftwareLimitSwitchBehavior);
	StepperY.SetSWPosLimits(ChanID, MinPosY, MaxPosY, SoftwareLimitSwitchBehavior);
	StepperZ.SetSWPosLimits(ChanID, MinPosZ, MaxPosZ, SoftwareLimitSwitchBehavior);
	StepperGonio.SetSWPosLimits(ChanID, MinPosGonio, MaxPosGonio, SoftwareLimitSwitchBehavior);

	Sleep(13000); //Wait until all movement has stopped bevor stopping this function


}

//GoToPositionButton
//This button is to be read horizontally, such that the Axis Selector and the GoToPosition Edit Box fall under its domain
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
	GetVoltageValues();
}




//TestButton, used for debugging
void CFiberAlignProjectVSDlg::ClickCommandbutton7() {
	time_t begin, end;
	time(&begin);

	time(&end);
	double difference = difftime(end, begin) / 30;
	DebugNum1.put_Caption(StringToLPCTSTR(std::to_string(difference)));
}




//Go from point to point, Measuring the Coupling Efficiency at every point, then evaluate where the maximum point is and returning the Lower and Upper Plateau edge, the middle and highest coupling efficiency.
//This button is meant to be read vertically, so that the axis selector, the Lower and UpperLimit and the Number of Points fall under its domain
std::vector<float> CFiberAlignProjectVSDlg::MeasurementRun(int AxisIndex, float LowerLimit, float UpperLimit, int NumberOfPoints, int Itterator) {
	


	std::vector<float> PositionList = NumberListFunction(LowerLimit, UpperLimit, NumberOfPoints); //Create the position list, containing NUmberOfPoints points between LowerLimit and UpperLimit
	std::vector<float> EfficiencyList(NumberOfPoints); 
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

	//Set Allowed Limits, which are compared to the determined Limits, to make sure they are within bounds
	switch (AxisIndex) {
	case 0: {
		AllowedLowerLim = 0; //While the stage can move into the negative values, it is not used as motor movement below 0mm results in no movement of the stage.
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
		AllowedLowerLim = -9; //Limits in degree, which is why they are different from Min- and MaxPosGonio
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


	MoveActuatorToPosition(AxisIndex, PositionList[0]); //Move motor to the lowest position
	Sleep(2);
	for (long i = 0; i < NumberOfPoints; i++) 
	{
		MoveActuatorToPosition(AxisIndex, PositionList[i]); //Go to position, take a voltage measurement, save the coupling efficiency to EfficiencyList and go to next point. 
		TempVoltList = GetVoltageValues();
		EfficiencyList[i] = TempVoltList[2];

	}
	

	std::string FolderStartString = "OutputVectors//Itteration";
	std::string FolderAppendage = std::to_string(Itterator);
	std::string FolderAppendedString = FolderStartString + FolderAppendage;
	const char* FolderDirChar = FolderAppendedString.c_str();
	_mkdir(FolderDirChar); //create new folder for the Position and Efficiency Lists. This does noch check if the folder already exists, as creating it a second time does nothing

	std::string FileTitlePosition = "Position";
	std::string FileTitelEfficiency = "Efficiency";

	SaveToFile(PositionList, FolderDirChar, FileTitlePosition + AxisString); //Save the Position and Efficiency Lists to .txt files, with the names of the Axis and the itteration number added
	SaveToFile(EfficiencyList, FolderDirChar, FileTitelEfficiency + AxisString);
	


	auto Maximum = std::max_element(std::begin(EfficiencyList), std::end(EfficiencyList)); //Gets the highest coupling efficiency value
	std::vector<float> Results(4);
	std::vector<float> PlateauResults;
	PlateauResults = DetectPlateau(EfficiencyList, PositionList,AxisIndex);
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
//Gets the values from the AxisSelector, the RelativeAndAbsoluteSelector, the Lower- and UpperLimit and the NumberOfPoints edit field
bool CFiberAlignProjectVSDlg::ClickCommandbutton4()
{
	
	int RelativOrAbsolute = RelativeAndAbsoluteSelector.GetCurSel();
	int AxisIndex = AxisSelectorDropDownMenu.GetCurSel();
	float LowerLimit = ReadLowerLimitValue();
	float UpperLimit = ReadUpperLimitValue();
	long NumberOfPoints = ReadNumberOfPointsValue();
	

	//Differentiate between relative and absolute measurements
	if (RelativOrAbsolute == 0) 
	{//Absolute Measurement
		MeasurementRun(AxisIndex, LowerLimit, UpperLimit, NumberOfPoints, 1);

	} else { 
	//Relative Measurement, only possible if a optimum finding run was successfull 

		MeasurementRun(AxisIndex, Optimum[AxisIndex] + LowerLimit, Optimum[AxisIndex] + UpperLimit, NumberOfPoints, 0);

	}




	return true;

}




//Return to the point of highest coupling efficiency
//Can only properly be called after successfull Peak finding.
void CFiberAlignProjectVSDlg::ClickCommandbutton3()
{
	MoveActuatorToPosition(0, Optimum[0]);
	MoveActuatorToPosition(1, Optimum[1]);
	MoveActuatorToPosition(2, Optimum[2]);
	MoveActuatorToPosition(3, Optimum[3]);

}
