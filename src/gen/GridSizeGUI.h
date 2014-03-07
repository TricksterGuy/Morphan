///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Nov  5 2013)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GRIDSIZEGUI_H__
#define __GRIDSIZEGUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/spinctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class GridSizeGUI
///////////////////////////////////////////////////////////////////////////////
class GridSizeGUI : public wxDialog 
{
	private:
	
	protected:
		wxPanel* m_panel1;
		wxStaticText* m_staticText1;
		wxSpinCtrl* gridSizeX;
		wxStaticText* m_staticText2;
		wxSpinCtrl* gridSizeY;
		wxButton* m_button1;
		wxButton* m_button2;
	
	public:
		
		GridSizeGUI( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Grid Size"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~GridSizeGUI();
	
};

#endif //__GRIDSIZEGUI_H__
