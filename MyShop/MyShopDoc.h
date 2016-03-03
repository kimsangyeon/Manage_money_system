
// MyShopDoc.h : CMyShopDoc Ŭ������ �������̽�
//


#pragma once


class CMyShopDoc : public CDocument
{
protected:
	SQLHENV m_hEnv;
	SQLHDBC m_hDbc;
	SQLHSTMT m_hStmt;

	SQLINTEGER m_BNO;
	SQLCHAR m_BNAME[21];
	SQLCHAR m_BPRICE[21];
	SQLCHAR m_BLOCATE[21];

	SQLINTEGER m_lBno, m_lBname, m_lBprice, m_lBlocate;

protected: // serialization������ ��������ϴ�.
	CMyShopDoc();
	DECLARE_DYNCREATE(CMyShopDoc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:
	BOOL IsReady() {return (m_hStmt != NULL)? TRUE : FALSE; };
	BOOL FetchNext() {return (SQLFetch(m_hStmt) != SQL_NO_DATA)? TRUE : FALSE;};
	int GetBNO() {return m_BNO;};
	char *GetBNAME() {return (char *)m_BNAME;};
	char *GetBPRICE() {return (char *)m_BPRICE;};
	char *GetBLOCATE() {return (char *)m_BLOCATE;};

	void Execute(void);
// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CMyShopDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnMyshopExpense();
	afx_msg void OnMyshopIncome();
	afx_msg void OnMyshopStates();
};
