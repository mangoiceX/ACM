#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
 
const int maxn = 5000 + 10;
const int INF = 1<<30;
typedef pair<int, int> P;
int N, R;
struct edge
{
    int to, cost;
};
vector<edge> G[maxn];
int dist[maxn];  //最短路径
int dist2[maxn];  //次短路经
void solve()
{
    priority_queue<P, vector<P>, greater<P> > que;
    fill(dist, dist+N, INF);  //最短距离
    fill(dist2, dist2+N, INF); //次短距离
    dist[0] = 0;
    que.push(P(0,0));
    while(!que.empty())
    {
        P p = que.top();
        que.pop();
        int v = p.second, d = p.first;
        if(dist2[v] < d) continue;
        for(int i=0; i<G[v].size(); ++i)
        {
            edge e = G[v][i];
            int d2 = d + e.cost;
            if(dist[e.to]>d2)
            {
                swap(dist[e.to], d2);
                que.push(P(dist[e.to], e.to));
            }
            if(dist2[e.to] > d2 && dist[e.to] < d2)
            {
                dist2[e.to] = d2;
                que.push(P(dist2[e.to], e.to));
            }
        }
    }
    printf("%d\n",dist2[N-1]);
}
 
int main()
{
    int i, a, b, c;
    edge e;
    while(~scanf("%d%d",&N,&R))
    {
        for(i=0; i<R; ++i)
        {
            scanf("%d%d%d", &a, &b, &c);
            a--,b--;
            e.to = b, e.cost = c;
            G[a].push_back(e);
            e.to = a;
            G[b].push_back(e);
        }
        solve();
    }
    return 0;
}

