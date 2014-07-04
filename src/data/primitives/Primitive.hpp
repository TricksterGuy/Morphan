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

#ifndef PRIMITIVE_HPP
#define PRIMITIVE_HPP

#include <vector>
#include <chrono>
#include <wx/dcgraph.h>

#include "Morphan.pb.h"

#define PI 3.14159265f

static inline long long timeSinceEpoch()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

class Primitive
{
    public:
        Primitive(unsigned long nid = 0) : id(nid), outline(0, 0, 0), fill(0, 0, 0), width(10) {}
        virtual ~Primitive() {}
        virtual Primitive* Copy() const = 0;
        virtual void Move(float x, float y);
        virtual std::vector<wxRealPoint> GetControlPoints() const = 0;
        virtual bool SetControlPoints(const std::vector<wxRealPoint>& points) = 0;
        virtual wxRect GetBounds() const = 0;
        virtual void Draw(wxGCDC& dc) const;
        virtual void Draw(wxGCDC& dc, Primitive* next, unsigned long delta, unsigned long length) const;
        virtual Type GetType() const {return Type::INVALID;}
        void CopyAttributes(Primitive* primitive, bool same_id = true) const;
        void SetId(long long nid) {id = nid;}
        void SetOutline(const wxColour& ncolor) {outline = ncolor;}
        void SetWidth(float nwidth) {width = nwidth;}
        void SetFill(const wxColour& ncolor) {fill = ncolor;}
        void SetFilled(bool isfilled) {filled = isfilled;}
        long long GetId() const {return id;}
        const wxColour& GetOutline() const {return outline;}
        float GetWidth() const {return width;}
        const wxColour& GetFill() const {return fill;}
        bool IsFilled() const {return filled;}
    private:
        long long id;
    protected:
        wxColour outline, fill;
        /*** Width of outline */
        float width;
        bool filled;
};

static inline float distance(const wxRealPoint& a, const wxRealPoint& b)
{
    return (float) sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

static inline float min(float x, float y) {return x > y ? y : x;}
static inline float max(float x, float y) {return x > y ? x : y;}

static inline float interpolate(int first, int second, unsigned long delta, unsigned long length)
{
    if (first == second) return first;
    float percent = 1.0 * delta / length;
    return first * (1.0f - percent) + second * percent;
}

static inline double interpolate(float first, float second, unsigned long delta, unsigned long length)
{
    if (first == second) return first;
    double percent = 1.0 * delta / length;
    return first * (1.0 - percent) + second * percent;
}

static inline double interpolate(double first, double second, unsigned long delta, unsigned long length)
{
    if (first == second) return first;
    float percent = 1.0 * delta / length;
    return first * (1.0f - percent) + second * percent;
}

static inline wxRealPoint interpolate(const wxRealPoint& first, const wxRealPoint& second, unsigned long delta, unsigned long length)
{
    if (first == second) return first;
    return wxRealPoint(interpolate(first.x, second.x, delta, length), interpolate(first.y, second.y, delta, length));
}

static inline wxColour interpolate(const wxColour& first, const wxColour& second, unsigned long delta, unsigned long length)
{
    if (first == second) return first;
    return wxColour(interpolate(first.Red(), second.Red(), delta, length),
                    interpolate(first.Green(), second.Green(), delta, length),
                    interpolate(first.Blue(), second.Blue(), delta, length),
                    interpolate(first.Alpha(), second.Alpha(), delta, length));
}

#endif
