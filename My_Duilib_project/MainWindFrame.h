#pragma once
#include "pch.h"
#include "resource.h"


class MainWindFrame : public WindowImplBase
{
protected:
	virtual CDuiString GetSkinFolder() override;							// ��ȡƤ���ļ���Ŀ¼������ж��Ŀ¼�����������
	virtual CDuiString GetSkinFile() override;								// ����Ƥ���ļ�����
	virtual LPCTSTR GetWindowClassName(void) const override;	// ���õ�ǰ���ڵ� class name
	DuiLib::UILIB_RESOURCETYPE GetResourceType() const;
	LPCTSTR GetResourceID() const;
	virtual void InitWindow() override;
	virtual void Notify(TNotifyUI& msg)  override;
	virtual LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) override;
public:
	static const LPCTSTR kClassName;
	static const LPCTSTR kMainWndFrame;

private:
	CButtonUI*	m_p_min_btn = nullptr;
	CButtonUI*	m_p_max_btn = nullptr;
	CButtonUI*	m_p_restore_btn = nullptr;
	CButtonUI*	m_p_close_btn = nullptr;
};
