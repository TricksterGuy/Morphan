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

#ifndef MODIFY_TOOL_HPP
#define MODIFY_TOOL_HPP

#include <set>
#include <vector>
#include <wx/clntdata.h>
#include <wx/dcgraph.h>
#include "Primitive.hpp"

enum class SelectionMode {ALL, FIRST};

extern wxRealPoint INVALID_POINT;

static inline bool IsValidPoint(const wxRealPoint& point)
{
    return point != INVALID_POINT;
}

struct PrimitiveSelection
{
    PrimitiveSelection(Primitive* nprimitive, int npoint) : primitive(nprimitive), point_id(npoint) {}
    Primitive* primitive;
    int point_id;
    bool operator<(const PrimitiveSelection& rhs) const
    {
        return primitive->GetId() < rhs.primitive->GetId();
    }
};

class ModifyTool : public wxClientData
{
    public:
        ModifyTool() {}
        virtual ~ModifyTool() {}
        virtual std::vector<Primitive*> Modify(const wxRealPoint& origin) = 0;
        /*** Performs the main modification */
        void DoModify(PrimitiveSelection& ps, const wxRealPoint& origin);
        /*** Preview Modification */
        std::set<PrimitiveSelection> PreviewModify(const wxRealPoint& origin);
        /*** Performs the attribute modification */
        void Modify(const wxColour& outline, int width, const wxColour& fill, int isfilled);
        /*** Sets selection mode */
        void SetSelectionMode(SelectionMode nmode) {mode = nmode;}
        /*** Sets selection of primitives */
        void SetSelection(const std::vector<Primitive*>& primitives, const wxRealPoint& point, bool reset = false);
        /*** Selects next object in selection */
        void SelectNext();
        /*** Selects previous object in selection */
        void SelectPrevious();
        /*** Gets selection */
        const std::set<PrimitiveSelection>& GetSelection() const {return selection;}
        /*** Gets selected Object */
        std::set<PrimitiveSelection>::iterator GetSelectedObject() const {return selected_object;}
        /*** Has Selection */
        bool HasSelection() const {return !selection.empty();}
        /*** Clears selection */
        void Clear() {selection.clear(); selected_object = selection.end();}
    protected:
        std::set<PrimitiveSelection> selection;
        std::set<PrimitiveSelection>::iterator selected_object;
        SelectionMode mode;
};

#endif
