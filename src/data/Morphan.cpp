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

#include "Morphan.hpp"
#include "Morphan.pb.h"
#include <fstream>

IMPLEMENT_DYNAMIC_CLASS(Morphan, wxDocument)

void Morphan::Dispose()
{
    for (unsigned int i = 0; i < frames.size(); i++)
    {
        frames[i].Dispose();
    }
    frames.clear();
}

void Morphan::Add(int frame, Primitive* primitive)
{
    frames[frame].Add(primitive);
    for (unsigned int i = frame + 1; i < frames.size(); i++)
    {
        frames[i].Add(primitive->Copy());
    }
}

void Morphan::Add(int frame)
{
    frames.insert(frames.begin() + frame, frames[frame].Copy());
}

void Morphan::Delete(int frame, Primitive* primitive)
{

}

void Morphan::Delete(int frame)
{
    frames[frame].Dispose();
    frames.erase(frames.begin() + frame);
}

bool Morphan::DeleteContents()
{
    Dispose();
    return true;
}

bool Morphan::DoSaveDocument(const wxString& file)
{
    std::ofstream out(file.c_str());
    if (!out.good()) return false;

    MorphanProto morphproto;
    for (unsigned int i = 0; i < frames.size(); i++)
    {
        const MorphanKeyFrame& frame = frames[i];
        MorphanKeyFrameProto* mkfproto = morphproto.add_frames();
        frame.Write(mkfproto);
    }

    bool ret = morphproto.SerializeToOstream(&out);
    out.close();

    return ret;
}

bool Morphan::DoOpenDocument(const wxString& file)
{
    std::ifstream in(file.c_str());
    if (!in.good()) return false;

    MorphanProto morphproto;
    if (!morphproto.ParseFromIstream(&in))
    {
        in.close();
        return false;
    }

    Dispose();
    for (const auto& mkfproto : morphproto.frames())
    {
        frames.push_back(MorphanKeyFrame());
        MorphanKeyFrame& frame = frames.back();
        frame.Read(mkfproto);
    }

    return true;
}

bool Morphan::OnNewDocument()
{
    bool ret = wxDocument::OnNewDocument();
    Dispose();
    frames.push_back(MorphanKeyFrame());
    return ret;
}
