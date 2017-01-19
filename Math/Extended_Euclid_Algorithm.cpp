/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * Extended_Euclid_Algorithm.cpp
 * Date: 26 Oct 2016
 */

#include <bits/stdc++.h>

using namespace std;

int exgcd( int a, int b, int &x, int &y ) {
  if( a == 0 ) {
    x = 0, y = 1;
    return b;
  }
  int x0, y0;
  int g = exgcd(b%a, b, x0, y0);
  x = y0 - b / a * x0;
  y = x0;
  return g;
}

int main()
{
  puts("Hello, World!");
}
