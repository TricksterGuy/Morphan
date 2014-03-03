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
#include "ArcTool.hpp"
#include "BezierTool.hpp"
#include "icons.hpp"

MorphanFrame::MorphanFrame(wxDocManager* nmanager, wxFrame* window) : MorphanGUI(nmanager, window), manager(nmanager)
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

    wxBitmapToggleButton* button = dynamic_cast<wxBitmapToggleButton*>(event.GetEventObject());
    button->SetValue(true);

    tool = static_cast<Tool*>(button->GetClientObject());
    ConvexPolygonTool* cptool = dynamic_cast<ConvexPolygonTool*>(tool);
    if (cptool)
    {
        long sides = wxGetNumberFromUser("Please enter a number (3-200).", "Number of sides?", "Morphan", 3, 3, 200);
        if (sides == -1) sides = 3;
        cptool->SetNumSides(sides);
    }

    MorphanView* view = dynamic_cast<MorphanView*>(manager->GetAnyUsableView());
    view->SetTool(tool);
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

    LineTool* line_tool = new LineTool();
    toolbtn1->SetClientObject(line_tool);
    toolbtn2->SetClientObject(new RectangleTool());
    toolbtn3->SetClientObject(new CircleTool());
    toolbtn4->SetClientObject(new ConvexPolygonTool());
    toolbtn5->SetClientObject(new PolygonTool());
    toolbtn6->SetClientObject(new EllipseTool());
    toolbtn7->SetClientObject(new ArcTool());
    toolbtn8->SetClientObject(new BezierTool());

    toolbtn1->SetBitmap(wxMEMORY_BITMAP(Line_png));
    toolbtn2->SetBitmap(wxMEMORY_BITMAP(Rectangle_png));
    toolbtn3->SetBitmap(wxMEMORY_BITMAP(Circle_png));
    toolbtn4->SetBitmap(wxMEMORY_BITMAP(ConvexPolygon_png));
    toolbtn5->SetBitmap(wxMEMORY_BITMAP(Polygon_png));
    toolbtn6->SetBitmap(wxMEMORY_BITMAP(Ellipse_png));
    toolbtn7->SetBitmap(wxMEMORY_BITMAP(Arc_png));
    toolbtn8->SetBitmap(wxMEMORY_BITMAP(BezierCurve_png));

    toolbtn1->SetValue(true);
    tool = line_tool;
}
