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

#include "MorphanView.hpp"
#include "MorphanApp.hpp"

IMPLEMENT_DYNAMIC_CLASS(MorphanView, wxView)

bool MorphanView::OnCreate(wxDocument* doc, long flags)
{
    if (!wxView::OnCreate(doc, flags))
        return false;

    // reuse the existing window and canvas
    MorphanApp* app = dynamic_cast<MorphanApp*>(wxTheApp);
    panel = app->GetFrame()->GetPanel();
    SetFrame(app->GetFrame());

    // Initialize the edit menu Undo and Redo items
    //doc->GetCommandProcessor()->SetEditMenu(app.GetMainWindowEditMenu());
    //doc->GetCommandProcessor()->Initialize();

    panel->Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(MorphanView::OnClick), NULL, this);
	panel->Connect(wxEVT_MOTION, wxMouseEventHandler(MorphanView::OnMotion), NULL, this);
	panel->Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(MorphanView::OnCancel), NULL, this);
	panel->SetView(this);

    return true;
}

bool MorphanView::OnClose(bool deleteWindow)
{
    if (!wxView::OnClose(deleteWindow))
        return false;

    Activate(false);
	panel->Disconnect(wxEVT_LEFT_DOWN, wxMouseEventHandler(MorphanView::OnClick), NULL, this);
	panel->Disconnect(wxEVT_MOTION, wxMouseEventHandler(MorphanView::OnMotion), NULL, this);
	panel->Disconnect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(MorphanView::OnCancel), NULL, this);
    panel->SetView(NULL);

    return true;
}

void MorphanView::OnUpdate(wxView* sender, wxObject* hint)
{
    wxView::OnUpdate(sender, hint);

}

void MorphanView::OnDraw(wxDC* dc)
{
    wxGraphicsContext* gc = wxGraphicsContext::Create(panel);
    if (!gc) return;

    wxGCDC gcdc(gc);

    int w, h;
    gcdc.GetSize(&w, &h);
    for (int i = 16; i < h; i += 16)
    {
        gcdc.DrawLine(0, i, w, i);
    }

    for (int j = 16; j < w; j += 16)
    {
        gcdc.DrawLine(j, 0, j, h);
    }
}


void MorphanView::OnClick(wxMouseEvent& event)
{
    tool->Add(wxRealPoint(event.GetX(), event.GetY()));
    if (tool->CanCreate())
    {

    }
}

void MorphanView::OnMotion(wxMouseEvent& event)
{

}

void MorphanView::OnCancel(wxMouseEvent& event)
{

}

Morphan* MorphanView::GetDocument()
{
    return wxStaticCast(wxView::GetDocument(), Morphan);
}
