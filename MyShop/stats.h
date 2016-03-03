// stats.h : Cstats�� �����Դϴ�.

#pragma once

// �ڵ� ���� ��ġ 2013�� 6�� 9�� �Ͽ���, ���� 2:44

class Cstats : public CRecordset
{
public:
	Cstats(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(Cstats)

// �ʵ�/�Ű� ���� ������

// �Ʒ��� ���ڿ� ����(���� ���)�� �����ͺ��̽� �ʵ��� ���� ������ ������
// ��Ÿ���ϴ�(CStringA: ANSI ������ ����, CStringW: �����ڵ� ������ ����).
// �̰��� ODBC ����̹����� ���ʿ��� ��ȯ�� ������ �� ������ �մϴ�.
// ���� ��� �̵� ����� CString �������� ��ȯ�� �� ������
// �׷� ��� ODBC ����̹����� ��� �ʿ��� ��ȯ�� �����մϴ�.
// (����: �����ڵ�� �̵� ��ȯ�� ��� �����Ϸ���  ODBC ����̹�
// ���� 3.5 �̻��� ����ؾ� �մϴ�).
protected:
	SQLHENV m_hEnv;
	SQLHDBC m_hDbc;

public:
	SQLHSTMT m_hStmt;

	long m_SNO;
	CStringA m_SMONTH;
	long m_BNO;
	long m_INO;
	
	CStringA m_BNAME;
	CStringA m_BPRICE;
	CStringA m_BLOCATE;
	CStringA m_IPRICE;
	CStringA m_ILOCATE;

public:
	BOOL Execute(LPCTSTR szSQL);
	BOOL IsReady() {return (m_hStmt != NULL)? TRUE : FALSE; };
	BOOL FetchNext() {return (SQLFetch(m_hStmt) != SQL_NO_DATA)? TRUE : FALSE;};

	void Connect();
// ������
	// �����翡�� ������ ���� �Լ� ������
	public:
	virtual CString GetDefaultConnect();	// �⺻ ���� ���ڿ�

	virtual CString GetDefaultSQL(); 	// ���ڵ� ������ �⺻ SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ����

// ����
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


