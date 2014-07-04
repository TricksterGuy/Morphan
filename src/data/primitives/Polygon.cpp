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

#include "Polygon.hpp"
#include "PolygonTool.hpp"

Primitive* Polygon::Copy() const
{
    Primitive* primitive = new Polygon(points);
    CopyAttributes(primitive);
    return primitive;
}

void Polygon::Draw(wxGCDC& dc) const
{
    Primitive::Draw(dc);
    PolygonTool::Draw(dc, points);
}

void Polygon::Draw(wxGCDC& dc, Primitive* next, unsigned long delta, unsigned long length) const
{
    Polygon* other = dynamic_cast<Polygon*>(next);
    assert(other);
    assert(points.size() == other->points.size());
    std::vector<wxRealPoint> npoints;
    for (unsigned int i = 0; i < points.size(); i++)
        npoints.push_back(interpolate(points[i], other->points[i], delta, length));
    PolygonTool::Draw(dc, npoints);
}

bool Polygon::SetControlPoints(const std::vector<wxRealPoint>& npoints)
{
    if (npoints.size() < 3) return false;
    points = npoints;

    return true;
}

wxRect Polygon::GetBounds() const
{
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
