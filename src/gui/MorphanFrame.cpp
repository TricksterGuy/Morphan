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

#include "MorphanFrame.hpp"
#include <wx/tglbtn.h>
#include <wx/numdlg.h>
#include <wx/config.h>

#include "ConvexPolygonTool.hpp"
#include "PolygonTool.hpp"
#include "LineTool.hpp"
#include "RectangleTool.hpp"
#include "CircleTool.hpp"
#include "EllipseTool.hpp"
#include "BezierTool.hpp"
#include "ArcTool.hpp"

#include "ModifyTool.hpp"
#include "DuplicateTool.hpp"
#include "MoveObjectTool.hpp"
#include "MovePointTool.hpp"
#include "SelectTool.hpp"

#include "icons.hpp"

#include "GridSizeDialog.hpp"

MorphanFrame::MorphanFrame(wxDocManager* nmanager, wxFrame* window) : MorphanGUI(nmanager, window), manager(nmanager), tool(NULL), modifyTool(NULL)
{
    new wxDocTemplate(manager, "Morphan", "*.morph", ".", "morph", "Morphan", "Morphan View",
                      CLASSINFO(Morphan), CLASSINFO(MorphanView));

    manager->FileHistoryLoad(*wxConfig::Get());
    manager->FileHistoryUseMenu(menuRecent);
    manager->FileHistoryAddFilesToMenu();
    manager->SetMaxDocsOpen(1);

    InitializeButtons();
}

MorphanFrame::~MorphanFrame()
{
}

void MorphanFrame::OnTool(wxCommandEvent& event)
{
    toolbtn1->SetValue(false);
    toolbtn2->SetValue(false);
    toolbtn3->SetValue(false);
    toolbtn4->SetValue(false);
    toolbtn5->SetValue(false);
    toolbtn6->SetValue(false);
    toolbtn7->SetValue(false);
    toolbtn8->SetValue(false);
    toolbtn9->SetValue(false);
    toolbtn10->SetValue(false);
    toolbtn11->SetValue(false);
    toolbtn12->SetValue(false);

    wxBitmapToggleButton* button = dynamic_cast<wxBitmapToggleButton*>(event.GetEventObject());
    button->SetValue(true);

    tool = dynamic_cast<Tool*>(button->GetClientObject());
    modifyTool = dynamic_cast<ModifyTool*>(button->GetClientObject());
    // TODO move into class tool->OnStart
    ConvexPolygonTool* cptool = dynamic_cast<ConvexPolygonTool*>(tool);
    if (cptool)
    {
        long sides = wxGetNumberFromUser("Please enter a number (3-200).", "Number of sides?", "Morphan", 3, 3, 200);
        if (sides == -1) sides = 3;
        cptool->SetNumSides(sides);
    }

    MorphanView* view = GetMorphanView();

    view->SetTool(tool);
    view->SetModifyTool(modifyTool);
}

void MorphanFrame::InitializeButtons()
{
    toolbtn1->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MorphanFrame::OnTool), NULL, this);
    toolbtn2->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MorphanFrame::OnTool), NULL, this);
    toolbtn3->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MorphanFrame::OnTool), NULL, this);
    toolbtn4->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MorphanFrame::OnTool), NULL, this);
    toolbtn5->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MorphanFrame::OnTool), NULL, this);
    toolbtn6->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MorphanFrame::OnTool), NULL, this);
    toolbtn7->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MorphanFrame::OnTool), NULL, this);
    toolbtn8->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MorphanFrame::OnTool), NULL, this);
    toolbtn9->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MorphanFrame::OnTool), NULL, this);
    toolbtn10->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MorphanFrame::OnTool), NULL, this);
    toolbtn11->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MorphanFrame::OnTool), NULL, this);
    toolbtn12->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MorphanFrame::OnTool), NULL, this);

    LineTool* line_tool = new LineTool();
    toolbtn1->SetClientObject(line_tool);
    toolbtn2->SetClientObject(new RectangleTool());
    toolbtn3->SetClientObject(new CircleTool());
    toolbtn4->SetClientObject(new ConvexPolygonTool());
    toolbtn5->SetClientObject(new PolygonTool());
    toolbtn6->SetClientObject(new EllipseTool());
    toolbtn7->SetClientObject(new ArcTool());
    toolbtn8->SetClientObject(new BezierTool());
    toolbtn9->SetClientObject(new MovePointTool());
    toolbtn10->SetClientObject(new MoveObjectTool());
    toolbtn11->SetClientObject(new DuplicateTool());
    toolbtn12->SetClientObject(new SelectTool());

    toolbtn1->SetBitmap(wxMEMORY_BITMAP(Line_png));
    toolbtn2->SetBitmap(wxMEMORY_BITMAP(Rectangle_png));
    toolbtn3->SetBitmap(wxMEMORY_BITMAP(Circle_png));
    toolbtn4->SetBitmap(wxMEMORY_BITMAP(ConvexPolygon_png));
    toolbtn5->SetBitmap(wxMEMORY_BITMAP(Polygon_png));
    toolbtn6->SetBitmap(wxMEMORY_BITMAP(Ellipse_png));
    toolbtn7->SetBitmap(wxMEMORY_BITMAP(Arc_png));
    toolbtn8->SetBitmap(wxMEMORY_BITMAP(BezierCurve_png));
    toolbtn9->SetBitmap(wxMEMORY_BITMAP(MovePoint_png));
    toolbtn10->SetBitmap(wxMEMORY_BITMAP(MoveObject_png));
    toolbtn11->SetBitmap(wxMEMORY_BITMAP(Duplicate_png));
    toolbtn12->SetBitmap(wxMEMORY_BITMAP(Select_png));

    toolbtn1->SetValue(true);
    tool = line_tool;
}

void MorphanFrame::InitializeStatusBar()
{
    const int widths[5] = {-8, -2, -2, -2, -2};
    const int styles[5] = {wxSB_NORMAL, wxSB_NORMAL, wxSB_NORMAL, wxSB_NORMAL, wxSB_NORMAL};
    statusBar->SetStatusWidths(5, widths);
    statusBar->SetStatusStyles(5, styles);
    UpdateStatusBar();
}

void MorphanFrame::UpdateStatusBar()
{
    Morphan* morphan = GetMorphan();
    MorphanView* view = GetMorphanView();

    wxSize size = view->GetSize();
    wxPoint mouse = view->GetMouse();
    statusBar->SetStatusText(wxString::Format("(%d / %d)", view->GetCurrentFrameId() + 1, morphan->NumFrames()), 1);
    statusBar->SetStatusText(wxString::Format("(%d %d)", size.GetWidth(), size.GetHeight()), 2);
    statusBar->SetStatusText(wxString::Format("%d%%", (int)(100 * view->GetZoom())), 3);
    statusBar->SetStatusText(wxString::Format("(%d, %d)", mouse.x, mouse.y), 4);
}

void MorphanFrame::OnCanvasSize(wxCommandEvent& event)
{
    MorphanView* view = GetMorphanView();
    int width, height;
    view->GetCanvasSize(width, height);
    GridSizeDialog dialog(width, height);
    if (dialog.ShowModal() == wxID_OK)
    {
        dialog.GetGridSize(width, height);
        view->SetCanvasSize(width, height);
    }
}

void MorphanFrame::OnClear(wxCommandEvent& event)
{
    MorphanView* view = GetMorphanView();
    view->DeleteSelection();
}

void MorphanFrame::OnZoomIn(wxCommandEvent& event)
{
    MorphanView* view = GetMorphanView();
    float zoom = view->GetZoom() * 2;
    if (zoom > 20) zoom = 20;
    view->SetZoom(zoom);
}

void MorphanFrame::OnZoomOut(wxCommandEvent& event)
{
    MorphanView* view = GetMorphanView();
    float zoom = view->GetZoom() / 2;
    if (zoom < 1/20.f) zoom = 1/20.f;
    view->SetZoom(zoom);
}

void MorphanFrame::OnResetZoom(wxCommandEvent& event)
{
    MorphanView* view = GetMorphanView();
    view->SetZoom(1.0f);
}

void MorphanFrame::OnZoom(wxCommandEvent& event)
{
    MorphanView* view = GetMorphanView();
    float zoom = view->GetZoom();
    long newzoom = wxGetNumberFromUser("Enter zoom value", "Zoom (5-2000)", "Zoom", zoom * 100, 5, 2000, this);
    if (newzoom != -1)
        view->SetZoom(newzoom / 100.f);
}

void MorphanFrame::OnModifyGrid(wxCommandEvent& event)
{
    MorphanView* view = GetMorphanView();
    int width, height;
    view->GetGridSize(width, height);
    GridSizeDialog dialog(width, height);
    if (dialog.ShowModal() == wxID_OK)
    {
        dialog.GetGridSize(width, height);
        view->SetGridSize(width, height);
    }
}

void MorphanFrame::OnShowGrid(wxCommandEvent& event)
{
    MorphanView* view = GetMorphanView();
    view->SetGrid(event.IsChecked());
}

void MorphanFrame::OnSnapToGrid(wxCommandEvent& event)
{
    MorphanView* view = GetMorphanView();
    view->SetGridSnap(event.IsChecked());
}

void MorphanFrame::OnSnapToPoints(wxCommandEvent& event)
{
    MorphanView* view = GetMorphanView();
    view->SetPointSnap(event.IsChecked());
}

void MorphanFrame::OnNextFrame(wxCommandEvent& event)
{
    MorphanView* view = GetMorphanView();
    view->NextFrame();
    UpdateStatusBar();
    OnKeyFrameChanged();
}

void MorphanFrame::OnPrevFrame(wxCommandEvent& event)
{
    MorphanView* view = GetMorphanView();
    view->PrevFrame();
    UpdateStatusBar();
    OnKeyFrameChanged();
}

void MorphanFrame::OnAddFrame(wxCommandEvent& event)
{
    MorphanView* view = GetMorphanView();
    UpdateStatusBar();
    view->AddFrame();
}

void MorphanFrame::OnDeleteFrame(wxCommandEvent& event)
{
    MorphanView* view = GetMorphanView();
    UpdateStatusBar();
    view->DeleteFrame();
}

void MorphanFrame::OnKeyFrameChanged(wxSpinEvent& event)
{
    MorphanView* view = GetMorphanView();
    int x, y;
    float scale_x, scale_y;
    float rotation;
    float opacity;
    float secs = 1.0f;

    x = keyFrameX->GetValue();
    y = keyFrameY->GetValue();
    scale_x = keyFrameScaleX->GetValue();
    scale_y = keyFrameScaleY->GetValue();
    rotation = keyFrameRotation->GetValue();
    opacity = keyFrameOpacity->GetValue();

    MorphanKeyFrame& keyFrame = view->GetCurrentFrame();
    keyFrame.SetPosition(x, y);
    keyFrame.SetScale(scale_x / 100.f, scale_y / 100.f);
    keyFrame.SetRotation(rotation);
    keyFrame.SetOpacity(opacity / 100.f);
    keyFrame.SetSecs(secs / 1000.f);
}

void MorphanFrame::OnKeyFrameChanged()
{
    MorphanView* view = GetMorphanView();
    int x, y;
    float scale_x, scale_y;
    float rotation;
    float opacity;
    float secs = 1.0f;

    MorphanKeyFrame& keyFrame = view->GetCurrentFrame();
    keyFrame.GetPosition(x, y);
    keyFrame.GetScale(scale_x, scale_y);
    rotation = keyFrame.GetRotation();
    opacity = keyFrame.GetOpacity();
    secs = keyFrame.GetSecs();

    keyFrameX->SetValue(x);
    keyFrameY->SetValue(y);
    keyFrameScaleX->SetValue(scale_x * 100);
    keyFrameScaleY->SetValue(scale_y * 100);
    keyFrameRotation->SetValue(rotation);
    keyFrameOpacity->SetValue(opacity * 100);
    keyFrameSecs->SetValue(secs * 1000);
}

void MorphanFrame::OnOutlineChanged(wxColourPickerEvent& event)
{
    MorphanView* view = GetMorphanView();
    view->SetOutlineColor(event.GetColour());
}

void MorphanFrame::OnWidthChanged(wxSpinEvent& event)
{
    MorphanView* view = GetMorphanView();
    view->SetOutlineWidth(event.GetValue());
}

void MorphanFrame::OnFillChanged(wxColourPickerEvent& event)
{
    MorphanView* view = GetMorphanView();
    view->SetFillColor(event.GetColour());
}
