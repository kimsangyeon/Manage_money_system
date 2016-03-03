// IInsertDataDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MyShop.h"
#include "IInsertDataDlg.h"
#include "afxdialogex.h"

#include "income.h"
// IInsertDataDlg ��ȭ �����Դϴ�.

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


// IInsertDataDlg �޽��� ó�����Դϴ�.


void IInsertDataDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString iprice;
	CString ilocate;
	CString str;

	int ino;
	int i;

	GetDlgItemText(IDC_IPRICE,iprice);
	GetDlgItemText(IDC_ILOCATE,ilocate);

	if(iprice =="")
	{
		AfxMessageBox("���Ա��� �Է��Ͻÿ�");
		return;
	}
	if(ilocate =="")
	{
		AfxMessageBox("������Ҹ� �Է��Ͻÿ�");
		return;
	}

	Cincome db;
	db.Connect();

	if(!db.Open())
	{
		AfxMessageBox("DB���� ����");
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
		AfxMessageBox("�߰� ����");
		return;
	}
	
	db.Close();
	CDialogEx::OnOK();
}
