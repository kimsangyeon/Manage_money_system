// BsaveDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MyShop.h"
#include "BsaveDlg.h"
#include "afxdialogex.h"

#include "stats.h"
#include "BuyDlg.h"

// CBsaveDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CBsaveDlg, CDialogEx)

CBsaveDlg::CBsaveDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBsaveDlg::IDD, pParent)
	, m_SBNO(_T(""))
	, m_SBNAME(_T(""))
	, m_SBPRICE(_T(""))
	, m_SBLOCATE(_T(""))
{

}

CBsaveDlg::~CBsaveDlg()
{
}

void CBsaveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SBNO, m_SBNO);
	DDX_Text(pDX, IDC_SBNAME, m_SBNAME);
	DDX_Text(pDX, IDC_SBPRICE, m_SBPRICE);
	DDX_Text(pDX, IDC_SBLOCATE, m_SBLOCATE);
}


BEGIN_MESSAGE_MAP(CBsaveDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CBsaveDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CBsaveDlg 메시지 처리기입니다.


BOOL CBsaveDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CString str;
	CBuyDlg* dlg = (CBuyDlg*)GetParent();

	dlg -> GetDlgItemText(IDC_ENO, str);
	SetDlgItemText(IDC_SBNO, str);
	
	dlg -> GetDlgItemText(IDC_ENAME, str);
	SetDlgItemText(IDC_SBNAME, str);
	
	dlg -> GetDlgItemText(IDC_EPRICE, str);
	SetDlgItemText(IDC_SBPRICE, str);
	
	dlg -> GetDlgItemText(IDC_ELOCATE, str);
	SetDlgItemText(IDC_SBLOCATE, str);
		
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CBsaveDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString bday;
	CString sbno;
	CString str;
	
	int index;
	int sno = 1;
	int bno;

	GetDlgItemText(IDC_SBNO, sbno);
	GetDlgItemText(IDC_DATETIMEPICKER1, bday);

	bno = _ttoi(sbno);

	if(bday =="")
	{
		AfxMessageBox("날짜를 입력하시오");
		return;
	}

	Cstats db;
	db.Connect();

	if(!db.Open())
	{
		AfxMessageBox("DB접속 실패");
		return;
	}
	if(db.FetchNext() == FALSE)
	{
		sno = 1;
	}
	else
	{
		db.MoveLast();
		sno = ++db.m_SNO;
	}

	str.Format("insert into stats values(%d,'%s', %d, %s)", sno, bday, bno, NULL);
	char * s = (LPSTR)(LPCTSTR)str;

	if(db.Execute(s) == FALSE)
	{
		AfxMessageBox("추가 실패");
		return;
	}
	
	db.Close();
	CDialogEx::OnOK();
}
