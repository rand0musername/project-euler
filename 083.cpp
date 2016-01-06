// RandomUsername (Nikola Jovanovic)
// Project Euler
// 083

#include <bits/stdc++.h>
#define DBG false
#define debug(x) if(DBG) printf("(ln %d) %s = %d\n", __LINE__, #x, x);
#define lld long long
#define ff(i,a,b) for(lld i=a; i<=b; i++)
#define fb(i,a,b) for(lld i=a; i>=b; i--)
#define par pair<int, int>
#define fi first
#define se second
#define mid (l+r)/2
#define INF 1000000000LL
#define MAXN 10005

using namespace std;

struct edg
{
    int i, j, w;
};

struct node
{
    vector<edg> adj;
    bool visited;
    int D;
};

int a[100][100];
node g[100][100];

bool Ok(int i, int j)
{
    if(i < 1 || j < 1 || i > 80 || j > 80)
        return false;
    return true;
}

struct nod
{
    int i, j, D;
};
struct cmp
{
    const bool operator()(const nod a, const nod b)
    const
    {
        return a.D > b.D;
    }
};

void Dijkstra(int ii, int jj)
{
    g[ii][jj].D = 4445;
    priority_queue<nod, vector<nod>, cmp> pq;
    pq.push({ii, jj, 0});
    while(!pq.empty())
    {
        nod curr = pq.top(); pq.pop();
        if(g[curr.i][curr.j].visited)
                continue;
        int limit = g[curr.i][curr.j].adj.size();
        ff(i, 0, limit-1)
        {
            edg eg = g[curr.i][curr.j].adj[i];
            if(g[eg.i][eg.j].visited)
                continue;
            if(g[curr.i][curr.j].D + eg.w < g[eg.i][eg.j].D)
            {
                g[eg.i][eg.j].D =  g[curr.i][curr.j].D + eg.w;
                pq.push({eg.i, eg.j, g[eg.i][eg.j].D});
            }
        }
        g[curr.i][curr.j].visited = true;
    }
}

int main()
{
    freopen("083.in","r",stdin);
    ff(i, 1, 80)
        ff(j, 1, 80)
            scanf("%d", &a[i][j]);
    ff(i, 1, 80)
        ff(j, 1, 80)
        {
            g[i][j].D = INF;
            if(Ok(i-1, j))
                g[i-1][j].adj.push_back({i, j, a[i][j]});
            if(Ok(i+1, j))
                g[i+1][j].adj.push_back({i, j, a[i][j]});
            if(Ok(i, j-1))
                g[i][j-1].adj.push_back({i, j, a[i][j]});
            if(Ok(i, j+1))
                g[i][j+1].adj.push_back({i, j, a[i][j]});
        }
    Dijkstra(1, 1);
    cout<<g[80][80].D<<endl;
    return 0;
}
