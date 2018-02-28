#include <bits/stdc++.h>

using namespace std;

#define MAX_NODE 112345
#define MAX_LEN 1123

char s[MAX_LEN];
int node[MAX_NODE][26], root, nnode;
bool isWord[MAX_NODE];

void initialize() {
  root = nnode = 0;
  for (int i = 0; i < 26; i++) {
    node[root][i] = -1;
  }
}

void addWord() {
  scanf("%s", s);
  int len = strlen(s);
  int now = root;
  for (int i = 0; i < len; i++) {
    if (node[now][s[i] - 'a'] == -1) {
      node[now][s[i] - 'a'] = ++nnode;
      for (int j = 0; j < 26; j++) {
        node[nnode][j] = -1;
      }
      isWord[nnode] = false;
    }
    now = node[now][s[i] - 'a'];
  }
  isWord = true;
}

int main() {
}
