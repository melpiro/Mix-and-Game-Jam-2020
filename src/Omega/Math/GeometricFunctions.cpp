#include "Math/GeometricFunctions.h"

namespace O{
namespace math {
namespace geo2d {

/////////////////////////////////////////////////////////////////////////////// POINT
    bool intersect_point_point(const sf::Vector2f& point1, const sf::Vector2f& point2)
    {
        return point1.x == point2.x&&point1.y == point2.y;
    }
    bool intersect_point_cercle(const sf::Vector2f& point, const sf::Vector2f& cercle_center, const float&  radius)
    {
        return math::getDistance(point, cercle_center) <= radius;
    }
    bool intersect_point_ligne(const sf::Vector2f& point, const sf::Vector2f& A, const sf::Vector2f& B)
    {
        sf::Vector2f AP = point - A;
        sf::Vector2f BP = point - B;

        if (BP.x == 0 || BP.y == 0) return BP.x / AP.x == BP.y / AP.y;
        return AP.x / BP.x == AP.y / BP.y;
    }
    bool intersect_point_segment(const sf::Vector2f& point, const sf::Vector2f& A, const sf::Vector2f& B)
    {
        return abs(math::getDistance(point, A) + math::getDistance(point, B) - math::getDistance(A, B)) < 0.00000000001;
    }

    bool intersect_point_AABB(const sf::Vector2f& point, const sf::Vector2f& O, const sf::Vector2f& size)
    {
        if (point.x >= O.x 
            && point.x < O.x + size.x
            && point.y >= O.y 
            && point.y < O.y + size.y)
            return true;
        else
            return false;
    }


    bool intersect_point_convexPolygon(const sf::Vector2f& point, const std::vector<sf::Vector2f>&  poly)
    {
        if (poly.size() == 0) return false;
        for(size_t i=0;i<poly.size();i++)
        {
            sf::Vector2f A = poly[i];
            sf::Vector2f B;
            if (i==poly.size()-1)
                B = poly[0];
            else
                B = poly[i+1];
            sf::Vector2f D,T;
            D.x = B.x - A.x;
            D.y = B.y - A.y;
            T.x = point.x - A.x;
            T.y = point.y - A.y;
            float d = D.x*T.y - D.y*T.x;
            if (d<0)
                return false;
        }
        return true; 
    }
    bool intersect_point_polygon(const sf::Vector2f& point, const std::vector<sf::Vector2f>&  poly)
    {
        sf::Vector2f I;
        I.x = 100000000 + rand()%100;
        I.y = 10000 + rand()%100;
        int nbintersections = 0;
        for(size_t i=0;i<poly.size();i++)
        {
            sf::Vector2f A = poly[i];
            sf::Vector2f B;
            if (i==poly.size()-1)  // si c'est le dernier point, on relie au premier
                B = poly[0];
            else           // sinon on relie au suivant.
                B = poly[i+1];
            bool iseg = O::math::geo2d::intersect_segment_segment(A,B,I,point);
            nbintersections+=iseg;
        }
        if (nbintersections%2==1)  // nbintersections est-il impair ?
            return true;
        else
            return false;
    }


/////////////////////////////////////////////////////////////////////////////// CERCLE
    bool intersect_cercle_point(const sf::Vector2f& cercle_center, const float&  radius, const sf::Vector2f& point)
    {
        return intersect_point_cercle(point, cercle_center, radius);
    }

    bool intersect_cercle_cercle(const sf::Vector2f& cercle1_center, const float&  radius1, const sf::Vector2f& cercle2_center, const float&  radius2)
    {
        return math::getDistance(cercle1_center, cercle2_center) <= radius1 + radius2;
    }
    bool intersect_cercle_ligne(const sf::Vector2f& C, const float&  radius, const sf::Vector2f& A, const sf::Vector2f& B)
    {
        sf::Vector2f V = B - A;
        sf::Vector2f VC = A - C;
        float a = V.x * V.x + V.y * V.y;
        float b = 2.f*(V.x* VC.x + V.y * VC.y);
        float c = VC.x * VC.x + VC.y * VC.y - (radius * radius);
        float d = b*b - 4.f * a * c;

        if (d >= 0 ) return true;
        else return false;
    }
    bool intersect_cercle_segment(const sf::Vector2f& C, const float&  radius, const sf::Vector2f& A, const sf::Vector2f& B)
    {
        if (intersect_point_cercle(A, C, radius) || intersect_point_cercle(B, C, radius)) return true;
        sf::Vector2f V = B - A;
        sf::Vector2f VC = A - C;
        float a = V.x * V.x + V.y * V.y;
        float b = 2.f*(V.x* VC.x + V.y * VC.y);
        float c = VC.x * VC.x + VC.y * VC.y - (radius * radius);
        float d = b*b - 4.f * a * c;

        if (d >= 0 )
        {
            float t = (-b - sqrt(d)) / (2.f * a);
            if (t >= 0 && t <= 1) return true;
            float u = (-b + sqrt(d)) / (2.f * a);
            if (u >= 0 && u <= 1) return true;
        }
        return false;
    }
    bool intersect_cercle_AABB(const sf::Vector2f& cercle_center, const float&  radius, const sf::Vector2f& O, const sf::Vector2f& size)
    {
        if (intersect_point_AABB(cercle_center, O, size)) return true;
        if (intersect_segment_cercle(O,O + sf::Vector2f(size.x, 0), cercle_center, radius)) return true;
        if (intersect_segment_cercle(O + sf::Vector2f(size.x, 0),O + size, cercle_center, radius)) return true;
        if (intersect_segment_cercle(O + size, O + sf::Vector2f(0, size.y), cercle_center, radius)) return true;
        if (intersect_segment_cercle(O + sf::Vector2f(0, size.y), O, cercle_center, radius)) return true;
        return false;
    }
    bool intersect_cercle_convexPolygon(const sf::Vector2f& cercle_center, const float&  radius, const std::vector<sf::Vector2f>&  poly)
    {
        return intersect_cercle_polygon(cercle_center, radius, poly);
    }
    bool intersect_cercle_polygon(const sf::Vector2f& cercle_center, const float&  radius, const std::vector<sf::Vector2f>&  poly)
    {
        if (intersect_point_polygon(cercle_center, poly)) return true;
        for (size_t i = 0; i < poly.size(); i++)
        {
            int i_1 = i + 1;
            if (i_1 == (long int)poly.size()) i_1 = 0;
            if (intersect_segment_cercle(poly[i], poly[i_1], cercle_center, radius)) return true;
        }
        return false;
    }



/////////////////////////////////////////////////////////////////////////////// LIGNE
    bool intersect_ligne_point(const sf::Vector2f& A, const sf::Vector2f& B, const sf::Vector2f& point)
    {
        return intersect_point_ligne(point, A, B);
    }
    bool intersect_ligne_cercle(const sf::Vector2f& A, const sf::Vector2f& B, const sf::Vector2f& cercle_center, const float&  radius)
    {
        return intersect_cercle_ligne(cercle_center, radius, A, B);
    }
    bool intersect_ligne_ligne(const sf::Vector2f& A1, const sf::Vector2f& B1, const sf::Vector2f& A2, const sf::Vector2f& B2)
    {
        sf::Vector2f V1 = B1 - A1;
        sf::Vector2f V2 = B2 - A2;
        //float t = ((V2.y / (V2.x * V1.y)) * (A1.x - A2.x) - A2.y / V1.y - A1.y / V1.y) / ((V2.y*V1.x) / (V2.x*V1.y) - 1);
        return abs(V2.y*V1.x - V2.x*V1.y) > 0.00000000001;
    }
    bool intersect_ligne_segment(const sf::Vector2f& A1, const sf::Vector2f& B1, const sf::Vector2f& A2, const sf::Vector2f& B2)
    {
        sf::Vector2f D,E;
        D.x = B1.x - A1.x;
        D.y = B1.y - A1.y;
        E.x = B2.x - A2.x;
        E.y = B2.y - A2.y;
        float denom = D.x*E.y - D.y*E.x;
        if (abs(denom)<=0.00000000001)
            return false;
        
        float u = - (-D.x*A1.y+D.x*A2.y+D.y*A1.x-D.y*A2.x) / denom;
        if (u<0 || u>=1)
            return false;
        return true;
    }
    bool intersect_ligne_AABB(const sf::Vector2f& A, const sf::Vector2f& B, const sf::Vector2f& O, const sf::Vector2f& size)
    {
        if (intersect_point_AABB(A, O, size)) return true;
        if (intersect_point_AABB(B, O, size)) return true;
        if (intersect_segment_ligne(O,O + sf::Vector2f(size.x, 0), A, B)) return true;
        if (intersect_segment_ligne(O + sf::Vector2f(size.x, 0),O + size, A, B)) return true;
        if (intersect_segment_ligne(O + size, O + sf::Vector2f(0, size.y), A, B)) return true;
        if (intersect_segment_ligne(O + sf::Vector2f(0, size.y), O, A, B)) return true;
        return false;
    }
    bool intersect_ligne_convexPolygon(const sf::Vector2f& A, const sf::Vector2f& B, const std::vector<sf::Vector2f>&  poly)
    {
        return intersect_ligne_polygon(A, B, poly);
    }
    bool intersect_ligne_polygon(const sf::Vector2f& A, const sf::Vector2f& B, const std::vector<sf::Vector2f>&  poly)
    {
        if (intersect_point_polygon(A, poly)) return true;
        if (intersect_point_polygon(B, poly)) return true;
        for (size_t i = 0; i < poly.size(); i++)
        {
            int i_1 = i + 1;
            if (i_1 == (long int)poly.size()) i_1 = 0;
            if (intersect_segment_ligne(poly[i], poly[i_1], A, B)) return true;
        }
        return false;
    }


    
/////////////////////////////////////////////////////////////////////////////// SEGMENT
    bool intersect_segment_point(const sf::Vector2f& A, const sf::Vector2f& B, const sf::Vector2f& point)
    {
        return intersect_point_segment(point, A, B);
    }

    bool intersect_segment_cercle(const sf::Vector2f& A, const sf::Vector2f& B, const sf::Vector2f& cercle_center, const float&  radius)
    {
        return intersect_cercle_segment(cercle_center, radius, A, B);
    }

    bool intersect_segment_ligne(const sf::Vector2f& A1, const sf::Vector2f& B1, const sf::Vector2f& A2, const sf::Vector2f& B2)
    {
        return intersect_ligne_segment(A2, B2, A1, B1);
    }

    bool intersect_segment_segment(const sf::Vector2f& A1, const sf::Vector2f& B1, const sf::Vector2f& A2, const sf::Vector2f& B2)
    {
        sf::Vector2f D,E;
        D.x = B1.x - A1.x;
        D.y = B1.y - A1.y;
        E.x = B2.x - A2.x;
        E.y = B2.y - A2.y;
        float denom = D.x*E.y - D.y*E.x;
        if (abs(denom)<=0.00000000001)
            return false;
        
        float t = - (A1.x*E.y-A2.x*E.y-E.x*A1.y+E.x*A2.y) / denom;
        if (t<0 || t>=1)
            return false;
        float u = - (-D.x*A1.y+D.x*A2.y+D.y*A1.x-D.y*A2.x) / denom;
        if (u<0 || u>=1)
            return false;
        return true;
    }

    bool intersect_segment_AABB(const sf::Vector2f& A, const sf::Vector2f& B, const sf::Vector2f& O, const sf::Vector2f& size)
    {
        if (intersect_point_AABB(A, O, size)) return true;
        if (intersect_point_AABB(B, O, size)) return true;
        if (intersect_segment_segment(O,O + sf::Vector2f(size.x, 0), A, B)) return true;
        if (intersect_segment_segment(O + sf::Vector2f(size.x, 0),O + size, A, B)) return true;
        if (intersect_segment_segment(O + size, O + sf::Vector2f(0, size.y), A, B)) return true;
        if (intersect_segment_segment(O + sf::Vector2f(0, size.y), O, A, B)) return true;
        return false;
    }
    bool intersect_segment_convexPolygon(const sf::Vector2f& A, const sf::Vector2f& B, const std::vector<sf::Vector2f>&  poly)
    {
        return intersect_segment_polygon(A, B, poly);
    }
    bool intersect_segment_polygon(const sf::Vector2f& A, const sf::Vector2f& B, const std::vector<sf::Vector2f>&  poly)
    {
        if (intersect_point_polygon(A, poly)) return true;
        if (intersect_point_polygon(B, poly)) return true;
        for (size_t i = 0; i < poly.size(); i++)
        {
            int i_1 = i + 1;
            if (i_1 == (long int)poly.size()) i_1 = 0;
            if (intersect_segment_segment(poly[i], poly[i_1], A, B)) return true;
        }
        return false;
    }

/////////////////////////////////////////////////////////////////////////////// AABB
    bool intersect_AABB_point(const sf::Vector2f& O, const sf::Vector2f& size, const sf::Vector2f& point)
    {
        return intersect_point_AABB(point, O, size);
    }
    bool intersect_AABB_cercle(const sf::Vector2f& O, const sf::Vector2f& size, const sf::Vector2f& cercle_center, const float&  radius)
    {
        return intersect_cercle_AABB(cercle_center, radius, O, size);
    }
    bool intersect_AABB_ligne(const sf::Vector2f& O, const sf::Vector2f& size, const sf::Vector2f& A, const sf::Vector2f& B)
    {
        return intersect_ligne_AABB(A, B, O, size);
    }
    bool intersect_AABB_segment(const sf::Vector2f& O, const sf::Vector2f& size, const sf::Vector2f& A, const sf::Vector2f& B)
    {
        return intersect_segment_AABB(A, B, O, size);
    }
    bool intersect_AABB_AABB(const sf::Vector2f& O1, const sf::Vector2f& size1, const sf::Vector2f& O2, const sf::Vector2f& size2)
    {
        if((O2.x >= O1.x + size1.x)  
            || (O2.x + size2.x <= O1.x)
            || (O2.y >= O1.y + size1.y)
            || (O2.y + size2.y <= O1.y))
            return false; 
        else
            return true; 
    }
    bool intersect_AABB_convexPolygon(const sf::Vector2f& O, const sf::Vector2f& size, const std::vector<sf::Vector2f>&  poly)
    {
        return intersect_AABB_polygon(O, size, poly);
    }
    bool intersect_AABB_polygon(const sf::Vector2f& O, const sf::Vector2f& size, const std::vector<sf::Vector2f>&  poly)
    {
        std::vector<sf::Vector2f> polyAABB = {
            O, 
            O + sf::Vector2f(size.x, 0),
            O + size,
            O + sf::Vector2f(0, size.y)
        };
        return intersect_polygon_polygon(poly, polyAABB);
    }


    
/////////////////////////////////////////////////////////////////////////////// convexPolygon
    bool intersect_convexPolygon_point(const std::vector<sf::Vector2f>&  poly, const sf::Vector2f& point)
    {
        return intersect_point_convexPolygon(point, poly);
    }
    bool intersect_convexPolygon_cercle(const std::vector<sf::Vector2f>&  poly, const sf::Vector2f& cercle_center, const float&  radius)
    {
        return intersect_cercle_convexPolygon(cercle_center, radius, poly);
    }
    bool intersect_convexPolygon_ligne(const std::vector<sf::Vector2f>&  poly, const sf::Vector2f& A, const sf::Vector2f& B)
    {
        return intersect_ligne_convexPolygon(A, B, poly);
    }
    bool intersect_convexPolygon_segment(const std::vector<sf::Vector2f>&  poly, const sf::Vector2f& A, const sf::Vector2f& B)
    {
        return intersect_segment_convexPolygon(A, B, poly);
    }
    bool intersect_convexPolygon_AABB(const std::vector<sf::Vector2f>&  poly, const sf::Vector2f& O, const sf::Vector2f& size)
    {
        return intersect_AABB_convexPolygon(O, size, poly);
    }
    bool intersect_convexPolygon_convexPolygon(const std::vector<sf::Vector2f>&  poly1, const std::vector<sf::Vector2f>&  poly2)
    {
        return intersect_polygon_polygon(poly1, poly2);
    }
    bool intersect_convexPolygon_polygon(const std::vector<sf::Vector2f>&  poly1, const std::vector<sf::Vector2f>&  poly2)
    {
        return intersect_polygon_polygon(poly1, poly2);
    }

/////////////////////////////////////////////////////////////////////////////// polygon
    bool intersect_polygon_point(const std::vector<sf::Vector2f>&  poly, const sf::Vector2f& point)
    {
        return intersect_point_polygon(point, poly);
    }
    bool intersect_polygon_cercle(const std::vector<sf::Vector2f>&  poly, const sf::Vector2f& cercle_center, const float&  radius)
    {
        return intersect_cercle_polygon(cercle_center, radius, poly);
    }
    bool intersect_polygon_ligne(const std::vector<sf::Vector2f>&  poly, const sf::Vector2f& A, const sf::Vector2f& B)
    {
        return intersect_ligne_polygon(A, B, poly);
    }
    bool intersect_polygon_segment(const std::vector<sf::Vector2f>&  poly, const sf::Vector2f& A, const sf::Vector2f& B)
    {
        return intersect_segment_polygon(A, B, poly);
    }
    bool intersect_polygon_AABB(const std::vector<sf::Vector2f>&  poly, const sf::Vector2f& O, const sf::Vector2f& size)
    {
        return intersect_AABB_polygon(O, size, poly);
    }
    bool intersect_polygon_convexPolygon(const std::vector<sf::Vector2f>&  poly1, const std::vector<sf::Vector2f>&  poly2)
    {
        return intersect_polygon_polygon(poly1, poly2);
    }
    
    bool intersect_polygon_polygon(const std::vector<sf::Vector2f>&  poly1, const std::vector<sf::Vector2f>&  poly2)
    {
        if (poly2.size() < poly1.size())
        {
            for (size_t i = 0; i < poly2.size(); i++)
            {
                if (intersect_point_polygon(poly2[i], poly1)) return true;
            }
        }
        else
        {
            for (size_t i = 0; i < poly1.size(); i++)
            {
                if (intersect_point_polygon(poly1[i], poly2)) return true;
            }
        }

        for (size_t i = 0; i < poly1.size(); i++)
        {
            size_t i_1 = i + 1;
            if (i_1 == poly1.size()) i_1 = 0;
            for (size_t j = 0; j < poly2.size(); j++)
            {
                size_t j_1 = j + 1;
                if (j_1 == poly2.size()) j_1 = 0;

                if (intersect_segment_segment(poly1[i],poly1[i_1], poly2[j], poly2[j_1])) return true;
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////
    // CROSS PART
    ///////////////////////////////////////////////////////////////
    
    /////////////////////////////////////////////////////////////// CERCLE
    std::vector<sf::Vector2f> cross_cercle_cercle(const sf::Vector2f& cercle_center1, const float&  radius1, const sf::Vector2f& cercle_center2, const float&  radius2)
    {
        if (cercle_center1.y - cercle_center2.y == 0)
        {
            std::vector<sf::Vector2f> res = cross_cercle_cercle(
                O::math::rotatePointDeg(cercle_center1, 90), radius1,
                O::math::rotatePointDeg(cercle_center2, 90), radius2);
            
            for (size_t i = 0; i < res.size(); i++)
            {
                res[i] = O::math::rotatePointDeg(res[i], - 90);
            }
            return res;
        }


        float coef =  (cercle_center1.x - cercle_center2.x) / (cercle_center1.y - cercle_center2.y);
        float n = (radius2 * radius2 
                - radius1 * radius1 
                - cercle_center2.x * cercle_center2.x 
                + cercle_center1.x * cercle_center1 .x
                - cercle_center2.y * cercle_center2.y 
                + cercle_center1.y * cercle_center1 .y) / (2.f * (cercle_center1.y - cercle_center2.y));

        float a = coef * coef + 1.f;
        float b = 2.f * cercle_center1.y * coef - 2.f * n * coef - 2.f * cercle_center1.x;
        float c = cercle_center1.x * cercle_center1.x 
            + cercle_center1.y * cercle_center1.y 
            + n * n 
            - radius1 * radius1
            - 2.f * cercle_center1.y * n;
        
        float d = b * b - 4.f * a * c;

        if (d == 0)
        {
            sf::Vector2f r(-b / (2.f * a), 0);
            r.y = n - r.x * coef;
            return std::vector<sf::Vector2f> {r};
        }
        else if (d >= 0)
        {
            sf::Vector2f r1((-b - sqrt(d)) / (2.f * a), 0);
            r1.y = n - r1.x * coef;
            sf::Vector2f r2((-b + sqrt(d)) / (2.f * a), 0);
            r2.y = n - r2.x * coef;
            return std::vector<sf::Vector2f> {r1, r2};
        }

        return std::vector<sf::Vector2f>(0);
    }
    std::vector<sf::Vector2f> cross_cercle_ligne(const sf::Vector2f& C, const float&  radius, const sf::Vector2f& A, const sf::Vector2f& B)
    {
        std::vector<sf::Vector2f> res(0);
        sf::Vector2f V = B - A;
        sf::Vector2f VC = A - C;
        float a = V.x * V.x + V.y * V.y;
        float b = 2.f*(V.x* VC.x + V.y * VC.y);
        float c = VC.x * VC.x + VC.y * VC.y - (radius * radius);
        float d = b*b - 4.f * a * c;

        if (d >= 0 )
        {
            float t = (-b - sqrt(d)) / (2.f * a);
            res.push_back(V * t + A);
            float u = (-b + sqrt(d)) / (2.f * a);
            res.push_back(V * u + A);
        }
        return res;
    }
    std::vector<sf::Vector2f> cross_cercle_segment(const sf::Vector2f& C, const float&  radius, const sf::Vector2f& A, const sf::Vector2f& B)
    {
        std::vector<sf::Vector2f> res(0);
        sf::Vector2f V = B - A;
        sf::Vector2f VC = A - C;
        float a = V.x * V.x + V.y * V.y;
        float b = 2.f*(V.x* VC.x + V.y * VC.y);
        float c = VC.x * VC.x + VC.y * VC.y - (radius * radius);
        float d = b*b - 4.f * a * c;

        if (d >= 0 )
        {
            float t = (-b - sqrt(d)) / (2.f * a);
            if (t >= 0 && t <= 1)
            {
                res.push_back(V * t + A);
            }
            float u = (-b + sqrt(d)) / (2.f * a);
            if (u >= 0 && u <= 1)
            {
                res.push_back(V * u + A);
            }
        }
        return res;
    }

    std::vector<sf::Vector2f> cross_cercle_AABB(const sf::Vector2f& cercle_center, const float&  radius, const sf::Vector2f& O, const sf::Vector2f& size)
    {
        std::vector<sf::Vector2f> res;
        O::vector::pushBack(res, cross_segment_cercle(O,O + sf::Vector2f(size.x, 0), cercle_center, radius));
        O::vector::pushBack(res, cross_segment_cercle(O + sf::Vector2f(size.x, 0),O + size, cercle_center, radius));
        O::vector::pushBack(res, cross_segment_cercle(O + size, O + sf::Vector2f(0, size.y), cercle_center, radius));
        O::vector::pushBack(res, cross_segment_cercle(O + sf::Vector2f(0, size.y), O, cercle_center, radius));
        return res;
    }

    std::vector<sf::Vector2f> cross_cercle_convexPolygon(const sf::Vector2f& cercle_center, const float&  radius, const std::vector<sf::Vector2f>&  poly)
    {
        return cross_cercle_polygon(cercle_center, radius, poly);
    }
    std::vector<sf::Vector2f> cross_cercle_polygon(const sf::Vector2f& cercle_center, const float&  radius, const std::vector<sf::Vector2f>&  poly)
    {
        std::vector<sf::Vector2f> res;
        for (size_t i = 0; i < poly.size(); i++)
        {
            size_t i_1 = i + 1;
            if (i_1 == poly.size()) i_1 = 0;
            O::vector::pushBack(res, cross_segment_cercle(poly[i], poly[i_1], cercle_center, radius));
        }
        return res;
    }



    /////////////////////////////////////////////////////////////// LINE
    std::vector<sf::Vector2f> cross_ligne_cercle(const sf::Vector2f& A, const sf::Vector2f& B, const sf::Vector2f& cercle_center, const float&  radius)
    {
        return cross_cercle_ligne(cercle_center, radius, A, B);
    }
    std::vector<sf::Vector2f> cross_ligne_ligne(const sf::Vector2f& A1, const sf::Vector2f& B1, const sf::Vector2f& A2, const sf::Vector2f& B2)
    {
        std::vector<sf::Vector2f> res;
        sf::Vector2f D,E;
        D.x = B1.x - A1.x;
        D.y = B1.y - A1.y;
        E.x = B2.x - A2.x;
        E.y = B2.y - A2.y;
        float denom = D.x*E.y - D.y*E.x;
        if (abs(denom)<=0.00000000001)
        {
            return res;
        }
        float t = - (A1.x*E.y-A2.x*E.y-E.x*A1.y+E.x*A2.y) / denom;
        res.push_back(D * t + A1);
        return res;
    }
    std::vector<sf::Vector2f> cross_ligne_segment(const sf::Vector2f& A1, const sf::Vector2f& B1, const sf::Vector2f& A2, const sf::Vector2f& B2)
    {
        std::vector<sf::Vector2f> res;
        sf::Vector2f D,E;
        D.x = B1.x - A1.x;
        D.y = B1.y - A1.y;
        E.x = B2.x - A2.x;
        E.y = B2.y - A2.y;
        float denom = D.x*E.y - D.y*E.x;
        if (abs(denom)<=0.00000000001)
        {
            return res;
        }
        
        float u = - (-D.x*A1.y+D.x*A2.y+D.y*A1.x-D.y*A2.x) / denom;
        if (u<0 || u>=1)
            return res;
        return std::vector<sf::Vector2f> {E * u + A2};
    }

    std::vector<sf::Vector2f> cross_ligne_AABB(const sf::Vector2f& A, const sf::Vector2f& B, const sf::Vector2f& O, const sf::Vector2f& size)
    {
        std::vector<sf::Vector2f> res;
        O::vector::pushBack(res,cross_ligne_segment(O,O + sf::Vector2f(size.x, 0), A, B));
        O::vector::pushBack(res,cross_ligne_segment(O + sf::Vector2f(size.x, 0),O + size, A, B));
        O::vector::pushBack(res,cross_ligne_segment(O + size, O + sf::Vector2f(0, size.y), A, B));
        O::vector::pushBack(res,cross_ligne_segment(O + sf::Vector2f(0, size.y), O, A, B));
        return res;
    }
    std::vector<sf::Vector2f> cross_ligne_convexPolygon(const sf::Vector2f& A, const sf::Vector2f& B, const std::vector<sf::Vector2f>&  poly)
    {
        return cross_ligne_polygon(A, B, poly);
    }
    std::vector<sf::Vector2f> cross_ligne_polygon(const sf::Vector2f& A, const sf::Vector2f& B, const std::vector<sf::Vector2f>&  poly)
    {
        std::vector<sf::Vector2f> res;
        for (size_t i = 0; i < poly.size(); i++)
        {
            size_t i_1 = i + 1;
            if (i_1 == poly.size()) i_1 = 0;
            O::vector::pushBack(res,cross_segment_ligne(poly[i], poly[i_1], A, B));
        }
        return res;
    }



    /////////////////////////////////////////////////////////////// SEGMENT
    std::vector<sf::Vector2f> cross_segment_cercle(const sf::Vector2f& A, const sf::Vector2f& B, const sf::Vector2f& cercle_center, const float&  radius)
    {
        return cross_cercle_segment(cercle_center, radius, A, B);
    }
    std::vector<sf::Vector2f> cross_segment_ligne(const sf::Vector2f& A1, const sf::Vector2f& B1, const sf::Vector2f& A2, const sf::Vector2f& B2)
    {
        return cross_ligne_segment(A2, B2, A1, B1);
    }
    std::vector<sf::Vector2f> cross_segment_segment(const sf::Vector2f& A1, const sf::Vector2f& B1, const sf::Vector2f& A2, const sf::Vector2f& B2)
    {
        std::vector<sf::Vector2f> res;
        sf::Vector2f D,E;
        D.x = B1.x - A1.x;
        D.y = B1.y - A1.y;
        E.x = B2.x - A2.x;
        E.y = B2.y - A2.y;
        float denom = D.x*E.y - D.y*E.x;
        if (abs(denom)<=0.00000000001)
            return res;
        
        float t = - (A1.x*E.y-A2.x*E.y-E.x*A1.y+E.x*A2.y) / denom;
        if (t<0 || t>=1)
            return res;
        float u = - (-D.x*A1.y+D.x*A2.y+D.y*A1.x-D.y*A2.x) / denom;
        if (u<0 || u>=1)
            return res;
            
        return std::vector<sf::Vector2f> {E * u + A2};
    }
    std::vector<sf::Vector2f> cross_segment_AABB(const sf::Vector2f& A, const sf::Vector2f& B, const sf::Vector2f& O, const sf::Vector2f& size)
    {
        std::vector<sf::Vector2f> res;
        O::vector::pushBack(res,cross_segment_segment(O,O + sf::Vector2f(size.x, 0), A, B));
        O::vector::pushBack(res,cross_segment_segment(O + sf::Vector2f(size.x, 0),O + size, A, B));
        O::vector::pushBack(res,cross_segment_segment(O + size, O + sf::Vector2f(0, size.y), A, B));
        O::vector::pushBack(res,cross_segment_segment(O + sf::Vector2f(0, size.y), O, A, B));
        return res;
    }
    std::vector<sf::Vector2f> cross_segment_convexPolygon(const sf::Vector2f& A, const sf::Vector2f& B, const std::vector<sf::Vector2f>&  poly)
    {
        return cross_segment_polygon(A, B, poly);
    }
    std::vector<sf::Vector2f> cross_segment_polygon(const sf::Vector2f& A, const sf::Vector2f& B, const std::vector<sf::Vector2f>&  poly)
    {
        std::vector<sf::Vector2f> res;
        for (size_t i = 0; i < poly.size(); i++)
        {
            size_t i_1 = i + 1;
            if (i_1 == poly.size()) i_1 = 0;
            O::vector::pushBack(res,cross_segment_segment(poly[i], poly[i_1], A, B));
        }
        return res;
    }
    
    /////////////////////////////////////////////////////////////// AABB
    std::vector<sf::Vector2f> cross_AABB_cercle(const sf::Vector2f& O, const sf::Vector2f& size, const sf::Vector2f& cercle_center, const float&  radius)
    {
        return cross_cercle_AABB(cercle_center, radius, O, size);
    }
    std::vector<sf::Vector2f> cross_AABB_ligne(const sf::Vector2f& O, const sf::Vector2f& size, const sf::Vector2f& A, const sf::Vector2f& B)
    {
        return cross_ligne_AABB(A, B, O, size);
    }
    std::vector<sf::Vector2f> cross_AABB_segment(const sf::Vector2f& O, const sf::Vector2f& size, const sf::Vector2f& A, const sf::Vector2f& B)
    {
        return cross_segment_AABB(A, B, O, size);
    }
    std::vector<sf::Vector2f> cross_AABB_AABB(const sf::Vector2f& O1, const sf::Vector2f& size1, const sf::Vector2f& O2, const sf::Vector2f& size2)
    {
        std::vector<sf::Vector2f> polyAABB = {
            O2, 
            O2 + sf::Vector2f(size2.x, 0),
            O2 + size2,
            O2 + sf::Vector2f(0, size2.y)
        };
        return cross_AABB_polygon(O1, size1, polyAABB);
    }
    std::vector<sf::Vector2f> cross_AABB_convexPolygon(const sf::Vector2f& O, const sf::Vector2f& size, const std::vector<sf::Vector2f>&  poly)
    {
        return cross_AABB_polygon(O, size, poly);
    }
    std::vector<sf::Vector2f> cross_AABB_polygon(const sf::Vector2f& O, const sf::Vector2f& size, const std::vector<sf::Vector2f>&  poly)
    {
        std::vector<sf::Vector2f> polyAABB = {
            O, 
            O + sf::Vector2f(size.x, 0),
            O + size,
            O + sf::Vector2f(0, size.y)
        };
        return cross_polygon_polygon(polyAABB, poly);
    }


   
    /////////////////////////////////////////////////////////////// CONVEX_POLY
    std::vector<sf::Vector2f> cross_convexPolygon_cercle(const std::vector<sf::Vector2f>&  poly, const sf::Vector2f& cercle_center, const float&  radius)
    {
        return cross_cercle_convexPolygon(cercle_center, radius, poly);
    }
    std::vector<sf::Vector2f> cross_convexPolygon_ligne(const std::vector<sf::Vector2f>&  poly, const sf::Vector2f& A, const sf::Vector2f& B)
    {
        return cross_ligne_convexPolygon(A, B, poly);
    }
    std::vector<sf::Vector2f> cross_convexPolygon_segment(const std::vector<sf::Vector2f>&  poly, const sf::Vector2f& A, const sf::Vector2f& B)
    {
        return cross_segment_convexPolygon(A, B, poly);
    }
    std::vector<sf::Vector2f> cross_convexPolygon_AABB(const std::vector<sf::Vector2f>&  poly, const sf::Vector2f& O, const sf::Vector2f& size)
    {
        return cross_AABB_convexPolygon(O, size, poly);
    }
    std::vector<sf::Vector2f> cross_convexPolygon_convexPolygon(const std::vector<sf::Vector2f>&  poly1, const std::vector<sf::Vector2f>&  poly2)
    {
        return cross_polygon_polygon(poly1, poly2);
    }
    std::vector<sf::Vector2f> cross_convexPolygon_polygon(const std::vector<sf::Vector2f>&  poly1, const std::vector<sf::Vector2f>&  poly2)
    {
        return cross_polygon_polygon(poly1, poly2);
    }


    /////////////////////////////////////////////////////////////// POLY
    std::vector<sf::Vector2f> cross_polygon_cercle(const std::vector<sf::Vector2f>&  poly, const sf::Vector2f& cercle_center, const float&  radius)
    {
        return cross_cercle_polygon(cercle_center, radius, poly);
    }
    std::vector<sf::Vector2f> cross_polygon_ligne(const std::vector<sf::Vector2f>&  poly, const sf::Vector2f& A, const sf::Vector2f& B)
    {
        return cross_ligne_polygon(A, B, poly);
    }
    std::vector<sf::Vector2f> cross_polygon_segment(const std::vector<sf::Vector2f>&  poly, const sf::Vector2f& A, const sf::Vector2f& B)
    {
        return cross_segment_polygon(A, B, poly);
    }
    std::vector<sf::Vector2f> cross_polygon_AABB(const std::vector<sf::Vector2f>&  poly, const sf::Vector2f& O, const sf::Vector2f& size)
    {
        return cross_AABB_polygon(O, size, poly);
    }
    std::vector<sf::Vector2f> cross_polygon_convexPolygon(const std::vector<sf::Vector2f>&  poly1, const std::vector<sf::Vector2f>&  poly2)
    {
        return cross_polygon_polygon(poly1, poly2);
    }
    std::vector<sf::Vector2f> cross_polygon_polygon(const std::vector<sf::Vector2f>&  poly1, const std::vector<sf::Vector2f>&  poly2)
    {
        std::vector<sf::Vector2f> res;
        for (size_t i = 0; i < poly1.size(); i++)
        {
            size_t i_1 = i + 1;
            if (i_1 == poly1.size()) i_1 = 0;
            for (size_t j = 0; j < poly2.size(); j++)
            {
                size_t j_1 = j + 1;
                if (j_1 == poly2.size()) j_1 = 0;

                O::vector::pushBack(res,cross_segment_segment(poly1[i],poly1[i_1], poly2[j], poly2[j_1]));
            }
        }
        return res;
    }


}
}
}