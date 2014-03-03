#ifndef MORPHAN_KEY_FRAME_HPP
#define MORPHAN_KEY_FRAME_HPP

#include <vector>
#include "Primitive.hpp"

class MorphanKeyFrame
{
    public:
        MorphanKeyFrame() {}
        ~MorphanKeyFrame() {}
    private:
        float secs;
        std::vector<Primitive*> primitives;
};

#endif
