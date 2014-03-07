///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Nov  5 2013)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GridSizeGUI.h"

///////////////////////////////////////////////////////////////////////////

GridSizeGUI::GridSizeGUI( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 0, 2, 0, 0 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText1 = new wxStaticText( m_panel1, wxID_ANY, wxT("Width"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer4->Add( m_staticText1, 0, wxALL, 5 );
	
	gridSizeX = new wxSpinCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 8, 1024, 16 );
	bSizer4->Add( gridSizeX, 0, wxALL, 5 );
	
	
	gSizer1->Add( bSizer4, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText2 = new wxStaticText( m_panel1, wxID_ANY, wxT("Height"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer5->Add( m_staticText2, 0, wxALL, 5 );
	
	gridSizeY = new wxSpinCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 8, 1024, 16 );
	bSizer5->Add( gridSizeY, 0, wxALL, 5 );
	
	
	gSizer1->Add( bSizer5, 1, wxEXPAND, 5 );
	
	
	bSizer2->Add( gSizer1, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button1 = new wxButton( m_panel1, wxID_OK, wxT("Ok"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_button1, 0, wxALL, 5 );
	
	m_button2 = new wxButton( m_panel1, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_button2, 0, wxALL, 5 );
	
	
	bSizer2->Add( bSizer6, 0, wxALIGN_RIGHT, 5 );
	
	
	m_panel1->SetSizer( bSizer2 );
	m_panel1->Layout();
	bSizer2->Fit( m_panel1 );
	bSizer1->Add( m_panel1, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	this->Centre( wxBOTH );
}

GridSizeGUI::~GridSizeGUI()
{
}
