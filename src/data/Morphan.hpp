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

#ifndef MORPHAN_HPP
#define MORPHAN_HPP

#include "MorphanKeyFrame.hpp"
#include <wx/docview.h>
#include <vector>

class Morphan : public wxDocument
{
    public:
        Morphan() : frames(1) {}
        ~Morphan() {}
        void Dispose();
        bool DeleteContents();
        int NumFrames() const {return frames.size();}
        const MorphanKeyFrame& Get(int frame) const {return frames[frame];}
        MorphanKeyFrame& Get(int frame) {return frames[frame];}
        const std::vector<MorphanKeyFrame>& GetFrames() const {return frames;}
        /*** Adds primitive to key frame */
        void Add(int frame, Primitive* primitive);
        /*** Adds new key frame */
        void Add(int frame);
        /*** Deletes primitive from frame */
        void Delete(int frame, Primitive* primitive);
        /*** Deletes keyframe */
        void Delete(int frame);
        bool OnNewDocument();
    protected:
        bool DoSaveDocument(const wxString& file);
        bool DoOpenDocument(const wxString& file);
    private:
        std::vector<MorphanKeyFrame> frames;
        DECLARE_DYNAMIC_CLASS(Morphan)
};

#endif
