// BInsertDataDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MyShop.h"
#include "BInsertDataDlg.h"
#include "afxdialogex.h"

#include "buy.h"

// BInsertDataDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(BInsertDataDlg, CDialogEx)

BInsertDataDlg::BInsertDataDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(BInsertDataDlg::IDD, pParent)
	, m_BNAME(_T(""))
	, m_BPRICE(_T(""))
	, m_BLOCATE(_T(""))
{

}

BInsertDataDlg::~BInsertDataDlg()
{
}

void BInsertDataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_BNANE, m_BNAME);
	DDX_Text(pDX, IDC_BPRICE, m_BPRICE);
	DDX_Text(pDX, IDC_BLOCATE, m_BLOCATE);
}


BEGIN_MESSAGE_MAP(BInsertDataDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &BInsertDataDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// BInsertDataDlg 메시지 처리기입니다.


void BInsertDataDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString bname;
	CString bprice;
	CString blocate;
	CString str;

	int bno;
	int i;

	GetDlgItemText(IDC_BNANE,bname);
	GetDlgItemText(IDC_BPRICE,bprice);
	GetDlgItemText(IDC_BLOCATE,blocate);

	if(bname =="")
	{
		AfxMessageBox("물품명을 입력하시오");
		return;
	}
	if(bprice =="")
	{
		AfxMessageBox("물품가격을 입력하시오");
		return;
	}
	if(blocate =="")
	{
		AfxMessageBox("구입장소를 입력하시오");
		return;
	}

	Cbuy db;
	db.Connect();

	if(!db.Open())
	{
		AfxMessageBox("DB접속 실패");
		return;
	}
	
	if(db.FetchNext() == FALSE)
	{
		bno = 1;
	}
	else
	{
		db.MoveLast();
		bno = ++db.m_BNO;
	}
	
	str.Format("insert into buy values(%d, '%s', '%s', '%s')", bno, bname, bprice, blocate);
	char * s = (LPSTR)(LPCTSTR)str;

	if(db.Execute(s) == FALSE)
	{
		AfxMessageBox("추가 실패");
		return;
	}
	
	db.Close();
	CDialogEx::OnOK();
}
