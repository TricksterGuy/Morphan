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

#include "PrimitiveFactory.hpp"
#include "Primitives.hpp"

void PrimitiveFactory::Write(Primitive* primitive, PrimitiveProto* proto)
{
    proto->set_type(primitive->GetType());
    proto->set_id(primitive->GetId());
    std::vector<wxRealPoint> points = primitive->GetControlPoints();
    for (const auto& point : points)
    {
        Point* p = proto->add_points();
        p->set_x(point.x);
        p->set_y(point.y);
    }
    Color* colorproto = proto->mutable_outline();
    colorproto->set_r(primitive->GetOutline().Red());
    colorproto->set_g(primitive->GetOutline().Green());
    colorproto->set_b(primitive->GetOutline().Blue());
    colorproto->set_a(primitive->GetOutline().Alpha());

    proto->set_width(primitive->GetWidth());

    colorproto = proto->mutable_fill();
    colorproto->set_r(primitive->GetFill().Red());
    colorproto->set_g(primitive->GetFill().Green());
    colorproto->set_b(primitive->GetFill().Blue());
    colorproto->set_a(primitive->GetFill().Alpha());

    /// Todo fix this
    ConvexPolygon* cp = dynamic_cast<ConvexPolygon*>(primitive);
    if (cp)
    {
        ExtraParams* params = proto->mutable_params();
        params->set_num_sides(cp->GetNumSides());
    }
}

Primitive* PrimitiveFactory::Read(const PrimitiveProto& proto)
{
    Type type = proto.type();
    long id = proto.id();
    std::vector<wxRealPoint> points;
    for (const Point& point : proto.points())
        points.push_back(wxRealPoint(point.x(), point.y()));

    const Color& outlineColor = proto.outline();
    wxColour outline(outlineColor.r(), outlineColor.g(), outlineColor.b(), outlineColor.a());

    int width = proto.width();

    const Color& fillColor = proto.fill();
    wxColour fill(fillColor.r(), fillColor.g(), fillColor.b(), fillColor.a());

    int num_sides = proto.has_params() ? proto.params().num_sides() : 3;

    Primitive* created = NULL;
    ConvexPolygon* cp;

    switch(type)
    {
        case Type::LINE:
            created = new Line();
            break;
        case Type::RECTANGLE:
            created = new Rectangle();
            break;
        case Type::CIRCLE:
            created = new Circle();
            break;
        case Type::CONVEX_POLYGON:
            cp = new ConvexPolygon();
            cp->SetNumSides(num_sides);
            created = cp;
            break;
        case Type::POLYGON:
            created = new Polygon();
            break;
        case Type::ELLIPSE:
            created = new Ellipse();
            break;
        case Type::ARC:
            created = new Arc();
            break;
        case Type::BEZIER_CURVE:
            created = new BezierCurve();
            break;
        default:
            return NULL;
    }

    created->SetId(id);
    if (!created->SetControlPoints(points))
    {
        delete created;
        return NULL;
    }
    created->SetOutline(outline);
    created->SetWidth(width);
    created->SetFill(fill);

    return created;
}
