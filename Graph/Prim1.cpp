/*###########################################
 *                                          #
 * fb.com/mfmejbah                          #
 * fmejbah@gmail.com                        #
 * Algorithm: MST Prim                      # 
 * Date: 27/10/15                           #
 *###########################################
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> edge[10001];
vector<long long int> cost[10001];
int n;

struct data
{
    int v;
    long long int w;
    bool operator<( const data &a ) const
    {
        return w > a.w;
    }
}d, p;

long long int prim( int source )
{
    priority_queue<data> Q;
    bool s[10001] = {0};
    long long int r = 0;
    for( int i = 0; i < edge[source].size(); i++ )
    {
        d.v = edge[source][i];
        d.w = cost[source][i];
        Q.push(d);
    }
    s[source] = 1;
    while(!Q.empty())
    {
        d = Q.top();
        Q.pop();
        if(!s[d.v])
        {
            s[d.v] = 1;
            r += d.w;
            for( int i = 0; i < edge[d.v].size(); i++ )
            {
                p.v = edge[d.v][i];
                p.w = cost[d.v][i];
                Q.push(p);
            }
        }
    }
    return r;
}

int main()
{
    int e, u, v;
    long long w;

    scanf("%d%d", &n, &e);
    for( int i = 0; i < e; i++ )
    {
        scanf("%d%d%lld", &u, &v, &w); 
        edge[u].push_back(v);
        edge[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    printf("%lld\n", prim(1));
    return 0;
}
