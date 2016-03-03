
// MyShopDoc.cpp : CMyShopDoc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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


// CMyShopDoc ����/�Ҹ�

CMyShopDoc::CMyShopDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.
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

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.
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
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CMyShopDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
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

// �˻� ó���⸦ �����մϴ�.
void CMyShopDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
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

// CMyShopDoc ����

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


// CMyShopDoc ���

void CMyShopDoc::OnMyshopExpense()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CBuyDlg dlg;
	dlg.DoModal();
}


void CMyShopDoc::OnMyshopIncome()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CIncomeDlg dlg;
	dlg.DoModal();
}


void CMyShopDoc::OnMyshopStates()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CStatsDlg dlg;
	dlg.DoModal();
}
