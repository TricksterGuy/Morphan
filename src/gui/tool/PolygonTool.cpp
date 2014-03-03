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

#include "Polygon.hpp"
#include "PolygonTool.hpp"

Primitive* PolygonTool::Create()
{
    return new Polygon(points);
}

bool PolygonTool::CanCreate() const
{
    return points.size() >= 3;
}

void PolygonTool::Preview(wxGCDC& dc, const wxPoint& mouse, bool is_end)
{
    points.push_back(mouse);
    PolygonTool::Draw(dc, points, is_end);
    points.pop_back();
}

void PolygonTool::Draw(wxGCDC& dc, const std::vector<wxRealPoint>& points, bool is_end)
{
    std::vector<wxPoint> ppoints(points.begin(), points.end());
    if (is_end || points.size() < 3)
        dc.DrawPolygon(ppoints.size(), ppoints.data());
    else
        dc.DrawLines(ppoints.size(), ppoints.data());
}
