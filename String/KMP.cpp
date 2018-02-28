#include <bits/stdc++.h>

using namespace std;

const int sz = 1e5 + 3;

int pi[sz];
string T, P;

void prefix_function() {
  int l = P.length(), now;
  pi[0] = now = -1;
  for (int i = 0; i < l; i++) {
    while (now != -1 && P[now + 1] != P[i]) {
      now = pi[now];
    }
    if (P[now + 1] == P[i]) {
      pi[i] = ++now;
    } else {
      pi[i] = now = -1;
    }
  }
}

bool kmp() {
  prefix_function();
  int n = T.length(), m = P.length(), now = -1;  
  for (int i = 0; i < n; i++) {
    while (now != -1 && P[now + 1] != T[i]) {
      now = pi[now];
    }
    if (P[now + 1] == P[i]) {
      now++;
    } else {
      now = -1;
    }
    if (now == m) {
      return 1;
    }
  }
  return 0;
}

int main() {
}
