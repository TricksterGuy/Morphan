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

#include "Arc.hpp"
#include "ArcTool.hpp"

//  public domain function by Darel Rex Finley, 2006
//  Determines the intersection point of the line defined by points A and B with the
//  line defined by points C and D.
//
//  Returns YES if the intersection point was found, and stores that point in X,Y.
//  Returns NO if there is no determinable intersection point, in which case X,Y will
//  be unmodified.
bool line_intersection(wxRealPoint a, wxRealPoint b, wxRealPoint c, wxRealPoint d, wxRealPoint& out)
{
  float  distAB, theCos, theSin, newX, ABpos ;

  //  (1) Translate the system so that point A is on the origin.
  b -= a;
  c -= a;
  d -= a;

  //  Discover the length of segment A-B.
  distAB = (float)sqrt(b.x * b.x + b.y * b.y);

  //  (2) Rotate the system so that point B is on the positive X axis.
  theCos = b.x / distAB;
  theSin = b.y / distAB;

  newX = c.x * theCos + c.y * theSin;
  c.y = c.y * theCos - c.x * theSin;
  c.x = newX;

  newX = d.x * theCos + d.y * theSin;
  d.y = d.y * theCos - d.x * theSin;
  d.x = newX;

  //  Fail if the lines are parallel.
  if (c.y == d.y) return false;

  //  (3) Discover the position of the intersection point along line A-B.
  ABpos = d.x + (c.x - d.x) * d.y / (d.y - c.y);

  //  (4) Apply the discovered position to line A-B in the original coordinate system.
  out.x = a.x + ABpos * theCos;
  out.y = a.y + ABpos * theSin;

  //  Success.
  return true;
}

Arc::Arc(const wxRealPoint& nstart, const wxRealPoint& nsecond, const wxRealPoint& nend) : start(nstart), second(nsecond), end(nend)
{
}

Primitive* Arc::Copy() const
{
    Primitive* primitive = new Arc(start, second, end);
    CopyAttributes(primitive);
    return primitive;
}

std::vector<wxRealPoint> Arc::GetControlPoints() const
{
    return {start, second, end};
}

bool Arc::SetControlPoints(const std::vector<wxRealPoint>& points)
{
    if (points.size() != 3) return false;

    start = points[0];
    second = points[1];
    end = points[2];

    return true;
}

void Arc::Draw(wxGCDC& dc) const
{
    Primitive::Draw(dc);
    dc.SetBrush(*wxTRANSPARENT_BRUSH);
    ArcTool::Draw(dc, start, second, end);
}

wxRect Arc::GetBounds() const
{
    wxRect rect;
    wxRealPoint center;
    if (!Arc::FindCenter(start, second, end, center))
        return rect;

    float i = atan2(start.y - center.y, start.x - center.x);
    float f = atan2(end.y - center.y, end.x - center.x);

    float t0;
    float tf;
    //if (Arc::IsClockwise(start, second, end))
    //{
    //    t0 = f;
    //    tf = i;
    //}
    //else
    {
        t0 = i;
        tf = f;

        if (tf < 0) tf += 2 * PI;
        if (t0 > tf) tf += 2 * PI;
    }

    float radius = distance(start, center);
    float minx, maxx, miny, maxy;
    minx = miny = 1e9;
    maxx = maxy = -1e9;

    for (float theta = -1; theta <= 2; theta += 0.5f)
    {
        if (t0 <= theta * PI && theta * PI <= tf)
        {
            UpdateMinMax(radius, theta * PI, minx, miny, maxx, maxy);
        }
    }
    UpdateMinMax(radius, t0, minx, miny, maxx, maxy);
    UpdateMinMax(radius, tf, minx, miny, maxx, maxy);

    return wxRect(wxPoint(minx + center.x, miny + center.y), wxPoint(maxx + center.x, maxy + center.y));
}

bool Arc::FindCenter(const wxRealPoint& start, const wxRealPoint& second, const wxRealPoint& end, wxRealPoint& center)
{
    wxRealPoint ab((start.x + second.x) / 2, (start.y + second.y) / 2);
    wxRealPoint abend(-(second.y - start.y) / 2 + ab.x, (second.x - start.x) / 2 + ab.y);

    wxRealPoint bc((end.x + second.x) / 2, (end.y + second.y) / 2);
    wxRealPoint bcend(-(end.y - second.y) / 2 + bc.x, (end.x - second.x) / 2 + bc.y);

    return line_intersection(ab, abend, bc, bcend, center);
}

bool Arc::IsClockwise(const wxRealPoint& start, const wxRealPoint& second, const wxRealPoint& end)
{
    wxRealPoint abvec(second.x - start.x, second.y - start.y);
    wxRealPoint acvec(end.x - start.x, end.y - start.y);
    float cross = abvec.x * acvec.y - abvec.y * acvec.x;
    return cross > 0;
}

void Arc::UpdateMinMax(float radius, float theta, float& minx, float& miny, float& maxx, float& maxy) const
{
    float px = radius * cos(theta);
    float py = radius * sin(theta);
    if (py > maxy)
        maxy = py;
    if (py < miny)
        miny = py;
    if (px > maxx)
        maxx = px;
    if (px < minx)
        minx = px;
}
