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
#include <wx/utils.h>
#include <wx/event.h>

IMPLEMENT_DYNAMIC_CLASS(MorphanView, wxView)

bool MorphanView::OnCreate(wxDocument* doc, long flags)
{
    if (!wxView::OnCreate(doc, flags))
        return false;

    // reuse the existing window and canvas
    MorphanApp* app = dynamic_cast<MorphanApp*>(wxTheApp);
    panel = app->GetFrame()->GetPanel();
    SetFrame(app->GetFrame());
    tool = app->GetFrame()->GetTool();

    // Initialize the edit menu Undo and Redo items
    //doc->GetCommandProcessor()->SetEditMenu(app.GetMainWindowEditMenu());
    //doc->GetCommandProcessor()->Initialize();

    panel->Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(MorphanView::OnClick), NULL, this);
	panel->Connect(wxEVT_MOTION, wxMouseEventHandler(MorphanView::OnMotion), NULL, this);
	panel->Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(MorphanView::OnCancel), NULL, this);
	panel->Connect(wxEVT_ENTER_WINDOW, wxMouseEventHandler(MorphanView::OnEnter), NULL, this);
	panel->Connect(wxEVT_LEAVE_WINDOW, wxMouseEventHandler(MorphanView::OnLeave), NULL, this);
	panel->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(MorphanView::OnKey), NULL, this);
	panel->Connect(wxEVT_KEY_UP, wxKeyEventHandler(MorphanView::OnKey), NULL, this);
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
	panel->Disconnect(wxEVT_ENTER_WINDOW, wxMouseEventHandler(MorphanView::OnEnter), NULL, this);
	panel->Disconnect(wxEVT_LEAVE_WINDOW, wxMouseEventHandler(MorphanView::OnLeave), NULL, this);
	panel->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(MorphanView::OnKey), NULL, this);
	panel->Disconnect(wxEVT_KEY_UP, wxKeyEventHandler(MorphanView::OnKey), NULL, this);
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

    Morphan* morphan = GetDocument();
    if (!morphan) return;

    const MorphanKeyFrame& keyFrame = morphan->Get(current_frame);

    wxPen cpbox(*wxBLACK, 2);
    wxBrush cpfill(*wxWHITE);

    for (const Primitive* p : keyFrame.GetPrimitives())
    {
        p->Draw(gcdc);

        gcdc.SetPen(cpbox);
        gcdc.SetBrush(cpfill);
        const std::vector<wxRealPoint> points = p->GetControlPoints();
        for (const auto& point : points)
        {
            gcdc.DrawRectangle(point.x - 4, point.y - 4, 8, 8);
        }
    }

    if (!in_window || !tool->CanPreview()) return;
    gcdc.SetPen(wxPen(wxColour(255, 0, 0, 255), 10));
    gcdc.SetBrush(*wxTRANSPARENT_BRUSH);
    tool->Preview(gcdc, mouse, wxGetKeyState(WXK_SHIFT));
}


void MorphanView::OnClick(wxMouseEvent& event)
{
    tool->Add(wxRealPoint(event.GetX(), event.GetY()));
    if ((tool->CanCreate() && tool->IsInfinitePoint() && event.ShiftDown()) ||
        (tool->CanCreate() && !tool->IsInfinitePoint()))
    {
        Primitive* p = tool->Create();
        GetDocument()->Add(current_frame, p);
        tool->Clear();
        panel->Refresh();
    }
}

void MorphanView::OnMotion(wxMouseEvent& event)
{
    mouse = event.GetPosition();
    panel->Refresh();
}

void MorphanView::OnCancel(wxMouseEvent& event)
{

}

void MorphanView::OnEnter(wxMouseEvent& event)
{
    in_window = true;
}

void MorphanView::OnLeave(wxMouseEvent& event)
{
    in_window = false;
}

void MorphanView::OnKey(wxKeyEvent& event)
{
    printf("%d\n", event.GetKeyCode());
    if (event.GetKeyCode() == WXK_SHIFT)
        panel->Refresh();
}

Morphan* MorphanView::GetDocument()
{
    return wxStaticCast(wxView::GetDocument(), Morphan);
}
