// income.h : Cincome�� �����Դϴ�.

#pragma once

// �ڵ� ���� ��ġ 2013�� 6�� 9�� �Ͽ���, ���� 1:05

class Cincome : public CRecordset
{
public:
	Cincome(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(Cincome)

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

	long m_INO;
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


