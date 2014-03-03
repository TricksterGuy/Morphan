///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Nov  5 2013)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MorphanPanel.hpp"
#include "wx/tglbtn.h"

#include "MorphanGUI.h"

///////////////////////////////////////////////////////////////////////////

MorphanGUI::MorphanGUI(wxDocManager* manager, wxFrame* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDocParentFrame( manager, parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	m_menubar1 = new wxMenuBar( 0 );
	file = new wxMenu();
	wxMenuItem* newMenu;
	newMenu = new wxMenuItem( file, wxID_NEW, wxString( wxT("&New") ) + wxT('\t') + wxT("Ctrl+N"), wxEmptyString, wxITEM_NORMAL );
	file->Append( newMenu );

	wxMenuItem* open;
	open = new wxMenuItem( file, wxID_OPEN, wxString( wxT("&Open") ) + wxT('\t') + wxT("Ctrl+O"), wxEmptyString, wxITEM_NORMAL );
	file->Append( open );

	wxMenuItem* save;
	save = new wxMenuItem( file, wxID_SAVE, wxString( wxT("&Save") ) + wxT('\t') + wxT("Ctrl+S"), wxEmptyString, wxITEM_NORMAL );
	file->Append( save );

	wxMenuItem* saveAs;
	saveAs = new wxMenuItem( file, wxID_SAVEAS, wxString( wxT("Save &As") ) + wxT('\t') + wxT("Ctrl+S"), wxEmptyString, wxITEM_NORMAL );
	file->Append( saveAs );

	wxMenuItem* revert;
	revert = new wxMenuItem( file, wxID_REVERT, wxString( wxT("&Revert") ) + wxT('\t') + wxT("Ctrl+R"), wxEmptyString, wxITEM_NORMAL );
	file->Append( revert );

	menuRecent = new wxMenu();
	menuRecent->AppendSeparator();

	file->Append( -1, wxT("Recent"), menuRecent );

	wxMenuItem* exit;
	exit = new wxMenuItem( file, wxID_EXIT, wxString( wxT("&Exit") ) + wxT('\t') + wxT("Alt+F4"), wxEmptyString, wxITEM_NORMAL );
	file->Append( exit );

	m_menubar1->Append( file, wxT("&File") );

	edit = new wxMenu();
	wxMenuItem* undo;
	undo = new wxMenuItem( edit, wxID_UNDO, wxString( wxT("&Undo") ) + wxT('\t') + wxT("Ctrl+Z"), wxEmptyString, wxITEM_NORMAL );
	edit->Append( undo );

	wxMenuItem* redo;
	redo = new wxMenuItem( edit, wxID_REDO, wxString( wxT("&Redo") ) + wxT('\t') + wxT("Ctrl+Y"), wxEmptyString, wxITEM_NORMAL );
	edit->Append( redo );

	m_menubar1->Append( edit, wxT("&Edit") );

	view = new wxMenu();
	wxMenuItem* zoomIn;
	zoomIn = new wxMenuItem( view, ID_ZOOM_IN, wxString( wxT("Zoom &In") ) + wxT('\t') + wxT("Ctrl++"), wxEmptyString, wxITEM_NORMAL );
	view->Append( zoomIn );

	wxMenuItem* zoomOut;
	zoomOut = new wxMenuItem( view, ID_ZOOM_OUT, wxString( wxT("Zoom &Out") ) + wxT('\t') + wxT("Ctrl+-"), wxEmptyString, wxITEM_NORMAL );
	view->Append( zoomOut );

	wxMenuItem* resetZoom;
	resetZoom = new wxMenuItem( view, ID_RESET_ZOOM, wxString( wxT("&Reset Zoom") ) + wxT('\t') + wxT("Ctrl+0"), wxEmptyString, wxITEM_NORMAL );
	view->Append( resetZoom );

	wxMenuItem* zoom;
	zoom = new wxMenuItem( view, ID_ZOOM, wxString( wxT("&Zoom...") ) , wxEmptyString, wxITEM_NORMAL );
	view->Append( zoom );

	m_menubar1->Append( view, wxT("&View") );

	helpMenu = new wxMenu();
	wxMenuItem* help;
	help = new wxMenuItem( helpMenu, wxID_HELP, wxString( wxT("&Help") ) + wxT('\t') + wxT("F1"), wxEmptyString, wxITEM_NORMAL );
	helpMenu->Append( help );

	wxMenuItem* about;
	about = new wxMenuItem( helpMenu, ID_ABOUT, wxString( wxT("&About") ) , wxEmptyString, wxITEM_NORMAL );
	helpMenu->Append( about );

	m_menubar1->Append( helpMenu, wxT("&Help") );

	this->SetMenuBar( m_menubar1 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	main = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	morphanPanel = new MorphanPanel( main, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	bSizer4->Add( morphanPanel, 7, wxEXPAND, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	m_button1 = new wxButton( main, wxID_ANY, wxT("Next"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_button1, 0, wxALL, 5 );

	m_button2 = new wxButton( main, wxID_ANY, wxT("Prev"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_button2, 0, wxALL, 5 );

	m_button3 = new wxButton( main, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_button3, 0, wxALL, 5 );

	m_button4 = new wxButton( main, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_button4, 0, wxALL, 5 );

	m_button5 = new wxButton( main, wxID_ANY, wxT("Copy"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_button5, 0, wxALL, 5 );


	bSizer4->Add( bSizer6, 0, wxEXPAND, 5 );


	bSizer11->Add( bSizer4, 1, wxEXPAND, 0 );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );

	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText1 = new wxStaticText( main, wxID_ANY, wxT("X:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	fgSizer1->Add( m_staticText1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_spinCtrl1 = new wxSpinCtrl( main, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	fgSizer1->Add( m_spinCtrl1, 0, wxALL, 5 );

	m_staticText2 = new wxStaticText( main, wxID_ANY, wxT("Y:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizer1->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_spinCtrl2 = new wxSpinCtrl( main, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	fgSizer1->Add( m_spinCtrl2, 0, wxALL, 5 );

	m_staticText5 = new wxStaticText( main, wxID_ANY, wxT("ScaleX:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	fgSizer1->Add( m_staticText5, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_spinCtrl5 = new wxSpinCtrl( main, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 1600, 100 );
	fgSizer1->Add( m_spinCtrl5, 0, wxALL, 5 );

	m_staticText6 = new wxStaticText( main, wxID_ANY, wxT("ScaleY:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	fgSizer1->Add( m_staticText6, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_spinCtrl6 = new wxSpinCtrl( main, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 1600, 100 );
	fgSizer1->Add( m_spinCtrl6, 0, wxALL, 5 );

	m_staticText7 = new wxStaticText( main, wxID_ANY, wxT("Rotation:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	fgSizer1->Add( m_staticText7, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_spinCtrl7 = new wxSpinCtrl( main, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	fgSizer1->Add( m_spinCtrl7, 0, wxALL, 5 );

	m_staticText9 = new wxStaticText( main, wxID_ANY, wxT("Opacity:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	fgSizer1->Add( m_staticText9, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_spinCtrl8 = new wxSpinCtrl( main, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0 );
	fgSizer1->Add( m_spinCtrl8, 0, wxALL, 5 );


	bSizer13->Add( fgSizer1, 0, wxEXPAND, 5 );

	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText8 = new wxStaticText( main, wxID_ANY, wxT("Outline:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	fgSizer2->Add( m_staticText8, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_colourPicker1 = new wxColourPickerCtrl( main, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	fgSizer2->Add( m_colourPicker1, 0, wxALL, 5 );

	m_staticText91 = new wxStaticText( main, wxID_ANY, wxT("Width:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText91->Wrap( -1 );
	fgSizer2->Add( m_staticText91, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_spinCtrl71 = new wxSpinCtrl( main, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	fgSizer2->Add( m_spinCtrl71, 0, wxALL, 5 );

	m_staticText81 = new wxStaticText( main, wxID_ANY, wxT("Fill:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText81->Wrap( -1 );
	fgSizer2->Add( m_staticText81, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_colourPicker11 = new wxColourPickerCtrl( main, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	fgSizer2->Add( m_colourPicker11, 0, wxALL, 5 );


	bSizer13->Add( fgSizer2, 0, wxEXPAND, 0 );

	toolSizer = new wxGridSizer( 2, 4, 0, 0 );

	toolbtn1 = new wxBitmapToggleButton( main, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	toolbtn1->SetToolTip( wxT("Line") );

	toolSizer->Add( toolbtn1, 0, wxALL, 5 );

	toolbtn2 = new wxBitmapToggleButton( main, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	toolbtn2->SetToolTip( wxT("Rectangle") );

	toolSizer->Add( toolbtn2, 0, wxALL, 5 );

	toolbtn3 = new wxBitmapToggleButton( main, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	toolbtn3->SetToolTip( wxT("Circle") );

	toolSizer->Add( toolbtn3, 0, wxALL, 5 );

	toolbtn4 = new wxBitmapToggleButton( main, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	toolbtn4->SetToolTip( wxT("Convex Polygon") );

	toolSizer->Add( toolbtn4, 0, wxALL, 5 );

	toolbtn5 = new wxBitmapToggleButton( main, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	toolbtn5->SetToolTip( wxT("Polygon") );

	toolSizer->Add( toolbtn5, 0, wxALL, 5 );

	toolbtn6 = new wxBitmapToggleButton( main, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	toolbtn6->SetToolTip( wxT("Ellipse") );

	toolSizer->Add( toolbtn6, 0, wxALL, 5 );

	toolbtn7 = new wxBitmapToggleButton( main, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	toolbtn7->SetToolTip( wxT("Arc") );

	toolSizer->Add( toolbtn7, 0, wxALL, 5 );

	toolbtn8 = new wxBitmapToggleButton( main, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	toolbtn8->SetToolTip( wxT("Bezier") );

	toolSizer->Add( toolbtn8, 0, wxALL, 5 );


	bSizer13->Add( toolSizer, 0, 0, 0 );


	bSizer11->Add( bSizer13, 0, wxEXPAND, 0 );


	main->SetSizer( bSizer11 );
	main->Layout();
	bSizer11->Fit( main );
	bSizer3->Add( main, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer3 );
	this->Layout();

	this->Centre( wxBOTH );
}

MorphanGUI::~MorphanGUI()
{
}
