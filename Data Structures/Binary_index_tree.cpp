#include <bits/stdc++.h>

using namespace std;

const int sz = 1e6, MaxVal;

int tree[sz];

int read(int idx) {
  int sum = 0;
  while (idx > 0) {
    sum += tree[idx];
    idx -= (idx & -idx);
  }
  return sum;
}

void update(int idx, int val) {
  while (idx <= MaxVal) {
    tree[idx] += val;
    idx += (idx & -idx);
  }
}

int range_sum(int i, int j) {
  return read(j) - read(i - 1);
}
