// BDeleteDataDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MyShop.h"
#include "BDeleteDataDlg.h"
#include "afxdialogex.h"

#include "buy.h"

// BDeleteDataDlg ��ȭ �����Դϴ�.

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


// BDeleteDataDlg �޽��� ó�����Դϴ�.


void BDeleteDataDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString Sbno;
	CString str;

	int bno;
	int i = 0;

	GetDlgItemText(IDC_BNO,Sbno);
	
	if(Sbno =="")
	{
		AfxMessageBox("��ǰ��ȣ�� �Է��Ͻÿ�");
		return;
	}

	bno = _ttoi(Sbno);
	
	Cbuy db;
	db.Connect();
	
	if(!db.Open())
	{
		AfxMessageBox("DB���� ����");
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
		AfxMessageBox("�����Ϳ� ���� ��ǰ�Դϴ�.");
		return;
	}

	str.Format("delete from buy where BNO = %d", bno);
	char * s = (LPSTR)(LPCTSTR)str;

	if(db.Execute(s) == FALSE)
	{
		AfxMessageBox("���� ����");
		return;
	}
	
	db.Close();
	CDialogEx::OnOK();
}
