// IDeleteDataDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MyShop.h"
#include "IDeleteDataDlg.h"
#include "afxdialogex.h"

#include "income.h"

// IDeleteDataDlg ��ȭ �����Դϴ�.

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


// IDeleteDataDlg �޽��� ó�����Դϴ�.


void IDeleteDataDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString Sino;
	CString str;

	int ino;
	int i = 0;

	GetDlgItemText(IDC_INO,Sino);
	
	if(Sino =="")
	{
		AfxMessageBox("��ǰ��ȣ�� �Է��Ͻÿ�");
		return;
	}

	ino = _ttoi(Sino);
	
	Cincome db;
	db.Connect();
	
	if(!db.Open())
	{
		AfxMessageBox("DB���� ����");
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
		AfxMessageBox("�����Ϳ� ���� ����Դϴ�.");
		return;
	}

	str.Format("delete from income where INO = %d", ino);
	char * s = (LPSTR)(LPCTSTR)str;

	if(db.Execute(s) == FALSE)
	{
		AfxMessageBox("���� ����");
		return;
	}
	
	db.Close();
	CDialogEx::OnOK();
}
