/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * Fenwick Tree.cpp
 * Date: 25 Jan 2017
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1003;

int fenwick[N][N];

void update(int x, int y, int val) {
	while (x < N) {
		int y1 = y;
		while (y1 < N) {
			fenwick[x][y1] += val;
			y1 += y1 & -y1;
		}
		x += x & -x;
	}
}

int read(int x, int y) {
	int sum = 0;
	while (x > 0) {
		int y1 = y;
		while (y1 > 0) {
			sum += fenwick[x][y1];
			y1 -= y1 & -y1;
		}
		x -= x & -x;
	}
	return sum;
}