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

#include "ModifyTool.hpp"

wxRealPoint INVALID_POINT(1e9, 1e9);

void DoModify(Primitive* primitive, const wxColour& outline, int width, const wxColour& fill, int isfilled)
{
    if (outline.IsOk())
        primitive->SetOutline(outline);
    if (width > 0)
        primitive->SetWidth(width);
    if (fill.IsOk())
        primitive->SetFill(fill);
    if (isfilled > 0)
        primitive->SetFilled(isfilled);
}

void ModifyTool::SetSelection(const std::vector<Primitive*>& primitives, const wxRealPoint& point, bool reset)
{
    if (reset)
        selection.clear();
    //if (point.IsFullySpecified())
    for (Primitive* primitive : primitives)
    {
        std::vector<wxRealPoint> points = primitive->GetControlPoints();
        float mindist = 1e9;
        int minpt = -1;

        for (unsigned int i = 0; i < points.size(); i++)
        {
            float curdist = distance(points[i], point);
            if (curdist < mindist)
            {
                mindist = curdist;
                minpt = i;
            }
        }

        selection.insert(PrimitiveSelection(primitive, minpt));
    }

    selected_object = selection.begin();
}

void ModifyTool::SelectNext()
{
    if (selected_object == selection.end()) return;
    selected_object++;
}

void ModifyTool::SelectPrevious()
{
    if (selected_object == selection.begin()) return;
    selected_object--;
}

void ModifyTool::Modify(const wxColour& outline, int width, const wxColour& fill, int isfilled)
{
    if (mode == SelectionMode::ALL)
    {
        for (const PrimitiveSelection& ps : selection)
        {
            ::DoModify(ps.primitive, outline, width, fill, isfilled);
        }
    }
    else
    {
        ::DoModify(selected_object->primitive, outline, width, fill, isfilled);
    }
}

std::set<PrimitiveSelection> ModifyTool::PreviewModify(const wxRealPoint& origin)
{
    std::set<PrimitiveSelection> newselection;
    std::set<PrimitiveSelection> old;
    if (mode == SelectionMode::ALL)
        old = selection;
    else
        old.insert(*selected_object);
    int id = 0;
    for (const PrimitiveSelection& ps : old)
    {
        Primitive* prim = ps.primitive->Copy();
        prim->SetId(id++);
        newselection.insert(PrimitiveSelection(prim, ps.point_id));
    }
    selection = newselection;
    std::vector<Primitive*> primitives = Modify(origin);
    selection = old;
    for (Primitive* primitive : primitives)
        newselection.insert(PrimitiveSelection(primitive, -1));
    return newselection;
}
