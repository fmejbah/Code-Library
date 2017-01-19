/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * Discrete_logarithm.cpp
 * Date: 26 Oct 2016
 */

#include <bits/stdc++.h>

using namespace std;

int Discrete_logarithm( int a, int b, int m ) {
  int n = sqrt(m + 0.) + 1;
  int an = 1;
  for( int i = 0; i < n; i++ )
    an = (an * a) % m;
  map<int, int> vals;
  for( int i = 1, cur = an; i <= n; i++ ) {
    if(!vals.count(cur))
      vals[cur] = i;
    cur = (cur * an) % m;
  }
  for( int i = 0, cur = b; i <= n; i++ ) {
    if(vals.count(cur)) {
      int ans = vals[cur] * n - i;
      if( ans < m ) return ans;
    }
    cur = (cur * a) % m;
  }
  return -1;
}

int main()
{
  puts("Hello, World!");
}
