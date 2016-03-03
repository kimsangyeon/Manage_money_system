// buy.h : Cbuy 클래스의 구현입니다.



// Cbuy 구현입니다.

// 코드 생성 위치 2013년 6월 8일 토요일, 오후 4:19

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
//#error 보안 문제: 연결 문자열에 암호가 포함되어 있을 수 있습니다.
// 아래 연결 문자열에 일반 텍스트 암호 및/또는 
// 다른 중요한 정보가 포함되어 있을 수 있습니다.
// 보안 관련 문제가 있는지 연결 문자열을 검토한 후에 #error을(를) 제거하십시오.
// 다른 형식으로 암호를 저장하거나 다른 사용자 인증을 사용하십시오.
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
// RFX_Text() 및 RFX_Int() 같은 매크로는 데이터베이스의 필드
// 형식이 아니라 멤버 변수의 형식에 따라 달라집니다.
// ODBC에서는 자동으로 열 값을 요청된 형식으로 변환하려고 합니다
	RFX_Long(pFX, _T("[BNO]"), m_BNO);
	RFX_Text(pFX, _T("[BNAME]"), m_BNAME);
	RFX_Text(pFX, _T("[BPRICE]"), m_BPRICE);
	RFX_Text(pFX, _T("[BLOCATE]"), m_BLOCATE);
}
/////////////////////////////////////////////////////////////////////////////
// Cbuy 진단

BOOL Cbuy::Execute(LPCTSTR szSQL)
{
	SQLRETURN ret;
	
	ret = SQLExecDirect(m_hStmt, (SQLCHAR *)szSQL, SQL_NTS);

	if((ret != SQL_SUCCESS) && (ret != SQL_SUCCESS_WITH_INFO) && (ret != SQL_NO_DATA))
	{
		AfxMessageBox("DB추가 실패");
		return FALSE;
	}
	return TRUE;
}

void Cbuy::Connect()
{
	SQLRETURN ret;
		
	if(SQL_ERROR == SQLAllocEnv(&m_hEnv))
	{
		AfxMessageBox("환경 정보 할당 실패");
		return;
	}

	if(SQL_ERROR == SQLAllocConnect(m_hEnv, &m_hDbc))
	{
		SQLFreeEnv(m_hEnv);
		m_hEnv = NULL;
		AfxMessageBox("연결 할당 실패");
		return;
	}
	// HDBC, ODBC 원본 이름. 아이디, 패스워드
	ret= SQLConnect(m_hDbc, (SQLCHAR *) "buy", SQL_NTS,
		(SQLCHAR *) "root", SQL_NTS,
		(SQLCHAR *) "apmsetup", SQL_NTS);

	// 서버 접속 실패
	if(ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO)
	{
		if(m_hDbc != SQL_NULL_HDBC) { SQLFreeConnect(m_hDbc); m_hDbc = NULL; };
		if(m_hEnv != SQL_NULL_HENV) { SQLFreeEnv(m_hEnv); m_hEnv = NULL; };
		AfxMessageBox("서버 접속 실패");
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
		AfxMessageBox("핸들 할당 실패");
		return;
	}

	// 변수와의 바인딩
	
	if(ret != SQL_SUCCESS)
	{
		if(m_hDbc)
		{
			SQLDisconnect(m_hDbc);
			SQLFreeHandle(SQL_HANDLE_DBC, m_hDbc);
			m_hDbc = NULL;
		}
		if(m_hEnv){SQLFreeHandle(SQL_HANDLE_ENV, m_hEnv); m_hEnv = NULL; };
		AfxMessageBox("변수 바인딩 실패");
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


