// IModifyDataDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MyShop.h"
#include "IModifyDataDlg.h"
#include "afxdialogex.h"

#include "income.h"
#include "IncomeDlg.h"
// IModifyDataDlg 대화 상자입니다.

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


// IModifyDataDlg 메시지 처리기입니다.


void IModifyDataDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
		AfxMessageBox("수입금을 입력하시오");
		return;
	}
	if(ilocate =="")
	{
		AfxMessageBox("수입장소를 입력하시오");
		return;
	}

	Cincome db;
	db.Connect();

	if(!db.Open())
	{
		AfxMessageBox("DB접속 실패");
		return;
	}
	
	db.MoveLast();
	
	str.Format("update income set IPRICE='%s',ILOCATE='%s' where INO=%d", iprice, ilocate, ino);
	char * s = (LPSTR)(LPCTSTR)str;

	if(db.Execute(s) == FALSE)
	{
		AfxMessageBox("추가 실패");
		return;
	}
	
	db.Close();
	CDialogEx::OnOK();
}


BOOL IModifyDataDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CString str;
	CIncomeDlg* dlg = (CIncomeDlg*)GetParent();

	dlg -> GetDlgItemText(IDC_EINO, str);
	SetDlgItemText(IDC_IMNO, str);

	dlg -> GetDlgItemText(IDC_EIPRICE, str);
	SetDlgItemText(IDC_IMPRICE, str);
	
	dlg -> GetDlgItemText(IDC_EILOCATE, str);
	SetDlgItemText(IDC_IMLOCATE, str);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
