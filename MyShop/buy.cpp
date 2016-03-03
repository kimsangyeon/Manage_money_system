// buy.h : Cbuy Ŭ������ �����Դϴ�.



// Cbuy �����Դϴ�.

// �ڵ� ���� ��ġ 2013�� 6�� 8�� �����, ���� 4:19

#include "stdafx.h"
#include "buy.h"
IMPLEMENT_DYNAMIC(Cbuy, CRecordset)

Cbuy::Cbuy(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_BNO = 0;
	m_BNAME = "";
	m_BPRICE = "";
	m_BLOCATE = "";

	m_hEnv = NULL;
	m_hStmt = NULL;
	m_hDbc = NULL;

	m_nFields = 4;
	m_nDefaultType = snapshot;
}
//#error ���� ����: ���� ���ڿ��� ��ȣ�� ���ԵǾ� ���� �� �ֽ��ϴ�.
// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.
CString Cbuy::GetDefaultConnect()
{
	return _T("DSN=Buy;DESCRIPTION=Buy table in MyShop;SERVER=localhost;UID=root;PWD=apmsetup;DATABASE=myshop;PORT=3306");
}

CString Cbuy::GetDefaultSQL()
{
	return _T("[buy]");
}

void Cbuy::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() ���� ��ũ�δ� �����ͺ��̽��� �ʵ�
// ������ �ƴ϶� ��� ������ ���Ŀ� ���� �޶����ϴ�.
// ODBC������ �ڵ����� �� ���� ��û�� �������� ��ȯ�Ϸ��� �մϴ�
	RFX_Long(pFX, _T("[BNO]"), m_BNO);
	RFX_Text(pFX, _T("[BNAME]"), m_BNAME);
	RFX_Text(pFX, _T("[BPRICE]"), m_BPRICE);
	RFX_Text(pFX, _T("[BLOCATE]"), m_BLOCATE);
}
/////////////////////////////////////////////////////////////////////////////
// Cbuy ����

BOOL Cbuy::Execute(LPCTSTR szSQL)
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

void Cbuy::Connect()
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
	ret= SQLConnect(m_hDbc, (SQLCHAR *) "buy", SQL_NTS,
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
void Cbuy::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cbuy::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


