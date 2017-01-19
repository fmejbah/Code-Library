/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * Diophantine
 * Date: 30 Oct 2016
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * ax + by = c
 * Given a, b and c find x and y
 * If a = b = 0 depend on c = 0 or not
 * If g|c than it's has a solution otherwise has no solution
 * where g = gcd(a, b)
 * a * xg + b * yg = g
 * a * xg * (c/g) + b * yg * (c/g) = c
 * So x = xg * (c/g) ans y = yg * (c/g)
 */
bool findAnySolution( int a, int b, int c, int &x, int &y, int &g ) {
  g = exgcd(abs(a), abs(b), x, y);
  if( c % g != 0 )
    return false;
  x *= c/g;
  y *= c/g;
  if( a < 0 ) x *= -1;
  if( b < 0 ) y *= -1;
  return true;
}

int main()
{
  //freopen("Diophantine.in", "r", stdin);
  //freopen("Diophantine.out", "w", stdout);
}
