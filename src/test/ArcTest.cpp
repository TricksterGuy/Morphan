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

#if !defined( WIN32 )
    #define BOOST_TEST_DYN_LINK
#endif
#define BOOST_TEST_MAIN
#include <boost/test/auto_unit_test.hpp>
#include "Arc.hpp"

struct ArcTest
{
    ArcTest() {}
    ~ArcTest() {}
};

const wxRealPoint pi0_8(100, 0);
const wxRealPoint pi1_8(92.38795325112868, -38.268343236508976);
const wxRealPoint pi2_8(70.71067811865476, -70.71067811865474);
const wxRealPoint pi3_8(38.26834323650898, -92.38795325112868);
const wxRealPoint pi4_8(0, -100);
const wxRealPoint pi5_8(-38.26834323650897, -92.38795325112867);
const wxRealPoint pi6_8(-70.71067811865475, -70.71067811865476);
const wxRealPoint pi7_8(-92.38795325112867, -38.26834323650899);
const wxRealPoint pi8_8(-100, 0);
const wxRealPoint pi9_8(-92.38795325112867, 38.26834323650899);
const wxRealPoint pi10_8(-70.71067811865475, 70.71067811865476);
const wxRealPoint pi11_8(-38.26834323650897, 92.38795325112867);
const wxRealPoint pi12_8(0, 100);
const wxRealPoint pi13_8(38.26834323650898, 92.38795325112868);
const wxRealPoint pi14_8(70.71067811865476, 70.71067811865474);
const wxRealPoint pi15_8(92.38795325112868, 38.268343236508976);

BOOST_FIXTURE_TEST_CASE(TestQ12, ArcTest)
{
    wxRect rect = Arc(pi5_8, pi6_8, pi7_8).GetBounds();
    BOOST_REQUIRE_EQUAL(rect.GetLeft(), -92);
    BOOST_REQUIRE_EQUAL(rect.GetTop(), -92);
    BOOST_REQUIRE_EQUAL(rect.GetRight(), -38);
    BOOST_REQUIRE_EQUAL(rect.GetBottom(), -38);

    rect = Arc(pi4_8, pi6_8, pi8_8).GetBounds();
    BOOST_REQUIRE_EQUAL(rect.GetLeft(), -100);
    BOOST_REQUIRE_EQUAL(rect.GetTop(), -100);
    BOOST_REQUIRE_EQUAL(rect.GetRight(), 0);
    BOOST_REQUIRE_EQUAL(rect.GetBottom(), 0);

    rect = Arc(pi7_8, pi6_8, pi5_8).GetBounds();
    BOOST_REQUIRE_EQUAL(rect.GetLeft(), -92);
    BOOST_REQUIRE_EQUAL(rect.GetTop(), -92);
    BOOST_REQUIRE_EQUAL(rect.GetRight(), -38);
    BOOST_REQUIRE_EQUAL(rect.GetBottom(), -38);

    rect = Arc(pi8_8, pi6_8, pi4_8).GetBounds();
    BOOST_REQUIRE_EQUAL(rect.GetLeft(), -100);
    BOOST_REQUIRE_EQUAL(rect.GetTop(), -100);
    BOOST_REQUIRE_EQUAL(rect.GetRight(), 0);
    BOOST_REQUIRE_EQUAL(rect.GetBottom(), 0);
}

BOOST_FIXTURE_TEST_CASE(TestQ13, ArcTest)
{
    wxRect rect = Arc(pi2_8, pi4_8, pi6_8).GetBounds();
    BOOST_REQUIRE_EQUAL(rect.GetLeft(), -70);
    BOOST_REQUIRE_EQUAL(rect.GetTop(), -100);
    BOOST_REQUIRE_EQUAL(rect.GetRight(), 70);
    BOOST_REQUIRE_EQUAL(rect.GetBottom(), -70);

    rect = Arc(pi0_8, pi4_8, pi8_8).GetBounds();
    BOOST_REQUIRE_EQUAL(rect.GetLeft(), -100);
    BOOST_REQUIRE_EQUAL(rect.GetTop(), -100);
    BOOST_REQUIRE_EQUAL(rect.GetRight(), 100);
    BOOST_REQUIRE_EQUAL(rect.GetBottom(), 0);

    rect = Arc(pi6_8, pi4_8, pi2_8).GetBounds();
    BOOST_REQUIRE_EQUAL(rect.GetLeft(), -70);
    BOOST_REQUIRE_EQUAL(rect.GetTop(), -100);
    BOOST_REQUIRE_EQUAL(rect.GetRight(), 70);
    BOOST_REQUIRE_EQUAL(rect.GetBottom(), -70);

    rect = Arc(pi8_8, pi4_8, pi0_8).GetBounds();
    BOOST_REQUIRE_EQUAL(rect.GetLeft(), -100);
    BOOST_REQUIRE_EQUAL(rect.GetTop(), -100);
    BOOST_REQUIRE_EQUAL(rect.GetRight(), 100);
    BOOST_REQUIRE_EQUAL(rect.GetBottom(), 0);
}

BOOST_FIXTURE_TEST_CASE(TestQ14, ArcTest)
{
    wxRect rect = Arc(pi14_8, pi2_8, pi6_8).GetBounds();
    BOOST_REQUIRE_EQUAL(rect.GetLeft(), -70);
    BOOST_REQUIRE_EQUAL(rect.GetTop(), -100);
    BOOST_REQUIRE_EQUAL(rect.GetRight(), 100);
    BOOST_REQUIRE_EQUAL(rect.GetBottom(), 70);

    rect = Arc(pi12_8, pi2_8, pi8_8).GetBounds();
    BOOST_REQUIRE_EQUAL(rect.GetLeft(), -100);
    BOOST_REQUIRE_EQUAL(rect.GetTop(), -100);
    BOOST_REQUIRE_EQUAL(rect.GetRight(), 100);
    BOOST_REQUIRE_EQUAL(rect.GetBottom(), 100);

    rect = Arc(pi6_8, pi2_8, pi14_8).GetBounds();
    BOOST_REQUIRE_EQUAL(rect.GetLeft(), -70);
    BOOST_REQUIRE_EQUAL(rect.GetTop(), -100);
    BOOST_REQUIRE_EQUAL(rect.GetRight(), 100);
    BOOST_REQUIRE_EQUAL(rect.GetBottom(), 70);

    rect = Arc(pi8_8, pi2_8, pi12_8).GetBounds();
    BOOST_REQUIRE_EQUAL(rect.GetLeft(), -100);
    BOOST_REQUIRE_EQUAL(rect.GetTop(), -100);
    BOOST_REQUIRE_EQUAL(rect.GetRight(), 100);
    BOOST_REQUIRE_EQUAL(rect.GetBottom(), 100);
}

BOOST_FIXTURE_TEST_CASE(TestQ11, ArcTest)
{
    wxRect rect = Arc(pi9_8, pi0_8, pi7_8).GetBounds();
    BOOST_REQUIRE_EQUAL(rect.GetLeft(), -92);
    BOOST_REQUIRE_EQUAL(rect.GetTop(), -100);
    BOOST_REQUIRE_EQUAL(rect.GetRight(), 100);
    BOOST_REQUIRE_EQUAL(rect.GetBottom(), 100);

    rect = Arc(pi7_8, pi0_8, pi9_8).GetBounds();
    BOOST_REQUIRE_EQUAL(rect.GetLeft(), -92);
    BOOST_REQUIRE_EQUAL(rect.GetTop(), -100);
    BOOST_REQUIRE_EQUAL(rect.GetRight(), 100);
    BOOST_REQUIRE_EQUAL(rect.GetBottom(), 100);
}
