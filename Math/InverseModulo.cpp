/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * InverseModulo.cpp
 * Date: 26 Oct 2016
 */

#include <bits/stdc++.h>

using namespace std;

int InverseModulo( int a, int m ) {
  int x, y;
  int g = exgcd(a, m, x, y);
  if( g != 1 ) {
    puts("No result");
    return -1;
  }
  x = (x % m + m) % m;
  return x;
}

void InverseModulo( int *A, int m ) {
  A[1] = 1;
  for( int i = 2; i < m; i++ )
    A[i] = (m - (m / i) * r[m/i] % m) % m;
}

int main()
{
  puts("Hello, World!");
}
