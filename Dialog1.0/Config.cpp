// Config.cpp: 实现文件
//

#include "pch.h"
#include "Dialog1.0.h"
#include "afxdialogex.h"
#include "Config.h"


// Config 对话框

IMPLEMENT_DYNAMIC(Config, CDialogEx)

Config::Config(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_CONFIG, pParent)
	, 真实姓名(_T(""))
	, ID(000000)
	, MYNAME(_T(""))
	, CODE(0)
	, JOB(_T(""))
	, EMAIL(_T(""))
	, HOBBY(_T(""))
	, Advantage(_T(""))
{

}

Config::~Config()
{
}

void Config::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, 真实姓名);
	DDX_Text(pDX, IDC_EDIT_ID, ID);
	DDX_Text(pDX, IDC_EDIT_MYNAME, MYNAME);
	DDX_Text(pDX, IDC_EDIT4, CODE);
	DDX_Text(pDX, IDC_EDIT_JOB, JOB);
	DDX_Text(pDX, IDC_EDIT_EMAIL, EMAIL);
	DDX_Control(pDX, IDC_COMBO_SEX, SEX);
	DDX_Control(pDX, IDC_COMBO_YEAR, BIRTHYEAR);
	DDX_Control(pDX, IDC_COMBO_MONTH, BIRTHMONTH);
	DDX_Control(pDX, IDC_COMBO_DAY, BIRTHDAY);
	DDX_Text(pDX, IDC_EDIT_HOBBY, HOBBY);
	DDX_Text(pDX, IDC_EDIT_ADV, Advantage);
	DDX_Control(pDX, IDC_PROGRESS1, Condition);
	DDX_Control(pDX, IDC_BUTTON1, Conadd);
	DDX_Control(pDX, IDOK, Submit);
}


BEGIN_MESSAGE_MAP(Config, CDialogEx)
	ON_STN_CLICKED(IDC_STATIC_SEX, &Config::OnStnClickedStaticSex)
	ON_BN_CLICKED(IDC_BUTTON1, &Config::OnBnClickedButtonConadd)
	ON_BN_CLICKED(IDOK, &Config::OnBnClickedOkSubmit)
END_MESSAGE_MAP()


// Config 消息处理程序


void Config::OnStnClickedStaticSex()
{
	// TODO: 在此添加控件通知处理程序代码
}


BOOL Config::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	Condition.SetRange(0, 100);
	Condition.SetPos(0);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void Config::OnBnClickedButtonConadd()
{
	// TODO: 在此添加控件通知处理程序代码
	int nPos = Condition.GetPos();
	Condition.SetPos(nPos + 20);
	UpdateData(FALSE);
}


void Config::OnBnClickedOkSubmit()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(L"提交成功！");
	CDialogEx::OnOK();
}
