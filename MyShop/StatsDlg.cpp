// StatsDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MyShop.h"
#include "StatsDlg.h"
#include "afxdialogex.h"

#include "stats.h"
#include "SDeleteDlg.h"

// CStatsDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CStatsDlg, CDialogEx)

CStatsDlg::CStatsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStatsDlg::IDD, pParent)
	, m_TIncome(_T(""))
	, m_TExpense(_T(""))
	, m_MONEY(_T(""))
{

}

CStatsDlg::~CStatsDlg()
{
}

void CStatsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_SList);
	DDX_Text(pDX, IDC_TINCOME, m_TIncome);
	DDX_Text(pDX, IDC_TEXPENSE, m_TExpense);
	DDX_Text(pDX, IDC_MONEY, m_MONEY);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_Starttime);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_Endtime);
}

int CStatsDlg::ShowTable()
{
	Cstats db;
	
	if(!db.Open())
		return ERROR_CONNECTION_UNAVAIL;

	m_SList.DeleteAllItems();

	int i = 0;
	int total_income = 0;
	int total_expense = 0;
	int money = 0;

	CString str;
	CString instr;
	CString outstr;

	while(!db.IsEOF())
	{
		str.Format(_T("%d"), db.m_SNO);
		m_SList.InsertItem(i, str);

		m_SList.SetItemText(i, 1, db.m_SMONTH);
		m_SList.SetItemText(i, 2, db.m_BNAME);
		m_SList.SetItemText(i, 3, db.m_BPRICE);
		m_SList.SetItemText(i, 4, db.m_BLOCATE);
		m_SList.SetItemText(i, 5, db.m_IPRICE);
		m_SList.SetItemText(i, 6, db.m_ILOCATE);

		total_income += _ttoi(db.m_IPRICE);
		total_expense += _ttoi(db.m_BPRICE);

		db.MoveNext();
		i++;
	}
	
	money = total_income - total_expense;

	instr.Format("%d", total_income);
	outstr.Format("%d", total_expense);
	str.Format("%d", money);

	SetDlgItemText(IDC_TINCOME, instr);
	SetDlgItemText(IDC_TEXPENSE, outstr);
	SetDlgItemText(IDC_MONEY, str);

	db.Close();
	return S_OK;
}
BEGIN_MESSAGE_MAP(CStatsDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CStatsDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CStatsDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CStatsDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CStatsDlg 메시지 처리기입니다.


BOOL CStatsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_SList.InsertColumn(0, ("SNO"), LVCFMT_CENTER, 80);
	m_SList.InsertColumn(1, ("MONTH"), LVCFMT_CENTER, 80);
	m_SList.InsertColumn(2, ("BNAME"), LVCFMT_CENTER, 80);
	m_SList.InsertColumn(3, ("BPRICE"), LVCFMT_CENTER, 80);
	m_SList.InsertColumn(4, ("BLOCATE"), LVCFMT_CENTER, 80);
	m_SList.InsertColumn(5, ("IPRICE"), LVCFMT_CENTER, 80);
	m_SList.InsertColumn(6, ("ILOCATE"), LVCFMT_CENTER, 80);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CStatsDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ShowTable();
}


void CStatsDlg::OnBnClickedButton2()
{
	CString startday,endday;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CTime first,end;
	CTimeSpan elepesd;
	m_Starttime.GetTime(first);
	m_Endtime.GetTime(end);
	elepesd=end-first;
	if(elepesd.GetDays()<0)
	{
		AfxMessageBox("검색시작일이 종료일보다 큽니다");
		return;
	}

	GetDlgItemText(IDC_DATETIMEPICKER1,startday);
	GetDlgItemText(IDC_DATETIMEPICKER2,endday);

	
	m_SList.DeleteAllItems();

	int i = 0;
	int total_income = 0;
	int total_expense = 0;
	int money = 0;

	CString str;
	CString instr;
	CString outstr;

	Cstats db;
	db.Connect();

	if(!db.Open())
	{
		AfxMessageBox("DB접속 실패");
		return;
	}
	
	str.Format("select * from stats where SMONTH >='%s' and SMONTH<='%s'",startday,endday);
	char * s = (LPSTR)(LPCTSTR)str;

	if(db.Execute(s) == FALSE)
	{
		AfxMessageBox("SELECT실패");
		return;
	}
	
	while(!db.IsEOF())
	{
		if(db.m_SMONTH >= startday && db.m_SMONTH <= endday)
		{
			str.Format(_T("%d"), db.m_SNO);
			m_SList.InsertItem(i, str);
			
			m_SList.SetItemText(i, 1, db.m_SMONTH);
			m_SList.SetItemText(i, 2, db.m_BNAME);
			m_SList.SetItemText(i, 3, db.m_BPRICE);
			m_SList.SetItemText(i, 4, db.m_BLOCATE);
			m_SList.SetItemText(i, 5, db.m_IPRICE);
			m_SList.SetItemText(i, 6, db.m_ILOCATE);
		
			total_income += _ttoi(db.m_IPRICE);
			total_expense += _ttoi(db.m_BPRICE);
			i++;	
		}
		db.MoveNext();
			
	}
	
	money = total_income - total_expense;

	instr.Format("%d", total_income);
	outstr.Format("%d", total_expense);
	str.Format("%d", money);

	SetDlgItemText(IDC_TINCOME, instr);
	SetDlgItemText(IDC_TEXPENSE, outstr);
	SetDlgItemText(IDC_MONEY, str);

	db.Close();
}


void CStatsDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SDeleteDlg dlg;
	dlg.DoModal();
}
