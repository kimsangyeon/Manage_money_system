// SDeleteDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MyShop.h"
#include "SDeleteDlg.h"
#include "afxdialogex.h"

#include "stats.h"

// SDeleteDlg ��ȭ �����Դϴ�.

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


// SDeleteDlg �޽��� ó�����Դϴ�.


void SDeleteDlg::OnBnClickedOk()
{
	CString Ssno;
	CString str;

	int sno;
	int i = 0;

	GetDlgItemText(IDC_EDIT1,Ssno);
	
	if(Ssno =="")
	{
		AfxMessageBox("������ ��Ϲ�ȣ�� �Է��Ͻÿ�");
		return;
	}

	sno = _ttoi(Ssno);
	
	Cstats db;
	db.Connect();
	
	if(!db.Open())
	{
		AfxMessageBox("DB���� ����");
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
		AfxMessageBox("�����Ϳ� ���� ����Դϴ�.");
		return;
	}

	str.Format("delete from stats where SNO = %d", sno);
	char * s = (LPSTR)(LPCTSTR)str;

	if(db.Execute(s) == FALSE)
	{
		AfxMessageBox("���� ����");
		return;
	}
	
	db.Close();
	CDialogEx::OnOK();
}
