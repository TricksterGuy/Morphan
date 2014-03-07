/******************************************************************************************************
 * Morphan
 * Copyright (C) 2009-2014 Brandon Whitehead (tricksterguy87[AT]gmail[DOT]com)
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

#ifndef MORPHAN_VIEW_HPP
#define MORPHAN_VIEW_HPP

#include <wx/docview.h>
#include <wx/dcgraph.h>
#include <wx/docview.h>
#include "Morphan.hpp"
#include "MorphanPanel.hpp"
#include "Tool.hpp"

class MorphanPanel;

class MorphanView : public wxView
{
    public:
        MorphanView() : wxView(), panel(NULL), tool(NULL), outlineColor(0, 0, 0), outlineWidth(1), fillColor(0, 0, 0),
                        grid_width(16), grid_height(16), snap_grid(false), show_grid(false), show_points(true), zoom(1.0f),
                        current_frame(0), in_window(false) {}
        bool OnCreate(wxDocument*, long flags);
        bool OnClose(bool deleteWindow = true);
        void OnUpdate(wxView *sender, wxObject *hint = NULL);

        void OnDraw(wxDC*);
        void OnClick(wxMouseEvent& event);
        void OnMotion(wxMouseEvent& event);
        void OnCancel(wxMouseEvent& event);
        void OnEnter(wxMouseEvent& event);
        void OnLeave(wxMouseEvent& event);
        void OnKey(wxKeyEvent& event);

        Morphan* GetDocument();
        wxSize GetSize();
        wxPoint GetMouse() const {return mouse;}
        float GetZoom() const {return zoom;}
        int GetCurrentFrameId() const {return current_frame;}
        MorphanKeyFrame& GetCurrentFrame();
        void GetGridSize(int& width, int& height) const;

        void SetOutlineColor(const wxColour& color) {outlineColor = color;}
        void SetOutlineWidth(int width) {outlineWidth = width;}
        void SetFillColor(const wxColour& color) {fillColor = color;}

        void SetTool(Tool* ntool) {tool = ntool;}
        void SetGridSize(int width, int height);
        void SetGrid(bool on) {show_grid = on;}
        void SetGridSnap(bool on) {snap_grid = on;}
        void SetZoom(float nzoom);
        wxRealPoint GetRealPosition(const wxPoint& point);

    private:
        MorphanPanel* panel;
        Tool* tool;
        wxColour outlineColor;
        int outlineWidth;
        wxColour fillColor;
        int grid_width, grid_height;
        bool snap_grid;
        bool show_grid;
        bool show_points;
        float zoom;
        int current_frame;
        bool in_window;
        wxRealPoint mouse;

        void DrawGrid(wxGCDC& gcdc);
        DECLARE_DYNAMIC_CLASS(MorphanView)
};

#endif
