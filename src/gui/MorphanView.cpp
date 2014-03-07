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

    gcdc.SetUserScale(zoom, zoom);

    if (show_grid)
        DrawGrid(gcdc);

    Morphan* morphan = GetDocument();
    if (!morphan) return;

    const MorphanKeyFrame& keyFrame = morphan->Get(current_frame);

    wxPen cpbox(*wxBLACK, 2);
    wxBrush cpfill(*wxWHITE);

    for (const Primitive* p : keyFrame.GetPrimitives())
    {
        p->Draw(gcdc);

        if (show_points)
        {
            gcdc.SetPen(cpbox);
            gcdc.SetBrush(cpfill);
            const std::vector<wxRealPoint> points = p->GetControlPoints();
            for (const auto& point : points)
                gcdc.DrawRectangle(point.x - 3, point.y - 3, 6, 6);
        }
    }

    if (!in_window || !tool->CanPreview()) return;
    gcdc.SetPen(wxPen(wxColour(255, 0, 0, 255), outlineWidth));
    gcdc.SetBrush(*wxTRANSPARENT_BRUSH);
    tool->Preview(gcdc, mouse, wxGetKeyState(WXK_SHIFT));
}

void MorphanView::DrawGrid(wxGCDC& gcdc)
{
    int w, h;
    gcdc.GetSize(&w, &h);

    float gridw = grid_width;// * zoom;
    float gridh = grid_height;// * zoom;

    for (float i = gridh; i < h; i += gridh)
        gcdc.DrawLine(0, i, w, i);

    for (float j = gridw; j < w; j += gridw)
        gcdc.DrawLine(j, 0, j, h);
}

void MorphanView::OnClick(wxMouseEvent& event)
{
    mouse = GetRealPosition(event.GetPosition());
    tool->Add(mouse);
    if ((tool->CanCreate() && tool->IsInfinitePoint() && event.ShiftDown()) ||
        (tool->CanCreate() && !tool->IsInfinitePoint()))
    {
        Primitive* p = tool->Create();
        p->SetFill(fillColor);
        p->SetOutline(outlineColor);
        p->SetWidth(outlineWidth);
        GetDocument()->Add(current_frame, p);
        GetDocument()->Modify(true);
        tool->Clear();
        panel->Refresh();
    }
}

void MorphanView::OnMotion(wxMouseEvent& event)
{
    mouse = GetRealPosition(event.GetPosition());
    MorphanApp* app = dynamic_cast<MorphanApp*>(wxTheApp);
    MorphanFrame* frame = dynamic_cast<MorphanFrame*>(app->GetFrame());
    if (frame)
        frame->UpdateStatusBar();

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
    if (event.GetKeyCode() == WXK_SHIFT)
        panel->Refresh();
}

Morphan* MorphanView::GetDocument()
{
    return wxStaticCast(wxView::GetDocument(), Morphan);
}

MorphanKeyFrame& MorphanView::GetCurrentFrame()
{
    return GetDocument()->Get(current_frame);
}

wxSize MorphanView::GetSize()
{
    return panel->GetSize();
}

void MorphanView::GetGridSize(int& width, int& height) const
{
    width = grid_width;
    height = grid_height;
}

void MorphanView::SetGridSize(int width, int height)
{
    grid_width = width;
    grid_height = height;
    panel->Refresh();
}

void MorphanView::SetZoom(float nzoom)
{
    zoom = nzoom;
    panel->Refresh();
}

wxRealPoint MorphanView::GetRealPosition(const wxPoint& point)
{
    wxRealPoint ret(point);
    if (snap_grid)
    {
        float gridw = grid_width * zoom;
        float gridh = grid_height * zoom;
        ret.x = round(point.x / gridw) * gridw;
        ret.y = round(point.y / gridh) * gridh;
    }
    ret.x = ret.x / zoom;
    ret.y = ret.y / zoom;
    return ret;
}
