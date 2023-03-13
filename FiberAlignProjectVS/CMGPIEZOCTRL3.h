#pragma once

// Mit Microsoft Visual C++ generierte IDispatch-Wrapperklasse(n)

// HINWEIS: Die Inhalte dieser Datei dürfen nicht geändert werden.
//  Die Änderungen werden überschrieben, wenn diese Klasse von Microsoft Visual C++ erneut generiert wird.

/////////////////////////////////////////////////////////////////////////////

#include "afxwin.h"

class CMGPIEZOCTRL3 : public CWnd
{
protected:
	DECLARE_DYNCREATE(CMGPIEZOCTRL3)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= {0xa9bc6065,0xd4f4,0x4a77,{0xb4,0x2b,0x21,0x5a,0x9d,0x6d,0xf4,0xc6}};
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
	POSCONTROLMODE = 3,
	OUTPUTVOLTS = 4,
	OUTPUTPOS = 5,
	MAXTRAVEL = 6,
	IPVOLTSOURCE = 7,
	PICONSTS = 8,
	ZEROOFFSETS = 9,
	HOSTDIGOUTPUTS = 10
}LLPZREQIDS;

enum
{
	CHAN1_ID = 0,
	CHAN2_ID = 1,
	CHANBOTH_ID = 10
}HWCHANNEL;

enum
{
	DISP_VOLTS = 1,
	DISP_POS = 2
}OPDISPMODE;

enum
{
	OPEN_LOOP = 1,
	CLOSED_LOOP = 2,
	OPEN_LOOP_SMOOTH = 3,
	CLOSED_LOOP_SMOOTH = 4
}OPCONTROLMODE;

enum
{
	INPUT_SWONLY = 1,
	INPUT_POSEXTBNC = 2,
	INPUT_NEGEXTBNC = 3,
	INPUT_EXTBNC = 4,
	INPUT_POT = 5,
	INPUT_POTEXTBNC = 6
}INPUTSOURCE;

enum
{
	INPUT_TPZ_SWONLY = 1,
	INPUT_TPZ_EXTIN = 2,
	INPUT_TPZ_POT = 3,
	INPUT_TPZ_POTEXTIN = 4
}INPUTSOURCE_TPZ;

enum
{
	HWMODE_PIEZO = 1,
	HWMODE_NANOTRAK = 2
}HWMODE;

enum
{
	CURRENTLIMIT_100MA = 0,
	CURRENTLIMIT_250MA = 1,
	CURRENTLIMIT_500MA = 2
}OUTPUTCURRENTLIMIT;

enum
{
	OUTPUTLPFILTER_10HZ = 0,
	OUTPUTLPFILTER_100HZ = 1,
	OUTPUTLPFILTER_5KHZ = 2,
	OUTPUTLPFILTER_NONE = 3
}OUTPUTLPFILTER;

enum
{
	FEEDBACK_TYPE_DC = 1,
	FEEDBACK_TYPE_AC = 2
}AMPFEEDBACKTYPE;

enum
{
	OUTPUTLUT_CONTINUOUS = 1,
	OUTPUTLUT_FIXED = 2
}OUTPUTLUTMODE;

enum
{
	TRIGSENSE_HI = 1,
	TRIGSENSE_LO = 2
}TRIGGERSENSE;

enum
{
	USB_BPC003 = 41,
	ETHNET_MMR601 = 42,
	USB_MMR601 = 43,
	USB_PPC102 = 46
}APT_PARENT_HWTYPES;

enum
{
	BNCMODE_LVOUT = 1,
	BNCMODE_TRIG = 2
}LVOUTTRIGBNCMODE;

enum
{
	VOLTAGELIMIT_75V = 1,
	VOLTAGELIMIT_100V = 2,
	VOLTAGELIMIT_150V = 3
}OUTPUTVOLTAGELIMIT;

enum
{
	HUB_ANALOGUEIN_1 = 1,
	HUB_ANALOGUEIN_2 = 2,
	SMA_ANALOGUEIN = 3
}HUBANALOGUEINPUT;

enum
{
	HUB_ANALOGUEOUT_1 = 1,
	HUB_ANALOGUEOUT_2 = 2
}HUBANALOGUEOUTPUT;

enum
{
	DISPUNITS_POSITION = 1,
	DISPUNITS_VOLTAGE = 2,
	DISPUNITS_FORCE = 3
}DISPUNITSMODE;

enum
{
	LUTVALTYPE_VOLTS = 1,
	LUTVALTYPE_POS = 2
}LUTVALUETYPE;

enum
{
	KPZ_WHEELMODE_VOLTAGE = 1,
	KPZ_WHEELMODE_JOG = 2,
	KPZ_WHEELMODE_GOTOVOLTAGE = 3
}KPZWHEELMODE;

enum
{
	KPZ_VOLTGEARBOX_HIGH = 1,
	KPZ_VOLTGEARBOX_MED = 2,
	KPZ_VOLTGEARBOX_LOW = 3
}KPZGEARBOX;

enum
{
	KPZ_WHEELDIRSENSE_POS = 1,
	KPZ_WHEELDIRSENSE_NEG = 2
}KPZWHEELDIRSENSE;

enum
{
	KPZ_TRIG_DISABLED = 0,
	KPZ_TRIGIN_GPI = 1,
	KPZ_TRIGIN_VOLTSTEP_UP = 2,
	KPZ_TRIGIN_VOLTSTEP_DOWN = 3,
	KPZ_TRIGOUT_GPO = 10
}KPZTRIGMODE;

enum
{
	KPZ_TRIGPOL_HIGH = 1,
	KPZ_TRIGPOL_LOW = 2
}KPZTRIGPOLARITY;

enum
{
	KSG_TRIG_DISABLED = 0,
	KSG_TRIGIN_GPI = 1,
	KSG_TRIGOUT_GPO = 10,
	KSG_TRIGOUT_LESSTHANLOWERLIMIT = 11,
	KSG_TRIGOUT_MORETHANLOWERLIMIT = 12,
	KSG_TRIGOUT_LESSTHANUPPERLIMIT = 13,
	KSG_TRIGOUT_MORETHANUPPERLIMIT = 14,
	KSG_TRIGOUT_BETWEENLIMITS = 15,
	KSG_TRIGOUT_OUTSIDELIMITS = 16
}KSGTRIGMODE;

enum
{
	KSG_TRIGPOL_HIGH = 1,
	KSG_TRIGPOL_LOW = 2
}KSGTRIGPOLARITY;



// Vorgänge
public:
// _DMG17Piezo

// Funktionen
//

	void AboutBox()
	{
		InvokeHelper(0xFFFFFDD8, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	long StartCtrl()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_I4, (void*)&result, nullptr);
		return result;
	}
	long StopCtrl()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_I4, (void*)&result, nullptr);
		return result;
	}
	long EnableHWChannel(long lChanID)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID);
		return result;
	}
	long DisableHWChannel(long lChanID)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID);
		return result;
	}
	long LLSetGetVoltOutput(BOOL bSet, long lChanID, long * plVoltage)
	{
		long result;
		static BYTE parms[] = VTS_BOOL VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bSet, lChanID, plVoltage);
		return result;
	}
	long LLSetGetPosOutput(BOOL bSet, long lChanID, long * plPos)
	{
		long result;
		static BYTE parms[] = VTS_BOOL VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x9, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bSet, lChanID, plPos);
		return result;
	}
	long LLReqHWParams(long lChanID, long lParamID)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4;
		InvokeHelper(0xC, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lParamID);
		return result;
	}
	long ZeroPosition(long lChanID)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0xD, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID);
		return result;
	}
	long LLSetGetDevParams(BOOL bSet, long * plDevParams)
	{
		long result;
		static BYTE parms[] = VTS_BOOL VTS_UNKNOWN;
		InvokeHelper(0xE, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bSet, plDevParams);
		return result;
	}
	long GetMaxTravel(long lChanID, float * pfMaxTravel)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0xF, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, pfMaxTravel);
		return result;
	}
	long LLGetZeroOffset(long lChanID, long * plZeroOffset)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x10, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plZeroOffset);
		return result;
	}
	long SetVoltPosDispMode(long lChanID, long lMode)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lMode);
		return result;
	}
	long GetVoltPosDispMode(long lChanID, long * plMode)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plMode);
		return result;
	}
	long SetControlMode(long lChanID, long lMode)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lMode);
		return result;
	}
	long GetControlMode(long lChanID, long * plMode)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x14, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plMode);
		return result;
	}
	long LLGetStatusBits(long lChanID, long * plStatusBits)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x15, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plStatusBits);
		return result;
	}
	long Identify()
	{
		long result;
		InvokeHelper(0x16, DISPATCH_METHOD, VT_I4, (void*)&result, nullptr);
		return result;
	}
	long LLGetDigIPs(long * plBits)
	{
		long result;
		static BYTE parms[] = VTS_UNKNOWN;
		InvokeHelper(0x17, DISPATCH_METHOD, VT_I4, (void*)&result, parms, plBits);
		return result;
	}
	long LLSetGetDigOPs(BOOL bSet, long * plBits)
	{
		long result;
		static BYTE parms[] = VTS_BOOL VTS_UNKNOWN;
		InvokeHelper(0x18, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bSet, plBits);
		return result;
	}
	long SetVoltOutput(long lChanID, float fVoltage)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_R4;
		InvokeHelper(0x19, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, fVoltage);
		return result;
	}
	long GetVoltOutput(long lChanID, float * pfVoltage)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x1A, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, pfVoltage);
		return result;
	}
	long SetPosOutput(long lChanID, float fPosition)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_R4;
		InvokeHelper(0x1B, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, fPosition);
		return result;
	}
	long GetPosOutput(long lChanID, float * pfPosition)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x1C, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, pfPosition);
		return result;
	}
	long SetPIConsts(long lChanID, long lProp, long lInt)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4;
		InvokeHelper(0x1D, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lProp, lInt);
		return result;
	}
	long GetPIConsts(long lChanID, long * plProp, long * plInt)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x1E, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plProp, plInt);
		return result;
	}
	long SetIPSource(long lChanID, long lSource)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4;
		InvokeHelper(0x1F, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lSource);
		return result;
	}
	long GetIPSource(long lChanID, long * plSource)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x20, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plSource);
		return result;
	}
	long SetJogStepSize(long lChanID, float fStepSize)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_R4;
		InvokeHelper(0x21, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, fStepSize);
		return result;
	}
	long GetJogStepSize(long lChanID, float * pfStepSize)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x22, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, pfStepSize);
		return result;
	}
	long LLSaveHWDefaults()
	{
		long result;
		InvokeHelper(0x23, DISPATCH_METHOD, VT_I4, (void*)&result, nullptr);
		return result;
	}
	long SetHWMode(long lMode)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x24, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMode);
		return result;
	}
	long DoEvents()
	{
		long result;
		InvokeHelper(0x26, DISPATCH_METHOD, VT_I4, (void*)&result, nullptr);
		return result;
	}
	long SetAmpOutputParams(long lChanID, long lCurrentLim, long lLPFilter)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4;
		InvokeHelper(0x27, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lCurrentLim, lLPFilter);
		return result;
	}
	long GetAmpOutputParams(long lChanID, long * plCurrentLim, long * plLPFilter)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x28, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plCurrentLim, plLPFilter);
		return result;
	}
	long SetAmpFeedbackSig(long lChanID, long lType)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4;
		InvokeHelper(0x29, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lType);
		return result;
	}
	long GetAmpFeedbackSig(long lChanID, long * plType)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x2A, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plType);
		return result;
	}
	long LLSetModuleLEDStates(long lStates)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x2B, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lStates);
		return result;
	}
	long SaveParamSet(LPCTSTR bstrName)
	{
		long result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x2C, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bstrName);
		return result;
	}
	long LoadParamSet(LPCTSTR bstrName)
	{
		long result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x2D, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bstrName);
		return result;
	}
	long DeleteParamSet(LPCTSTR bstrName)
	{
		long result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x2E, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bstrName);
		return result;
	}
	long SetOutputLUTValue(long lChanID, long lIndex, float fValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_R4;
		InvokeHelper(0x2F, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lIndex, fValue);
		return result;
	}
	long GetOutputLUTValue(long lChanID, long lIndex, float * pfValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x30, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lIndex, pfValue);
		return result;
	}
	long StartOutputLUT(long lChanID)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x33, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID);
		return result;
	}
	long StopOutputLUT(long lChanID)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x34, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID);
		return result;
	}
	long SetOutputLUTParams(long lChanID, long lMode, long lCycleLength, long lNumCycles, float fLUTValDelay, float fPreCycleDelay, float fPostCycleDelay)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_R4 VTS_R4 VTS_R4;
		InvokeHelper(0x35, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lMode, lCycleLength, lNumCycles, fLUTValDelay, fPreCycleDelay, fPostCycleDelay);
		return result;
	}
	long GetOutputLUTParams(long lChanID, long * plMode, long * plCycleLength, long * plNumCycles, float * pfLUTValDelay, float * pfPreCycleDelay, float * pfPostCycleDelay)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x36, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plMode, plCycleLength, plNumCycles, pfLUTValDelay, pfPreCycleDelay, pfPostCycleDelay);
		return result;
	}
	long SetOutputLUTTrigParams(long lChanID, BOOL bOPTrigEnable, BOOL bIPTrigEnable, long lOPTrigStart, float fOPTrigWidth, long lOPTrigSense, long lIPTrigSense, BOOL bOPTrigRepeat, long lOPTrigRepeat)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BOOL VTS_BOOL VTS_I4 VTS_R4 VTS_I4 VTS_I4 VTS_BOOL VTS_I4;
		InvokeHelper(0x37, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, bOPTrigEnable, bIPTrigEnable, lOPTrigStart, fOPTrigWidth, lOPTrigSense, lIPTrigSense, bOPTrigRepeat, lOPTrigRepeat);
		return result;
	}
	long GetOutputLUTTrigParams(long lChanID, BOOL * pbOPTrigEnable, BOOL * pbIPTrigEnable, long * plOPTrigStart, float * pfOPTrigWidth, long * plOPTrigSense, long * plIPTrigSense, BOOL * pbOPTrigRepeat, long * plOPTrigRepeat)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x38, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, pbOPTrigEnable, pbIPTrigEnable, plOPTrigStart, pfOPTrigWidth, plOPTrigSense, plIPTrigSense, pbOPTrigRepeat, plOPTrigRepeat);
		return result;
	}
	long LLSetGetHostDigOPs(BOOL bSet, long * plBits)
	{
		long result;
		static BYTE parms[] = VTS_BOOL VTS_UNKNOWN;
		InvokeHelper(0x39, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bSet, plBits);
		return result;
	}
	long LLGetHostStatusBits(long * plStatusBits)
	{
		long result;
		static BYTE parms[] = VTS_UNKNOWN;
		InvokeHelper(0x3A, DISPATCH_METHOD, VT_I4, (void*)&result, parms, plStatusBits);
		return result;
	}
	long GetParentHWInfo(long * plHWSerialNum, long * plHWType)
	{
		long result;
		static BYTE parms[] = VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x3B, DISPATCH_METHOD, VT_I4, (void*)&result, parms, plHWSerialNum, plHWType);
		return result;
	}
	long SetLVTrigBNCMode(long lMode)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x3C, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMode);
		return result;
	}
	long SetForceSenseParams(long lChanID, BOOL bForceMode, float fCalib, float fOffset)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BOOL VTS_R4 VTS_R4;
		InvokeHelper(0x3D, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, bForceMode, fCalib, fOffset);
		return result;
	}
	long GetForceSenseParams(long lChanID, BOOL * pbForceMode, float * pfCalib, float * pfOffset)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x3E, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, pbForceMode, pfCalib, pfOffset);
		return result;
	}
	long SetDispIntensity(long lIntensity)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x3F, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lIntensity);
		return result;
	}
	long GetDispIntensity(long * plIntensity)
	{
		long result;
		static BYTE parms[] = VTS_UNKNOWN;
		InvokeHelper(0x40, DISPATCH_METHOD, VT_I4, (void*)&result, parms, plIntensity);
		return result;
	}
	long SetVoltageOutputLimit(long lChanID, long lLimit)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4;
		InvokeHelper(0x41, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lLimit);
		return result;
	}
	long GetVoltageOutputLimit(long lChanID, long * plLimit)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x42, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plLimit);
		return result;
	}
	long SetExtAnalogueInput(long lChanID, long lHubChan)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4;
		InvokeHelper(0x43, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lHubChan);
		return result;
	}
	long GetExtAnalogueInput(long lChanID, long * plHubChan)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x44, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plHubChan);
		return result;
	}
	long SG_SetHubAnalogueChanOut(long lChanID, long lHubChan)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4;
		InvokeHelper(0x45, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lHubChan);
		return result;
	}
	long SG_GetHubAnalogueChanOut(long lChanID, long * plHubChan)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x46, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plHubChan);
		return result;
	}
	long SG_SetDispMode(long lChanID, long lMode)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4;
		InvokeHelper(0x47, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lMode);
		return result;
	}
	long SG_GetDispMode(long lChanID, long * plMode)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x48, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plMode);
		return result;
	}
	long SG_SetDispIntensity(long lIntensity)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x49, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lIntensity);
		return result;
	}
	long SG_GetDispIntensity(long * plIntensity)
	{
		long result;
		static BYTE parms[] = VTS_UNKNOWN;
		InvokeHelper(0x4A, DISPATCH_METHOD, VT_I4, (void*)&result, parms, plIntensity);
		return result;
	}
	long SG_GetReading(long lChanID, float * pfReading)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x4B, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, pfReading);
		return result;
	}
	long SG_ZeroPosition(long lChanID)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x4C, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID);
		return result;
	}
	long SG_GetMaxTravel(long lChanID, float * pfMaxTravel)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x4D, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, pfMaxTravel);
		return result;
	}
	long SG_SaveParamSet(LPCTSTR bstrName)
	{
		long result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x4E, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bstrName);
		return result;
	}
	long SG_LoadParamSet(LPCTSTR bstrName)
	{
		long result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x4F, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bstrName);
		return result;
	}
	long SG_DeleteParamSet(LPCTSTR bstrName)
	{
		long result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x50, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bstrName);
		return result;
	}
	long SG_SetForceCalib(long lChanID, float fCalib)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_R4;
		InvokeHelper(0x51, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, fCalib);
		return result;
	}
	long SG_GetForceCalib(long lChanID, float * pfCalib)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x52, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, pfCalib);
		return result;
	}
	long SetOutputLUTValueTypes(long lType)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x53, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lType);
		return result;
	}
	long EnableEventDlg(BOOL bEnable)
	{
		long result;
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x54, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bEnable);
		return result;
	}
	long ShowEventDlg()
	{
		long result;
		InvokeHelper(0x55, DISPATCH_METHOD, VT_I4, (void*)&result, nullptr);
		return result;
	}
	long LLSetGetSerNum(BOOL bSet, long * plSerNum)
	{
		long result;
		static BYTE parms[] = VTS_BOOL VTS_UNKNOWN;
		InvokeHelper(0x56, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bSet, plSerNum);
		return result;
	}
	long SetMaxOPVoltage(long lChanID, float fMaxVoltage)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_R4;
		InvokeHelper(0x57, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, fMaxVoltage);
		return result;
	}
	long GetMaxOPVoltage(long lChanID, float * pfMaxVoltage)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x58, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, pfMaxVoltage);
		return result;
	}
	long SetSlewRates(long lChanID, float fOpenSlewRate, float fClosedSlewRate)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_R4 VTS_R4;
		InvokeHelper(0x59, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, fOpenSlewRate, fClosedSlewRate);
		return result;
	}
	long GetSlewRates(long lChanID, float * pfOpenSlewRate, float * pfClosedSlewRate)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x5A, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, pfOpenSlewRate, pfClosedSlewRate);
		return result;
	}
	long LLSetGetDevParamsEx(BOOL bSet, VARIANT * plDevParams)
	{
		long result;
		static BYTE parms[] = VTS_BOOL VTS_UNKNOWN;
		InvokeHelper(0x5B, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bSet, plDevParams);
		return result;
	}
	long SetPPCPIDParams(long lChanID, float fProp, float fInt, float fDeriv, float fDerivLPCutOffFreq, long lDerivFilterOn)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_I4;
		InvokeHelper(0x5C, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, fProp, fInt, fDeriv, fDerivLPCutOffFreq, lDerivFilterOn);
		return result;
	}
	long GetPPCPIDParams(long lChanID, float * pfProp, float * pfInt, float * pfDeriv, float * pfDerivLPCutOffFreq, long * plDerivFilterOn)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x5D, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, pfProp, pfInt, pfDeriv, pfDerivLPCutOffFreq, plDerivFilterOn);
		return result;
	}
	long SetPPCNotchParams(long lChanID, long lFilterNo, float fNotch1CentreFreq, float fNotch1Q, long lNotch1FilterOn, float fNotch2CentreFreq, float fNotch2Q, long lNotch2FilterOn)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_R4 VTS_R4 VTS_I4 VTS_R4 VTS_R4 VTS_I4;
		InvokeHelper(0x5E, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lFilterNo, fNotch1CentreFreq, fNotch1Q, lNotch1FilterOn, fNotch2CentreFreq, fNotch2Q, lNotch2FilterOn);
		return result;
	}
	long GetPPCNotchParams(long lChanID, long * plFilterNo, float * pfNotch1CentreFreq, float * pfNotch1Q, long * plNotch1FilterOn, float * pfNotch2CentreFreq, float * pfNotch2Q, long * plNotch2FilterOn)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x5F, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plFilterNo, pfNotch1CentreFreq, pfNotch1Q, plNotch1FilterOn, pfNotch2CentreFreq, pfNotch2Q, plNotch2FilterOn);
		return result;
	}
	long SetPPCIOSettings(long lChanID, long lControlSrc, long lMonitorOPSig, long lMonitorOPBandwidth, long lFeedbackSrc)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4;
		InvokeHelper(0x60, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lControlSrc, lMonitorOPSig, lMonitorOPBandwidth, lFeedbackSrc);
		return result;
	}
	long GetPPCIOSettings(long lChanID, long * plControlSrc, long * plMonitorOPSig, long * plMonitorOPBandwidth, long * plFeedbackSrc)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x61, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plControlSrc, plMonitorOPSig, plMonitorOPBandwidth, plFeedbackSrc);
		return result;
	}
	long SetKCubePanelParams(long lChanID, long lWheelMode, long lWheelGear, float fWheelJogStep, long lWheelDirSense, float fPresetVolt1, float fPresetVolt2, long lDispBrightness)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_R4 VTS_I4 VTS_R4 VTS_R4 VTS_I4;
		InvokeHelper(0x62, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lWheelMode, lWheelGear, fWheelJogStep, lWheelDirSense, fPresetVolt1, fPresetVolt2, lDispBrightness);
		return result;
	}
	long GetKCubePanelParams(long lChanID, long * plWheelMode, long * plWheelGear, float * pfWheelJogStep, long * plWheelDirSense, float * pfPresetVolt1, float * pfPresetVolt2, long * plDispBrightness)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x63, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plWheelMode, plWheelGear, pfWheelJogStep, plWheelDirSense, pfPresetVolt1, pfPresetVolt2, plDispBrightness);
		return result;
	}
	long SetKCubeTriggerParams(long lChanID, long lTrig1Mode, long lTrig1Polarity, long lTrig2Mode, long lTrig2Polarity)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4;
		InvokeHelper(0x64, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lTrig1Mode, lTrig1Polarity, lTrig2Mode, lTrig2Polarity);
		return result;
	}
	long GetKCubeTriggerParams(long lChanID, long * plTrig1Mode, long * plTrig1Polarity, long * plTrig2Mode, long * plTrig2Polarity)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plTrig1Mode, plTrig1Polarity, plTrig2Mode, plTrig2Polarity);
		return result;
	}
	long SetKSGPanelParams(long lChanID, long lDispBrightness)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lDispBrightness);
		return result;
	}
	long GetKSGPanelParams(long lChanID, long * plDispBrightness)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN;
		InvokeHelper(0x67, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plDispBrightness);
		return result;
	}
	long SetKSGTriggerParams(long lChanID, long lTrig1Mode, long lTrig1Polarity, long lTrig2Mode, long lTrig2Polarity, float fLowerLim, float fUpperLim, long lSmoothingSamples)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_R4 VTS_R4 VTS_I4;
		InvokeHelper(0x68, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, lTrig1Mode, lTrig1Polarity, lTrig2Mode, lTrig2Polarity, fLowerLim, fUpperLim, lSmoothingSamples);
		return result;
	}
	long GetKSGTriggerParams(long lChanID, long * plTrig1Mode, long * plTrig1Polarity, long * plTrig2Mode, long * plTrig2Polarity, float * pfLowerLim, float * pfUpperLim, long * plSmoothingSamples)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN VTS_UNKNOWN;
		InvokeHelper(0x69, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lChanID, plTrig1Mode, plTrig1Polarity, plTrig2Mode, plTrig2Polarity, pfLowerLim, pfUpperLim, plSmoothingSamples);
		return result;
	}
// _DMG17PiezoEvents

// Funktionen
//

	void HWResponse(long lHWCode, long lMsgIdent)
	{
		static BYTE parms[] = VTS_I4 VTS_I4;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, lHWCode, lMsgIdent);
	}
	void SettingsChanged(long lFlags)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, lFlags);
	}


};
