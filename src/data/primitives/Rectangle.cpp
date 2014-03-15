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

#include "Rectangle.hpp"
#include "RectangleTool.hpp"

Primitive* Rectangle::Copy() const
{
    Primitive* primitive = new Rectangle(start, end);
    CopyAttributes(primitive);
    return primitive;
}

std::vector<wxRealPoint> Rectangle::GetControlPoints() const
{
    return {start, end};
}

bool Rectangle::SetControlPoints(const std::vector<wxRealPoint>& points)
{
    if (points.size() != 2) return false;

    start = points[0];
    end = points[1];

    return true;
}

void Rectangle::Draw(wxGCDC& dc) const
{
    Primitive::Draw(dc);
    RectangleTool::Draw(dc, start, end);
}

wxRect Rectangle::GetBounds() const
{
    return wxRect(start, end);
}
