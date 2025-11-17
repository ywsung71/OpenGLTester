#pragma once

#include "OpenGLRenderer.h"

class COpenGLTesterDlg : public CDialogEx {
public:
    COpenGLTesterDlg(CWnd* pParent = nullptr);

#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_OPENGLTESTER_DIALOG };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);

protected:
    HICON m_hIcon;

    virtual BOOL OnInitDialog();
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    afx_msg void OnDestroy();
    afx_msg void OnLoadPly1();
    afx_msg void OnLoadPly2();
    afx_msg void OnRadioOrthographic();
    afx_msg void OnRadioPerspective();
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    afx_msg void OnSize(UINT nType, int cx, int cy);
    DECLARE_MESSAGE_MAP()

private:
    OpenGLRenderer m_renderer;
    CPoint m_lastMousePos;
    bool m_isMouseTracking;
    UINT_PTR m_renderTimer;

    void UpdateRendererSize();
};
