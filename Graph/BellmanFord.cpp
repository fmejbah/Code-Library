/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * Graph: BellmanFord
 */
#include <bits/stdc++.h>

using namespace std;

#define M 305
#define cycle -33

vector<int> e[M], c[M];
int n, d[M], p[M]; // d is for distance, p for predecessor
int inf = 1<<29; // 2^29, infinity

int bellmanFord( int s, int f )
{
  for( int i = 0; i < n; i++ )
  {
    d[i] = (i == s) ? 0 : inf;
    p[i] = -1;
  }
  // updating the shortest paths
  for( int k = 0; i < n; i++ )
  {
    bool done = 1;
    // the following two loops iterates
    // on the whole set of edges
    for( int i = 0; i < n; i++ ) // for each node i
    {
      for( int j = 0; j < e[i].size(); j++ )  // each edge of i
      {
        int u = i, v = e[i][j], uv = c[i][j]; // simplicity
        if( d[u] + uv < d[v] )
        {
          d[v] = d[u] + uv;
          p[v] = u; // the best way to come to v is through u
          done = false; // found something to update
        }
      }
    }
    if(done) break; // there was nothing to update
  }
  // looking for cycle
  for( int i = 0; i < n; i++ )   // for each node i
  {
    for( int j = 0; j < e[i].size(); j++ )  // for each edge of node i
    {
      int u = i, v = e[i][j], uv = c[i][j]; // simplicity!
      if( d[u] + uv < d[v] ) return cycle; // we found cycle
    }
  }
  return d[f];
}
