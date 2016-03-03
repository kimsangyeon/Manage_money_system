// BModifyDataDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MyShop.h"
#include "BModifyDataDlg.h"
#include "afxdialogex.h"

#include "buy.h"
#include "BuyDlg.h"

// BModifyDataDlg 대화 상자입니다.

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


// BModifyDataDlg 메시지 처리기입니다.


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
		
	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void BModifyDataDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
		AfxMessageBox("물품명을 입력하시오");
		return;
	}
	if(bprice =="")
	{
		AfxMessageBox("물품가격을 입력하시오");
		return;
	}
	if(blocate =="")
	{
		AfxMessageBox("구입장소를 입력하시오");
		return;
	}

	Cbuy db;
	db.Connect();

	if(!db.Open())
	{
		AfxMessageBox("DB접속 실패");
		return;
	}
	
	db.MoveLast();
	
	str.Format("update buy set BNAME='%s',BPRICE='%s',BLOCATE='%s' where BNO=%d", bname, bprice, blocate, bno);
	char * s = (LPSTR)(LPCTSTR)str;

	if(db.Execute(s) == FALSE)
	{
		AfxMessageBox("추가 실패");
		return;
	}
	
	db.Close();
	CDialogEx::OnOK();
}
