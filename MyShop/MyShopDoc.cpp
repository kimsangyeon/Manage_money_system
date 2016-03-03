
// MyShopDoc.cpp : CMyShopDoc 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MyShop.h"
#endif

#include "MyShopDoc.h"
#include "buy.h"
#include "BuyDlg.h"
#include "IncomeDlg.h"
#include "BInsertDataDlg.h"
#include "StatsDlg.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMyShopDoc

IMPLEMENT_DYNCREATE(CMyShopDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyShopDoc, CDocument)
	ON_COMMAND(ID_MYSHOP_START, &CMyShopDoc::OnMyshopExpense)
	ON_COMMAND(ID_MYSHOP_INCOME, &CMyShopDoc::OnMyshopIncome)
	ON_COMMAND(ID_MYSHOP_STATES, &CMyShopDoc::OnMyshopStates)
END_MESSAGE_MAP()


// CMyShopDoc 생성/소멸

CMyShopDoc::CMyShopDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.
	m_hEnv = NULL;
	m_hDbc = NULL;
	m_hStmt = NULL;

	m_BNAME[0] = NULL;
	m_BPRICE[0] = NULL;
	m_BLOCATE[0] = NULL;
}

CMyShopDoc::~CMyShopDoc()
{
}

BOOL CMyShopDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.
	m_hEnv = NULL;
	m_hDbc = NULL;
	m_hStmt = NULL;

	m_BNAME[0] = NULL;
	m_BPRICE[0] = NULL;
	m_BLOCATE[0] = NULL;

	return TRUE;
}




// CMyShopDoc serialization

void CMyShopDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CMyShopDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CMyShopDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMyShopDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMyShopDoc 진단

#ifdef _DEBUG
void CMyShopDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyShopDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMyShopDoc 명령

void CMyShopDoc::OnMyshopExpense()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CBuyDlg dlg;
	dlg.DoModal();
}


void CMyShopDoc::OnMyshopIncome()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIncomeDlg dlg;
	dlg.DoModal();
}


void CMyShopDoc::OnMyshopStates()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CStatsDlg dlg;
	dlg.DoModal();
}
