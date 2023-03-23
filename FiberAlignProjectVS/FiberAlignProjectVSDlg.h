
// FiberAlignProjectVSDlg.h: Headerdatei
//

#pragma once
#include "CMGPIEZOCTRL1.h"
#include "CMGPIEZOCTRL2.h"
#include "CMGPIEZOCTRL3.h"
#include "CMGMOTORCTRL1.h"
#include "CMGMOTORCTRL2.h"
#include "CMGMOTORCTRL3.h"
#include "CMGMOTORCTRL4.h"
#include "CLABEL1.h"
#include "CCOMMANDBUTTON1.h"
#include "CLABEL3.h"
#include "CLABEL2.h"
#include "CCOMMANDBUTTON2.h"
#include "CLABEL4.h"
#include "CLABEL5.h"
#include "CLABEL6.h"
#include "CCOMMANDBUTTON3.h"
#include "CCOMMANDBUTTON4.h"
#include "CLABEL7.h"
#include "CMG17LOGGERCTRL1.h"
#include "CLABEL11.h"
#include "CLABEL12.h"
#include <string>
#include "CCOMMANDBUTTON6.h"
#include "CCOMMANDBUTTON7.h"
#include "CCOMMANDBUTTON8.h"
#include "CLABEL14.h"
#include <vector>



// CFiberAlignProjectVSDlg-Dialogfeld
class CFiberAlignProjectVSDlg : public CDialogEx
{
// Konstruktion
public:
	CFiberAlignProjectVSDlg(CWnd* pParent = nullptr);	// Standardkonstruktor

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FIBERALIGNPROJECTVS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung


// Implementierung
protected:
	HICON m_hIcon;

	// Generierte Funktionen für die Meldungstabellen
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CMGPIEZOCTRL1 PiezoX;
	CMGPIEZOCTRL2 PiezoY;
	CMGPIEZOCTRL3 PiezoZ;
	CMGMOTORCTRL1 StepperX;
	CMGMOTORCTRL2 StepperY;
	CMGMOTORCTRL3 StepperZ;
	CMGMOTORCTRL4 StepperGonio;
	CLABEL1 DebugNum1;
	CCOMMANDBUTTON1 StartHomingButton;
	CLABEL3 MeasuredVoltagesLabel;
	CLABEL2 DebugNum2;
	CCOMMANDBUTTON2 ManualVoltageMeasurementButton;
	CLABEL4 MeasurementArmOpticalPowerLabel;
	CLABEL5 ReferenceArmOpticalPowerLabel;
	CLABEL6 CouplingEfficiencyLabel;
	CCOMMANDBUTTON3 ReturnToOptimumButton;
	CCOMMANDBUTTON4 StartCouplingSensitivityMeasurementButton;
	CLABEL7 DebugNum3;
	CMG17LOGGERCTRL1 CommunicationLogger;
	afx_msg void OnLbnSelchangeList2();
	afx_msg void OnEnChangeEdit2();
	CComboBox AxisSelectorDropDownMenu;
	CEdit LowerPositionInputField;
	CEdit UpperPositionInputField;
	CEdit NumberOfMeasurementPointsNumberField;
//	afx_msg void OnEnChangeEdit3();
	DECLARE_EVENTSINK_MAP()
		LPCTSTR StringToLPCTSTR(std::string ToConvertString);
	bool ClickCommandbutton1();
	std::vector<float> GetVoltageValues();
	CLABEL11 LowerLimitUnitLabel;
	CLABEL12 UpperLimitUnitLabel;
	afx_msg void OnCbnEditchangeCombo1();
	afx_msg void OnCbnSelchangeCombo1();
	CCOMMANDBUTTON6 InitializeArdunio;
	void ClickCommandbutton6();
	void ClickCommandbutton5();
	CCOMMANDBUTTON7 TestButton;
//	void ClickCommandbutton7();
	void ClickCommandbutton7();
	float StepperCorrection(long AxisIndex, float Position);
	float MoveActuatorToPosition(long AxisIndex, float Position);
	CCOMMANDBUTTON8 GoToPositionButton;
	CLABEL14 GoToPosUnitLabel;
	CEdit GoToPosValue;
	float ReadGoToPosValue();
	float ReadLowerLimitValue();
	float ReadUpperLimitValue();
	float ReadNumberOfPointsValue();
	void ClickCommandbutton8();
	void ClickCommandbutton2();
	bool ClickCommandbutton4();
	std::vector<float> MeasurementRun(int AxisIndex, float LowerLimit, float UpperLimit, int NumberOfPoints, int Itterator);
	CComboBox RelativeAndAbsoluteSelector;
	void ClickCommandbutton3();
};
