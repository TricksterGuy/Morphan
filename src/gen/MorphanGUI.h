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
class wxDocParentFrame;

#include "wx/docview.h"
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
#include <wx/statbox.h>
#include <wx/clrpicker.h>
#include <wx/bmpbuttn.h>
#include <wx/statusbr.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

#define ID_SELECT_FIRST_POINT 1000
#define ID_SELECT_ALL 1001
#define ID_SELECT_NONE 1002
#define ID_CUT 1003
#define ID_COPY 1004
#define ID_PASTE 1005
#define ID_CLEAR 1006
#define ID_DUPLICATE 1007
#define ID_CANVAS_SIZE 1008
#define ID_SHRINK_WRAP 1009
#define ID_ZOOM_IN 1010
#define ID_ZOOM_OUT 1011
#define ID_RESET_ZOOM 1012
#define ID_ZOOM 1013
#define ID_MODIFY_GRID 1014
#define ID_SHOW_GRID 1015
#define ID_SNAP_TO_GRID 1016
#define ID_SNAP_TO_POINT 1017
#define ID_ABOUT 1018

///////////////////////////////////////////////////////////////////////////////
/// Class MorphanGUI
///////////////////////////////////////////////////////////////////////////////
class MorphanGUI : public wxDocParentFrame
{
	private:

	protected:
		wxMenuBar* m_menubar1;
		wxMenu* fileMenu;
		wxMenu* menuRecent;
		wxMenu* editMenu;
		wxMenu* selectMode;
		wxMenu* viewMenu;
		wxMenu* playMenu;
		wxMenu* helpMenu;
		wxPanel* main;
		MorphanPanel* morphanPanel;
		wxButton* m_button1;
		wxButton* m_button2;
		wxButton* m_button3;
		wxButton* m_button4;
		wxStaticText* m_staticText1;
		wxSpinCtrl* keyFrameX;
		wxStaticText* m_staticText2;
		wxSpinCtrl* keyFrameY;
		wxStaticText* m_staticText5;
		wxSpinCtrl* keyFrameScaleX;
		wxStaticText* m_staticText6;
		wxSpinCtrl* keyFrameScaleY;
		wxStaticText* m_staticText7;
		wxSpinCtrl* keyFrameRotation;
		wxStaticText* m_staticText9;
		wxSpinCtrl* keyFrameOpacity;
		wxStaticText* m_staticText10;
		wxSpinCtrl* keyFrameSecs;
		wxStaticText* m_staticText8;
		wxColourPickerCtrl* outlineColor;
		wxStaticText* m_staticText91;
		wxSpinCtrl* objectWidth;
		wxStaticText* m_staticText81;
		wxColourPickerCtrl* fillColor;
		wxGridSizer* toolSizer;
		wxBitmapToggleButton* toolbtn1;
		wxBitmapToggleButton* toolbtn2;
		wxBitmapToggleButton* toolbtn3;
		wxBitmapToggleButton* toolbtn4;
		wxBitmapToggleButton* toolbtn5;
		wxBitmapToggleButton* toolbtn6;
		wxBitmapToggleButton* toolbtn7;
		wxBitmapToggleButton* toolbtn8;
		wxBitmapToggleButton* toolbtn9;
		wxBitmapToggleButton* toolbtn10;
		wxBitmapToggleButton* toolbtn11;
		wxBitmapToggleButton* toolbtn12;
		wxStatusBar* statusBar;

		// Virtual event handlers, overide them in your derived class
		virtual void OnSelectAll( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectNone( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCut( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCopy( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPaste( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClear( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDuplicate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCanvasSize( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnShrinkWrap( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnZoomIn( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnZoomOut( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnResetZoom( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnZoom( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnModifyGrid( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnShowGrid( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSnapToGrid( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSnapToPoints( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPlay( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNextFrame( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPrevFrame( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddFrame( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeleteFrame( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnKeyFrameChanged( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnOutlineChanged( wxColourPickerEvent& event ) { event.Skip(); }
		virtual void OnWidthChanged( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnFillChanged( wxColourPickerEvent& event ) { event.Skip(); }


	public:

		MorphanGUI( wxDocManager* manager, wxFrame* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Morphan"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 720,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MorphanGUI();

};

#endif //__MORPHANGUI_H__
