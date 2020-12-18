
// EasyPlayerDlg.h : 头文件
//

#pragma once

#include "DlgVideo.h"
#include ".\EasySkinUI\skindialog.h"

#define KEY "59615A67426F69576B5A734132635A666F446B6D7065314659584E35556C524E55454E73615756756443356C6547556A567778576F502B6C2F32566863336B3D"

#define	_SURV_MAX_WINDOW_NUM		16
#define MSG_LOG WM_USER +0x1001

typedef struct __VIDEO_NODE_T
{
	bool		fullscreen;
	int			maximizedId;
	int			selectedId;
	int			channels;
	CDlgVideo	*pDlgVideo;
}VIDEO_NODE_T;

// CEasyPlayerDlg 对话框
class CEasyPlayerDlg : public CSkinDialog
{
// 构造
public:
	CEasyPlayerDlg(CWnd* pParent = NULL);	// 标准构造函数


public:
	CComboBox		*pComboxSplitScreen;
	CComboBox		*pComboxRenderFormat;	//IDC_COMBO_RENDER_FORMAT
	VIDEO_NODE_T	*pVideoWindow;		//视频窗口
	CSkinButton			pChkShownToScale;	//按比例显示
	CStatic			*pStaticCopyright;	//IDC_STATIC_COPYRIGHT

	void	InitialComponents();
	void	CreateComponents();
	void	UpdateComponents();
	void	DeleteComponents();
	void	UpdateVideoPosition(LPRECT lpRect);

// 对话框数据
	enum { IDD = IDD_EASYPLAYER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	LRESULT OnWindowMaximized(WPARAM wParam, LPARAM lParam);
	LRESULT OnLog(WPARAM wParam, LPARAM lParam);

public:
	virtual BOOL DestroyWindow();
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	afx_msg void OnCbnSelchangeComboSplitScreen();
	afx_msg void OnCbnSelchangeComboRenderFormat();
	afx_msg void OnBnClickedCheckShowntoscale();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

private:
	int m_nValidTimes;

};
