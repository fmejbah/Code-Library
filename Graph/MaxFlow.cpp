#include <bits/stdc++.h>

using namespace std;

const int SIZE = 10;

int n, s, t, G[SIZE][SIZE], previous[SIZE];

bool isPathExist() {
  bool visited[SIZE];
  memset(visited, 0, sizeof visited);
  memset(previous, -1, sizeof previous);
  queue<int> Q;
  Q.push(s);
  visited[s] = 1;
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (int v = 1; v <= n; v++) {
      if (!visited[v] && G[u][v] > 0) {
        visited[v] = 1;
        previous[v] = u;
        Q.push(v);
      }
    }
  }
  return previous[t] != -1;
}

int fordFulkerson() {
  int totalFlow = 0;
  while (isPathExist()) {
    int v = t, minResidualCapacity = INT_MAX;
    while (previous[v] != -1) {
      minResidualCapacity = min(minResidualCapacity, G[previous[v]][v]);
      v = previous[v];
    }
    v = t;
    while (previous[v] != -1) {
      int u = previous[v];
      G[u][v] -= minResidualCapacity;
      G[v][u] += minResidualCapacity;
      v = u;
    }
    totalFlow += minResidualCapacity;
  }
  return totalFlow;
}

int main() { 
  freopen("2input.txt", "r", stdin);
  int m, u, v, c;
  scanf("%d%d%d%d", &n, &m, &s, &t);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &u, &v, &c);
    G[u][v] = c;
  }
  printf("Total Flow: %d\n", fordFulkerson());
}
