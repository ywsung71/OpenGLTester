#include "pch.h"
#include "framework.h"
#include "OpenGLTester.h"
#include "OpenGLTesterDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(COpenGLTesterApp, CWinApp)
END_MESSAGE_MAP()

COpenGLTesterApp::COpenGLTesterApp() {
    m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
}

COpenGLTesterApp theApp;

BOOL COpenGLTesterApp::InitInstance() {
    CWinApp::InitInstance();

    COpenGLTesterDlg dlg;
    m_pMainWnd = &dlg;
    INT_PTR nResponse = dlg.DoModal();

    return FALSE;
}
