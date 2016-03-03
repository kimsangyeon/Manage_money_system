// BModifyDataDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MyShop.h"
#include "BModifyDataDlg.h"
#include "afxdialogex.h"

#include "buy.h"
#include "BuyDlg.h"

// BModifyDataDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(BModifyDataDlg, CDialogEx)

BModifyDataDlg::BModifyDataDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(BModifyDataDlg::IDD, pParent)
	, m_BMNO(_T(""))
	, m_BMNAME(_T(""))
	, m_BMPRICE(_T(""))
	, m_BMLOCATE(_T(""))
{

}

BModifyDataDlg::~BModifyDataDlg()
{
}

void BModifyDataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_BMNO, m_BMNO);
	DDX_Text(pDX, IDC_BMNAME, m_BMNAME);
	DDX_Text(pDX, IDC_BMPRICE, m_BMPRICE);
	DDX_Text(pDX, IDC_BMLOCATE, m_BMLOCATE);
}


BEGIN_MESSAGE_MAP(BModifyDataDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &BModifyDataDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// BModifyDataDlg �޽��� ó�����Դϴ�.


BOOL BModifyDataDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CString str;
	CBuyDlg* dlg = (CBuyDlg*)GetParent();

	dlg -> GetDlgItemText(IDC_ENO, str);
	SetDlgItemText(IDC_BMNO, str);
	
	dlg -> GetDlgItemText(IDC_ENAME, str);
	SetDlgItemText(IDC_BMNAME, str);
	
	dlg -> GetDlgItemText(IDC_EPRICE, str);
	SetDlgItemText(IDC_BMPRICE, str);
	
	dlg -> GetDlgItemText(IDC_ELOCATE, str);
	SetDlgItemText(IDC_BMLOCATE, str);
		
	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void BModifyDataDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString sbno;
	CString bname;
	CString bprice;
	CString blocate;
	CString str;

	int bno;
	int i;

	GetDlgItemText(IDC_BMNO,sbno);
	GetDlgItemText(IDC_BMNAME,bname);
	GetDlgItemText(IDC_BMPRICE,bprice);
	GetDlgItemText(IDC_BMLOCATE,blocate);

	bno = _ttoi(sbno);

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
	
	db.MoveLast();
	
	str.Format("update buy set BNAME='%s',BPRICE='%s',BLOCATE='%s' where BNO=%d", bname, bprice, blocate, bno);
	char * s = (LPSTR)(LPCTSTR)str;

	if(db.Execute(s) == FALSE)
	{
		AfxMessageBox("�߰� ����");
		return;
	}
	
	db.Close();
	CDialogEx::OnOK();
}
