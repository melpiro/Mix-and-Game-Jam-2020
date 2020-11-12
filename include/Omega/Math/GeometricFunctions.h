
#pragma once
#include "MathFunctions.h"
#include "Math/Matrix.h"
#include "SFML/System/Vector2.hpp"
#include "Vector/VectorFunctions.h"


namespace O{
namespace math {
namespace geo2d {

    bool intersect_point_point(const sf::Vector2f& point1, const sf::Vector2f& point2);
    bool intersect_point_cercle(const sf::Vector2f& point, const sf::Vector2f& cercle_center, const float& radius);
    bool intersect_point_ligne(const sf::Vector2f& point, const sf::Vector2f& A, const sf::Vector2f& B);
    bool intersect_point_segment(const sf::Vector2f& point, const sf::Vector2f& A, const sf::Vector2f& B);
    bool intersect_point_AABB(const sf::Vector2f& point, const sf::Vector2f& O, const sf::Vector2f& size);
    bool intersect_point_convexPolygon(const sf::Vector2f& point, const std::vector<sf::Vector2f>& poly);
    bool intersect_point_polygon(const sf::Vector2f& point, const std::vector<sf::Vector2f>& poly);

    bool intersect_cercle_point(const sf::Vector2f& cercle_center, const float& radius, const sf::Vector2f& point);
    bool intersect_cercle_cercle(const sf::Vector2f& cercle_center1, const float& radius1, const sf::Vector2f& cercle_center2, const float& radius2);
    bool intersect_cercle_ligne(const sf::Vector2f& cercle_center, const float& radius, const sf::Vector2f& A, const sf::Vector2f& B);
    bool intersect_cercle_segment(const sf::Vector2f& cercle_center, const float& radius, const sf::Vector2f& A, const sf::Vector2f& B);
    bool intersect_cercle_AABB(const sf::Vector2f& cercle_center, const float& radius, const sf::Vector2f& O, const sf::Vector2f& size);
    bool intersect_cercle_convexPolygon(const sf::Vector2f& cercle_center, const float& radius, const std::vector<sf::Vector2f>& poly);
    bool intersect_cercle_polygon(const sf::Vector2f& cercle_center, const float& radius, const std::vector<sf::Vector2f>& poly);

    bool intersect_ligne_point(const sf::Vector2f& A, const sf::Vector2f& B, const sf::Vector2f& point);
    bool intersect_ligne_cercle(const sf::Vector2f& A, const sf::Vector2f& B, const sf::Vector2f& cercle_center, const float& radius);
    bool intersect_ligne_ligne(const sf::Vector2f& A1, const sf::Vector2f& B1, const sf::Vector2f& A2, const sf::Vector2f& B2);
    bool intersect_ligne_segment(const sf::Vector2f& A1, const sf::Vector2f& B1, const sf::Vector2f& A2, const sf::Vector2f& B2);
    bool intersect_ligne_AABB(const sf::Vector2f& A, const sf::Vector2f& B, const sf::Vector2f& O, const sf::Vector2f& size);
    bool intersect_ligne_convexPolygon(const sf::Vector2f& A, const sf::Vector2f& B, const std::vector<sf::Vector2f>& poly);
    bool intersect_ligne_polygon(const sf::Vector2f& A, const sf::Vector2f& B, const std::vector<sf::Vector2f>& poly);

    bool intersect_segment_point(const sf::Vector2f& A, const sf::Vector2f& B, const sf::Vector2f& point);
    bool intersect_segment_cercle(const sf::Vector2f& A, const sf::Vector2f& B, const sf::Vector2f& cercle_center, const float& radius);
    bool intersect_segment_ligne(const sf::Vector2f& A1, const sf::Vector2f& B1, const sf::Vector2f& A2, const sf::Vector2f& B2);
    bool intersect_segment_segment(const sf::Vector2f& A1, const sf::Vector2f& B1, const sf::Vector2f& A2, const sf::Vector2f& B2);
    bool intersect_segment_AABB(const sf::Vector2f& A, const sf::Vector2f& B, const sf::Vector2f& O, const sf::Vector2f& size);
    bool intersect_segment_convexPolygon(const sf::Vector2f& A, const sf::Vector2f& B, const std::vector<sf::Vector2f>& poly);
    bool intersect_segment_polygon(const sf::Vector2f& A, const sf::Vector2f& B, const std::vector<sf::Vector2f>& poly);

    bool intersect_AABB_point(const sf::Vector2f& O, const sf::Vector2f& size, const sf::Vector2f& point);
    bool intersect_AABB_cercle(const sf::Vector2f& O, const sf::Vector2f& size, const sf::Vector2f& cercle_center, const float& radius);
    bool intersect_AABB_ligne(const sf::Vector2f& O, const sf::Vector2f& size, const sf::Vector2f& A, const sf::Vector2f& B);
    bool intersect_AABB_segment(const sf::Vector2f& O, const sf::Vector2f& size, const sf::Vector2f& A, const sf::Vector2f& B);
    bool intersect_AABB_AABB(const sf::Vector2f& O1, const sf::Vector2f& size1, const sf::Vector2f& O2, const sf::Vector2f& size2);
    bool intersect_AABB_convexPolygon(const sf::Vector2f& O, const sf::Vector2f& size, const std::vector<sf::Vector2f>& poly);
    bool intersect_AABB_polygon(const sf::Vector2f& O, const sf::Vector2f& size, const std::vector<sf::Vector2f>& poly);

    bool intersect_convexPolygon_point(const std::vector<sf::Vector2f>& poly, const sf::Vector2f& point);
    bool intersect_convexPolygon_cercle(const std::vector<sf::Vector2f>& poly, const sf::Vector2f& cercle_center, const float& radius);
    bool intersect_convexPolygon_ligne(const std::vector<sf::Vector2f>& poly, const sf::Vector2f& A, const sf::Vector2f& B);
    bool intersect_convexPolygon_segment(const std::vector<sf::Vector2f>& poly, const sf::Vector2f& A, const sf::Vector2f& B);
    bool intersect_convexPolygon_AABB(const std::vector<sf::Vector2f>& poly, const sf::Vector2f& O, const sf::Vector2f& size);
    bool intersect_convexPolygon_convexPolygon(const std::vector<sf::Vector2f>& poly1, const std::vector<sf::Vector2f>& poly2);
    bool intersect_convexPolygon_polygon(const std::vector<sf::Vector2f>& poly1, const std::vector<sf::Vector2f>& poly2);

    bool intersect_polygon_point(const std::vector<sf::Vector2f>& poly, const sf::Vector2f& point);
    bool intersect_polygon_cercle(const std::vector<sf::Vector2f>& poly, const sf::Vector2f& cercle_center, const float& radius);
    bool intersect_polygon_ligne(const std::vector<sf::Vector2f>& poly, const sf::Vector2f& A, const sf::Vector2f& B);
    bool intersect_polygon_segment(const std::vector<sf::Vector2f>& poly, const sf::Vector2f& A, const sf::Vector2f& B);
    bool intersect_polygon_AABB(const std::vector<sf::Vector2f>& poly, const sf::Vector2f& O, const sf::Vector2f& size);
    bool intersect_polygon_convexPolygon(const std::vector<sf::Vector2f>& poly1, const std::vector<sf::Vector2f>& poly2);
    bool intersect_polygon_polygon(const std::vector<sf::Vector2f>& poly1, const std::vector<sf::Vector2f>& poly2);

    





    std::vector<sf::Vector2f> cross_cercle_cercle(const sf::Vector2f& cercle_center1, const float& radius1, const sf::Vector2f& cercle_center2, const float& radius2);
    std::vector<sf::Vector2f> cross_cercle_ligne(const sf::Vector2f& cercle_center, const float& radius, const sf::Vector2f& A, const sf::Vector2f& B);
    std::vector<sf::Vector2f> cross_cercle_segment(const sf::Vector2f& cercle_center, const float& radius, const sf::Vector2f& A, const sf::Vector2f& B);
    std::vector<sf::Vector2f> cross_cercle_AABB(const sf::Vector2f& cercle_center, const float& radius, const sf::Vector2f& O, const sf::Vector2f& size);
    std::vector<sf::Vector2f> cross_cercle_convexPolygon(const sf::Vector2f& cercle_center, const float& radius, const std::vector<sf::Vector2f>& poly);
    std::vector<sf::Vector2f> cross_cercle_polygon(const sf::Vector2f& cercle_center, const float& radius, const std::vector<sf::Vector2f>& poly);

    std::vector<sf::Vector2f> cross_ligne_cercle(const sf::Vector2f& A, const sf::Vector2f& B, const sf::Vector2f& cercle_center, const float& radius);
    std::vector<sf::Vector2f> cross_ligne_ligne(const sf::Vector2f& A1, const sf::Vector2f& B1, const sf::Vector2f& A2, const sf::Vector2f& B2);
    std::vector<sf::Vector2f> cross_ligne_segment(const sf::Vector2f& A1, const sf::Vector2f& B1, const sf::Vector2f& A2, const sf::Vector2f& B2);
    std::vector<sf::Vector2f> cross_ligne_AABB(const sf::Vector2f& A, const sf::Vector2f& B, const sf::Vector2f& O, const sf::Vector2f& size);
    std::vector<sf::Vector2f> cross_ligne_convexPolygon(const sf::Vector2f& A, const sf::Vector2f& B, const std::vector<sf::Vector2f>& poly);
    std::vector<sf::Vector2f> cross_ligne_polygon(const sf::Vector2f& A, const sf::Vector2f& B, const std::vector<sf::Vector2f>& poly);

    std::vector<sf::Vector2f> cross_segment_cercle(const sf::Vector2f& A, const sf::Vector2f& B, const sf::Vector2f& cercle_center, const float& radius);
    std::vector<sf::Vector2f> cross_segment_ligne(const sf::Vector2f& A1, const sf::Vector2f& B1, const sf::Vector2f& A2, const sf::Vector2f& B2);
    std::vector<sf::Vector2f> cross_segment_segment(const sf::Vector2f& A1, const sf::Vector2f& B1, const sf::Vector2f& A2, const sf::Vector2f& B2);
    std::vector<sf::Vector2f> cross_segment_AABB(const sf::Vector2f& A, const sf::Vector2f& B, const sf::Vector2f& O, const sf::Vector2f& size);
    std::vector<sf::Vector2f> cross_segment_convexPolygon(const sf::Vector2f& A, const sf::Vector2f& B, const std::vector<sf::Vector2f>& poly);
    std::vector<sf::Vector2f> cross_segment_polygon(const sf::Vector2f& A, const sf::Vector2f& B, const std::vector<sf::Vector2f>& poly);

    std::vector<sf::Vector2f> cross_AABB_cercle(const sf::Vector2f& O, const sf::Vector2f& size, const sf::Vector2f& cercle_center, const float& radius);
    std::vector<sf::Vector2f> cross_AABB_ligne(const sf::Vector2f& O, const sf::Vector2f& size, const sf::Vector2f& A, const sf::Vector2f& B);
    std::vector<sf::Vector2f> cross_AABB_segment(const sf::Vector2f& O, const sf::Vector2f& size, const sf::Vector2f& A, const sf::Vector2f& B);
    std::vector<sf::Vector2f> cross_AABB_AABB(const sf::Vector2f& O1, const sf::Vector2f& size1, const sf::Vector2f& O2, const sf::Vector2f& size2);
    std::vector<sf::Vector2f> cross_AABB_convexPolygon(const sf::Vector2f& O, const sf::Vector2f& size, const std::vector<sf::Vector2f>& poly);
    std::vector<sf::Vector2f> cross_AABB_polygon(const sf::Vector2f& O, const sf::Vector2f& size, const std::vector<sf::Vector2f>& poly);

    std::vector<sf::Vector2f> cross_convexPolygon_cercle(const std::vector<sf::Vector2f>& poly, const sf::Vector2f& cercle_center, const float& radius);
    std::vector<sf::Vector2f> cross_convexPolygon_ligne(const std::vector<sf::Vector2f>& poly, const sf::Vector2f& A, const sf::Vector2f& B);
    std::vector<sf::Vector2f> cross_convexPolygon_segment(const std::vector<sf::Vector2f>& poly, const sf::Vector2f& A, const sf::Vector2f& B);
    std::vector<sf::Vector2f> cross_convexPolygon_AABB(const std::vector<sf::Vector2f>& poly, const sf::Vector2f& O, const sf::Vector2f& size);
    std::vector<sf::Vector2f> cross_convexPolygon_convexPolygon(const std::vector<sf::Vector2f>& poly1, const std::vector<sf::Vector2f>& poly2);
    std::vector<sf::Vector2f> cross_convexPolygon_polygon(const std::vector<sf::Vector2f>& poly1, const std::vector<sf::Vector2f>& poly2);

    std::vector<sf::Vector2f> cross_polygon_cercle(const std::vector<sf::Vector2f>& poly, const sf::Vector2f& cercle_center, const float& radius);
    std::vector<sf::Vector2f> cross_polygon_ligne(const std::vector<sf::Vector2f>& poly, const sf::Vector2f& A, const sf::Vector2f& B);
    std::vector<sf::Vector2f> cross_polygon_segment(const std::vector<sf::Vector2f>& poly, const sf::Vector2f& A, const sf::Vector2f& B);
    std::vector<sf::Vector2f> cross_polygon_AABB(const std::vector<sf::Vector2f>& poly, const sf::Vector2f& O, const sf::Vector2f& size);
    std::vector<sf::Vector2f> cross_polygon_convexPolygon(const std::vector<sf::Vector2f>& poly1, const std::vector<sf::Vector2f>& poly2);
    std::vector<sf::Vector2f> cross_polygon_polygon(const std::vector<sf::Vector2f>& poly1, const std::vector<sf::Vector2f>& poly2);


}
}
}