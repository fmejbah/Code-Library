/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * 1176.cpp
 * Date: 14 Oct 2016
 */
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int SIZE = 64;
 
map<string, int> mp;
int n, G[SIZE][SIZE], previous[SIZE];
 
bool IsPathExist( int s, int d ) {
  bool visited[SIZE];
  memset(visited, 0, sizeof(visited));
  memset(previous, -1, sizeof(previous));
  queue<int> Q;
  Q.push(s);
  while(!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for( int i = 1; i <= n; i++ ) {
      if( !visited[i] && G[u][i] > 0 ) {
        visited[i] = 1;
        previous[i] = u;
        Q.push(i);
      }
    }
  }
  return previous[d] != -1;
}
 
int FordFulkerson( int s, int t ) {
  int totalFlow = 0;
 
  while(IsPathExist(s, t)) {
    int x = t, minResCap = INT_MAX;
    while( previous[x] != -1 ) {
      minResCap = min(minResCap, G[previous[x]][x]);
      x = previous[x];
    }
 
    int v = t;
    while( previous[v] != -1 ) {
      int u = previous[v];
      G[u][v] -= minResCap;
      G[v][u] += minResCap;
      v = u;
    }
    totalFlow += minResCap;
  }
  return totalFlow;
}
 
int main()
{
  mp["XXL"] = 1;
  mp["XL"] = 2;
  mp["L"] = 3;
  mp["M"] = 4;
  mp["S"] = 5;
  mp["XS"] = 6;
  int T;
  cin >> T;
  for( int cn = 1; cn <= T; cn++ ) {
    int n1, m;
    cin >> n1 >> m;
    n = m+7;
    memset(G, 0, sizeof(G));
    for( int i = 7; i <= m+6; i++ ) {
      G[0][i] = 1;
      string c1, c2; cin >> c1 >> c2;
      G[i][mp[c1]] = G[i][mp[c2]] = 1;
    }
    for( int i = 1; i < 7; i++ ) {
      G[i][m+7] = n1;
    }
    if( FordFulkerson(0, m+7) == m )
      printf("Case %d: YES\n", cn);
    else
      printf("Case %d: NO\n", cn);
  }
}
