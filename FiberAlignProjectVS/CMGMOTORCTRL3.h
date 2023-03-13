#pragma once

// Mit Microsoft Visual C++ generierte IDispatch-Wrapperklasse(n)

// HINWEIS: Die Inhalte dieser Datei dürfen nicht geändert werden.
//  Die Änderungen werden überschrieben, wenn diese Klasse von Microsoft Visual C++ erneut generiert wird.

/////////////////////////////////////////////////////////////////////////////

#include "afxwin.h"

class CMGMOTORCTRL3 : public CWnd
{
protected:
	DECLARE_DYNCREATE(CMGMOTORCTRL3)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= {0x3ce35bf3,0x1e13,0x4d2c,{0x8c,0x0b,0xde,0xf6,0x31,0x44,0x20,0xb3}};
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
						const RECT& rect, CWnd* pParentWnd, UINT nID, 
						CCreateContext* pContext = nullptr)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID);
	}

	BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd,
				UINT nID, CFile* pPersist = nullptr, BOOL bStorage = FALSE,
				BSTR bstrLicKey = nullptr)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); 
	}

// Attribute
public:
enum
{
	DEV_PARAMS = 0,
	DIGOUTPUTS = 1,
	CHANENABLEDSTATE = 2,
	VEL_PARAMS = 3,
	JOG_PARAMS = 4,
	LIMSWITCH_PARAMS = 5,
	POWER_PARAMS = 6,
	GENMOVE_PARAMS = 7,
	HOME_PARAMS = 8,
	MOVEREL_PARAMS = 9,
	MOVEABS_PARAMS = 10,
	MOVEVEL_PARAMS = 11,
	TRIGBITS = 12,
	HOSTDIGOUTPUTS = 13,
	DCPID_PARAMS = 14,
	DCADVANCED_PARAMS = 15,
	POT_PARAMS = 16,
	AV_MODES = 17,
	BUTTON_PARAMS = 18,
	PMD_ILOOP_PARAMS = 19,
	PMD_PLOOP_PARAMS = 20,
	PMD_MOUTPUT_PARAMS = 21,
	PMD_TRACKSETTLE_PARAMS = 22,
	PMD_PROFILE_PARAMS = 23,
	PMD_JOYSTICK_PARAMS = 24,
	PMD_STAGEAXIS_PARAMS = 25,
	PMD_ILOOPSETTLED_PARAMS = 26
}LLMOTREQIDS;

enum
{
	CHAN1_ID = 0,
	CHAN2_ID = 1,
	CHANBOTH_ID = 10
}HWCHANNEL;

enum
{
	TYPE_UNKNOWN = 1,
	TYPE_17APT600R = 2,
	TYPE_17APT600L = 3,
	TYPE_NANOMAX300 = 16,
	TYPE_NST150 = 32,
	TYPE_NST25 = 33,
	TYPE_NST50 = 34,
	TYPE_NST75 = 35,
	TYPE_NST100 = 36,
	TYPE_NANOMAX600_DRV001 = 48,
	TYPE_DRV005 = 64,
	TYPE_DRV006 = 65,
	TYPE_DRV013 = 66,
	TYPE_DRV014 = 67,
	TYPE_DRV113 = 68,
	TYPE_DRV114 = 69,
	TYPE_AMR101 = 80,
	TYPE_ZST6 = 96,
	TYPE_ZST13 = 97,
	TYPE_ZST25 = 98,
	TYPE_Z606 = 99,
	TYPE_Z612 = 100,
	TYPE_Z625 = 101,
	TYPE_07EAS503 = 112,
	TYPE_07EAS504 = 113
}STAGETYPE;

enum
{
	AXIS_UNKNOWN = 1,
	AXIS_SINGLE = 2,
	AXIS_ROTARY = 3,
	AXIS_X = 16,
	AXIS_Y = 17,
	AXIS_Z = 18,
	AXIS_PITCH = 19,
	AXIS_ROLL = 20,
	AXIS_YAW = 21
}STAGEAXIS;

enum
{
	UNITS_MM = 1,
	UNITS_DEG = 2
}STAGEUNITS;

enum
{
	STOP_IMMEDIATE = 1,
	STOP_PROFILED = 2
}STOPMODE;

enum
{
	JOG_CONTINUOUS = 1,
	JOG_SINGLESTEP = 2
}JOGMODE;

enum
{
	SWLIMIT_IGNORE = 1,
	SWLIMIT_IMMEDIATESTOP = 2,
	SWLIMIT_PROFILEDSTOP = 3
}SWLIMITMODE;

enum
{
	HOME_FWD = 1,
	HOME_REV = 2
}HOMEDIR;

enum
{
	HOMELIMSW_FWD_HW = 4,
	HOMELIMSW_REV_HW = 1
}HOMELIMSWITCH;

enum
{
	HWLIMSW_IGNORE = 1,
	HWLIMSW_MAKES = 2,
	HWLIMSW_BREAKS = 3,
	HWLIMSW_MAKES_HOMEONLY = 4,
	HWLIMSW_BREAKS_HOMEONLY = 5
}HWLIMSWITCH;

enum
{
	MOVE_FWD = 1,
	MOVE_REV = 2
}MOVEVELDIR;

enum
{
	JOG_FWD = 1,
	JOG_REV = 2
}MOVEJOGDIR;

enum
{
	TRIGMODE_DISABLED = 1,
	TRIGMODE_IN = 2,
	TRIGMODE_INOUT = 3,
	TRIGMODE_OUT = 4
}TRIGMODE;

enum
{
	TRIGMOVE_REL = 1,
	TRIGMOVE_ABS = 2,
	TRIGMOVE_HOME = 3
}TRIGMOVE;

enum
{
	ENC_QEP_POSITIVE = 1,
	ENC_QEP_NEGATIVE = -1
}ENCQEPSENSE;

enum
{
	ENC_POSSRC_MICROSTEP = 1,
	ENC_POSSRC_ENCODER = 2
}ENCPOSSOURCEMODE;

enum
{
	ENC_POSCTRL_DISABLED = 1,
	ENC_POSCTRL_POSITION = 2,
	ENC_POSCTRL_POSITIONSTOPSHORT = 3
}ENCPOSCONTROLMODE;

enum
{
	DISPMODE_PANEL = 1,
	DISPMODE_GRAPH = 2,
	DISPMODE_POSITION = 3
}DISPLAYMODE;

enum
{
	LED_IDENT = 1,
	LED_LIMITSWITCH = 2,
	LED_BUTTONMODECHANGE = 4,
	LED_MOVING = 8
}INDICATORLEDMODE;

enum
{
	BUTTON_MODEJOG = 1,
	BUTTON_MODEGOTO = 2
}BUTTONMODE;

enum
{
	USB_BMC103 = 40,
	USB_BBD103 = 45,
	ETHNET_MMR601 = 42,
	USB_MMR601 = 43
}APT_PARENT_HWTYPES;

enum
{
	ROT_MOVE_POS = 1,
	ROT_MOVE_NEG = 2,
	ROT_MOVE_SHORT = 3
}ROTMOVEMODE;

enum
{
	ROT_POSDISP_360 = 1,
	ROT_POSDISP_TOTAL = 2
}ROTPOSDISPMODE;

enum
{
	PROFMODE_TRAPEZOIDAL = 1,
	PROFMODE_SCURVE = 3
}DCPROFILEMODE;

enum
{
	OUTPUTSTATE_ON = 1,
	OUTPUTSTATE_OFF = 2
}SOLOUTPUTSTATE;

enum
{
	SOLENOID_MANUAL = 1,
	SOLENOID_SINGLE = 2,
	SOLENOID_AUTO = 3,
	SOLENOID_TRIGGER = 4
}SOLOPERATINGMODE;

enum
{
	BRAKE_ON = 1,
	BRAKE_OFF = 2
}BRAKE_STATE;

enum
{
	DCTRIGIN_DISABLED = 1,
	DCTRIGINRISE_RELMOVE = 2,
	DCTRIGINFALL_RELMOVE = 3,
	DCTRIGINRISE_ABSMOVE = 4,
	DCTRIGINFALL_ABSMOVE = 5,
	DCTRIGINRISE_HOMEMOVE = 6,
	DCTRIGINFALL_HOMEMOVE = 7
}DCTRIGINMODE;

enum
{
	DCTRIGOUT_DISABLED = 1,
	DCTRIGOUTHIGH_INMOTION = 2,
	DCTRIGOUTLOW_INMOTION = 3,
	DCTRIGOUTHIGH_MOTIONCOMPLETE = 4,
	DCTRIGOUTLOW_MOTIONCOMPLETE = 5,
	DCTRIGOUTHIGH_MAXVELOCITY = 6,
	DCTRIGOUTLOW_MAXVELOCITY = 7
}DCTRIGOUTMODE;

enum
{
	MFFOPERMODE_IP_TOGGLEPOS = 1,
	MFFOPERMODE_IP_GOTOPOS = 2,
	MFFOPERMODE_OP_ATPOS = 3,
	MFFOPERMODE_OP_MOVING = 4
}MFFOPERMODE;

enum
{
	MFFSIGMODE_IP_BUTTON = 1,
	MFFSIGMODE_IP_LOGIC = 2,
	MFFSIGMODE_IP_SWAP = 4,
	MFFSIGMODE_OP_LEVEL = 16,
	MFFSIGMODE_OP_PULSE = 32,
	MFFSIGMODE_OP_INVERT = 64
}MFFSIGMODE;

enum
{
	KMOT_WHEELMODE_VEL = 1,
	KMOT_WHEELMODE_JOG = 2,
	KMOT_WHEELMODE_GOTOPOS = 3
}KMOTWHEELMODE;

enum
{
	KMOT_WHEELDIRSENSE_DISABLED = 0,
	KMOT_WHEELDIRSENSE_POS = 1,
	KMOT_WHEELDIRSENSE_NEG = 2
}KMOTWHEELDIRSENSE;

enum
{
	KMOT_TRIG_DISABLED = 0,
	KMOT_TRIGIN_GPI = 1,
	KMOT_TRIGIN_RELMOVE = 2,
	KMOT_TRIGIN_ABSMOVE = 3,
	KMOT_TRIGIN_HOME = 4,
	KMOT_TRIGOUT_GPO = 10,
	KMOT_TRIGOUT_INMOTION = 11,
	KMOT_TRIGOUT_MAXVELOCITY = 12,
	KMOT_TRIGOUT_POSSTEPS_FWD = 13,
	KMOT_TRIGOUT_POSSTEPS_REV = 14,
	KMOT_TRIGOUT_POSSTEPS_BOTH = 15
}KMOTTRIGMODE;

enum
{
	KMOT_TRIGPOL_HIGH = 1,
	KMOT_TRIGPOL_LOW = 2
}KMOTTRIGPOLARITY;

enum
{
	KST_LOOP_OPEN = 1,
	KSTR_LOOP_CLOSED = 2
}KSTLOOPMODE;



// Vorgänge
public:
// _DMG17Motor

// Funktionen
//

	void AboutBox()
	{
		InvokeHelper(0xFFFFFDD8, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	long StartCtrl()
	{
		long result;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_I4, (void*)&result, nullptr);
		return result;
	}
	long StopCtrl()
	{
		long result;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_I4, (void*)&result, nullptr);
		return result;
	}
	long GetPosition(long lChanID, float * pfPosition)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, pfPosition);
		return result;
	}
	long LLSetGetPosParams(BOOL bSet, long lChanID, long * plPosControlMode, long * plMicroStepDivider, long * plPosStepRes)
	{
		long result;
		static BYTE parms[] = VTS_BOOL VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0xA, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bSet, lChanID, plPosControlMode, plMicroStepDivider, plPosStepRes);
		return result;
	}
	long LLSetGetVelParams(BOOL bSet, long lChanID, long * plMinVel, long * plAccn, long * plMaxVel)
	{
		long result;
		static BYTE parms[] = VTS_BOOL VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0xB, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bSet, lChanID, plMinVel, plAccn, plMaxVel);
		return result;
	}
	long LLSetGetJogParams(BOOL bSet, long lChanID, long * plJogMode, long * plJogStepSize, long * plMinVel, long * plAccn, long * plMaxVel)
	{
		long result;
		static BYTE parms[] = VTS_BOOL VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0xD, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bSet, lChanID, plJogMode, plJogStepSize, plMinVel, plAccn, plMaxVel);
		return result;
	}
	long LLSetGetLimSwitchParams(BOOL bSet, long lChanID, long * plCWHardLimit, long * plCCWHardLimit, long * plCWSoftLimit, long * plCCWSoftLimit, long * plSoftLimitMode)
	{
		long result;
		static BYTE parms[] = VTS_BOOL VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0xE, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bSet, lChanID, plCWHardLimit, plCCWHardLimit, plCWSoftLimit, plCCWSoftLimit, plSoftLimitMode);
		return result;
	}
	long LLSetGetPowerParams(BOOL bSet, long lChanID, long * plRestFactor, long * plMoveFactor)
	{
		long result;
		static BYTE parms[] = VTS_BOOL VTS_I4 VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0xF, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bSet, lChanID, plRestFactor, plMoveFactor);
		return result;
	}
	long LLSetGetHomeParams(BOOL bSet, long lChanID, long * plDirection, long * plLimSwitch, long * plHomeVel, long * plOffsetDist)
	{
		long result;
		static BYTE parms[] = VTS_BOOL VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x10, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bSet, lChanID, plDirection, plLimSwitch, plHomeVel, plOffsetDist);
		return result;
	}
	long LLSetGetMoveRelParams(BOOL bSet, long lChanID, long * plRelDist)
	{
		long result;
		static BYTE parms[] = VTS_BOOL VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bSet, lChanID, plRelDist);
		return result;
	}
	long LLSetGetMoveAbsParams(BOOL bSet, long lChanID, long * plAbsPos)
	{
		long result;
		static BYTE parms[] = VTS_BOOL VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bSet, lChanID, plAbsPos);
		return result;
	}
	long MoveVelocity(long lChanID, long lDirection)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4;
		InvokeHelper(0x16, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lDirection);
		return result;
	}
	long LLMoveStop(long lChanID, long lStopMode)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4;
		InvokeHelper(0x17, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lStopMode);
		return result;
	}
	long LLReqHWParams(long lChanID, long lParamID)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4;
		InvokeHelper(0x18, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lParamID);
		return result;
	}
	long EnableHWChannel(long lChanID)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x19, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID);
		return result;
	}
	long DisableHWChannel(long lChanID)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x1A, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID);
		return result;
	}
	long LLSetGetDevParams(BOOL bSet, long * plDevParams)
	{
		long result;
		static BYTE parms[] = VTS_BOOL VTS_UNKNOWN;
		InvokeHelper(0x1B, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bSet, plDevParams);
		return result;
	}
	long LLSetGetDevParamsEx(BOOL bSet, VARIANT * plDevParams)
	{
		long result;
		static BYTE parms[] = VTS_BOOL VTS_UNKNOWN;
		InvokeHelper(0x1C, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bSet, plDevParams);
		return result;
	}
	long MoveHome(long lChanID, BOOL bWait)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BOOL;
		InvokeHelper(0x1D, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, bWait);
		return result;
	}
	long StopImmediate(long lChanID)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x1E, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID);
		return result;
	}
	long StopProfiled(long lChanID)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x1F, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID);
		return result;
	}
	long MoveRelativeEx(long lChanID, float fRelDistCh1, float fRelDistCh2, BOOL bWait)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_R4 VTS_R4 VTS_BOOL;
		InvokeHelper(0x20, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, fRelDistCh1, fRelDistCh2, bWait);
		return result;
	}
	long MoveAbsoluteEx(long lChanID, float fAbsPosCh1, float fAbsPosCh2, BOOL bWait)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_R4 VTS_R4 VTS_BOOL;
		InvokeHelper(0x21, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, fAbsPosCh1, fAbsPosCh2, bWait);
		return result;
	}
	long MoveRelative(long lChanID, BOOL bWait)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BOOL;
		InvokeHelper(0x22, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, bWait);
		return result;
	}
	long MoveAbsolute(long lChanID, BOOL bWait)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BOOL;
		InvokeHelper(0x23, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, bWait);
		return result;
	}
	long LLGetStatusBits(long lChanID, long * plStatusBits)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x24, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plStatusBits);
		return result;
	}
	long LLSetGetGenMoveParams(BOOL bSet, long lChanID, long * plBLashDist)
	{
		long result;
		static BYTE parms[] = VTS_BOOL VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x25, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bSet, lChanID, plBLashDist);
		return result;
	}
	long SetVelParams(long lChanID, float fMinVel, float fAccn, float fMaxVel)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_R4 VTS_R4 VTS_R4;
		InvokeHelper(0x26, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, fMinVel, fAccn, fMaxVel);
		return result;
	}
	long GetVelParams(long lChanID, float * pfMinVel, float * pfAccn, float * pfMaxVel)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x27, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, pfMinVel, pfAccn, pfMaxVel);
		return result;
	}
	long GetStageAxis(long lChanID, BSTR * pbstrStageAxisName, long * plStageID, long * plAxisID)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x28, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, pbstrStageAxisName, plStageID, plAxisID);
		return result;
	}
	long GetStageAxisInfo(long lChanID, float * pfMinPos, float * pfMaxPos, long * plUnits, float * pfPitch, long * plDirSense)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x29, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, pfMinPos, pfMaxPos, plUnits, pfPitch, plDirSense);
		return result;
	}
	long GetVelParamLimits(long lChanID, float * pfMaxAccn, float * pfMaxVel)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x2A, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, pfMaxAccn, pfMaxVel);
		return result;
	}
	long SetJogMode(long lChanID, long lMode, long lStopMode)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4;
		InvokeHelper(0x2B, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lMode, lStopMode);
		return result;
	}
	long GetJogMode(long lChanID, long * plMode, long * plStopMode)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x2C, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plMode, plStopMode);
		return result;
	}
	long SetJogStepSize(long lChanID, float fStepSize)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_R4;
		InvokeHelper(0x2D, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, fStepSize);
		return result;
	}
	long GetJogStepSize(long lChanID, float * pfStepSize)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x2E, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, pfStepSize);
		return result;
	}
	long SetJogVelParams(long lChanID, float fMinVel, float fAccn, float fMaxVel)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_R4 VTS_R4 VTS_R4;
		InvokeHelper(0x2F, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, fMinVel, fAccn, fMaxVel);
		return result;
	}
	long GetJogVelParams(long lChanID, float * pfMinVel, float * pfAccn, float * pfMaxVel)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x30, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, pfMinVel, pfAccn, pfMaxVel);
		return result;
	}
	long SetRelMoveDist(long lChanID, float fRelDist)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_R4;
		InvokeHelper(0x31, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, fRelDist);
		return result;
	}
	long GetRelMoveDist(long lChanID, float * pfRelDist)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x32, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, pfRelDist);
		return result;
	}
	long SetAbsMovePos(long lChanID, float fAbsPos)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_R4;
		InvokeHelper(0x33, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, fAbsPos);
		return result;
	}
	long GetAbsMovePos(long lChanID, float * pfAbsPos)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x34, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, pfAbsPos);
		return result;
	}
	long LLSetGetDigOPs(BOOL bSet, long * plBits)
	{
		long result;
		static BYTE parms[] = VTS_BOOL VTS_UNKNOWN;
		InvokeHelper(0x36, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bSet, plBits);
		return result;
	}
	long LLGetDigIPs(long * plBits)
	{
		long result;
		static BYTE parms[] = VTS_UNKNOWN;
		InvokeHelper(0x37, DISPATCH_METHOD, VT_I4, (void*)&result, parms, plBits);
		return result;
	}
	long LLGetADCInputs(long * plADCVal1, long * plADCVal2)
	{
		long result;
		static BYTE parms[] = VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x38, DISPATCH_METHOD, VT_I4, (void*)&result, parms, plADCVal1, plADCVal2);
		return result;
	}
	long LLGetPosition(long lChanID, long * plPosition)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x39, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plPosition);
		return result;
	}
	long SetBLashDist(long lChanID, float fBLashDist)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_R4;
		InvokeHelper(0x3A, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, fBLashDist);
		return result;
	}
	long GetBLashDist(long lChanID, float * pfBLashDist)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x3B, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, pfBLashDist);
		return result;
	}
	long Identify()
	{
		long result;
		InvokeHelper(0x3C, DISPATCH_METHOD, VT_I4, (void*)&result, nullptr);
		return result;
	}
	long SetSWPosLimits(long lChanID, float fRevPosLimit, float fFwdPosLimit, long lLimitMode)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_R4 VTS_R4 VTS_I4;
		InvokeHelper(0x3D, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, fRevPosLimit, fFwdPosLimit, lLimitMode);
		return result;
	}
	long GetSWPosLimits(long lChanID, float * pfRevPosLimit, float * pfFwdPosLimit, long * plLimitMode)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x3E, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, pfRevPosLimit, pfFwdPosLimit, plLimitMode);
		return result;
	}
	long SetStageAxisInfo(long lChanID, float fMinPos, float fMaxPos, long lUnits, float fPitch, long lDirSense)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_R4 VTS_R4 VTS_I4 VTS_R4 VTS_I4;
		InvokeHelper(0x3F, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, fMinPos, fMaxPos, lUnits, fPitch, lDirSense);
		return result;
	}
	long LLSaveHWDefaults()
	{
		long result;
		InvokeHelper(0x40, DISPATCH_METHOD, VT_I4, (void*)&result, nullptr);
		return result;
	}
	long SetHomeParams(long lChanID, long lDirection, long lLimSwitch, float fHomeVel, float fZeroOffset)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_R4 VTS_R4;
		InvokeHelper(0x41, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lDirection, lLimSwitch, fHomeVel, fZeroOffset);
		return result;
	}
	long GetHomeParams(long lChanID, long * plDirection, long * plLimSwitch, float * pfHomeVel, float * pfZeroOffset)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x42, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plDirection, plLimSwitch, pfHomeVel, pfZeroOffset);
		return result;
	}
	long SetHWLimSwitches(long lChanID, long lRevLimSwitch, long lFwdLimSwitch)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4;
		InvokeHelper(0x43, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lRevLimSwitch, lFwdLimSwitch);
		return result;
	}
	long GetHWLimSwitches(long lChanID, long * plRevLimSwitch, long * plFwdLimSwitch)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x44, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plRevLimSwitch, plFwdLimSwitch);
		return result;
	}
	long SetPhaseCurrents(long lChanID, long lRestVal, long lMoveVal)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4;
		InvokeHelper(0x47, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lRestVal, lMoveVal);
		return result;
	}
	long GetPhaseCurrents(long lChanID, long * plRestVal, long * plMoveVal)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x48, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plRestVal, plMoveVal);
		return result;
	}
	long GetPositionEx(long lChanID, float * pfCalibPosition, float * pfUncalibPosition)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x49, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, pfCalibPosition, pfUncalibPosition);
		return result;
	}
	long DoEvents()
	{
		long result;
		InvokeHelper(0x4A, DISPATCH_METHOD, VT_I4, (void*)&result, nullptr);
		return result;
	}
	long LLSetEncoderCount(long lChanID, long lEncCount)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4;
		InvokeHelper(0x4B, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lEncCount);
		return result;
	}
	long LLGetEncoderCount(long lChanID, long * plEncCount)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x4C, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plEncCount);
		return result;
	}
	long LLSetGetTrigBits(BOOL bSet, long lChanID, long * plBits)
	{
		long result;
		static BYTE parms[] = VTS_BOOL VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x4D, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bSet, lChanID, plBits);
		return result;
	}
	long MoveJog(long lChanID, long lJogDir)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4;
		InvokeHelper(0x4E, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lJogDir);
		return result;
	}
	long SetMotorParams(long lChanID, long lStepsPerRev, long lGearBoxRatio)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4;
		InvokeHelper(0x4F, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lStepsPerRev, lGearBoxRatio);
		return result;
	}
	long GetMotorParams(long lChanID, long * plStepsPerRev, long * plGearBoxRatio)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x50, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plStepsPerRev, plGearBoxRatio);
		return result;
	}
	long SetTriggerParams(long lChanID, long lTrigMode, long lTrigMove)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4;
		InvokeHelper(0x51, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lTrigMode, lTrigMove);
		return result;
	}
	long GetTriggerParams(long lChanID, long * plTrigMode, long * plTrigMove)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x52, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plTrigMode, plTrigMove);
		return result;
	}
	long SaveParamSet(LPCTSTR bstrName)
	{
		long result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x53, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bstrName);
		return result;
	}
	long LoadParamSet(LPCTSTR bstrName)
	{
		long result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x54, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bstrName);
		return result;
	}
	long DeleteParamSet(LPCTSTR btsrName)
	{
		long result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x55, DISPATCH_METHOD, VT_I4, (void*)&result, parms, btsrName);
		return result;
	}
	long LLSetDSPProgState(BOOL bProg)
	{
		long result;
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x56, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bProg);
		return result;
	}
	long LLSendDSPProgData(long lNumBytes, unsigned char * lpbyData)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x57, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lNumBytes, lpbyData);
		return result;
	}
	long MoveAbsoluteEnc(long lChanID, float fAbsPosCh1, float fAbsPosCh2, long lTimeInc, BOOL bWait)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_R4 VTS_R4 VTS_I4 VTS_BOOL;
		InvokeHelper(0x58, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, fAbsPosCh1, fAbsPosCh2, lTimeInc, bWait);
		return result;
	}
	long MoveRelativeEnc(long lChanID, float fRelDistCh1, float fRelDistCh2, long lTimeInc, BOOL bWait)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_R4 VTS_R4 VTS_I4 VTS_BOOL;
		InvokeHelper(0x59, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, fRelDistCh1, fRelDistCh2, lTimeInc, bWait);
		return result;
	}
	long CalibrateEnc(long lChanID, BOOL bWait)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BOOL;
		InvokeHelper(0x5A, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, bWait);
		return result;
	}
	long SetEncCalibTableParams(long lChanID, long lEncCalib, float fCalibStep, long lCalibDwell, long lQEPSense)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_R4 VTS_I4 VTS_I4;
		InvokeHelper(0x5B, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lEncCalib, fCalibStep, lCalibDwell, lQEPSense);
		return result;
	}
	long GetEncCalibTableParams(long lChanID, long * plEncCalib, float * pfCalibStep, long * plCalibDwell, long * plQEPSense)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x5C, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plEncCalib, pfCalibStep, plCalibDwell, plQEPSense);
		return result;
	}
	long SetEncPosCorrectParams(long lChanID, long lPosSetPtWnd, long lSnguStepWnd, long lStopShortDist, long lCorrMoveStep)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4;
		InvokeHelper(0x5D, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lPosSetPtWnd, lSnguStepWnd, lStopShortDist, lCorrMoveStep);
		return result;
	}
	long GetEncPosCorrectParams(long lChanID, long * plPosSetPtWnd, long * plSnguStepWnd, long * plStopShortDist, long * plCorrMoveStep)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x5E, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plPosSetPtWnd, plSnguStepWnd, plStopShortDist, plCorrMoveStep);
		return result;
	}
	long SetEncPosControlParams(long lChanID, long lPosSrcMode, long lPosCorrMode, BOOL bUseCalib)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_BOOL;
		InvokeHelper(0x5F, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lPosSrcMode, lPosCorrMode, bUseCalib);
		return result;
	}
	long GetEncPosControlParams(long lChanID, long * plPosSrcMode, long * plPosCorrMode, BOOL * pbUseCalib)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x60, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plPosSrcMode, plPosCorrMode, pbUseCalib);
		return result;
	}
	long LLSetGetHostDigOPs(BOOL bSet, long * plBits)
	{
		long result;
		static BYTE parms[] = VTS_BOOL VTS_UNKNOWN;
		InvokeHelper(0x62, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bSet, plBits);
		return result;
	}
	long LLGetHostStatusBits(long * plStatusBits)
	{
		long result;
		static BYTE parms[] = VTS_UNKNOWN;
		InvokeHelper(0x63, DISPATCH_METHOD, VT_I4, (void*)&result, parms, plStatusBits);
		return result;
	}
	long LLSetGetPIDParams(BOOL bSet, long lChanID, long * plProp, long * plInt, long * plDeriv, long * plIntLimit, long * plFilterCtrl)
	{
		long result;
		static BYTE parms[] = VTS_BOOL VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x64, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bSet, lChanID, plProp, plInt, plDeriv, plIntLimit, plFilterCtrl);
		return result;
	}
	long LLGetAdvancedDCParams(long lChanID, long * plTargetPos, long * plTargetVel, long * plIntSum)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plTargetPos, plTargetVel, plIntSum);
		return result;
	}
	long LLSetGetPotParams(BOOL bSet, long lChanID, long * plZeroWnd, long * plVel1, long * plWnd1, long * plVel2, long * plWnd2, long * plVel3, long * plWnd3, long * plVel4)
	{
		long result;
		static BYTE parms[] = VTS_BOOL VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bSet, lChanID, plZeroWnd, plVel1, plWnd1, plVel2, plWnd2, plVel3, plWnd3, plVel4);
		return result;
	}
	long SetIndicatorLEDMode(long lChanID, long lLEDMode)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4;
		InvokeHelper(0x67, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lLEDMode);
		return result;
	}
	long GetIndicatorLEDMode(long lChanID, long * plLEDMode)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x68, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plLEDMode);
		return result;
	}
	long LLSetGetAVMode(BOOL bSet, long lChanID, long * plModeBits)
	{
		long result;
		static BYTE parms[] = VTS_BOOL VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x69, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bSet, lChanID, plModeBits);
		return result;
	}
	long LLSetGetButtonParams(BOOL bSet, long lChanID, long * plMode, long * plPos1, long * plPos2, long * plTimeout1, long * plTimeout2)
	{
		long result;
		static BYTE parms[] = VTS_BOOL VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x6A, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bSet, lChanID, plMode, plPos1, plPos2, plTimeout1, plTimeout2);
		return result;
	}
	long LLGetOptoDCVelParams(long lChanID, long * plMinVel, long * plAccn, long * plMaxVel)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x6B, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plMinVel, plAccn, plMaxVel);
		return result;
	}
	long LLGetOptoDCJogParams(long lChanID, long * plJogMode, long * plJogStepSize, long * plMinVel, long * plAccn, long * plMaxVel)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x6C, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plJogMode, plJogStepSize, plMinVel, plAccn, plMaxVel);
		return result;
	}
	long LLGetOptoDCHomeParams(long lChanID, long * plDirection, long * plLimSwitch, long * plHomeVel, long * plOffsetDist)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x6D, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plDirection, plLimSwitch, plHomeVel, plOffsetDist);
		return result;
	}
	long GetParentHWInfo(long * plHWSerialNum, long * plHWType)
	{
		long result;
		static BYTE parms[] = VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x6E, DISPATCH_METHOD, VT_I4, (void*)&result, parms, plHWSerialNum, plHWType);
		return result;
	}
	long SetButtonParams(long lChanID, long lButMode, float fLeftButPos, float fRightButPos)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_R4 VTS_R4;
		InvokeHelper(0x6F, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lButMode, fLeftButPos, fRightButPos);
		return result;
	}
	long GetButtonParams(long lChanID, long * plButMode, float * pfLeftButPos, float * pfRightButPos)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x70, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plButMode, pfLeftButPos, pfRightButPos);
		return result;
	}
	long SetPotParams(long lChanID, long lVel1PotVal, float fVel1, long lVel2PotVal, float fVel2, long lVel3PotVal, float fVel3, long lVel4PotVal, float fVel4)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_R4 VTS_I4 VTS_R4 VTS_I4 VTS_R4 VTS_I4 VTS_R4;
		InvokeHelper(0x71, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lVel1PotVal, fVel1, lVel2PotVal, fVel2, lVel3PotVal, fVel3, lVel4PotVal, fVel4);
		return result;
	}
	long GetPotParams(long lChanID, long * plVel1PotVal, float * pfVel1, long * plVel2PotVal, float * pfVel2, long * plVel3PotVal, float * pfVel3, long * plVel4PotVal, float * pfVel4)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x72, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plVel1PotVal, pfVel1, plVel2PotVal, pfVel2, plVel3PotVal, pfVel3, plVel4PotVal, pfVel4);
		return result;
	}
	long LLSetEEPROMParams(long lChanID, long lMsgID)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4;
		InvokeHelper(0x73, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lMsgID);
		return result;
	}
	long ShowSettingsDlg()
	{
		long result;
		InvokeHelper(0x77, DISPATCH_METHOD, VT_I4, (void*)&result, nullptr);
		return result;
	}
	long GetCtrlStarted(BOOL * pbStarted)
	{
		long result;
		static BYTE parms[] = VTS_UNKNOWN;
		InvokeHelper(0x78, DISPATCH_METHOD, VT_I4, (void*)&result, parms, pbStarted);
		return result;
	}
	long GetHWCommsOK(BOOL * pbCommsOK)
	{
		long result;
		static BYTE parms[] = VTS_UNKNOWN;
		InvokeHelper(0x79, DISPATCH_METHOD, VT_I4, (void*)&result, parms, pbCommsOK);
		return result;
	}
	long SetPositionOffset(long lChanID, float fPosOffset)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_R4;
		InvokeHelper(0x7E, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, fPosOffset);
		return result;
	}
	long LLSetGUIEnable(BOOL bEnable)
	{
		long result;
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x7F, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bEnable);
		return result;
	}
	long LLSetContextMenuEnable(BOOL bEnabled)
	{
		long result;
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x80, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bEnabled);
		return result;
	}
	long LLSetPosDispClickEventEnable(BOOL bEnabled)
	{
		long result;
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x81, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bEnabled);
		return result;
	}
	long LLSetPosDispDblClickEventEnable(BOOL bEnabled)
	{
		long result;
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x82, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bEnabled);
		return result;
	}
	long GetPositionOffset(long lChanID, float * pfPosOffset)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x83, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, pfPosOffset);
		return result;
	}
	long SetDispMode(long lDispMode)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x84, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lDispMode);
		return result;
	}
	long GetDispMode(long * plDispMode)
	{
		long result;
		static BYTE parms[] = VTS_UNKNOWN;
		InvokeHelper(0x85, DISPATCH_METHOD, VT_I4, (void*)&result, parms, plDispMode);
		return result;
	}
	long SetChannelSwitch(long lChanID)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x86, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID);
		return result;
	}
	long GetChannelSwitch(long * plChanID)
	{
		long result;
		static BYTE parms[] = VTS_UNKNOWN;
		InvokeHelper(0x87, DISPATCH_METHOD, VT_I4, (void*)&result, parms, plChanID);
		return result;
	}
	long MoveAbsoluteRot(long lChanID, float fAnglePosCh1, float fAnglePosCh2, long lMoveMode, BOOL bWait)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_R4 VTS_R4 VTS_I4 VTS_BOOL;
		InvokeHelper(0x88, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, fAnglePosCh1, fAnglePosCh2, lMoveMode, bWait);
		return result;
	}
	float GetVelParams_Accn(long lChanID)
	{
		float result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x89, DISPATCH_METHOD, VT_R4, (void*)&result, parms, lChanID);
		return result;
	}
	float GetVelParams_MaxVel(long lChanID)
	{
		float result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x8A, DISPATCH_METHOD, VT_R4, (void*)&result, parms, lChanID);
		return result;
	}
	float GetStageAxisInfo_MinPos(long lChanID)
	{
		float result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x8B, DISPATCH_METHOD, VT_R4, (void*)&result, parms, lChanID);
		return result;
	}
	float GetStageAxisInfo_MaxPos(long lChanID)
	{
		float result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x8C, DISPATCH_METHOD, VT_R4, (void*)&result, parms, lChanID);
		return result;
	}
	float GetRelMoveDist_RelDist(long lChanID)
	{
		float result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x8D, DISPATCH_METHOD, VT_R4, (void*)&result, parms, lChanID);
		return result;
	}
	float GetAbsMovePos_AbsPos(long lChanID)
	{
		float result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x8E, DISPATCH_METHOD, VT_R4, (void*)&result, parms, lChanID);
		return result;
	}
	float GetBLashDist_BLashDist(long lChanID)
	{
		float result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x8F, DISPATCH_METHOD, VT_R4, (void*)&result, parms, lChanID);
		return result;
	}
	float GetPosition_Position(long lChanID)
	{
		float result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x90, DISPATCH_METHOD, VT_R4, (void*)&result, parms, lChanID);
		return result;
	}
	float GetPositionEx_UncalibPosition(long lChanID)
	{
		float result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x91, DISPATCH_METHOD, VT_R4, (void*)&result, parms, lChanID);
		return result;
	}
	long GetJogMode_Mode(long lChanID)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x92, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID);
		return result;
	}
	long GetJogMode_StopMode(long lChanID)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x93, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID);
		return result;
	}
	float GetJogStepSize_StepSize(long lChanID)
	{
		float result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x94, DISPATCH_METHOD, VT_R4, (void*)&result, parms, lChanID);
		return result;
	}
	long GetStatusBits_Bits(long lChanID)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x95, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID);
		return result;
	}
	float GetJogVelParams_Accn(long lChanID)
	{
		float result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x96, DISPATCH_METHOD, VT_R4, (void*)&result, parms, lChanID);
		return result;
	}
	float GetJogVelParams_MaxVel(long lChanID)
	{
		float result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x97, DISPATCH_METHOD, VT_R4, (void*)&result, parms, lChanID);
		return result;
	}
	float GetHomeParams_HomeVel(long lChanID)
	{
		float result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x98, DISPATCH_METHOD, VT_R4, (void*)&result, parms, lChanID);
		return result;
	}
	float GetHomeParams_ZeroOffset(long lChanID)
	{
		float result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x99, DISPATCH_METHOD, VT_R4, (void*)&result, parms, lChanID);
		return result;
	}
	long GetPIDParams_Prop(long lChanID)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x9A, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID);
		return result;
	}
	long GetPIDParams_Int(long lChanID)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x9B, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID);
		return result;
	}
	long GetPIDParams_Deriv(long lChanID)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x9C, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID);
		return result;
	}
	long SC_SetOperatingMode(long lChanID, long lMode)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4;
		InvokeHelper(0x9D, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lMode);
		return result;
	}
	long SC_GetOperatingMode(long lChanID, long * plMode)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x9E, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plMode);
		return result;
	}
	long SC_SetCycleParams(long lChanID, float fOnTime, float fOffTime, long lNumCycles)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_R4 VTS_R4 VTS_I4;
		InvokeHelper(0x9F, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, fOnTime, fOffTime, lNumCycles);
		return result;
	}
	long SC_GetCycleParams(long lChanID, float * pfOnTime, float * pfOffTime, long * plNumCycles)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0xA0, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, pfOnTime, pfOffTime, plNumCycles);
		return result;
	}
	long SC_Enable(long lChanID)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0xA3, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID);
		return result;
	}
	long SC_Disable(long lChanID)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0xA4, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID);
		return result;
	}
	long SC_GetOPState(long lChanID, long * plState)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0xA5, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plState);
		return result;
	}
	long SetBrakeState(long lChanID, long lState)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4;
		InvokeHelper(0xA6, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lState);
		return result;
	}
	long GetBrakeState(long lChanID, long * plState)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0xA7, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plState);
		return result;
	}
	long LLSuspendEndOfMoveMsgs()
	{
		long result;
		InvokeHelper(0xA8, DISPATCH_METHOD, VT_I4, (void*)&result, nullptr);
		return result;
	}
	long LLResumeEndOfMoveMsgs()
	{
		long result;
		InvokeHelper(0xA9, DISPATCH_METHOD, VT_I4, (void*)&result, nullptr);
		return result;
	}
	long EnableEventDlg(BOOL bEnable)
	{
		long result;
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0xAA, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bEnable);
		return result;
	}
	long ShowEventDlg()
	{
		long result;
		InvokeHelper(0xAB, DISPATCH_METHOD, VT_I4, (void*)&result, nullptr);
		return result;
	}
	long SetRotStageModes(long lChanID, long lMoveMode, long lPosReportMode)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4;
		InvokeHelper(0xAC, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lMoveMode, lPosReportMode);
		return result;
	}
	long GetRotStageModes(long lChanID, long * plMoveMode, long * plPosReportMode)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0xAD, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plMoveMode, plPosReportMode);
		return result;
	}
	long LLSetPMDParam(long lCommandCode, long lParamCode, long lVal)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4;
		InvokeHelper(0xAE, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lCommandCode, lParamCode, lVal);
		return result;
	}
	long LLGetPMDParam(long lCommandCode, long lParamCode, long * plVal)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0xAF, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lCommandCode, lParamCode, plVal);
		return result;
	}
	long SetDCCurrentLoopParams(long lChanID, long lProp, long lInt, long lIntLim, long lIntDeadBand, long lFFwd)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4;
		InvokeHelper(0xB0, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lProp, lInt, lIntLim, lIntDeadBand, lFFwd);
		return result;
	}
	long GetDCCurrentLoopParams(long lChanID, long * plProp, long * plInt, long * plIntLim, long * plIntDeadBand, long * plFFwd)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0xB1, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plProp, plInt, plIntLim, plIntDeadBand, plFFwd);
		return result;
	}
	long SetDCPositionLoopParams(long lChanID, long lProp, long lInt, long lIntLim, long lDeriv, long lDerivTime, long lLoopGain, long lVelFFwd, long lAccFFwd, long lPosErrLim)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4;
		InvokeHelper(0xB2, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lProp, lInt, lIntLim, lDeriv, lDerivTime, lLoopGain, lVelFFwd, lAccFFwd, lPosErrLim);
		return result;
	}
	long GetDCPositionLoopParams(long lChanID, long * plProp, long * plInt, long * plIntLim, long * plDeriv, long * plDerivTime, long * plLoopGain, long * plVelFFwd, long * plAccFFwd, long * plPosErrLim)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0xB3, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plProp, plInt, plIntLim, plDeriv, plDerivTime, plLoopGain, plVelFFwd, plAccFFwd, plPosErrLim);
		return result;
	}
	long SetDCMotorOutputParams(long lChanID, float fContCurrLim, float fEnergyLim, float fMotorLim, float fMotorBias)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_R4 VTS_R4 VTS_R4 VTS_R4;
		InvokeHelper(0xB4, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, fContCurrLim, fEnergyLim, fMotorLim, fMotorBias);
		return result;
	}
	long GetDCMotorOutputParams(long lChanID, float * pfContCurrLim, float * pfEnergyLim, float * pfMotorLim, float * pfMotorBias)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0xB5, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, pfContCurrLim, pfEnergyLim, pfMotorLim, pfMotorBias);
		return result;
	}
	long SetDCTrackSettleParams(long lChanID, long lSettleTime, long lSettleWnd, long lTrackWnd)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4;
		InvokeHelper(0xB6, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lSettleTime, lSettleWnd, lTrackWnd);
		return result;
	}
	long GetDCTrackSettleParams(long lChanID, long * plSettleTime, long * plSettleWnd, long * plTrackWnd)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0xB7, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plSettleTime, plSettleWnd, plTrackWnd);
		return result;
	}
	long SetDCProfileModeParams(long lChanID, long lProfMode, float fJerk)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_R4;
		InvokeHelper(0xB8, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lProfMode, fJerk);
		return result;
	}
	long GetDCProfileModeParams(long lChanID, long * plProfMode, float * pfJerk)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0xB9, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plProfMode, pfJerk);
		return result;
	}
	long SetDCJoystickParams(long lChanID, float fMaxVelLO, float fMaxVelHI, float fAccnLO, float fAccnHI, long lDirSense)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_I4;
		InvokeHelper(0xBA, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, fMaxVelLO, fMaxVelHI, fAccnLO, fAccnHI, lDirSense);
		return result;
	}
	long GetDCJoystickParams(long lChanID, float * pfMaxVelLO, float * pfMaxVelHI, float * pfAccnLO, float * pfAccnHI, long * plDirSense)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0xBB, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, pfMaxVelLO, pfMaxVelHI, pfAccnLO, pfAccnHI, plDirSense);
		return result;
	}
	long SetDCSettledCurrentLoopParams(long lChanID, long lSettledProp, long lSettledInt, long lSettledIntLim, long lSettledIntDeadBand, long lSettledFFwd)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4;
		InvokeHelper(0xBC, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lSettledProp, lSettledInt, lSettledIntLim, lSettledIntDeadBand, lSettledFFwd);
		return result;
	}
	long GetDCSettledCurrentLoopParams(long lChanID, long * plSettledProp, long * plSettledInt, long * plSettledIntLim, long * plSettledIntDeadBand, long * plSettledFFwd)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0xBD, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plSettledProp, plSettledInt, plSettledIntLim, plSettledIntDeadBand, plSettledFFwd);
		return result;
	}
	long SetBowIndex(long lChanID, long lBowIndex)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4;
		InvokeHelper(0xBE, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lBowIndex);
		return result;
	}
	long GetBowIndex(long lChanID, long * plBowIndex)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0xBF, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plBowIndex);
		return result;
	}
	long SetDCTriggerParams(long lChanID, long lTrigInMode, long lTrigOutMode)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4;
		InvokeHelper(0xC0, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lTrigInMode, lTrigOutMode);
		return result;
	}
	long GetDCTriggerParams(long lChanID, long * plTrigInMode, long * plTrigOutMode)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0xC1, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plTrigInMode, plTrigOutMode);
		return result;
	}
	long SetMFFOperParams(long lChanID, long lTransitTime, long lDigIO1OperMode, long lDigIO1SigMode, long lDigIO1PulseWidth, long lDigIO2OperMode, long lDigIO2SigMode, long lDigIO2PulseWidth)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4;
		InvokeHelper(0xC2, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lTransitTime, lDigIO1OperMode, lDigIO1SigMode, lDigIO1PulseWidth, lDigIO2OperMode, lDigIO2SigMode, lDigIO2PulseWidth);
		return result;
	}
	long GetMFFOperParams(long lChanID, long * plTransitTime, long * plDigIO1OperMode, long * plDigIO1SigMode, long * plDigIO1PulseWidth, long * plDigIO2OperMode, long * plDigIO2SigMode, long * plDigIO2PulseWidth)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0xC3, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plTransitTime, plDigIO1OperMode, plDigIO1SigMode, plDigIO1PulseWidth, plDigIO2OperMode, plDigIO2SigMode, plDigIO2PulseWidth);
		return result;
	}
	long LLSetPosition(long lChanID, long lPosition)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4;
		InvokeHelper(0xC4, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lPosition);
		return result;
	}
	long SetKCubePanelParams(long lChanID, long lWheelMode, float fWheelVel, float fWheelAccn, long lWheelDirSense, float fPresetPos1, float fPresetPos2, long lDispBrightness)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_R4 VTS_R4 VTS_I4 VTS_R4 VTS_R4 VTS_I4;
		InvokeHelper(0xC5, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lWheelMode, fWheelVel, fWheelAccn, lWheelDirSense, fPresetPos1, fPresetPos2, lDispBrightness);
		return result;
	}
	long GetKCubePanelParams(long lChanID, long * plWheelMode, float * pfWheelVel, float * pfWheelAccn, long * plWheelDirSense, float * pfPresetPos1, float * pfPresetPos2, long * plDispBrightness)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0xC6, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plWheelMode, pfWheelVel, pfWheelAccn, plWheelDirSense, pfPresetPos1, pfPresetPos2, plDispBrightness);
		return result;
	}
	long SetKCubeTriggerParams(long lChanID, long lTrig1Mode, long lTrig1Polarity, long lTrig2Mode, long lTrig2Polarity)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4;
		InvokeHelper(0xC7, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lTrig1Mode, lTrig1Polarity, lTrig2Mode, lTrig2Polarity);
		return result;
	}
	long GetKCubeTriggerParams(long lChanID, long * plTrig1Mode, long * plTrig1Polarity, long * plTrig2Mode, long * plTrig2Polarity)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0xC8, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plTrig1Mode, plTrig1Polarity, plTrig2Mode, plTrig2Polarity);
		return result;
	}
	long SetKCubePosTriggerParams(long lChanID, float fStartPosFwd, float fPosIntervalFwd, long lNumPulsesFwd, float fStartPosRev, float fPosIntervalRev, long lNumPulsesRev, float fPulseWidth, long lNumCycles)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_R4 VTS_R4 VTS_I4 VTS_R4 VTS_R4 VTS_I4 VTS_R4 VTS_I4;
		InvokeHelper(0xC9, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, fStartPosFwd, fPosIntervalFwd, lNumPulsesFwd, fStartPosRev, fPosIntervalRev, lNumPulsesRev, fPulseWidth, lNumCycles);
		return result;
	}
	long GetKCubePosTriggerParams(long lChanID, float * pfStartPosFwd, float * pfPosIntervalFwd, long * plNumPulsesFwd, float * pfStartPosRev, float * pfPosIntervalRev, long * plNumPulsesRev, float * pfPulseWidth, long * plNumCycles)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0xCA, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, pfStartPosFwd, pfPosIntervalFwd, plNumPulsesFwd, pfStartPosRev, pfPosIntervalRev, plNumPulsesRev, pfPulseWidth, plNumCycles);
		return result;
	}
	long SetKCubeKSTLoopParams(long lChan, long lLoopMode, long lProp, long lInt, long LDiff, long lPIDClip, long lPIDTol, long lEncCount)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4;
		InvokeHelper(0xCB, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChan, lLoopMode, lProp, lInt, LDiff, lPIDClip, lPIDTol, lEncCount);
		return result;
	}
	long GetKCubeKSTLoopParams(long lChanID, long * plLoopMode, long * plProp, long * plInt, long * plDiff, long * plPIDClip, long * lPIDTol, long * plEncCount)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0xCC, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plLoopMode, plProp, plInt, plDiff, plPIDClip, lPIDTol, plEncCount);
		return result;
	}
// _DMG17MotorEvents

// Funktionen
//

	void MoveComplete(long lChanID)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, lChanID);
	}
	void HomeComplete(long lChanID)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, lChanID);
	}
	void MoveStopped(long lChanID)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, lChanID);
	}
	void HWResponse(long lHWCode, long lMsgIdent)
	{
		static BYTE parms[] = VTS_I4 VTS_I4;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, lHWCode, lMsgIdent);
	}
	void SettingsChanged(long lFlags)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, lFlags);
	}
	void EncCalibComplete(long lChanID)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x9, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, lChanID);
	}
	void PositionClick(float fCurrentPosition)
	{
		static BYTE parms[] = VTS_R4;
		InvokeHelper(0xA, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, fCurrentPosition);
	}
	void PositionDblClick(float fCurrentPosition)
	{
		static BYTE parms[] = VTS_R4;
		InvokeHelper(0xB, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, fCurrentPosition);
	}
	void HWPoweredDown(long lChanID)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0xC, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, lChanID);
	}


};
