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

#ifndef CONVEX_POLYGON_HPP
#define CONVEX_POLYGON_HPP

#include "Primitive.hpp"

class ConvexPolygon : public Primitive
{
    public:
        ConvexPolygon() : num_sides(3) {}
        ConvexPolygon(const wxRealPoint& ncenter, const wxRealPoint& nedge, int nsides) : center(ncenter), edge(nedge), num_sides(nsides) {}
        Primitive* Copy() const;
        std::vector<wxRealPoint> GetControlPoints() const;
        bool SetControlPoints(const std::vector<wxRealPoint>& points);
        void Draw(MorphanDrawContext& context) const;
        void Draw(MorphanDrawContext& context, Primitive* next, unsigned long delta, unsigned long length) const;
        Type GetType() const {return Type::CONVEX_POLYGON;}
        wxRect GetBounds() const;
        int GetNumSides() const {return num_sides;}
        void SetNumSides(int sides) {num_sides = sides;}
        static std::vector<wxPoint> GetPoints(const wxRealPoint& center, const wxRealPoint& edge, int sides);
    private:
        wxRealPoint center;
        wxRealPoint edge;
        int num_sides;
};

#endif
