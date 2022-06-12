#include<bits/stdc++.h>
#define fi first
#define se second 
#define mk make_pair
#define pb push_back
#define P pair<ll,ll>
#define mod 1000000007
#define lowbit(n) n&-n
#define mem(i) memset(i,0,sizeof(i))
#define bcnt(x) __builtin_popcount(x)
#define bcntz(x) __builtin_ctz(x)
using namespace std;
const int maxn=100010;
typedef long long ll;
typedef long double ld; 
int n,m;
int gi(){
    char a=getchar();int b=0;
    while(a<'0'||a>'9')a=getchar();
    while(a>='0'&&a<='9')b=b*10+a-'0',a=getchar();
    return b;
}

ll d[maxn][2];

struct edge{
    ll u,v;
    ll w;
}line[maxn];
vector<edge> G1[maxn];
struct noob
{
    ll dis,pos;
    bool operator < (const noob &node) const{
        return dis > node.dis;
    }
};
void dij(int x,int idd)
{
    priority_queue<noob> Q;
    while (!Q.empty()) 
        Q.pop();
    Q.push((noob){0,x});
    while (!Q.empty())
    {
        noob t=Q.top();
        int u=t.pos;
        Q.pop();
        int tem=t.pos;
        if(d[tem][idd]<t.dis) 
            continue;
        //cout<<u<<" "<<d[u][idd]<<endl;
        for (int i=0;i<G1[u].size();i++)
        {
            ll tv=G1[u][i].v,tu=G1[u][i].u,tw=G1[u][i].w;
            //cout<<tv<<" "<<tu<<" "<<tw<<endl;
            if (d[tv][idd]>d[tu][idd]+tw)
            {
                //cout<<tv<<" "<<d[tu][idd]+tw<<endl;
                d[tv][idd]=d[tu][idd]+tw;
                Q.push((noob){tw,tv});
            } 
        }
    }
}
void add(ll u,ll v,ll w)
{
    G1[u].push_back((edge){u,v,w});
    G1[v].push_back((edge){v,u,w});
}

const int N=10010;
const ll INF=1000000000000000000;
struct edge2  
{  
    ll to,cap, next;  
} g[maxn];  
int head[N], iter[N], level[N];  
int cnt;  
void add_edge(int v, int u, ll cap)  
{  
    g[cnt].to = u, g[cnt].cap = cap, g[cnt].next = head[v], head[v] = cnt++;  
    g[cnt].to = v, g[cnt].cap = 0, g[cnt].next = head[u], head[u] = cnt++;  
}  
bool bfs(int s, int t)  
{  
    memset(level, -1, sizeof(level));  
    queue<int> que;  
    level[s] = 0;  
    que.push(s);  
    while(! que.empty())  
    {  
        // cout << "nima" <<endl;
        int v = que.front();  
        que.pop();  
        for(int i = head[v]; i != -1; i = g[i].next)  
        {  
            // cout << "jiji" << endl;
            int u = g[i].to;  
            if(g[i].cap > 0 && level[u] < 0)  
            {  
                level[u] = level[v] + 1;  
                que.push(u);  
            }  
        }  
    }  
    return level[t] == -1;  
}  
ll dfs(int v, int t,ll f)  
{  
    // cout << "niajfoiad" << endl;
    if(v == t) return f;  
    for(int &i = iter[v]; i != -1; i = g[i].next)  
    {  
        int u = g[i].to;  
        if(g[i].cap > 0 && level[v] < level[u])  
        {  
            ll d = dfs(u, t, min(f, g[i].cap));  
            if(d > 0)  
            {  
                g[i].cap -= d, g[i^1].cap += d;  
                return d;  
            }  
        }  
    }  
    return 0;  
}  
ll dinic(int s, int t)  
{  
    ll flow = 0, f;  
    while(true) {
    // {  cout << "hah" << endl
        if(bfs(s, t)) return flow;  
        memcpy(iter, head, sizeof(head));  
        while((f = dfs(s, t, INF)) > 0)  
            flow += f;  
    }  
} 

void init(){
    cnt=0;
    memset(g,0,sizeof(g));
    for (int i=0;i<=n;i++) 
        G1[i].clear();
    for(int i=0;i<=n;i++)
        d[i][1]=d[i][0]=INF;
}

ll xx[maxn],yy[maxn],ww[maxn],ju[maxn];
int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        init();
        
        for (int i=1;i<=m;i++)
        {
            ll u,v,w;
            scanf("%lld%lld%lld",&u,&v,&w);
            add(u,v,w);
            line[i].u=u;
            line[i].v=v;
            line[i].w=w;
        }
        d[1][0]=0;
        dij(1,0); 
        d[n][1]=0;
        dij(n,1);
        ll mn=d[n][0];
        // int cnt=1;
        for(int i = 0;i <= n;++i){
            head[i] = -1;
        }
        for(int i=1;i<=m;i++){
            if(line[i].w+d[line[i].u][0]+d[line[i].v][1]==mn){
                add_edge(line[i].u,line[i].v,line[i].w);
            }
            else if(line[i].w+d[line[i].v][0]+d[line[i].u][1]==mn){
                add_edge(line[i].v,line[i].u,line[i].w);
            }
        }
        printf("%lld\n",dinic(1,n));
    }
    
}
