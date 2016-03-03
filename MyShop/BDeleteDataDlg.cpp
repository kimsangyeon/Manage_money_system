// BDeleteDataDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MyShop.h"
#include "BDeleteDataDlg.h"
#include "afxdialogex.h"

#include "buy.h"

// BDeleteDataDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(BDeleteDataDlg, CDialogEx)

BDeleteDataDlg::BDeleteDataDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(BDeleteDataDlg::IDD, pParent)
	, m_BNO(_T(""))
{

}

BDeleteDataDlg::~BDeleteDataDlg()
{
}

void BDeleteDataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_BNO, m_BNO);
}


BEGIN_MESSAGE_MAP(BDeleteDataDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &BDeleteDataDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// BDeleteDataDlg 메시지 처리기입니다.


void BDeleteDataDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString Sbno;
	CString str;

	int bno;
	int i = 0;

	GetDlgItemText(IDC_BNO,Sbno);
	
	if(Sbno =="")
	{
		AfxMessageBox("물품번호를 입력하시오");
		return;
	}

	bno = _ttoi(Sbno);
	
	Cbuy db;
	db.Connect();
	
	if(!db.Open())
	{
		AfxMessageBox("DB접속 실패");
		return;
	}
	
	db.MoveFirst();

	while(!db.IsEOF())
	{
		if(bno == db.m_BNO)
		{	
			i=1;
			break;
		}
		db.MoveNext();
	}

	if(i != TRUE)
	{
		AfxMessageBox("데이터에 없는 물품입니다.");
		return;
	}

	str.Format("delete from buy where BNO = %d", bno);
	char * s = (LPSTR)(LPCTSTR)str;

	if(db.Execute(s) == FALSE)
	{
		AfxMessageBox("삭제 실패");
		return;
	}
	
	db.Close();
	CDialogEx::OnOK();
}
