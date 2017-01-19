/*#######################################################
 *                                                      #
 * fb.com/mfmejbah                                      #
 * fmejbah@gmail.com                                    #
 * Geometry: Graham Scan algorithm for Convex hull      #
 * Date: 11/10/15                                       #
 *#######################################################
 */

#include <bits/stdc++.h>

using namespace std;

const int CLOCKWISE = -1, COLLINEAR = 0, COUNTERCLOCKWISE = 1;

struct Point
{
    double x, y;
};
/*
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

int get_direction( Point a, Point b, Point c )
{
    b = subtract(b, a);
    c =  subtract(c, a);
    double cross_product = get_cross_product(b, c);
    if( cross_product < 0 ) return CLOCKWISE;
    else if( cross_product > 0 ) return COUNTERCLOCKWISE;
    else return COLLINEAR;
}
*/

stack<Point> hull;
Point vertices[100];
int n;

bool comp( Point a, Point b )
{
    return ((a.x - vertices[0].x) * (b.y - vertices[0].y) - (a.y - vertices[0].y) * (b.x - vertices[0].x)) > 0;
}

int get_direction( Point a, Point b, Point c )
{
    /*
     *                   |a.x a.y 1|
     * 2 * Area(a,b,c) = |b.x b.y 1| = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) = (b - a) * (c - a)
     *                   |c.x c.y 1|
     */
    double cross_product = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if( cross_product < 0 ) return CLOCKWISE;
    else if( cross_product > 0 ) return COUNTERCLOCKWISE;
    else return COLLINEAR;
}

void convexHull()
{
    sort(vertices+1,vertices+n, comp);
    hull.push(vertices[0]);
    hull.push(vertices[1]);
    for( int i = 2; i < n; i++ )
    {
         Point top = hull.top();
         while( get_direction(hull.top(), top, vertices[i]) <= 0 )
             top = hull.top(), hull.pop();
         hull.push(top);
         hull.push(vertices[i]);
    }
}

int main()
{
    scanf("%d", &n);
    for( int i = 0; i < n; i++ )
    {
        scanf("%lf%lf", &vertices[i].x, &vertices[i].y);
        if( vertices[i].y < vertices[0].y ) swap(vertices[i], vertices[0]);
    }
    convexHull();
    while(!hull.empty())
    {
        Point p = hull.top();
        cout << p.x << " " << p.y << endl;
        hull.pop();
    }
    return 0;
}
