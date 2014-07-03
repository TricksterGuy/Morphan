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

#include "ConvexPolygon.hpp"
#include "ConvexPolygonTool.hpp"

Primitive* ConvexPolygon::Copy() const
{
    Primitive* primitive = new ConvexPolygon(center, edge, num_sides);
    CopyAttributes(primitive);
    return primitive;
}

std::vector<wxRealPoint> ConvexPolygon::GetControlPoints() const
{
    return {center, edge};
}

bool ConvexPolygon::SetControlPoints(const std::vector<wxRealPoint>& points)
{
    if (points.size() != 2) return false;

    center = points[0];
    edge = points[1];

    return true;
}

void ConvexPolygon::Draw(wxGCDC& dc) const
{
    Primitive::Draw(dc);
    ConvexPolygonTool::Draw(dc, center, edge, num_sides);
}

wxRect ConvexPolygon::GetBounds() const
{
    std::vector<wxPoint> points = ConvexPolygon::GetPoints(center, edge, num_sides);
    float minx, miny, maxx, maxy;
    minx = miny = 1e9;
    maxx = maxy = -1e9;
    for (const auto& pt : points)
    {
        if (pt.y > maxy)
            maxy = pt.y;
        if (pt.y < miny)
            miny = pt.y;
        if (pt.x > maxx)
            maxx = pt.x;
        if (pt.x < minx)
            minx = pt.x;
    }
    return wxRect(wxPoint(minx, miny), wxPoint(maxx, maxy));
}

// TODO use templates.
std::vector<wxPoint> ConvexPolygon::GetPoints(const wxRealPoint& center, const wxRealPoint& edge, int sides)
{
    std::vector<wxPoint> points;
    points.push_back(edge);

    float angle = atan2(edge.y - center.y, edge.x - center.x);
    float radius = distance(center, edge);
    for (int i = 1; i < sides; i++)
    {
        angle += 2 * PI / sides;
        points.push_back(wxRealPoint(radius * cos(angle) + center.x, radius * sin(angle) + center.y));
    }

    return points;
}

