
// MFCprojectDlg.h : header file
//

#pragma once

#include "Figure.h"
//!! 17 b
#include "Rectangle1.h"
#include "EllipseF.h"
#include "SegmentF.h"
#include "Triangular.h"
#include "MagenDavid.h"
#include "Square.h"

//!! 17 e

// CMFCprojectDlg dialog
class CMFCprojectDlg : public CDialogEx
{

	CTypedPtrArray<CObArray, Figure*>OldFigArr;
// Construction
public:
	CMFCprojectDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPROJECT_DIALOG };
#endif
	CPoint start, end;
	COLORREF Background = RGB(255, 255, 255);
	bool isPressed=false;
	 CTypedPtrArray< CObArray, Figure*> figs;
     //!! 17 b
	 int futureFigureKind = 1; //Rectangle (2 - Ellipse)
	 //!! 17 e
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	COLORREF clr;
	COLORREF frameClr;
	int width = 1;
	CColorDialog cd;



	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedMfccolorbutton1();
	afx_msg void PenWidth2();
	afx_msg void PenWidth6();
	afx_msg void OnWidth8();
	afx_msg void PenWidth16();
	afx_msg void OnWidth24();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg void FileSaveAll();
	afx_msg void FileLode();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio6();
	afx_msg void OnBnClickedRadio7();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnFileClear();
};
