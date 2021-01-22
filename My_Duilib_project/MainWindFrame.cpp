#include "pch.h"
#include "MainWindFrame.h"



DuiLib::CDuiString MainWindFrame::GetSkinFolder()
{
	// GetInstancePath �ӿڷ���Ĭ�ϵ�Ƥ���ļ�λ��
	// �� main ���������ǿ���ͨ�� SetResourcePath ������·��
#if _DEBUG
	return _T("theme");
#else
	return m_PaintManager.GetInstancePath();
#endif
}

DuiLib::CDuiString MainWindFrame::GetSkinFile()
{
	// ��Ա���������Ƥ���ļ���
	return kMainWndFrame;
}

LPCTSTR MainWindFrame::GetWindowClassName(void) const
{
	// ��Ա��������Ĵ��� class name
	return kClassName;
}

DuiLib::UILIB_RESOURCETYPE MainWindFrame::GetResourceType() const
{
#if _DEBUG
	return UILIB_FILE;
#else
	return UILIB_ZIPRESOURCE;
#endif
}

LPCTSTR MainWindFrame::GetResourceID() const
{
	return MAKEINTRESOURCE(101);
}

const LPCTSTR MainWindFrame::kClassName = _T("main_wnd_frame");
const LPCTSTR MainWindFrame::kMainWndFrame = _T("main_wnd_frame.xml");

void MainWindFrame::InitWindow()
{
	m_p_min_btn = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("btn_wnd_min")));
	m_p_max_btn = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("btn_wnd_max")));
	m_p_restore_btn = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("btn_wnd_restore")));
	m_p_close_btn = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("btn_wnd_close")));
}

void MainWindFrame::Notify(TNotifyUI & msg)
{
	if (msg.sType == DUI_MSGTYPE_CLICK)
	{
		CDuiString strName = msg.pSender->GetName();
		if (strName == _T("btn_wnd_min"))
		{
			SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0);
		}
	}

	__super::Notify(msg);
}

LRESULT MainWindFrame::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	if (uMsg == WM_CLOSE)
	{
		PostQuitMessage(0L);
	}

	return __super::OnClose(uMsg, wParam, lParam, bHandled);
}