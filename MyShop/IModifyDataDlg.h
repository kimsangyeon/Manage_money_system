#pragma once


// IModifyDataDlg ��ȭ �����Դϴ�.

class IModifyDataDlg : public CDialogEx
{
	DECLARE_DYNAMIC(IModifyDataDlg)

public:
	IModifyDataDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~IModifyDataDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_IModify };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	CString m_IMNO;
	CString m_IMPRICE;
	CString m_IMLOCATE;
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
