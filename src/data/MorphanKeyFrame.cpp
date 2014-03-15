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

#include "MorphanKeyFrame.hpp"
#include "PrimitiveFactory.hpp"

MorphanKeyFrame::~MorphanKeyFrame()
{
}

void MorphanKeyFrame::Dispose()
{
    for (Primitive* primitive : primitives)
        delete primitive;
    primitives.clear();
}

MorphanKeyFrame MorphanKeyFrame::Copy()
{
    MorphanKeyFrame frame;
    for (Primitive* primitive : primitives)
        frame.Add(primitive->Copy());
    frame.x = x;
    frame.y = y;
    frame.scale_x = scale_x;
    frame.scale_y = scale_y;
    frame.secs = secs;
    frame.opacity = opacity;
    frame.rotation = rotation;

    return frame;
}

void MorphanKeyFrame::Add(Primitive* primitive)
{
    primitives.push_back(primitive);
}

void MorphanKeyFrame::SetPosition(int nx, int ny)
{
    x = nx;
    y = ny;
}

void MorphanKeyFrame::SetScale(float nsx, float nsy)
{
    scale_x = nsx;
    scale_y = nsy;
}

void MorphanKeyFrame::Write(MorphanKeyFrameProto* proto) const
{
    proto->set_x(x);
    proto->set_y(y);
    proto->set_scale_x(scale_x);
    proto->set_scale_y(scale_y);
    proto->set_rotation(rotation);
    proto->set_opacity(opacity);
    proto->set_secs(secs);
    for (unsigned int j = 0; j < primitives.size(); j++)
    {
        PrimitiveProto* pproto = proto->add_primitives();
        PrimitiveFactory::Write(primitives[j], pproto);
    }
}

void MorphanKeyFrame::Read(const MorphanKeyFrameProto& proto)
{
    x = proto.x();
    y = proto.y();
    scale_x = proto.scale_x();
    scale_y = proto.scale_y();
    rotation = proto.rotation();
    opacity = proto.opacity();
    secs = proto.secs();

    for (const auto& pproto : proto.primitives())
    {
        Primitive* primitive = PrimitiveFactory::Read(pproto);
        if (primitive)
            primitives.push_back(primitive);
    }
}
