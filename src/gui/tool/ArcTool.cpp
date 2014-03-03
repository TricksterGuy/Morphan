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
    wxRealPoint ab((start.x + second.x) / 2, (start.y + second.y) / 2);
    wxRealPoint abend(-(second.y - start.y) / 2 + ab.x, (second.x - start.x) / 2 + ab.y);

    wxRealPoint bc((end.x + second.x) / 2, (end.y + second.y) / 2);
    wxRealPoint bcend(-(end.y - second.y) / 2 + bc.x, (end.x - second.x) / 2 + bc.y);

    wxRealPoint center;
    if (!line_intersection(ab, abend, bc, bcend, center))
        return;

    wxRealPoint abvec(second.x - start.x, second.y - start.y);
    wxRealPoint bcvec(end.x - second.x, end.y - second.y);
    float cross = abvec.x*bcvec.y - abvec.y*bcvec.x;

    if (cross > 0)
        dc.DrawArc(end, start, center);
    else
        dc.DrawArc(start, end, center);

}

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
