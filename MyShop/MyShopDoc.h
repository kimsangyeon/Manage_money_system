
// MyShopDoc.h : CMyShopDoc 클래스의 인터페이스
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

protected: // serialization에서만 만들어집니다.
	CMyShopDoc();
	DECLARE_DYNCREATE(CMyShopDoc)

// 특성입니다.
public:

// 작업입니다.
public:
	BOOL IsReady() {return (m_hStmt != NULL)? TRUE : FALSE; };
	BOOL FetchNext() {return (SQLFetch(m_hStmt) != SQL_NO_DATA)? TRUE : FALSE;};
	int GetBNO() {return m_BNO;};
	char *GetBNAME() {return (char *)m_BNAME;};
	char *GetBPRICE() {return (char *)m_BPRICE;};
	char *GetBLOCATE() {return (char *)m_BLOCATE;};

	void Execute(void);
// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CMyShopDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnMyshopExpense();
	afx_msg void OnMyshopIncome();
	afx_msg void OnMyshopStates();
};
