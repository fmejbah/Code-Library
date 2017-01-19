/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * Graph: Dijkstra
 */
#include <bits/stdc++.h>

using namespace std;

#define SZ 100

vector<int> edge[SZ], cost[SZ];
const int infinity = 1000000000;
//edge[i][j] = jth node connected with i
//cost[i][j] = cost of that edge
struct data
{
    int city, dist;
    bool operator < (const data& p) const {
        return dist > p.dist;
    }
};

int dijkstra( int source, int destination )
{
    int d[SZ]; // For storing distance
    data u, v;
    priority_queue<data> q;
    for( int i = 0; i < SZ; i++)
        d[i] = infinity;
    u.city = source, u.dist = 0;
    q.push(u);
    d[source] = 0;
    while(!q.empty())
    {
        u = q.top();
        q.pop();
        for( int i = 0; i < edge[u.city].size(); i++ )
        {
            v.city = edge[u.city][i];
            v.dist = cost[u.city][i] + d[u.city];
            // relaxing
            if(d[v.city] > v.dist) {
                d[v.city] = v.dist;
                q.push(v);
            }
        }
    }
    return d[destination];
}

int main()
{
    int n, e, u, v, w;

    cin >> n >> e;
    for( int i = 0; i < e; i++ )
    {
        cin >> u >> v >> w;
        edge[u].push_back(v);
        edge[v].push_back(u);
        cost[u].push_back(v);
        cost[v].push_back(u);
    }
    cout << dijkstra(1,4) << endl;
}
