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
    if (!Arc::FindCenter(start, second, end, center)) {
        return rect;
    }

    float radius = distance(start, center);

    float minx, miny, maxx, maxy;
    float starta, enda;

    starta = atan2(-start.y + center.y, start.x - center.x);
    enda = atan2(-end.y + center.y, end.x - center.x);

    if (enda < 0) enda += 2 * PI;
    if (starta < 0) starta += 2 * PI;

    minx = min(start.x, end.x);
    maxx = max(start.x, end.x);
    miny = min(start.y, end.y);
    maxy = max(start.y, end.y);

    bool test_in = !IsClockwise(start, second, end);
    if (starta > enda)
    {
        float temp = enda;
        enda = starta;
        starta = temp;
        test_in = !test_in;
    }

    if ((starta < PI && PI < enda) == test_in)
        minx = center.x - radius;
    if ((starta < PI / 2 && PI / 2 < enda) == test_in)
        miny = center.y - radius;
    if ((starta < 0 && 0 < enda) == test_in)
        maxx = center.x + radius;
    if ((starta < 3 * PI / 2 && 3 * PI / 2 < enda) == test_in)
        maxy = center.y + radius;

    return wxRect(wxPoint(minx, miny), wxPoint(maxx, maxy));
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
