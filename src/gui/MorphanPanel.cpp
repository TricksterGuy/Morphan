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

#include "MorphanPanel.hpp"
#include <wx/dcclient.h>

MorphanPanel::MorphanPanel(wxWindow* Parent, wxWindowID Id, const wxPoint& Position, const wxSize& Size, long Style) :
    wxPanel(Parent, Id, Position, Size, Style), grid_width(16), grid_height(16)
{
    Connect(wxEVT_PAINT, wxPaintEventHandler(MorphanPanel::OnPaint), NULL, this);
	Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(MorphanPanel::OnClick), NULL, this);
	Connect(wxEVT_MOTION, wxMouseEventHandler(MorphanPanel::OnMotion), NULL, this);
	Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(MorphanPanel::OnCancel), NULL, this);
}

MorphanPanel::~MorphanPanel()
{
    Disconnect(wxEVT_PAINT, wxPaintEventHandler(MorphanPanel::OnPaint), NULL, this);
	Disconnect(wxEVT_LEFT_DOWN, wxMouseEventHandler(MorphanPanel::OnClick), NULL, this);
	Disconnect(wxEVT_MOTION, wxMouseEventHandler(MorphanPanel::OnMotion), NULL, this);
	Disconnect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(MorphanPanel::OnCancel), NULL, this);
}

void MorphanPanel::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);
    OnDraw(dc);
}

void MorphanPanel::OnDraw(wxDC& dc)
{
    int w, h;
    GetClientSize(&w, &h);
    for (int i = 16; i < h; i += 16)
    {
        dc.DrawLine(0, i, w, i);
    }

    for (int j = 16; j < w; j += 16)
    {
        dc.DrawLine(j, 0, j, h);
    }
}

void MorphanPanel::OnClick(wxMouseEvent& event)
{

}

void MorphanPanel::OnMotion(wxMouseEvent& event)
{

}

void MorphanPanel::OnCancel(wxMouseEvent& event)
{

}
