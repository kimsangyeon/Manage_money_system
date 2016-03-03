// BuyDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MyShop.h"
#include "BuyDlg.h"
#include "afxdialogex.h"

#include "buy.h"
#include "BInsertDataDlg.h"
#include "BDeleteDataDlg.h"
#include "BModifyDataDlg.h"
#include "BsaveDlg.h"


// CBuyDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CBuyDlg, CDialogEx)

CBuyDlg::CBuyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBuyDlg::IDD, pParent)

	, m_ENAME(_T(""))
	, m_EPRICE(_T(""))
	, m_ELOCATE(_T(""))
	, m_ENO(_T(""))
{

}

CBuyDlg::~CBuyDlg()
{
}

void CBuyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_BList);

	DDX_Text(pDX, IDC_ENAME, m_ENAME);
	DDX_Text(pDX, IDC_EPRICE, m_EPRICE);
	DDX_Text(pDX, IDC_ELOCATE, m_ELOCATE);
	DDX_Text(pDX, IDC_ENO, m_ENO);
}



BEGIN_MESSAGE_MAP(CBuyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CBuyDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CBuyDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CBuyDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CBuyDlg::OnBnClickedButton3)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CBuyDlg::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON5, &CBuyDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CBuyDlg 메시지 처리기입니다.

BOOL CBuyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	m_BList.InsertColumn(0, ("BNO"), LVCFMT_CENTER, 80);
	m_BList.InsertColumn(1, ("BNAME"), LVCFMT_CENTER, 80);
	m_BList.InsertColumn(2, ("BPRICE"), LVCFMT_CENTER, 80);
	m_BList.InsertColumn(3, ("BLOCATE"), LVCFMT_CENTER, 80);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

int CBuyDlg::ShowTable()
{
	Cbuy db;

	if(!db.Open())
		return ERROR_CONNECTION_UNAVAIL;

	m_BList.DeleteAllItems();

	int i = 0;
	CString str;

	while(!db.IsEOF())
	{
		str.Format(("%d"), db.m_BNO);
		m_BList.InsertItem(i, str);

		m_BList.SetItemText(i, 1, db.m_BNAME);
		m_BList.SetItemText(i, 2, db.m_BPRICE);
		m_BList.SetItemText(i, 3, db.m_BLOCATE);
				
		db.MoveNext();
		i++;
	}

	db.Close();
	return S_OK;

}

void CBuyDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ShowTable();
}

void CBuyDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	BInsertDataDlg dlg;
	dlg.DoModal();
}


void CBuyDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	BDeleteDataDlg dlg;
	CString str = "";

	GetDlgItemText(IDC_ENO, str);

	if(str == "")
	{
		AfxMessageBox("수정 항목을 선택하세요");
		return;
	}

	dlg.DoModal();
}

void CBuyDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	BModifyDataDlg dlg;
	dlg.DoModal();
}

void CBuyDlg::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CBsaveDlg dlg;
	CString str = "";

	GetDlgItemText(IDC_ENO, str);

	if(str == "")
	{
		AfxMessageBox("저장 항목을 선택하세요");
		return;
	}

	dlg.DoModal();
}

void CBuyDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	m_BList.SetExtendedStyle( LVS_EX_FULLROWSELECT );
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if(pNMLV -> uChanged&LVIF_STATE)
	{
		if(pNMLV->uNewState&(LVIS_SELECTED|LVIS_FOCUSED))
		{
			CString str;
			
			str=m_BList.GetItemText(pNMLV->iItem,0);
			SetDlgItemText(IDC_ENO,str);
			
			str=m_BList.GetItemText(pNMLV->iItem,1);
			SetDlgItemText(IDC_ENAME,str);
			
			str=m_BList.GetItemText(pNMLV->iItem,2);
			SetDlgItemText(IDC_EPRICE,str);
			
			str=m_BList.GetItemText(pNMLV->iItem,3);
			SetDlgItemText(IDC_ELOCATE,str);
		}
	}

	*pResult = 0;
}


