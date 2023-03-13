
// FiberAlignProjectVS.h: Hauptheaderdatei für die PROJECT_NAME-Anwendung
//

#pragma once

#ifndef __AFXWIN_H__
	#error "'pch.h' vor dieser Datei für PCH einschließen"
#endif

#include "resource.h"		// Hauptsymbole


// CFiberAlignProjectVSApp:
// Siehe FiberAlignProjectVS.cpp für die Implementierung dieser Klasse
//

class CFiberAlignProjectVSApp : public CWinApp
{
public:
	CFiberAlignProjectVSApp();

// Überschreibungen
public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
};

extern CFiberAlignProjectVSApp theApp;
