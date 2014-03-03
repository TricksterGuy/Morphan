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

#include "ConvexPolygon.hpp"

#define PI 3.14159265

ConvexPolygon::ConvexPolygon(const wxRealPoint& ncenter, const wxRealPoint& nedge, int npoints) : center(ncenter), edge(nedge), num_points(npoints)
{
    points.push_back(edge);

    float angle = atan2(edge.y - center.y, edge.x - center.x);
    float radius = distance(ncenter, nedge);
    for (int i = 1; i < num_points; i++)
    {
        angle += 2 * PI / num_points;
        points.push_back(wxRealPoint(radius * cos(angle) + center.x, radius * sin(angle) + center.y));
    }
}

std::vector<wxRealPoint> ConvexPolygon::GetControlPoints() const
{
    return {center, edge};
}

void ConvexPolygon::Draw(wxGCDC& dc) const
{
    Primitive::Draw(dc);
    dc.DrawPolygon(points.size(), points.data(), 0, 0);
}
