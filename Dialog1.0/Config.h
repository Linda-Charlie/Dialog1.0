#pragma once
#include "afxdialogex.h"


// Config 对话框

class Config : public CDialogEx
{
	DECLARE_DYNAMIC(Config)

public:
	Config(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Config();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CONFIG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedStaticSex();
	// 真实姓名
	CString 真实姓名;
	// 身份证号
	double ID;
	// 用户名
	CString MYNAME;
	// 密码
	int CODE;
	// 职业
	CString JOB;
	// 邮箱
	CString EMAIL;
	// 性别
	CComboBox SEX;
	// 出生年
	CComboBox BIRTHYEAR;
	// 出生月
	CComboBox BIRTHMONTH;
	// 出生日
	CComboBox BIRTHDAY;
	// 爱好
	CString HOBBY;
	// 特长
	CString Advantage;
	// 信息录入与设置完成情况
	CProgressCtrl Condition;
	virtual BOOL OnInitDialog();
	// 加载
	CButton Conadd;
	afx_msg void OnBnClickedButtonConadd();
	// 提交
	CButton Submit;
	afx_msg void OnBnClickedOkSubmit();
};
