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

#include "Primitive.hpp"

void Primitive::CopyAttributes(Primitive* primitive, bool same_id) const
{
    primitive->SetOutline(outline);
    primitive->SetFill(fill);
    primitive->SetWidth(width);
    if (same_id) primitive->SetId(id);
}

void Primitive::Move(float x, float y)
{
    std::vector<wxRealPoint> cpoints = GetControlPoints();
    for (auto& pt : cpoints)
    {
        pt.x += x;
        pt.y += y;
    }
    SetControlPoints(cpoints);
}

void Primitive::Draw(wxGCDC& dc) const
{
    dc.SetPen(wxPen(outline, width));
    dc.SetBrush(wxBrush(fill));
}
