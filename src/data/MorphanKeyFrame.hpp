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

#ifndef MORPHAN_KEY_FRAME_HPP
#define MORPHAN_KEY_FRAME_HPP

#include <set>
#include "Primitive.hpp"

struct PrimitivePtrComp
{
  bool operator()(const Primitive* lhs, const Primitive* rhs) const  {return lhs->GetId() < rhs->GetId();}
};

class MorphanKeyFrame
{
    public:
        MorphanKeyFrame() : x(0), y(0), scale_x(1.0f), scale_y(1.0f), rotation(0), opacity(100), millisecs(1000) {}
        ~MorphanKeyFrame();
        void Dispose();
        MorphanKeyFrame Copy();
        const std::set<Primitive*, PrimitivePtrComp> GetPrimitives() const {return primitives;}
        void Add(Primitive* primitive);
        void Delete(Primitive* primitive);
        Primitive* FindMatching(Primitive* p) const;
        void Write(MorphanKeyFrameProto* proto) const;
        void Read(const MorphanKeyFrameProto& proto);
        void SetPosition(int nx, int ny);
        void SetScale(float nsx, float nsy);
        void SetRotation(float nrotation) {rotation = nrotation;}
        void SetOpacity(float nopacity) {opacity = nopacity;}
        void SetMilliSecs(float nmillisecs) {millisecs = nmillisecs;}
        void GetPosition(int& nx, int& ny) const {nx = x; ny = y;}
        void GetScale(float& nsx, float& nsy) const {nsx = scale_x; nsy = scale_y;}
        float GetRotation() const {return rotation;}
        float GetOpacity() const {return opacity;}
        float GetMilliSecs() const {return millisecs;}
    private:
        int x, y;
        float scale_x, scale_y;
        float rotation;
        float opacity;
        int millisecs;
        std::set<Primitive*, PrimitivePtrComp> primitives;
};

#endif
