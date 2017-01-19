/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * Graph: FloydWarshall
 */
#include <bits/stdc++.h>

using namespace std;

#define REP(k,n) for( int k = 0; k < n; k++ )
#define M 10

int main() {
    int n, mat[M][M], d[M][M];

    cin >> n;
    REP(i,n) REP(j,n) {
        cin >> mat[i][j];

        if( i != j ) {
            d[i][j] = mat[i][j] != 0 ? mat[i][j] : 1000000;
        }
    }
    REP(k,n) REP(i,n) REP(j,n) d[i][j] = min(d[i][j],d[i][k]+d[k][j]);

    REP(i,n) REP(j,n) {
        cout << d[i][j] << ' ';
        if( j == n-1 ) puts("");
    }
}
