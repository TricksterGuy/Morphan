#ifndef MORPHAN_DRAW_CONTEXT_HPP
#define MORPHAN_DRAW_CONTEXT_HPP

struct MorphanDrawContext
{
    MorphanDrawContext(wxGCDC& ngcdc, float nopacity) : gcdc(ngcdc), opacity(nopacity) {}
    ~MorphanDrawContext() {}
    wxGCDC& gcdc;
    float opacity;
};

#endif
