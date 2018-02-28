#include <bits/stdc++.h>

using namespace std;

const int sz = 112345;

int level[sz], table[sz][23], parents[sz], dis[sz];
vector<int> graph[sz], cost[sz];

void dfs(int from, int u, int depth) {
  parents[u] = from;
  level[u] = depth;
  for (int i = 0; i < (int)graph[u].size(); i++) {
    int v = graph[u][i];
    if (v == from) {
      continue;
    }
    dis[v] = dis[u] + cost[u][i];
    dfs(u, v, depth + 1);
  }
}

void lca_init(int N) {
  memset(table, -1, sizeof table);
  for (int i = 0; i < N; i++) {
    table[i][0] = parents[i];
  }
  for (int j = 1; (1 << j) < N; j++) {
    for (int i = 0; i < N; i++) {
      if (table[i][j - 1] != -1) {
        table[i][j] = table[table[i][j - 1]][j - 1];
      }
    }
  }
}

int lca_query(int N, int p, int q) {      // N = number of node
  if (level[p] < level[q]) {
    swap(p, q);
  }

  int log = 0;
  while (1) {
    if ((1 << (log + 1)) > level[p]) {
      break;
    }
    log++;
  }

  for (int i = log; i >= 0; i--) {
    if (level[p] - (1 << i) >= level[q]) {
      p = table[p][i];
    }
  }

  if (p == q) {
    return p;
  }

  for (int i = log; i >= 0; i--) {
    if (table[p][i] != -1 && table[p][i] != table[q][i]) {
      p = table[p][i];
      q = table[q][i];
    }
  }

  return table[p][0];
}

int query(int N, int a, int l) {
  //cout << "p: " << l << endl;
  for (int i = 23; i >= 0; i--) {
    if (l & (1 << i)) {
      a = table[a][i];
    }
  }
  return a;
}

void clear() {
  for (int i = 0; i < sz; i++) {
    graph[i].clear();
    cost[i].clear();
  }
}

int main() {
  int t, N, a, b, c, k, l;
  char s[11];
  scanf("%d", &t);
  while (t--) {
    clear();
    scanf("%d", &N);
    for (int i = 1; i < N; i++) {
      scanf("%d%d%d", &a, &b, &c);
      graph[a].push_back(b);
      graph[b].push_back(a);
      cost[a].push_back(c);
      cost[b].push_back(c);
    }
    memset (parents, -1, sizeof parents);
    memset (dis, 0, sizeof dis);
    dfs(-1, 1, 0);
    lca_init(N + 1);
    /*
    for (int i = 0; i <= N; i++) {
      cout << i << " -> ";
      for (int j = 0; j <= 3; j++) {
        cout << table[i][j] << ' ';
      } puts("");
    }
    */
    while (1) {
      scanf("%s", s);
      if (s[0] == 'D' && s[1] == 'O') {
        break;
      }
      if (s[0] == 'D') {
        scanf("%d%d", &a, &b);
        c = lca_query(N + 1, a, b);
        //cout << a << ' ' << b << ' ';
        c = dis[a] + dis[b] - 2 * dis[c];
        printf("%d\n", c);
      } else {
        scanf("%d%d%d", &a, &b, &k);
        c = lca_query(N + 1, a, b);
        //cout << "level: " << level[a] << ' ' << level[b] << ' ' << level[c] << endl;
        l = level[a] - level[c] + 1;
        //cout << "l: " << l << endl;
        if (l >= k) {
          cout << query(N + 1, a, k - 1) << endl;
        } else {
          l = level[b] - level[c] - k + l;
          //cout << "e_l: " << l << endl;
          cout << query(N + 1, b, l) << endl;
        }
      }
    }
  }
}
