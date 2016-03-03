// SDeleteDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MyShop.h"
#include "SDeleteDlg.h"
#include "afxdialogex.h"

#include "stats.h"

// SDeleteDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(SDeleteDlg, CDialogEx)

SDeleteDlg::SDeleteDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(SDeleteDlg::IDD, pParent)
	, m_SNO(0)
{

}

SDeleteDlg::~SDeleteDlg()
{
}

void SDeleteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_SNO);
}


BEGIN_MESSAGE_MAP(SDeleteDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &SDeleteDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// SDeleteDlg 메시지 처리기입니다.


void SDeleteDlg::OnBnClickedOk()
{
	CString Ssno;
	CString str;

	int sno;
	int i = 0;

	GetDlgItemText(IDC_EDIT1,Ssno);
	
	if(Ssno =="")
	{
		AfxMessageBox("삭제할 목록번호를 입력하시오");
		return;
	}

	sno = _ttoi(Ssno);
	
	Cstats db;
	db.Connect();
	
	if(!db.Open())
	{
		AfxMessageBox("DB접속 실패");
		return;
	}
	
	db.MoveFirst();

	while(!db.IsEOF())
	{
		if(sno == db.m_SNO)
		{	
			i=1;
			break;
		}
		db.MoveNext();
	}

	if(i != TRUE)
	{
		AfxMessageBox("데이터에 없는 목록입니다.");
		return;
	}

	str.Format("delete from stats where SNO = %d", sno);
	char * s = (LPSTR)(LPCTSTR)str;

	if(db.Execute(s) == FALSE)
	{
		AfxMessageBox("삭제 실패");
		return;
	}
	
	db.Close();
	CDialogEx::OnOK();
}
