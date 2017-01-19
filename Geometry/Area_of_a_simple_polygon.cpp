/*###########################################
 *                                          #
 * fb.com/mfmejbah                          #
 * fmejbah@gmail.com                        #
 * Geometry: Area of a simple polygon       #
 * Date: 11/10/15                           #
 *###########################################
 */

#include <bits/stdc++.h>

using namespace std;

struct Point
{
    double x, y;
};

double cross_product( Point a, Point b )
{
    return ( a.x*b.y - a.y*b.x );
}

double area( Point[] vertices, int n )
{
    double sum = 0.0;
    for( int i = 0; i < n; i++ )
        sum += cross_product(vertices[i],vertices[(i+1)%n]);
    return abs(sum)/2.0;
}
