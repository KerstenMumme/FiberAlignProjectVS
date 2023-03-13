#pragma once

// Mit Microsoft Visual C++ generierte IDispatch-Wrapperklasse(n)

// HINWEIS: Die Inhalte dieser Datei dürfen nicht geändert werden.
//  Die Änderungen werden überschrieben, wenn diese Klasse von Microsoft Visual C++ erneut generiert wird.

/////////////////////////////////////////////////////////////////////////////

#include "afxwin.h"

class CMG17LOGGERCTRL1 : public CWnd
{
protected:
	DECLARE_DYNCREATE(CMG17LOGGERCTRL1)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= {0x3da95bb9,0x9a53,0x4ed0,{0xb1,0xaa,0x2d,0x98,0x80,0x5c,0x89,0x5f}};
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
	MG17_EVENT_NORMAL = 1,
	MG17_EVENT_WARNING = 2,
	MG17_EVENT_ERROR = 4
}MG_EVENT_TYPES;

enum
{
	MG17_OK = 0,
	MG17_UNKNOWN_ERR = 10000,
	MG17_INTERNAL_ERR = 10001,
	MG17_FAILED = 10002,
	MG17_INVALIDPARAM_ERR = 10003,
	MG17_SETTINGSNOTFOUND = 10004,
	MG17_DLLNOTINITIALISED = 10005,
	MG17_DISKACCESS_ERR = 10050,
	MG17_ETHERNET_ERR = 10051,
	MG17_REGISTRY_ERR = 10052,
	MG17_MEMORY_ERR = 10053,
	MG17_COM_ERR = 10054,
	MG17_USB_ERR = 10055,
	MG17_NOTTHORLABSDEVICE_ERR = 10056,
	MG17_SERIALNUMUNKNOWN_ERR = 10100,
	MG17_DUPLICATESERIALNUM_ERR = 10101,
	MG17_DUPLICATEDEVICEIDENT_ERR = 10102,
	MG17_INVALIDMSGSRC_ERR = 10103,
	MG17_UNKNOWNMSGIDENT_ERR = 10104,
	MG17_UNKNOWNHWTYPE_ERR = 10105,
	MG17_INVALIDSERIALNUM_ERR = 10106,
	MG17_INVALIDMSGDEST_ERR = 10107,
	MG17_INVALIDINDEX_ERR = 10108,
	MG17_CTRLCOMMSDISABLED_ERR = 10109,
	MG17_HWRESPONSE_ERR = 10110,
	MG17_HWTIMEOUT_ERR = 10111,
	MG17_INCORRECTVERSION_ERR = 10112,
	MG17_HARDLOCKDRIVER_ERR = 10113,
	MG17_HARDLOCKMISSING_ERR = 10114,
	MG17_INCOMPATIBLEHARDWARE_ERR = 10115,
	MG17_OLDVERSION_ERR = 10116,
	MG17_NOSTAGEAXISINFO = 10150,
	MG17_CALIBTABLE_ERR = 10151,
	MG17_ENCCALIB_ERR = 10152,
	MG17_ENCNOTPRESENT_ERR = 10153,
	MG17_MOTORNOTHOMED_ERR = 10154,
	MG17_MOTORDISABLED_ERR = 10155,
	MG17_PMDMSG_ERR = 10156,
	MG17_PMDREADONLY_ERR = 10157,
	MG17_PIEZOLED_ERR = 10200,
	MG17_NANOTRAKLED_ERR = 10250,
	MG17_NANOTRAKCLOSEDLOOP_ERR = 10251,
	MG17_NANOTRAKPOWER_ERR = 10252
}MG_RET_CODES;



// Vorgänge
public:
// _DMG17Logger

// Funktionen
//

	void AboutBox()
	{
		InvokeHelper(0xFFFFFDD8, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	void Clear()
	{
		InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	void AddItem(LPCTSTR bstrItem)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, bstrItem);
	}
	void RemoveItem(long lIndex)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, lIndex);
	}
	CString get_List(long lIndex)
	{
		CString result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, parms, lIndex);
		return result;
	}
// _DMG17LoggerEvents

// Funktionen
//

	void Click()
	{
		InvokeHelper(0xFFFFFDA8, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	void DblClick()
	{
		InvokeHelper(0xFFFFFDA7, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	void Updated(LPCTSTR bstrEventInfo)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, bstrEventInfo);
	}
	void APTError(long lErrCode, long lIntIdent, LPCTSTR bstrErrInfo)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, lErrCode, lIntIdent, bstrErrInfo);
	}


};
