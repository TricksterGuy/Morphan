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

MorphanGUI::MorphanGUI( wxDocManager* manager, wxFrame* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDocParentFrame( manager, parent, id, title, pos, size, style )
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

	edit->AppendSeparator();

	wxMenuItem* selectAll;
	selectAll = new wxMenuItem( edit, ID_SELECT_ALL, wxString( wxT("&Select All") ) + wxT('\t') + wxT("Ctrl+A"), wxEmptyString, wxITEM_NORMAL );
	edit->Append( selectAll );

	wxMenuItem* selectNone;
	selectNone = new wxMenuItem( edit, ID_SELECT_NONE, wxString( wxT("&Select None") ) + wxT('\t') + wxT("Ctrl+Shift+A"), wxEmptyString, wxITEM_NORMAL );
	edit->Append( selectNone );

	wxMenuItem* cut;
	cut = new wxMenuItem( edit, ID_CUT, wxString( wxT("Cu&t") ) + wxT('\t') + wxT("Ctrl+X"), wxEmptyString, wxITEM_NORMAL );
	edit->Append( cut );

	wxMenuItem* copy;
	copy = new wxMenuItem( edit, ID_COPY, wxString( wxT("&Copy") ) + wxT('\t') + wxT("Ctrl+C"), wxEmptyString, wxITEM_NORMAL );
	edit->Append( copy );

	wxMenuItem* paste;
	paste = new wxMenuItem( edit, ID_PASTE, wxString( wxT("&Paste") ) + wxT('\t') + wxT("Ctrl+V"), wxEmptyString, wxITEM_NORMAL );
	edit->Append( paste );

	wxMenuItem* clear;
	clear = new wxMenuItem( edit, ID_CLEAR, wxString( wxT("Cl&ear") ) + wxT('\t') + wxT("Delete"), wxEmptyString, wxITEM_NORMAL );
	edit->Append( clear );

	wxMenuItem* duplicate;
	duplicate = new wxMenuItem( edit, ID_DUPLICATE, wxString( wxT("&Duplicate") ) + wxT('\t') + wxT("Ctrl+D"), wxEmptyString, wxITEM_NORMAL );
	edit->Append( duplicate );

	m_menubar1->Append( edit, wxT("&Edit") );

	view = new wxMenu();
	wxMenuItem* canvasSize;
	canvasSize = new wxMenuItem( view, ID_CANVAS_SIZE, wxString( wxT("&Canvas Size...") ) , wxEmptyString, wxITEM_NORMAL );
	view->Append( canvasSize );

	wxMenuItem* shrinkWrap;
	shrinkWrap = new wxMenuItem( view, ID_SHRINK_WRAP, wxString( wxT("&Shrink Wrap") ) + wxT('\t') + wxT("Ctrl+E"), wxEmptyString, wxITEM_NORMAL );
	view->Append( shrinkWrap );

	view->AppendSeparator();

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

	view->AppendSeparator();

	wxMenuItem* modifyGrid;
	modifyGrid = new wxMenuItem( view, ID_MODIFY_GRID, wxString( wxT("&Modify Grid...") ) , wxEmptyString, wxITEM_NORMAL );
	view->Append( modifyGrid );

	wxMenuItem* showGrid;
	showGrid = new wxMenuItem( view, ID_SHOW_GRID, wxString( wxT("Show &Grid") ) + wxT('\t') + wxT("Ctrl+G"), wxEmptyString, wxITEM_CHECK );
	view->Append( showGrid );

	wxMenuItem* snapToGrid;
	snapToGrid = new wxMenuItem( view, ID_SNAP_TO_GRID, wxString( wxT("Snap &To Grid") ) , wxEmptyString, wxITEM_CHECK );
	view->Append( snapToGrid );

	m_menubar1->Append( view, wxT("&View") );

	playMenu = new wxMenu();
	wxMenuItem* play;
	play = new wxMenuItem( playMenu, wxID_ANY, wxString( wxT("Play") ) + wxT('\t') + wxT("F9"), wxEmptyString, wxITEM_NORMAL );
	playMenu->Append( play );

	m_menubar1->Append( playMenu, wxT("Play") );

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


	bSizer4->Add( bSizer6, 0, wxEXPAND, 5 );


	bSizer11->Add( bSizer4, 1, wxEXPAND, 0 );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( main, wxID_ANY, wxT("Frame") ), wxVERTICAL );

	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText1 = new wxStaticText( main, wxID_ANY, wxT("X:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	fgSizer1->Add( m_staticText1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	keyFrameX = new wxSpinCtrl( main, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	fgSizer1->Add( keyFrameX, 0, wxALL, 5 );

	m_staticText2 = new wxStaticText( main, wxID_ANY, wxT("Y:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizer1->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	keyFrameY = new wxSpinCtrl( main, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	fgSizer1->Add( keyFrameY, 0, wxALL, 5 );

	m_staticText5 = new wxStaticText( main, wxID_ANY, wxT("ScaleX:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	fgSizer1->Add( m_staticText5, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	keyFrameScaleX = new wxSpinCtrl( main, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 1600, 100 );
	fgSizer1->Add( keyFrameScaleX, 0, wxALL, 5 );

	m_staticText6 = new wxStaticText( main, wxID_ANY, wxT("ScaleY:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	fgSizer1->Add( m_staticText6, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	keyFrameScaleY = new wxSpinCtrl( main, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 1600, 100 );
	fgSizer1->Add( keyFrameScaleY, 0, wxALL, 5 );

	m_staticText7 = new wxStaticText( main, wxID_ANY, wxT("Rotation:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	fgSizer1->Add( m_staticText7, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	keyFrameRotation = new wxSpinCtrl( main, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 360, 0 );
	fgSizer1->Add( keyFrameRotation, 0, wxALL, 5 );

	m_staticText9 = new wxStaticText( main, wxID_ANY, wxT("Opacity:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	fgSizer1->Add( m_staticText9, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	keyFrameOpacity = new wxSpinCtrl( main, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0 );
	fgSizer1->Add( keyFrameOpacity, 0, wxALL, 5 );


	sbSizer3->Add( fgSizer1, 0, wxEXPAND, 5 );


	bSizer13->Add( sbSizer3, 0, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( main, wxID_ANY, wxT("Object") ), wxVERTICAL );

	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText8 = new wxStaticText( main, wxID_ANY, wxT("Outline:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	fgSizer2->Add( m_staticText8, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	outlineColor = new wxColourPickerCtrl( main, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	fgSizer2->Add( outlineColor, 0, wxALL, 5 );

	m_staticText91 = new wxStaticText( main, wxID_ANY, wxT("Width:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText91->Wrap( -1 );
	fgSizer2->Add( m_staticText91, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	objectWidth = new wxSpinCtrl( main, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 128, 0 );
	fgSizer2->Add( objectWidth, 0, wxALL, 5 );

	m_staticText81 = new wxStaticText( main, wxID_ANY, wxT("Fill:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText81->Wrap( -1 );
	fgSizer2->Add( m_staticText81, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	fillColor = new wxColourPickerCtrl( main, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	fgSizer2->Add( fillColor, 0, wxALL, 5 );


	sbSizer1->Add( fgSizer2, 0, wxEXPAND, 0 );


	bSizer13->Add( sbSizer1, 0, wxEXPAND, 5 );

	toolSizer = new wxGridSizer( 3, 4, 0, 0 );

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

	toolbtn9 = new wxBitmapToggleButton( main, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	toolbtn9->SetToolTip( wxT("Bezier") );

	toolSizer->Add( toolbtn9, 0, wxALL, 5 );

	toolbtn10 = new wxBitmapToggleButton( main, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	toolbtn10->SetToolTip( wxT("Bezier") );

	toolSizer->Add( toolbtn10, 0, wxALL, 5 );

	toolbtn11 = new wxBitmapToggleButton( main, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	toolbtn11->SetToolTip( wxT("Line") );

	toolSizer->Add( toolbtn11, 0, wxALL, 5 );

	toolbtn12 = new wxBitmapToggleButton( main, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	toolbtn12->SetToolTip( wxT("Line") );

	toolSizer->Add( toolbtn12, 0, wxALL, 5 );


	bSizer13->Add( toolSizer, 0, 0, 0 );


	bSizer11->Add( bSizer13, 0, wxEXPAND, 0 );


	main->SetSizer( bSizer11 );
	main->Layout();
	bSizer11->Fit( main );
	bSizer3->Add( main, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer3 );
	this->Layout();
	statusBar = this->CreateStatusBar( 5, wxST_SIZEGRIP, wxID_ANY );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( selectAll->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnSelectAll ) );
	this->Connect( selectNone->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnSelectNone ) );
	this->Connect( cut->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnCut ) );
	this->Connect( copy->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnCopy ) );
	this->Connect( paste->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnPaste ) );
	this->Connect( clear->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnClear ) );
	this->Connect( duplicate->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnDuplicate ) );
	this->Connect( canvasSize->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnCanvasSize ) );
	this->Connect( shrinkWrap->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnShrinkWrap ) );
	this->Connect( zoomIn->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnZoomIn ) );
	this->Connect( zoomOut->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnZoomOut ) );
	this->Connect( resetZoom->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnResetZoom ) );
	this->Connect( zoom->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnZoom ) );
	this->Connect( modifyGrid->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnModifyGrid ) );
	this->Connect( showGrid->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnShowGrid ) );
	this->Connect( snapToGrid->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnSnapToGrid ) );
	this->Connect( play->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnPlay ) );
	m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MorphanGUI::OnNextFrame ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MorphanGUI::OnPrevFrame ), NULL, this );
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MorphanGUI::OnAddFrame ), NULL, this );
	m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MorphanGUI::OnDeleteFrame ), NULL, this );
	keyFrameX->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MorphanGUI::OnKeyFrameChanged ), NULL, this );
	keyFrameY->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MorphanGUI::OnKeyFrameChanged ), NULL, this );
	keyFrameScaleX->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MorphanGUI::OnKeyFrameChanged ), NULL, this );
	keyFrameScaleY->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MorphanGUI::OnKeyFrameChanged ), NULL, this );
	keyFrameRotation->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MorphanGUI::OnKeyFrameChanged ), NULL, this );
	keyFrameOpacity->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MorphanGUI::OnKeyFrameChanged ), NULL, this );
	outlineColor->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( MorphanGUI::OnOutlineChanged ), NULL, this );
	objectWidth->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MorphanGUI::OnWidthChanged ), NULL, this );
	fillColor->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( MorphanGUI::OnFillChanged ), NULL, this );
}

MorphanGUI::~MorphanGUI()
{
	// Disconnect Events
	this->Disconnect( ID_SELECT_ALL, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnSelectAll ) );
	this->Disconnect( ID_SELECT_NONE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnSelectNone ) );
	this->Disconnect( ID_CUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnCut ) );
	this->Disconnect( ID_COPY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnCopy ) );
	this->Disconnect( ID_PASTE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnPaste ) );
	this->Disconnect( ID_CLEAR, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnClear ) );
	this->Disconnect( ID_DUPLICATE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnDuplicate ) );
	this->Disconnect( ID_CANVAS_SIZE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnCanvasSize ) );
	this->Disconnect( ID_SHRINK_WRAP, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnShrinkWrap ) );
	this->Disconnect( ID_ZOOM_IN, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnZoomIn ) );
	this->Disconnect( ID_ZOOM_OUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnZoomOut ) );
	this->Disconnect( ID_RESET_ZOOM, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnResetZoom ) );
	this->Disconnect( ID_ZOOM, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnZoom ) );
	this->Disconnect( ID_MODIFY_GRID, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnModifyGrid ) );
	this->Disconnect( ID_SHOW_GRID, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnShowGrid ) );
	this->Disconnect( ID_SNAP_TO_GRID, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnSnapToGrid ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MorphanGUI::OnPlay ) );
	m_button1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MorphanGUI::OnNextFrame ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MorphanGUI::OnPrevFrame ), NULL, this );
	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MorphanGUI::OnAddFrame ), NULL, this );
	m_button4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MorphanGUI::OnDeleteFrame ), NULL, this );
	keyFrameX->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MorphanGUI::OnKeyFrameChanged ), NULL, this );
	keyFrameY->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MorphanGUI::OnKeyFrameChanged ), NULL, this );
	keyFrameScaleX->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MorphanGUI::OnKeyFrameChanged ), NULL, this );
	keyFrameScaleY->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MorphanGUI::OnKeyFrameChanged ), NULL, this );
	keyFrameRotation->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MorphanGUI::OnKeyFrameChanged ), NULL, this );
	keyFrameOpacity->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MorphanGUI::OnKeyFrameChanged ), NULL, this );
	outlineColor->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( MorphanGUI::OnOutlineChanged ), NULL, this );
	objectWidth->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MorphanGUI::OnWidthChanged ), NULL, this );
	fillColor->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( MorphanGUI::OnFillChanged ), NULL, this );

}
