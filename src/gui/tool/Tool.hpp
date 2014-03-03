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

#ifndef TOOL_HPP
#define TOOL_HPP

#include <vector>
#include <wx/clntdata.h>
#include <wx/dcgraph.h>
#include "Primitive.hpp"

class Tool : public wxClientData
{
    public:
        Tool() {}
        virtual ~Tool() {}
        /*** Creates primitive with current set of control points */
        virtual Primitive* Create() = 0;
        /*** Can create primitive with points given? */
        virtual bool CanCreate() const = 0;
        /*** Can preview object? */
        virtual bool CanPreview() const {return !points.empty();}
        /*** Called before the first point is added to the tool */
        virtual void OnStart() {}
        /*** Shows a preview of tools results on dc passed in with mouse location and state of shift key */
        virtual void Preview(wxGCDC& dc, const wxPoint& mouse, bool is_end) = 0;
        /*** Does tool require user intervention to end since infinite points can be added? (ex. Polygon, Bezier)
             If this returns true then condition for ending because CanCreate && IsInfinitePoint && UserEndsTool
             */
        virtual bool IsInfinitePoint() const {return false;}
        /*** Get Current Set of Points */
        const std::vector<wxRealPoint>& GetPoints() const {return points;}
        /*** Add point as a control point */
        void Add(wxRealPoint point) {points.push_back(point);}
        /*** Clears current object */
        void Clear() {points.clear();}
    protected:
        std::vector<wxRealPoint> points;

};

#endif
