// stats.h : Cstats Ŭ������ �����Դϴ�.

// Cstats �����Դϴ�.

// �ڵ� ���� ��ġ 2013�� 6�� 9�� �Ͽ���, ���� 2:44

#include "stdafx.h"
#include "stats.h"
IMPLEMENT_DYNAMIC(Cstats, CRecordset)

Cstats::Cstats(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_SNO = 0;
	m_SMONTH = "";
	m_BNO = 0;
	m_INO = 0;
	
	m_BNAME = "";
	m_BPRICE = "";
	m_BLOCATE = "";

	m_IPRICE = "";
	m_ILOCATE = "";

	m_hEnv = NULL;
	m_hStmt = NULL;
	m_hDbc = NULL;

	m_nFields = 7;
	m_nDefaultType = snapshot;
}
//#error ���� ����: ���� ���ڿ��� ��ȣ�� ���ԵǾ� ���� �� �ֽ��ϴ�.
// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.
CString Cstats::GetDefaultConnect()
{
	return _T("DSN=Stats;DESCRIPTION=Stats table in MyShop;SERVER=localhost;UID=root;PWD=apmsetup;DATABASE=myshop;PORT=3306");
}

CString Cstats::GetDefaultSQL()
{
	return _T("select stats.SNO, stats.SMONTH, buy.BNAME, buy.BPRICE, buy.BLOCATE, income.IPRICE, income.ILOCATE\
			  from stats left join buy on stats.BNO = buy.BNO left join income on stats.INO = income.INO");
}

void Cstats::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() ���� ��ũ�δ� �����ͺ��̽��� �ʵ�
// ������ �ƴ϶� ��� ������ ���Ŀ� ���� �޶����ϴ�.
// ODBC������ �ڵ����� �� ���� ��û�� �������� ��ȯ�Ϸ��� �մϴ�
	
	RFX_Long(pFX, _T("[SNO]"), m_SNO);
	RFX_Text(pFX, _T("[SMONTH]"), m_SMONTH);
	RFX_Text(pFX, _T("[BNANE]"), m_BNAME);
	RFX_Text(pFX, _T("[BPRICE]"), m_BPRICE);
	RFX_Text(pFX, _T("[BLOCATE]"), m_BLOCATE);
	RFX_Text(pFX, _T("[IPRICE]"), m_IPRICE);
	RFX_Text(pFX, _T("[ILOCATE]"), m_ILOCATE);
}
/////////////////////////////////////////////////////////////////////////////
// Cstats ����

BOOL Cstats::Execute(LPCTSTR szSQL)
{
	SQLRETURN ret;
	
	ret = SQLExecDirect(m_hStmt, (SQLCHAR *)szSQL, SQL_NTS);

	if((ret != SQL_SUCCESS) && (ret != SQL_SUCCESS_WITH_INFO) && (ret != SQL_NO_DATA))
	{
		AfxMessageBox("DB�߰� ����");
		return FALSE;
	}
	return TRUE;
}

void Cstats::Connect()
{
	SQLRETURN ret;
		
	if(SQL_ERROR == SQLAllocEnv(&m_hEnv))
	{
		AfxMessageBox("ȯ�� ���� �Ҵ� ����");
		return;
	}

	if(SQL_ERROR == SQLAllocConnect(m_hEnv, &m_hDbc))
	{
		SQLFreeEnv(m_hEnv);
		m_hEnv = NULL;
		AfxMessageBox("���� �Ҵ� ����");
		return;
	}
	// HDBC, ODBC ���� �̸�. ���̵�, �н�����
	ret= SQLConnect(m_hDbc, (SQLCHAR *) "stats", SQL_NTS,
		(SQLCHAR *) "root", SQL_NTS,
		(SQLCHAR *) "apmsetup", SQL_NTS);

	// ���� ���� ����
	if(ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO)
	{
		if(m_hDbc != SQL_NULL_HDBC) { SQLFreeConnect(m_hDbc); m_hDbc = NULL; };
		if(m_hEnv != SQL_NULL_HENV) { SQLFreeEnv(m_hEnv); m_hEnv = NULL; };
		AfxMessageBox("���� ���� ����");
		return;

	}

	if(SQLAllocHandle(SQL_HANDLE_STMT, m_hDbc, &m_hStmt) != SQL_SUCCESS)
	{
		if(m_hDbc)
		{
			SQLDisconnect(m_hDbc);
			SQLFreeHandle(SQL_HANDLE_DBC, m_hDbc);
			m_hDbc = NULL;
		}
		if(m_hEnv)
		{
			SQLFreeHandle(SQL_HANDLE_ENV, m_hEnv);
			m_hEnv = NULL;
		}
		AfxMessageBox("�ڵ� �Ҵ� ����");
		return;
	}

	// �������� ���ε�
	
	if(ret != SQL_SUCCESS)
	{
		if(m_hDbc)
		{
			SQLDisconnect(m_hDbc);
			SQLFreeHandle(SQL_HANDLE_DBC, m_hDbc);
			m_hDbc = NULL;
		}
		if(m_hEnv){SQLFreeHandle(SQL_HANDLE_ENV, m_hEnv); m_hEnv = NULL; };
		AfxMessageBox("���� ���ε� ����");
		return;
	}
}

#ifdef _DEBUG
void Cstats::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cstats::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


