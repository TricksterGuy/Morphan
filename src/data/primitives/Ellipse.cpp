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

#include "Ellipse.hpp"
#include "EllipseTool.hpp"

Primitive* Ellipse::Copy() const
{
    Primitive* primitive = new Ellipse(center, edge);
    CopyAttributes(primitive);
    return primitive;
}

std::vector<wxRealPoint> Ellipse::GetControlPoints() const
{
    return {center, edge};
}

bool Ellipse::SetControlPoints(const std::vector<wxRealPoint>& points)
{
    if (points.size() != 2) return false;

    center = points[0];
    edge = points[1];

    return true;
}

void Ellipse::Draw(wxGCDC& dc) const
{
    Primitive::Draw(dc);
    EllipseTool::Draw(dc, center, edge);
}

wxRect Ellipse::GetBounds() const
{
    float ar = abs(center.x - edge.x);
    float br = abs(center.y - edge.y);
    return wxRect(center.x - ar, center.y - br, 2 * ar, 2 * br);
}
