// IncomeDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MyShop.h"
#include "IncomeDlg.h"
#include "afxdialogex.h"

#include "income.h"
#include "IInsertDataDlg.h"
#include "IDeleteDataDlg.h"
#include "IModifyDataDlg.h"
#include "IsaveDlg.h"

// CIncomeDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CIncomeDlg, CDialogEx)

CIncomeDlg::CIncomeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CIncomeDlg::IDD, pParent)
	, m_EINO(_T(""))
	, m_EIPRICE(_T(""))
	, m_EILOCATE(_T(""))
{

}

CIncomeDlg::~CIncomeDlg()
{
}

void CIncomeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_IList);
	DDX_Text(pDX, IDC_EINO, m_EINO);
	DDX_Text(pDX, IDC_EIPRICE, m_EIPRICE);
	DDX_Text(pDX, IDC_EILOCATE, m_EILOCATE);
}

BEGIN_MESSAGE_MAP(CIncomeDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CIncomeDlg::OnBnClickedButton1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CIncomeDlg::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON2, &CIncomeDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CIncomeDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CIncomeDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CIncomeDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CIncomeDlg 메시지 처리기입니다.
int CIncomeDlg::ShowTable()
{
	
	Cincome db;

	if(!db.Open())
		return ERROR_CONNECTION_UNAVAIL;

	m_IList.DeleteAllItems();

	int i = 0;
	CString str;

	while(!db.IsEOF())
	{
		str.Format(("%d"), db.m_INO);
		m_IList.InsertItem(i, str);

		m_IList.SetItemText(i, 1, db.m_IPRICE);
		m_IList.SetItemText(i, 2, db.m_ILOCATE);
				
		db.MoveNext();
		i++;
	}

	db.Close();
	return S_OK;

}

void CIncomeDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ShowTable();
}


BOOL CIncomeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_IList.SetExtendedStyle( LVS_EX_FULLROWSELECT );

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_IList.InsertColumn(0, ("INO"), LVCFMT_CENTER, 80);
	m_IList.InsertColumn(1, ("IPRICE"), LVCFMT_CENTER, 80);
	m_IList.InsertColumn(2, ("ILOCATE"), LVCFMT_CENTER, 80);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CIncomeDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if(pNMLV -> uChanged&LVIF_STATE)
	{
		if(pNMLV->uNewState&(LVIS_SELECTED|LVIS_FOCUSED))
		{
			CString str;
			
			str=m_IList.GetItemText(pNMLV->iItem,0);
			SetDlgItemText(IDC_EINO,str);
			
			str=m_IList.GetItemText(pNMLV->iItem,1);
			SetDlgItemText(IDC_EIPRICE,str);
			
			str=m_IList.GetItemText(pNMLV->iItem,2);
			SetDlgItemText(IDC_EILOCATE,str);
		}
	}
	*pResult = 0;
}


void CIncomeDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	IInsertDataDlg dlg;
	dlg.DoModal();
}


void CIncomeDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	IDeleteDataDlg dlg;
	dlg.DoModal();
}


void CIncomeDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	IModifyDataDlg dlg;
	CString str = "";

	GetDlgItemText(IDC_EINO, str);

	if(str == "")
	{
		AfxMessageBox("수정할 항목을 선택하세요");
		return;
	}

	dlg.DoModal();
}


void CIncomeDlg::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	IsaveDlg dlg;
	CString str = "";

	GetDlgItemText(IDC_EINO, str);

	if(str == "")
	{
		AfxMessageBox("저장할 항목을 선택하세요");
		return;
	}

	dlg.DoModal();
}
