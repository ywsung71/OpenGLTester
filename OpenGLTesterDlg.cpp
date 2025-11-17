#include "pch.h"
#include "framework.h"
#include "OpenGLTester.h"
#include "OpenGLTesterDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

COpenGLTesterDlg::COpenGLTesterDlg(CWnd* pParent)
    : CDialogEx(IDD_OPENGLTESTER_DIALOG, pParent)
    , m_isMouseTracking(false)
    , m_renderTimer(0) {
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COpenGLTesterDlg::DoDataExchange(CDataExchange* pDX) {
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(COpenGLTesterDlg, CDialogEx)
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_WM_DESTROY()
    ON_BN_CLICKED(IDC_LOAD_PLY1, &COpenGLTesterDlg::OnLoadPly1)
    ON_BN_CLICKED(IDC_LOAD_PLY2, &COpenGLTesterDlg::OnLoadPly2)
    ON_BN_CLICKED(IDC_RADIO_ORTHOGRAPHIC, &COpenGLTesterDlg::OnRadioOrthographic)
    ON_BN_CLICKED(IDC_RADIO_PERSPECTIVE, &COpenGLTesterDlg::OnRadioPerspective)
    ON_WM_MOUSEMOVE()
    ON_WM_MOUSEWHEEL()
    ON_WM_TIMER()
    ON_WM_SIZE()
END_MESSAGE_MAP()

BOOL COpenGLTesterDlg::OnInitDialog() {
    CDialogEx::OnInitDialog();

    SetIcon(m_hIcon, TRUE);
    SetIcon(m_hIcon, FALSE);

    // Initialize OpenGL renderer
    CWnd* pWnd = GetDlgItem(IDC_OPENGL_VIEW);
    if (pWnd) {
        m_renderer.Initialize(pWnd->GetSafeHwnd());
        
        CRect rect;
        pWnd->GetClientRect(&rect);
        m_renderer.Resize(rect.Width(), rect.Height());
    }

    // Set default to perspective view
    CheckRadioButton(IDC_RADIO_ORTHOGRAPHIC, IDC_RADIO_PERSPECTIVE, IDC_RADIO_PERSPECTIVE);
    m_renderer.SetProjectionMode(ProjectionMode::PERSPECTIVE);

    // Start render timer
    m_renderTimer = SetTimer(1, 16, nullptr); // ~60 FPS

    return TRUE;
}

void COpenGLTesterDlg::OnPaint() {
    if (IsIconic()) {
        CPaintDC dc(this);

        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        dc.DrawIcon(x, y, m_hIcon);
    } else {
        CDialogEx::OnPaint();
    }
}

HCURSOR COpenGLTesterDlg::OnQueryDragIcon() {
    return static_cast<HCURSOR>(m_hIcon);
}

void COpenGLTesterDlg::OnDestroy() {
    if (m_renderTimer) {
        KillTimer(m_renderTimer);
        m_renderTimer = 0;
    }

    m_renderer.Cleanup();

    CDialogEx::OnDestroy();
}

void COpenGLTesterDlg::OnLoadPly1() {
    CFileDialog dlg(TRUE, _T("ply"), nullptr,
        OFN_HIDEREADONLY | OFN_FILEMUSTEXIST,
        _T("PLY Files (*.ply)|*.ply|All Files (*.*)|*.*||"));

    if (dlg.DoModal() == IDOK) {
        CString filePath = dlg.GetPathName();
        CT2A asciiPath(filePath);
        m_renderer.LoadPLY1(std::string(asciiPath));
        m_renderer.Render();
    }
}

void COpenGLTesterDlg::OnLoadPly2() {
    CFileDialog dlg(TRUE, _T("ply"), nullptr,
        OFN_HIDEREADONLY | OFN_FILEMUSTEXIST,
        _T("PLY Files (*.ply)|*.ply|All Files (*.*)|*.*||"));

    if (dlg.DoModal() == IDOK) {
        CString filePath = dlg.GetPathName();
        CT2A asciiPath(filePath);
        m_renderer.LoadPLY2(std::string(asciiPath));
        m_renderer.Render();
    }
}

void COpenGLTesterDlg::OnRadioOrthographic() {
    m_renderer.SetProjectionMode(ProjectionMode::ORTHOGRAPHIC);
    m_renderer.Render();
}

void COpenGLTesterDlg::OnRadioPerspective() {
    m_renderer.SetProjectionMode(ProjectionMode::PERSPECTIVE);
    m_renderer.Render();
}

void COpenGLTesterDlg::OnMouseMove(UINT nFlags, CPoint point) {
    CWnd* pWnd = GetDlgItem(IDC_OPENGL_VIEW);
    if (pWnd) {
        CRect rect;
        pWnd->GetWindowRect(&rect);
        ScreenToClient(&rect);

        if (rect.PtInRect(point)) {
            if (nFlags & MK_LBUTTON) {
                if (m_isMouseTracking) {
                    float deltaX = static_cast<float>(point.x - m_lastMousePos.x);
                    float deltaY = static_cast<float>(point.y - m_lastMousePos.y);
                    m_renderer.RotateCamera(deltaX * 0.5f, deltaY * 0.5f);
                    m_renderer.Render();
                }
                m_isMouseTracking = true;
            } else {
                m_isMouseTracking = false;
            }
            m_lastMousePos = point;
        }
    }

    CDialogEx::OnMouseMove(nFlags, point);
}

BOOL COpenGLTesterDlg::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) {
    CWnd* pWnd = GetDlgItem(IDC_OPENGL_VIEW);
    if (pWnd) {
        CRect rect;
        pWnd->GetWindowRect(&rect);

        if (rect.PtInRect(pt)) {
            float delta = zDelta / 120.0f;
            m_renderer.ZoomCamera(delta);
            m_renderer.Render();
        }
    }

    return CDialogEx::OnMouseWheel(nFlags, zDelta, pt);
}

void COpenGLTesterDlg::OnTimer(UINT_PTR nIDEvent) {
    if (nIDEvent == 1) {
        m_renderer.Render();
    }

    CDialogEx::OnTimer(nIDEvent);
}

void COpenGLTesterDlg::OnSize(UINT nType, int cx, int cy) {
    CDialogEx::OnSize(nType, cx, cy);

    if (::IsWindow(m_hWnd)) {
        UpdateRendererSize();
    }
}

void COpenGLTesterDlg::UpdateRendererSize() {
    CWnd* pWnd = GetDlgItem(IDC_OPENGL_VIEW);
    if (pWnd && ::IsWindow(pWnd->GetSafeHwnd())) {
        CRect rect;
        pWnd->GetClientRect(&rect);
        if (rect.Width() > 0 && rect.Height() > 0) {
            m_renderer.Resize(rect.Width(), rect.Height());
            m_renderer.Render();
        }
    }
}
