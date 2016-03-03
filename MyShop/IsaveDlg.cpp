// IsaveDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MyShop.h"
#include "IsaveDlg.h"
#include "afxdialogex.h"

#include "stats.h"
#include "IncomeDlg.h"

// IsaveDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(IsaveDlg, CDialogEx)

IsaveDlg::IsaveDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IsaveDlg::IDD, pParent)
	, m_SINO(_T(""))
	, m_SIPRICE(_T(""))
	, m_SILOCATE(_T(""))
{

}

IsaveDlg::~IsaveDlg()
{
}

void IsaveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SINO, m_SINO);
	DDX_Text(pDX, IDC_SIPRICE, m_SIPRICE);
	DDX_Text(pDX, IDC_SILOCATE, m_SILOCATE);
}


BEGIN_MESSAGE_MAP(IsaveDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &IsaveDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// IsaveDlg 메시지 처리기입니다.


BOOL IsaveDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CString str;
	CIncomeDlg* dlg = (CIncomeDlg*)GetParent();

	dlg -> GetDlgItemText(IDC_EINO, str);
	SetDlgItemText(IDC_SINO, str);

	dlg -> GetDlgItemText(IDC_EIPRICE, str);
	SetDlgItemText(IDC_SIPRICE, str);
	
	dlg -> GetDlgItemText(IDC_EILOCATE, str);
	SetDlgItemText(IDC_SILOCATE, str);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void IsaveDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString Iday;
	CString sino;
	CString str;
	
	int index;
	int sno = 1;
	int ino;

	GetDlgItemText(IDC_SINO, sino);
	GetDlgItemText(IDC_IDATETIMEPICKER, Iday);

	ino = _ttoi(sino);

	if(Iday =="")
	{
		AfxMessageBox("날짜를 입력하시오");
		return;
	}

	Cstats db;
	db.Connect();

	if(!db.Open())
	{
		AfxMessageBox("DB접속 실패");
		return;
	}

	if(db.FetchNext() == FALSE)
	{
		sno = 1;
	}
	else
	{
		db.MoveLast();
		sno = ++db.m_SNO;
	}

	str.Format("insert into stats values(%d,'%s', %s, %d)", sno, Iday, NULL, ino);
	char * s = (LPSTR)(LPCTSTR)str;

	if(db.Execute(s) == FALSE)
	{
		AfxMessageBox("추가 실패");
		return;
	}
	
	db.Close();
	CDialogEx::OnOK();
}
