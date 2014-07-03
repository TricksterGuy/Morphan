/******************************************************************************************************
 * Morphan
 * Copyright (C) 2014 Brandon Whitehead (tricksterguy87[AT]gmail[DOT]com)
 *
 * This software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * excluding commercial applications, and to alter it and redistribute it freely,
 * subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented;
 *    you must not claim that you wrote the original software.
 *    An acknowledgement in your documentation and link to the original version is required.
 *
 * 2. Altered source versions must be plainly marked as such,
 *    and must not be misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source distribution.
 ******************************************************************************************************/

#ifndef MORPHANFRAME_HPP
#define MORPHANFRAME_HPP

#include <wx/docview.h>

#include "Morphan.hpp"
#include "MorphanGUI.h"
#include "MorphanPanel.hpp"
#include "MorphanView.hpp"
#include "Tool.hpp"

/**
  *  Represents the main class of the application
  */
class MorphanFrame : public MorphanGUI
{
    public:
        MorphanFrame(wxDocManager* manager, wxFrame* window);
        ~MorphanFrame();
        MorphanPanel* GetPanel() {return morphanPanel;}
        Tool* GetTool() {return tool;}
        ModifyTool* GetModifyTool() {return modifyTool;}
        void OnTool(wxCommandEvent& event);
        void UpdateStatusBar();

        // Edit
        void OnClear(wxCommandEvent& event);
        // View
        void OnCanvasSize(wxCommandEvent& event);
		void OnZoomIn(wxCommandEvent& event);
        void OnZoomOut(wxCommandEvent& event);
		void OnResetZoom(wxCommandEvent& event);
		void OnZoom(wxCommandEvent& event);
        void OnModifyGrid(wxCommandEvent& event);
		void OnShowGrid(wxCommandEvent& event);
		void OnSnapToGrid(wxCommandEvent& event);
		void OnSnapToPoints(wxCommandEvent& event);
		// KeyFrame Control
		void OnNextFrame(wxCommandEvent& event);
		void OnPrevFrame(wxCommandEvent& event);
		void OnAddFrame(wxCommandEvent& event);
		void OnDeleteFrame(wxCommandEvent& event);
		// Misc
        void OnKeyFrameChanged(wxSpinEvent& event);
        void OnKeyFrameChanged();
		void OnOutlineChanged(wxColourPickerEvent& event);
		void OnWidthChanged(wxSpinEvent& event);
		void OnFillChanged(wxColourPickerEvent& event);
    private:
        wxDocManager* manager;
        Tool* tool;
        ModifyTool* modifyTool;

        inline Morphan* GetMorphan() {return dynamic_cast<Morphan*>(manager->GetCurrentDocument());}
        MorphanView* GetMorphanView() {return dynamic_cast<MorphanView*>(manager->GetCurrentView());}
        void InitializeButtons();
        void InitializeStatusBar();
};

#endif
