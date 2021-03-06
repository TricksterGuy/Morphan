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

#include "ArcTool.hpp"
#include "LineTool.hpp"
#include "Arc.hpp"

bool line_intersection(wxRealPoint a, wxRealPoint b, wxRealPoint c, wxRealPoint d,
                       wxRealPoint& out);

Primitive* ArcTool::Create()
{
    return new Arc(points[0], points[1], points[2]);
}

bool ArcTool::CanCreate() const
{
    return points.size() >= 3;
}

void ArcTool::Preview(wxGCDC& dc, const wxPoint& mouse, bool is_end)
{
    if (points.size() == 1)
        LineTool::Draw(dc, points[0], mouse);
    else
        ArcTool::Draw(dc, points[0], points[1], mouse);
}

void ArcTool::Draw(wxGCDC& dc, const wxRealPoint& start, const wxRealPoint& second, const wxRealPoint& end)
{
    wxRealPoint center;
    if (!Arc::FindCenter(start, second, end, center))
        return;

    //dc.CrossHair(center);
    if (Arc::IsClockwise(start, second, end))
        dc.DrawArc(end, start, center);
    else
        dc.DrawArc(start, end, center);
}
