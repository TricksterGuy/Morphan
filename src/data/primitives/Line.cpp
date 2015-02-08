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

#include "Line.hpp"
#include "LineTool.hpp"

Primitive* Line::Copy() const
{
    Primitive* primitive = new Line(start, end);
    CopyAttributes(primitive);
    return primitive;
}

std::vector<wxRealPoint> Line::GetControlPoints() const
{
    return {start, end};
}

bool Line::SetControlPoints(const std::vector<wxRealPoint>& points)
{
    if (points.size() != 2) return false;

    start = points[0];
    end = points[1];

    return true;
}

void Line::Draw(MorphanDrawContext& context) const
{
    Primitive::Draw(context);
    LineTool::Draw(context.gcdc, start, end);
}

void Line::Draw(MorphanDrawContext& context, Primitive* next, unsigned long delta, unsigned long length) const
{
    Primitive::Draw(context, next, delta, length);
    Line* other = dynamic_cast<Line*>(next);
    assert(other);
    wxRealPoint nstart = interpolate(start, other->start, delta, length);
    wxRealPoint nend = interpolate(end, other->end, delta, length);
    LineTool::Draw(context.gcdc, nstart, nend);
}

wxRect Line::GetBounds() const
{
    return wxRect(start, end);
}
