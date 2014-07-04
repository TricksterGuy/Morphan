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

 #include "MorphanPlayerPanel.hpp"

unsigned long getMilliTime()
{
    //static unsigned long time = -1;
    //time += 1;
    //return time;
    return wxMilliClockToLong(wxGetLocalTimeMillis());
}

MorphanPlayerPanel::MorphanPlayerPanel(wxWindow* Parent, wxWindowID Id, const wxPoint& Position, const wxSize& Size, long Style) :
    wxScrolledCanvas(Parent, Id, Position, Size, Style)
{
    clock.Add(this);
}

MorphanPlayerPanel::~MorphanPlayerPanel()
{

}

void MorphanPlayerPanel::OnDraw(wxDC& dc)
{
    wxGraphicsContext* gc = wxGraphicsContext::Create(this);
    if (!gc) return;

    wxGCDC gcdc(gc);

    long delta = getMilliTime() - time;
    std::map<unsigned int, int>::const_iterator it = time_map.lower_bound(delta);
    it--;
    unsigned long delta_frame = delta - it->first;
    int frame = it->second;
    if (frame == -1) return;

    const MorphanKeyFrame& cur = morphan->Get(frame);
    const MorphanKeyFrame& next = morphan->Get(frame + 1 < morphan->NumFrames() ? frame + 1 : frame);
    unsigned long cur_length = cur.GetSecs() * 1000;

    for (Primitive* p : cur.GetPrimitives())
    {
        Primitive* np = next.FindMatching(p);
        p->Draw(gcdc, np, delta_frame, cur_length);
    }
}

void MorphanPlayerPanel::OnPlay(Morphan* toPlay)
{
    morphan = toPlay;
    time_map.clear();
    unsigned int sum = 0;
    for (int i = 0; i < morphan->NumFrames(); i++)
    {
        MorphanKeyFrame& key_frame = morphan->Get(i);
        int key_time = (int)(key_frame.GetSecs() * 1000);
        time_map[sum] = i;
        sum += key_time;
    }
    time_map[sum] = -1;
    clock.SetFramerate(200);
    clock.Run();
    time = getMilliTime();
}
