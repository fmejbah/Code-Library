/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * Graph: Stable Marriage Problem
 * Stable_Marriage_Problem.cpp
 * Date: 27 Aug 2016
 */

#include <bits/stdc++.h>

using namespace std;

int n, x, y, m, m1, w, M[501][501], W[501][501], woman[501], m2w[501], w2m[501];
queue<int> fre;
bool engaged_man[501], engaged_woman[501];

void engaged( int m, int w ) {
  m2w[m] = w;
  w2m[w] = m;
}

void stableMatching() {
  while(!fre.empty()) {
    m = fre.front();
    w = M[m][woman[m]++];
    fre.pop();
    if(!engaged_woman[w]) {
      engaged(m, w);
    } else {
      m1 = w2m[w];
      if( W[w][m1] > W[w][m] ) {
        engaged_man[m1] = 0;
        fre.push(m1);
        engaged(m, w);
      } else {
        fre.push(m);
      }
    }
  }
}

int main()
{
  cin >> n;
  memset(engaged_man, 0, sizeof(engaged_man));
  memset(engaged_woman, 0, sizeof(engaged_woman));
  memset(woman, 0, sizeof(woman));
  for( int i = 1; i <= n; i++ )
    fre.push(i);
}
