
// MFCprojectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCproject.h"
#include "MFCprojectDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCprojectDlg dialog



CMFCprojectDlg::CMFCprojectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCPROJECT_DIALOG, pParent)
{
	//clr = RGB(255, 0, 0);
	frameClr = RGB(0, 0, 0);
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCprojectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCprojectDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_RADIO1, &CMFCprojectDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMFCprojectDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCprojectDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON1, &CMFCprojectDlg::OnBnClickedMfccolorbutton1)
	ON_COMMAND(ID_WIDTH_2, &CMFCprojectDlg::PenWidth2)
	ON_COMMAND(ID_WIDTH_8, &CMFCprojectDlg::PenWidth6)
	ON_COMMAND(ID_WIDTH_9, &CMFCprojectDlg::OnWidth8)
	ON_COMMAND(ID_WIDTH_16, &CMFCprojectDlg::PenWidth16)
	ON_COMMAND(ID_WIDTH_24, &CMFCprojectDlg::OnWidth24)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCprojectDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCprojectDlg::OnBnClickedButton5)
	ON_COMMAND(ID_FILE_SAVEALL32778, &CMFCprojectDlg::FileSaveAll)
	ON_COMMAND(ID_FILE_LODE32779, &CMFCprojectDlg::FileLode)
	ON_BN_CLICKED(IDC_RADIO3, &CMFCprojectDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CMFCprojectDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO6, &CMFCprojectDlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_RADIO7, &CMFCprojectDlg::OnBnClickedRadio7)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCprojectDlg::OnBnClickedButton1)
	ON_COMMAND(ID_FILE_CLEAR, &CMFCprojectDlg::OnFileClear)
END_MESSAGE_MAP()


// CMFCprojectDlg message handlers

BOOL CMFCprojectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	//!! 16 b
	CheckRadioButton(IDC_RADIO1, IDC_RADIO2, IDC_RADIO1);
	//!! 16 e

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCprojectDlg::OnPaint()
{

	if (IsIconic())
	{
		CPaintDC dc(this);// device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		for (int i = 0; i < figs.GetSize(); i++)
		{
			CBrush myBrush;
			CPen myPen;

			myPen.CreatePen(PS_SOLID, (*figs[i]).getWidthPen(), (*figs[i]).getFrameColor());
			myBrush.CreateSolidBrush((*figs[i]).getColor());
			dc.SelectObject(&myPen);
			dc.SelectObject(&myBrush);

			(*figs[i]).Draw(&dc);
		}

		CDialogEx::OnPaint();
	}
	
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCprojectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCprojectDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	start = point;
	isPressed = true;

	switch (futureFigureKind)
	{
	case 1:
		figs.Add(new Rectangle1(start, start,clr, frameClr,width));
		break;
	case 2:
  	    figs.Add(new EllipseF(start, start,clr, frameClr,width));
		break;
	case 3:
		figs.Add(new SegmentF(start, start, clr, frameClr, width));
		break;
	case 4:
		figs.Add(new Triangular(start, start, clr, frameClr, width));
		break;
	case 5:
		figs.Add(new MagenDavid(start, start, clr, frameClr, width));
		break;
	case 6:
		figs.Add(new Square(start, start, clr, frameClr, width));
		break;
	}

	CDialogEx::OnLButtonDown(nFlags, point);

	Invalidate();
}


void CMFCprojectDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	
	if (isPressed)
	{
		end = point;
		isPressed = false;
		figs[figs.GetSize() - 1]->Redefine(start, end);
		Invalidate(); //simulates the WM_PAINT message to redraw window
	}
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMFCprojectDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (isPressed)
	{
		end = point;
		figs[figs.GetSize()-1]->Redefine(start,end);
		Invalidate(); //simulates the WM_PAINT message to redraw window
	}
	CDialogEx::OnMouseMove(nFlags, point);
}


void CMFCprojectDlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	//!! 18 b
	futureFigureKind = 1;
	//!! 18 e
}


void CMFCprojectDlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	//!! 19 b
	futureFigureKind = 2;
	//!! 19 e
}

void CMFCprojectDlg::OnBnClickedButton4()
{
	if (cd.DoModal() == IDOK) {
		clr = cd.GetColor();
	}
}


void CMFCprojectDlg::OnBnClickedMfccolorbutton1()
{
	if (cd.DoModal() == IDOK) {
		frameClr = cd.GetColor();
	}
}

void CMFCprojectDlg::PenWidth2()
{
	width = 2;
}


void CMFCprojectDlg::PenWidth6()
{
	width = 6;
}


void CMFCprojectDlg::OnWidth8()
{
	width = 8;
}


void CMFCprojectDlg::PenWidth16()
{
	width = 16;
}


void CMFCprojectDlg::OnWidth24()
{
	width = 24;
}

void CMFCprojectDlg::OnBnClickedButton3() // UNDO
{
	if (!figs.IsEmpty()) {
		OldFigArr.Add(figs[figs.GetSize() - 1]);
		figs.RemoveAt(figs.GetSize() - 1);
		Invalidate();
	}
}


void CMFCprojectDlg::OnBnClickedButton5() // REDO
{
	if (!OldFigArr.IsEmpty()) {
		figs.Add(OldFigArr[OldFigArr.GetSize() - 1]);
		OldFigArr.RemoveAt(OldFigArr.GetSize() - 1);
		Invalidate();
	}
}



void CMFCprojectDlg::FileSaveAll()
{
	CFileDialog dlg(FALSE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
	}
}


void CMFCprojectDlg::FileLode()
{
	CFileDialog dlg(TRUE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
}


void CMFCprojectDlg::OnBnClickedRadio3()
{
	futureFigureKind = 3;
}


void CMFCprojectDlg::OnBnClickedRadio4()
{
	futureFigureKind = 4;
}




void CMFCprojectDlg::OnBnClickedRadio6()
{
	futureFigureKind = 5;
}




void CMFCprojectDlg::OnBnClickedRadio7()
{
	futureFigureKind = 6;
}


void CMFCprojectDlg::OnBnClickedButton1()
{
	if (cd.DoModal() == IDOK) {
		Background = cd.GetColor();
		CDialogEx::SetBackgroundColor(Background);
	}
}


void CMFCprojectDlg::OnFileClear()
{
	figs.RemoveAll();
	Invalidate();

	isPressed = false;

	UpdateData(true);
	Background = RGB(255, 255, 255);
	CDialogEx::SetBackgroundColor(Background);
	clr = RGB(240, 240, 240);
	frameClr = RGB(0, 0, 0);
	width = 1;
}
