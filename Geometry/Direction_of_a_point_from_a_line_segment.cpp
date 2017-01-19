/*#######################################################
 *                                                      #
 * fb.com/mfmejbah                                      #
 * fmejbah@gmail.com                                    #
 * Geometry: Direction of a point from a line segment   #
 * Date: 11/10/15                                       #
 *#######################################################
 */

#include <bits/stdc++.h>

using namespace std;

const int RIGHT = -1, LEFT = 1, ON_THE_LINE = 0;

struct Point
{
    double x, y;
};

double get_cross_product( Point a, Point b )
{
    return ( a.x*b.y - a.y*b.x );
}

Point subtract( Point a, Point b )
{
    Point r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    return r;
}

int get_direction( Point a, Point b, Point p )
{
    b = subtract(b, a);
    p = subtract(p, a);
    double cross_product = get_cross_product(b, p);
    if( cross_product < 0 ) return RIGHT;
    else if( cross_product > 0 ) return LEFT;
    else return ON_THE_LINE;
}

int get_direction( Point a, Point b, Point p )
{
    /*
     *                   |a.x a.y 1|
     * 2 * Area(a,b,c) = |b.x b.y 1| = (b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x) = (b - a) * (p - a)
     *                   |p.x p.y 1|
     */
    double cross_product = (b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x);
    if( cross_product < 0 ) return RIGHT;
    else if( cross_product > 0 ) return LEFT;
    else return ON_THE_LINE;
}
