// income.h : Cincome Ŭ������ �����Դϴ�.



// Cincome �����Դϴ�.

// �ڵ� ���� ��ġ 2013�� 6�� 9�� �Ͽ���, ���� 1:05

#include "stdafx.h"
#include "income.h"
IMPLEMENT_DYNAMIC(Cincome, CRecordset)

Cincome::Cincome(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_INO = 0;
	m_IPRICE = "";
	m_ILOCATE = "";

	m_nFields = 3;
	m_nDefaultType = snapshot;
}
//#error ���� ����: ���� ���ڿ��� ��ȣ�� ���ԵǾ� ���� �� �ֽ��ϴ�.
// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.
CString Cincome::GetDefaultConnect()
{
	return _T("DSN=Income;DESCRIPTION=Income table in MyShop;SERVER=localhost;UID=root;PWD=apmsetup;DATABASE=myshop;PORT=3306");
}

CString Cincome::GetDefaultSQL()
{
	return _T("[income]");
}

void Cincome::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() ���� ��ũ�δ� �����ͺ��̽��� �ʵ�
// ������ �ƴ϶� ��� ������ ���Ŀ� ���� �޶����ϴ�.
// ODBC������ �ڵ����� �� ���� ��û�� �������� ��ȯ�Ϸ��� �մϴ�
	RFX_Long(pFX, _T("[INO]"), m_INO);
	RFX_Text(pFX, _T("[IPRICE]"), m_IPRICE);
	RFX_Text(pFX, _T("[ILOCATE]"), m_ILOCATE);
}
/////////////////////////////////////////////////////////////////////////////
// Cincome ����
BOOL Cincome::Execute(LPCTSTR szSQL)
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

void Cincome::Connect()
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
	ret= SQLConnect(m_hDbc, (SQLCHAR *) "income", SQL_NTS,
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
void Cincome::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cincome::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


