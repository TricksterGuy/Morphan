///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Nov  5 2013)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __MORPHANGUI_H__
#define __MORPHANGUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
class MorphanPanel;
class wxBitmapToggleButton;

#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/spinctrl.h>
#include <wx/clrpicker.h>
#include <wx/bmpbuttn.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

#define ID_ZOOM_IN 1000
#define ID_ZOOM_OUT 1001
#define ID_RESET_ZOOM 1002
#define ID_ZOOM 1003
#define ID_ABOUT 1004

///////////////////////////////////////////////////////////////////////////////
/// Class MorphanGUI
///////////////////////////////////////////////////////////////////////////////
class MorphanGUI : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* m_menubar1;
		wxMenu* file;
		wxMenu* menuRecent;
		wxMenu* edit;
		wxMenu* view;
		wxMenu* helpMenu;
		wxPanel* main;
		MorphanPanel* morphanPanel;
		wxButton* m_button1;
		wxButton* m_button2;
		wxButton* m_button3;
		wxButton* m_button4;
		wxButton* m_button5;
		wxStaticText* m_staticText1;
		wxSpinCtrl* m_spinCtrl1;
		wxStaticText* m_staticText2;
		wxSpinCtrl* m_spinCtrl2;
		wxStaticText* m_staticText5;
		wxSpinCtrl* m_spinCtrl5;
		wxStaticText* m_staticText6;
		wxSpinCtrl* m_spinCtrl6;
		wxStaticText* m_staticText7;
		wxSpinCtrl* m_spinCtrl7;
		wxStaticText* m_staticText9;
		wxSpinCtrl* m_spinCtrl8;
		wxStaticText* m_staticText8;
		wxColourPickerCtrl* m_colourPicker1;
		wxStaticText* m_staticText91;
		wxSpinCtrl* m_spinCtrl71;
		wxStaticText* m_staticText81;
		wxColourPickerCtrl* m_colourPicker11;
		wxGridSizer* toolSizer;
		wxBitmapToggleButton* toolbtn1;
		wxBitmapToggleButton* toolbtn2;
		wxBitmapToggleButton* toolbtn3;
		wxBitmapToggleButton* toolbtn4;
		wxBitmapToggleButton* toolbtn5;
		wxBitmapToggleButton* toolbtn6;
		wxBitmapToggleButton* toolbtn7;
		wxBitmapToggleButton* toolbtn8;
	
	public:
		
		MorphanGUI( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Morphan"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 680,480 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~MorphanGUI();
	
};

#endif //__MORPHANGUI_H__
