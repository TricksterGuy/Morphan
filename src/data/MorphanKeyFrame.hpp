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

#ifndef MORPHAN_KEY_FRAME_HPP
#define MORPHAN_KEY_FRAME_HPP

#include <set>
#include "Primitive.hpp"

class MorphanKeyFrame
{
    public:
        MorphanKeyFrame() : x(0), y(0), scale_x(1.0f), scale_y(1.0f), rotation(0), opacity(100), secs(1.0f) {}
        ~MorphanKeyFrame();
        void Dispose();
        MorphanKeyFrame Copy();
        const std::set<Primitive*> GetPrimitives() const {return primitives;}
        void Add(Primitive* primitive);
        void Delete(Primitive* primitive);
        void Write(MorphanKeyFrameProto* proto) const;
        void Read(const MorphanKeyFrameProto& proto);
        void SetPosition(int nx, int ny);
        void SetScale(float nsx, float nsy);
        void SetRotation(float nrotation) {rotation = nrotation;}
        void SetOpacity(float nopacity) {opacity = nopacity;}
        void SetSecs(float nsecs) {secs = nsecs;}
        void GetPosition(int& nx, int& ny) const {nx = x; ny = y;}
        void GetScale(float& nsx, float& nsy) const {nsx = scale_x; nsy = scale_y;}
        float GetRotation() const {return rotation;}
        float GetOpacity() const {return opacity;}
        float GetSecs() const {return secs;}
    private:
        int x, y;
        float scale_x, scale_y;
        float rotation;
        float opacity;
        float secs;
        std::set<Primitive*> primitives;
};

#endif
