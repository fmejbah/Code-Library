/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * Graph: Kruskal
 */
#include <bits/stdc++.h>

using namespace std;

struct edge
{
    int u, v, weight;
    bool operator<( const edge& e ) const {
        return weight < e.weight;
    }
}E[20];

int id[20], sz[20], n, e;
vector<int> A[20];

void MakeSet( int x )
{
    id[x] = x;
    sz[x] = 1;
}

int root( int x )
{
    while( x != id[x] ) x = id[x];	//For_Path_compression_id[i]=id[id[i]];
    return x;
}

void Union( int x, int y )
{
    int i = root(x);
    int j = root(y);
    if( i == j ) return;	//Important
    if( sz[i] < sz[j] )
    {
        id[i] = j;
        sz[j] += sz[i];
    }
    else
    {
        id[j] = i;
        sz[i] += sz[j];
    }
}

void MST_KRUSKAL() {
    for( int i = 1; i <= n; i++ ) {
        MakeSet(i);
    }
    sort(E,E+e);
    for( int i = 0; i < e; i++ ) {
        cout << E[i].u << "->" << E[i].v << ": " << E[i].weight << endl;
        if( root(E[i].u) != root(E[i].v) ) {
            //cout << E[i].u << "->" << E[i].v << ": " << E[i].weight << endl;
            cout << "Taken\n";
            A[E[i].u].push_back(E[i].v);
            A[E[i].v].push_back(E[i].u);
            Union(E[i].u,E[i].v);
        }
    }
}

int main() {
    cin >> n >> e;
    for( int i = 0; i < e; i++ ) {
        cin >> E[i].u >> E[i].v >> E[i].weight;
    }
    MST_KRUSKAL();
    for( int i = 1; i <= n; i++ ) {
        cout << i << "->";
        for( int j = 0; j < A[i].size(); j++ ) {
            cout << ' ' << A[i][j];
        }
        cout << endl;
    }
}

/*
9 14
1 2 4
1 8 8
2 3 8
2 8 11
3 4 7
3 6 4
3 9 2
4 5 9
4 6 14
5 6 10
6 7 2
7 8 1
7 9 6
8 9 7
*/
