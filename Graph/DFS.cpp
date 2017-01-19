/*
DFS(G,v)   ( v is the vertex where the search starts )
         Stack S := {};   ( start with an empty stack )
         for each vertex u, set visited[u] := false;
         push S, v;
         while (S is not empty) do
            u := pop S;
            if (not visited[u]) then
               visited[u] := true;
               for each unvisited neighbour w of u
                  push S, w;
            end if
         end while
      END DFS()
*/

#include <bits/stdc++.h>

using namespace std;

#define M 15
#define GRAY -1
#define BLACK 0
#define WHITE 1
struct TIME {
    int discover, finish, v;
    bool operator<( const TIME& t ) const {
        return finish > t.finish;
    }
}Time[M];
vector<int> Graph[M], parents(M), color(M);
int t = 0, n;
void dfs_visit( int u ) {
    t = t + 1;
    Time[u].discover = t;
    color[u] = GRAY;
    for( int i = 0; i < Graph[u].size(); i++ ) {
        int v = Graph[u][i];
        if( color[v] == WHITE ) {
            parents[v] = u;
            dfs_visit(v);
            /*
             * count++; for connected component
             */
        }
    }
    color[u] = BLACK;
    t = t + 1;
    Time[u].finish = t;
    Time[u].v = u;
}

void dfs() {
    for( int i = 0; i < M; i++ ) {
        color[i] = WHITE;
        parents[i] = -1;
    }
    dfs_visit(5);
    for( int i = 1; i <= n; i++ ) {
        if( color[i] == WHITE ) {
            dfs_visit(i);
        }
    }
}

int main() {
    int e, u, v;

    cin >> n >> e;
    for( int i = 0; i < e; i++ ) {
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    dfs();

    for( int i = 1; i <= n; i++ ) {
        cout << i << "->" << Time[i].discover << '/' << Time[i].finish << endl;
    }
    /*
     * Topological sort
    sort(Time+1,Time+n+1);
    for( int i = 1; i <= n; i++ ) {
        cout << Time[i].v << ' ';
    }
    */
}


/*
6 8
1 2
1 4
2 5
3 5
3 6
4 2
5 4
6 6
*/
/*
7 12
1 2
1 4
1 5
1 6
2 3
2 5
2 7
3 4
3 5
3 7
4 5
4 6
*/
