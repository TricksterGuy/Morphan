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

#ifndef ICONS_HPP
#define ICONS_HPP

extern unsigned char Select_png[898];
extern unsigned char Rectangle_png[307];
extern unsigned char Polygon_png[516];
extern unsigned char MovePoint_png[327];
extern unsigned char MoveObject_png[530];
extern unsigned char Line_png[249];
extern unsigned char Ellipse_png[437];
extern unsigned char Duplicate_png[402];
extern unsigned char ConvexPolygon_png[454];
extern unsigned char Circle_png[474];
extern unsigned char BezierCurve_png[349];
extern unsigned char Arc_png[401];

#include <wx/image.h>
#include <wx/bitmap.h>
#include <wx/mstream.h>

#define wxMEMORY_IMAGE( name ) _wxConvertMemoryToImage( name, sizeof( name ) )
#define wxMEMORY_IMAGEEX( name, type ) _wxConvertMemoryToImage( name, sizeof( name ), type )
#define wxMEMORY_BITMAP( name ) _wxConvertMemoryToBitmap( name, sizeof( name ) )
#define wxMEMORY_BITMAPEX( name, type ) _wxConvertMemoryToBitmap( name, sizeof( name ), type )

inline wxImage _wxConvertMemoryToImage(unsigned char* data, int length, wxBitmapType type = wxBITMAP_TYPE_ANY )
{
	wxMemoryInputStream stream( data, length );
	return wxImage( stream, type, -1 );
}

inline wxBitmap _wxConvertMemoryToBitmap(unsigned char* data, int length, wxBitmapType type = wxBITMAP_TYPE_ANY )
{
	wxMemoryInputStream stream( data, length );
	return wxBitmap( wxImage( stream, type, -1 ));
}

#endif
