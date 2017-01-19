#include <bits/stdc++.h>

using namespace std;

class QuickFind
{
    int *id;
    public:
    QuickFind( int n )
    {
        id = new int[n];
        for( int i = 0; i < n; i++ ) id[i] = i;
    }
    bool connected( int p, int q )
    {
        rerurn id[p] == id[q];
    }
    void Union( int p, int q )
    {
        for( int i = 0; i < n; i++ )
            if( id[i] == id[p] ) id[i] = id[q];
    }
};

class QuickUnion
{
    int *id;
    public:
    QuickUnion( int n )
    {
        id = new int[n];
        for( int i = 0; i < n; i++ ) id[i] = i;
    }
    int root( int p )
    {
        while( p != id[p] ) p = id[p];
        return p;
    }
    bool connected( int p, int q )
    {
        return root(p) == root(q);
    }
    void Union( int p, int q )
    {
        int i = root(p);
        int j = root(q);
        id[i] = j;
    }
};

class QuickUnionFind
{
    int *id, *sz;
    public:
    QuickUnionFind( int n )
    {
        id = new int[n];
        sz = new int[n];
        for( int i = 0; i < n; i++ ) id[i] = i, sz[i] = 1;
    }
    int root( int p )
    {
        while( p != id[p] ) p = id[p];          //For_Path_compression_id[i]=id[id[i]];
        return p;
    }
    bool connected( int p, int q )
    {
        return root(p) == root(q);
    }
    void Union( int p, int q )
    {
        int i = root(p);
        int j = root(q);
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
};

int main()
{
    int n, m, p, q, t;
    cin >> n >> m;
    QuickUnionFind x(n);
    for( int i = 0; i < m; i ++ )
    {
        cin >> t >> p >> q;
        if( t == 0 ) x.Union(p,q);
        else cout << x.connected(p,q) << endl;
    }
    return 0;
}
