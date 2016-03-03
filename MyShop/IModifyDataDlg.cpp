// IModifyDataDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MyShop.h"
#include "IModifyDataDlg.h"
#include "afxdialogex.h"

#include "income.h"
#include "IncomeDlg.h"
// IModifyDataDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(IModifyDataDlg, CDialogEx)

IModifyDataDlg::IModifyDataDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IModifyDataDlg::IDD, pParent)
	, m_IMNO(_T(""))
	, m_IMPRICE(_T(""))
	, m_IMLOCATE(_T(""))
{

}

IModifyDataDlg::~IModifyDataDlg()
{
}

void IModifyDataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_IMNO, m_IMNO);
	DDX_Text(pDX, IDC_IMPRICE, m_IMPRICE);
	DDX_Text(pDX, IDC_IMLOCATE, m_IMLOCATE);
}


BEGIN_MESSAGE_MAP(IModifyDataDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &IModifyDataDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// IModifyDataDlg �޽��� ó�����Դϴ�.


void IModifyDataDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString sino;
	CString iprice;
	CString ilocate;
	CString str;

	int ino;
	int i;

	GetDlgItemText(IDC_IMNO, sino);
	GetDlgItemText(IDC_IMPRICE, iprice);
	GetDlgItemText(IDC_IMLOCATE, ilocate);

	ino = _ttoi(sino);

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
	
	db.MoveLast();
	
	str.Format("update income set IPRICE='%s',ILOCATE='%s' where INO=%d", iprice, ilocate, ino);
	char * s = (LPSTR)(LPCTSTR)str;

	if(db.Execute(s) == FALSE)
	{
		AfxMessageBox("�߰� ����");
		return;
	}
	
	db.Close();
	CDialogEx::OnOK();
}


BOOL IModifyDataDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	CString str;
	CIncomeDlg* dlg = (CIncomeDlg*)GetParent();

	dlg -> GetDlgItemText(IDC_EINO, str);
	SetDlgItemText(IDC_IMNO, str);

	dlg -> GetDlgItemText(IDC_EIPRICE, str);
	SetDlgItemText(IDC_IMPRICE, str);
	
	dlg -> GetDlgItemText(IDC_EILOCATE, str);
	SetDlgItemText(IDC_IMLOCATE, str);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
