#pragma once
#include "pch.h"
#include "resource.h"


class MainWindFrame : public WindowImplBase
{
protected:
	virtual CDuiString GetSkinFolder() override;							// 获取皮肤文件的目录，如果有多层目录这里可以设置
	virtual CDuiString GetSkinFile() override;								// 设置皮肤文件名字
	virtual LPCTSTR GetWindowClassName(void) const override;	// 设置当前窗口的 class name
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
