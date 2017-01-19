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

long long int prim( int source )
{
    priority_queue< pair<long long int, int> > Q;
    bool s[10001] = {0};
    //memset(s,0,sizeof(s));
    long long int r = 0;
    for( int i = 0; i < edge[source].size(); i++ )
        Q.push(make_pair(-cost[source][i], edge[source][i]));
    s[source] = 1;
    int i = 1;
    while( i < n )
    {
        pair<long long int, int> p = Q.top();
        Q.pop();
        if(!s[p.second])
        {
            i++;
            s[p.second] = 1;
            r += p.first;
            for( int i = 0; i < edge[p.second].size(); i++ )
                Q.push(make_pair(-cost[p.second][i], edge[p.second][i]));
        }
    }
    return -r;
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

