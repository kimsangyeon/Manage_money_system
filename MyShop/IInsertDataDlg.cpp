// IInsertDataDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MyShop.h"
#include "IInsertDataDlg.h"
#include "afxdialogex.h"

#include "income.h"
// IInsertDataDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(IInsertDataDlg, CDialogEx)

IInsertDataDlg::IInsertDataDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IInsertDataDlg::IDD, pParent)
	, m_IPRICE(_T(""))
	, m_ILOCATE(_T(""))
{

}

IInsertDataDlg::~IInsertDataDlg()
{
}

void IInsertDataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_IPRICE, m_IPRICE);
	DDX_Text(pDX, IDC_ILOCATE, m_ILOCATE);
}


BEGIN_MESSAGE_MAP(IInsertDataDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &IInsertDataDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// IInsertDataDlg 메시지 처리기입니다.


void IInsertDataDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString iprice;
	CString ilocate;
	CString str;

	int ino;
	int i;

	GetDlgItemText(IDC_IPRICE,iprice);
	GetDlgItemText(IDC_ILOCATE,ilocate);

	if(iprice =="")
	{
		AfxMessageBox("수입금을 입력하시오");
		return;
	}
	if(ilocate =="")
	{
		AfxMessageBox("수입장소를 입력하시오");
		return;
	}

	Cincome db;
	db.Connect();

	if(!db.Open())
	{
		AfxMessageBox("DB접속 실패");
		return;
	}
	
	if(db.FetchNext() == FALSE)
	{
		ino = 1;
	}
	else
	{
		db.MoveLast();
		ino = ++db.m_INO;
	}
	
	str.Format("insert into income values(%d, '%s', '%s')", ino, iprice, ilocate);
	char * s = (LPSTR)(LPCTSTR)str;

	if(db.Execute(s) == FALSE)
	{
		AfxMessageBox("추가 실패");
		return;
	}
	
	db.Close();
	CDialogEx::OnOK();
}
