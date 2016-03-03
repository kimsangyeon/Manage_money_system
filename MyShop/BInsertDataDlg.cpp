// BInsertDataDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MyShop.h"
#include "BInsertDataDlg.h"
#include "afxdialogex.h"

#include "buy.h"

// BInsertDataDlg ��ȭ �����Դϴ�.

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


// BInsertDataDlg �޽��� ó�����Դϴ�.


void BInsertDataDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
		AfxMessageBox("��ǰ���� �Է��Ͻÿ�");
		return;
	}
	if(bprice =="")
	{
		AfxMessageBox("��ǰ������ �Է��Ͻÿ�");
		return;
	}
	if(blocate =="")
	{
		AfxMessageBox("������Ҹ� �Է��Ͻÿ�");
		return;
	}

	Cbuy db;
	db.Connect();

	if(!db.Open())
	{
		AfxMessageBox("DB���� ����");
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
		AfxMessageBox("�߰� ����");
		return;
	}
	
	db.Close();
	CDialogEx::OnOK();
}
