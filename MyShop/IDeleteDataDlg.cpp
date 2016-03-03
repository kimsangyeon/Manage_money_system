// IDeleteDataDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MyShop.h"
#include "IDeleteDataDlg.h"
#include "afxdialogex.h"

#include "income.h"

// IDeleteDataDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(IDeleteDataDlg, CDialogEx)

IDeleteDataDlg::IDeleteDataDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDeleteDataDlg::IDD, pParent)
	, m_INO(_T(""))
{

}

IDeleteDataDlg::~IDeleteDataDlg()
{
}

void IDeleteDataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_INO, m_INO);
}


BEGIN_MESSAGE_MAP(IDeleteDataDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &IDeleteDataDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// IDeleteDataDlg 메시지 처리기입니다.


void IDeleteDataDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString Sino;
	CString str;

	int ino;
	int i = 0;

	GetDlgItemText(IDC_INO,Sino);
	
	if(Sino =="")
	{
		AfxMessageBox("물품번호를 입력하시오");
		return;
	}

	ino = _ttoi(Sino);
	
	Cincome db;
	db.Connect();
	
	if(!db.Open())
	{
		AfxMessageBox("DB접속 실패");
		return;
	}
	
	db.MoveFirst();

	while(!db.IsEOF())
	{
		if(ino == db.m_INO)
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

	str.Format("delete from income where INO = %d", ino);
	char * s = (LPSTR)(LPCTSTR)str;

	if(db.Execute(s) == FALSE)
	{
		AfxMessageBox("삭제 실패");
		return;
	}
	
	db.Close();
	CDialogEx::OnOK();
}
