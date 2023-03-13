#pragma once

// Mit Microsoft Visual C++ generierte IDispatch-Wrapperklasse(n)

// HINWEIS: Die Inhalte dieser Datei dürfen nicht geändert werden.
//  Die Änderungen werden überschrieben, wenn diese Klasse von Microsoft Visual C++ erneut generiert wird.

/////////////////////////////////////////////////////////////////////////////

#include "afxwin.h"

class CLABEL4 : public CWnd
{
protected:
	DECLARE_DYNCREATE(CLABEL4)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= {0x978c9e23,0xd4b0,0x11ce,{0xbf,0x2d,0x00,0xaa,0x00,0x3f,0x40,0xd0}};
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
	fmDropEffectNone = 0,
	fmDropEffectCopy = 1,
	fmDropEffectMove = 2,
	fmDropEffectCopyOrMove = 3
}fmDropEffect;

enum
{
	fmActionCut = 0,
	fmActionCopy = 1,
	fmActionPaste = 2,
	fmActionDragDrop = 3
}fmAction;

enum
{
	fmModeInherit = -2,
	fmModeOn = -1,
	fmModeOff = 0
}fmMode;

enum
{
	fmMousePointerDefault = 0,
	fmMousePointerArrow = 1,
	fmMousePointerCross = 2,
	fmMousePointerIBeam = 3,
	fmMousePointerSizeNESW = 6,
	fmMousePointerSizeNS = 7,
	fmMousePointerSizeNWSE = 8,
	fmMousePointerSizeWE = 9,
	fmMousePointerUpArrow = 10,
	fmMousePointerHourGlass = 11,
	fmMousePointerNoDrop = 12,
	fmMousePointerAppStarting = 13,
	fmMousePointerHelp = 14,
	fmMousePointerSizeAll = 15,
	fmMousePointerCustom = 99
}fmMousePointer;

enum
{
	fmScrollBarsNone = 0,
	fmScrollBarsHorizontal = 1,
	fmScrollBarsVertical = 2,
	fmScrollBarsBoth = 3
}fmScrollBars;

enum
{
	fmScrollActionNoChange = 0,
	fmScrollActionLineUp = 1,
	fmScrollActionLineDown = 2,
	fmScrollActionPageUp = 3,
	fmScrollActionPageDown = 4,
	fmScrollActionBegin = 5,
	fmScrollActionEnd = 6,
	_fmScrollActionAbsoluteChange = 7,
	fmScrollActionPropertyChange = 8,
	fmScrollActionControlRequest = 9,
	fmScrollActionFocusRequest = 10
}fmScrollAction;

enum
{
	fmCycleAllForms = 0,
	fmCycleCurrentForm = 2
}fmCycle;

enum
{
	fmZOrderFront = 0,
	fmZOrderBack = 1
}fmZOrder;

enum
{
	fmBorderStyleNone = 0,
	fmBorderStyleSingle = 1
}fmBorderStyle;

enum
{
	fmTextAlignLeft = 1,
	fmTextAlignCenter = 2,
	fmTextAlignRight = 3
}fmTextAlign;

enum
{
	fmAlignmentLeft = 0,
	fmAlignmentRight = 1
}fmAlignment;

enum
{
	fmBordersNone = 0,
	fmBordersBox = 1,
	fmBordersLeft = 2,
	fmBordersTop = 3
}fmBorders;

enum
{
	fmBackStyleTransparent = 0,
	fmBackStyleOpaque = 1
}fmBackStyle;

enum
{
	fmButtonStylePushButton = 0,
	fmButtonStyleToggleButton = 1
}fmButtonStyle;

enum
{
	fmPicPositionCenter = 0,
	fmPicPositionTopLeft = 1,
	fmPicPositionTopCenter = 2,
	fmPicPositionTopRight = 3,
	fmPicPositionCenterLeft = 4,
	fmPicPositionCenterRight = 5,
	fmPicPositionBottomLeft = 6,
	fmPicPositionBottomCenter = 7,
	fmPicPositionBottomRight = 8
}fmPicPosition;

enum
{
	fmVerticalScrollBarSideRight = 0,
	fmVerticalScrollBarSideLeft = 1
}fmVerticalScrollBarSide;

enum
{
	fmLayoutEffectNone = 0,
	fmLayoutEffectInitiate = 1,
	_fmLayoutEffectRespond = 2
}fmLayoutEffect;

enum
{
	fmSpecialEffectFlat = 0,
	fmSpecialEffectRaised = 1,
	fmSpecialEffectSunken = 2,
	fmSpecialEffectEtched = 3,
	fmSpecialEffectBump = 6
}fmSpecialEffect;

enum
{
	fmDragStateEnter = 0,
	fmDragStateLeave = 1,
	fmDragStateOver = 2
}fmDragState;

enum
{
	fmPictureSizeModeClip = 0,
	fmPictureSizeModeStretch = 1,
	fmPictureSizeModeZoom = 3
}fmPictureSizeMode;

enum
{
	fmPictureAlignmentTopLeft = 0,
	fmPictureAlignmentTopRight = 1,
	fmPictureAlignmentCenter = 2,
	fmPictureAlignmentBottomLeft = 3,
	fmPictureAlignmentBottomRight = 4
}fmPictureAlignment;

enum
{
	fmButtonEffectFlat = 0,
	fmButtonEffectSunken = 2
}fmButtonEffect;

enum
{
	fmOrientationAuto = -1,
	fmOrientationVertical = 0,
	fmOrientationHorizontal = 1
}fmOrientation;

enum
{
	fmSnapPointTopLeft = 0,
	fmSnapPointTopCenter = 1,
	fmSnapPointTopRight = 2,
	fmSnapPointCenterLeft = 3,
	fmSnapPointCenter = 4,
	fmSnapPointCenterRight = 5,
	fmSnapPointBottomLeft = 6,
	fmSnapPointBottomCenter = 7,
	fmSnapPointBottomRight = 8
}fmSnapPoint;

enum
{
	fmPicturePositionLeftTop = 0,
	fmPicturePositionLeftCenter = 1,
	fmPicturePositionLeftBottom = 2,
	fmPicturePositionRightTop = 3,
	fmPicturePositionRightCenter = 4,
	fmPicturePositionRightBottom = 5,
	fmPicturePositionAboveLeft = 6,
	fmPicturePositionAboveCenter = 7,
	fmPicturePositionAboveRight = 8,
	fmPicturePositionBelowLeft = 9,
	fmPicturePositionBelowCenter = 10,
	fmPicturePositionBelowRight = 11,
	fmPicturePositionCenter = 12
}fmPicturePosition;

enum
{
	fmDisplayStyleText = 1,
	fmDisplayStyleList = 2,
	fmDisplayStyleCombo = 3,
	fmDisplayStyleCheckBox = 4,
	fmDisplayStyleOptionButton = 5,
	fmDisplayStyleToggle = 6,
	fmDisplayStyleDropList = 7
}fmDisplayStyle;

enum
{
	fmShowListWhenNever = 0,
	fmShowListWhenButton = 1,
	fmShowListWhenFocus = 2,
	fmShowListWhenAlways = 3
}fmShowListWhen;

enum
{
	fmShowDropButtonWhenNever = 0,
	fmShowDropButtonWhenFocus = 1,
	fmShowDropButtonWhenAlways = 2
}fmShowDropButtonWhen;

enum
{
	fmMultiSelectSingle = 0,
	fmMultiSelectMulti = 1,
	fmMultiSelectExtended = 2
}fmMultiSelect;

enum
{
	fmListStylePlain = 0,
	fmListStyleOption = 1
}fmListStyle;

enum
{
	fmEnterFieldBehaviorSelectAll = 0,
	fmEnterFieldBehaviorRecallSelection = 1
}fmEnterFieldBehavior;

enum
{
	fmDragBehaviorDisabled = 0,
	fmDragBehaviorEnabled = 1
}fmDragBehavior;

enum
{
	fmMatchEntryFirstLetter = 0,
	fmMatchEntryComplete = 1,
	fmMatchEntryNone = 2
}fmMatchEntry;

enum
{
	fmDropButtonStylePlain = 0,
	fmDropButtonStyleArrow = 1,
	fmDropButtonStyleEllipsis = 2,
	fmDropButtonStyleReduce = 3
}fmDropButtonStyle;

enum
{
	fmStyleDropDownCombo = 0,
	fmStyleDropDownList = 2
}fmStyle;

enum
{
	fmTabOrientationTop = 0,
	fmTabOrientationBottom = 1,
	fmTabOrientationLeft = 2,
	fmTabOrientationRight = 3
}fmTabOrientation;

enum
{
	fmTabStyleTabs = 0,
	fmTabStyleButtons = 1,
	fmTabStyleNone = 2
}fmTabStyle;

enum
{
	fmIMEModeNoControl = 0,
	fmIMEModeOn = 1,
	fmIMEModeOff = 2,
	fmIMEModeDisable = 3,
	fmIMEModeHiragana = 4,
	fmIMEModeKatakana = 5,
	fmIMEModeKatakanaHalf = 6,
	fmIMEModeAlphaFull = 7,
	fmIMEModeAlpha = 8,
	fmIMEModeHangulFull = 9,
	fmIMEModeHangul = 10,
	fmIMEModeHanziFull = 11,
	fmIMEModeHanzi = 12
}fmIMEMode;

enum
{
	fmTransitionEffectNone = 0,
	fmTransitionEffectCoverUp = 1,
	fmTransitionEffectCoverRightUp = 2,
	fmTransitionEffectCoverRight = 3,
	fmTransitionEffectCoverRightDown = 4,
	fmTransitionEffectCoverDown = 5,
	fmTransitionEffectCoverLeftDown = 6,
	fmTransitionEffectCoverLeft = 7,
	fmTransitionEffectCoverLeftUp = 8,
	fmTransitionEffectPushUp = 9,
	fmTransitionEffectPushRight = 10,
	fmTransitionEffectPushDown = 11,
	fmTransitionEffectPushLeft = 12
}fmTransitionEffect;

enum
{
	_fmListBoxStylesNone = 0,
	_fmListBoxStylesListBox = 1,
	_fmListBoxStylesComboBox = 2
}fmListBoxStyles;

enum
{
	_fmRepeatDirectionHorizontal = 0,
	_fmRepeatDirectionVertical = 1
}fmRepeatDirection;

enum
{
	_fmEnAutoSizeNone = 0,
	_fmEnAutoSizeHorizontal = 1,
	_fmEnAutoSizeVertical = 2,
	_fmEnAutoSizeBoth = 3
}fmEnAutoSize;



// Vorgänge
public:
// ILabelControl

// Funktionen
//

	void put_AutoSize(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0xFFFFFE0C, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_AutoSize()
	{
		BOOL result;
		InvokeHelper(0xFFFFFE0C, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_BackColor(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0xFFFFFE0B, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	long get_BackColor()
	{
		long result;
		InvokeHelper(0xFFFFFE0B, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_BackStyle(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0xFFFFFE0A, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	long get_BackStyle()
	{
		long result;
		InvokeHelper(0xFFFFFE0A, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_BorderColor(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0xFFFFFE09, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	long get_BorderColor()
	{
		long result;
		InvokeHelper(0xFFFFFE09, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_BorderStyle(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0xFFFFFE08, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	long get_BorderStyle()
	{
		long result;
		InvokeHelper(0xFFFFFE08, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_Caption(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x0, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	CString get_Caption()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
	void put_Enabled(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0xFFFFFDFE, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_Enabled()
	{
		BOOL result;
		InvokeHelper(0xFFFFFDFE, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put__Font_Reserved(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH;
		InvokeHelper(0x7FFFFDFF, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	void putref_Font(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH;
		InvokeHelper(0xFFFFFE00, DISPATCH_PROPERTYPUTREF, VT_EMPTY, nullptr, parms, newValue);
	}
	LPDISPATCH get_Font()
	{
		LPDISPATCH result;
		InvokeHelper(0xFFFFFE00, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, nullptr);
		return result;
	}
	void put_FontItalic(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_FontItalic()
	{
		BOOL result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_FontBold(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_FontBold()
	{
		BOOL result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_FontName(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	CString get_FontName()
	{
		CString result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
	void put_FontSize(CY newValue)
	{
		static BYTE parms[] = VTS_CY;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, &newValue);
	}
	CY get_FontSize()
	{
		CY result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_CY, (void*)&result, nullptr);
		return result;
	}
	void put_FontStrikethru(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_FontStrikethru()
	{
		BOOL result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_FontUnderline(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_FontUnderline()
	{
		BOOL result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_ForeColor(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0xFFFFFDFF, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	long get_ForeColor()
	{
		long result;
		InvokeHelper(0xFFFFFDFF, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_MouseIcon(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH;
		InvokeHelper(0xFFFFFDF6, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	void putref_MouseIcon(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH;
		InvokeHelper(0xFFFFFDF6, DISPATCH_PROPERTYPUTREF, VT_EMPTY, nullptr, parms, newValue);
	}
	LPDISPATCH get_MouseIcon()
	{
		LPDISPATCH result;
		InvokeHelper(0xFFFFFDF6, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, nullptr);
		return result;
	}
	void put_MousePointer(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0xFFFFFDF7, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	long get_MousePointer()
	{
		long result;
		InvokeHelper(0xFFFFFDF7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_Picture(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH;
		InvokeHelper(0xFFFFFDF5, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	void putref_Picture(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH;
		InvokeHelper(0xFFFFFDF5, DISPATCH_PROPERTYPUTREF, VT_EMPTY, nullptr, parms, newValue);
	}
	LPDISPATCH get_Picture()
	{
		LPDISPATCH result;
		InvokeHelper(0xFFFFFDF5, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, nullptr);
		return result;
	}
	void put_PicturePosition(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0xB, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	long get_PicturePosition()
	{
		long result;
		InvokeHelper(0xB, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_SpecialEffect(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0xC, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	long get_SpecialEffect()
	{
		long result;
		InvokeHelper(0xC, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_TextAlign(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0xD, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	long get_TextAlign()
	{
		long result;
		InvokeHelper(0xD, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_WordWrap(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0xFFFFFDE8, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_WordWrap()
	{
		BOOL result;
		InvokeHelper(0xFFFFFDE8, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_Accelerator(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xFFFFFDE1, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	CString get_Accelerator()
	{
		CString result;
		InvokeHelper(0xFFFFFDE1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
	void put_FontWeight(short newValue)
	{
		static BYTE parms[] = VTS_I2;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	short get_FontWeight()
	{
		short result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, nullptr);
		return result;
	}
	void put__Value(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xFFFFFDFA, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	CString get__Value()
	{
		CString result;
		InvokeHelper(0xFFFFFDFA, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
// LabelControlEvents

// Funktionen
//

	void BeforeDragOver(LPDISPATCH Cancel, LPDISPATCH Data, float X, float Y, long DragState, LPDISPATCH Effect, short Shift)
	{
		static BYTE parms[] = VTS_DISPATCH VTS_DISPATCH VTS_R4 VTS_R4 VTS_I4 VTS_DISPATCH VTS_I2;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, Cancel, Data, X, Y, DragState, Effect, Shift);
	}
	void BeforeDropOrPaste(LPDISPATCH Cancel, long Action, LPDISPATCH Data, float X, float Y, LPDISPATCH Effect, short Shift)
	{
		static BYTE parms[] = VTS_DISPATCH VTS_I4 VTS_DISPATCH VTS_R4 VTS_R4 VTS_DISPATCH VTS_I2;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, Cancel, Action, Data, X, Y, Effect, Shift);
	}
	void Click()
	{
		InvokeHelper(0xFFFFFDA8, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	void DblClick(LPDISPATCH Cancel)
	{
		static BYTE parms[] = VTS_DISPATCH;
		InvokeHelper(0xFFFFFDA7, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, Cancel);
	}
	void Error(short Number, LPDISPATCH Description, long SCode, LPCTSTR Source, LPCTSTR HelpFile, long HelpContext, LPDISPATCH CancelDisplay)
	{
		static BYTE parms[] = VTS_I2 VTS_DISPATCH VTS_I4 VTS_BSTR VTS_BSTR VTS_I4 VTS_DISPATCH;
		InvokeHelper(0xFFFFFDA0, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, Number, Description, SCode, Source, HelpFile, HelpContext, CancelDisplay);
	}
	void MouseDown(short Button, short Shift, float X, float Y)
	{
		static BYTE parms[] = VTS_I2 VTS_I2 VTS_R4 VTS_R4;
		InvokeHelper(0xFFFFFDA3, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, Button, Shift, X, Y);
	}
	void MouseMove(short Button, short Shift, float X, float Y)
	{
		static BYTE parms[] = VTS_I2 VTS_I2 VTS_R4 VTS_R4;
		InvokeHelper(0xFFFFFDA2, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, Button, Shift, X, Y);
	}
	void MouseUp(short Button, short Shift, float X, float Y)
	{
		static BYTE parms[] = VTS_I2 VTS_I2 VTS_R4 VTS_R4;
		InvokeHelper(0xFFFFFDA1, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, Button, Shift, X, Y);
	}


};
