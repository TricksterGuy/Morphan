///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jan 29 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __MorphanPlayer__
#define __MorphanPlayer__

class MorphanPlayerPanel;

#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MorphanPlayer
///////////////////////////////////////////////////////////////////////////////
class MorphanPlayer : public wxDialog 
{
	private:
	
	protected:
		MorphanPlayerPanel* morphanPlayerPanel;
	
	public:
		
		MorphanPlayer( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Player"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 649,599 ), long style = wxDEFAULT_DIALOG_STYLE );
		~MorphanPlayer();
	
};

#endif //__MorphanPlayer__
