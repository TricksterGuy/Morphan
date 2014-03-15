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

 #include "MoveObjectTool.hpp"

std::vector<Primitive*> MoveObjectTool::Modify(const wxRealPoint& origin)
{
    std::vector<Primitive*> new_guys;
    for (const PrimitiveSelection& ps : selection)
    {
        Primitive* new_guy = ps.primitive;
        std::vector<wxRealPoint> controls = new_guy->GetControlPoints();
        wxRealPoint start = controls[ps.point_id];
        float offx = origin.x - start.x;
        float offy = origin.y - start.y;

        new_guy->Move(offx, offy);
    }

    return new_guys;
}
