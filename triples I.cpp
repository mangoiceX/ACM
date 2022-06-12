#include<iostream>
#include<queue>
#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define P pair<ll,ll>
#define INF 0x3f3f3f3f
#define mod 1000000007
#define lowbit(n) n&-n
#define mem(i) memset(i,0,sizeof(i))
#define bcnt(x) __builtin_popcount(x)
#define bcntz(x) __builtin_ctz(x)
using namespace std;
typedef long long ll;
const int MAXN = 100005;
const int MAXM = 111111;
int n,m,mx=-1;
const int maxn=100010;
int tot=0,head2[maxn];
struct abcd{
    int to,nxt,id;
    ll f;
}table[2*maxn];
void Ginit()
{
    tot=0;mem(table);mem(head2);
}
void Add(int x,int y,ll z)
{
    table[++tot].to=y;
    table[tot].f=z;
    table[tot].nxt=head2[x];
    head2[x]=tot;
}
struct abbcd{
    int x,y,w;
}ee[maxn];
int cnt=0;
int yes[maxn],yes2[maxn];
void dfs(int x,int p)
{
    for(int i=head2[x];i;i=table[i].nxt)
    {
        if(table[i].to!=p)
        {
            dfs(table[i].to,x);
            if(yes2[table[i].to])
            {
               ee[cnt].x=table[i].to,ee[cnt].y=x,ee[cnt++].w=1;
                yes2[x]=1;
            }
        }
    }
    if(yes[x]) yes2[x]=1;
}
struct EDGE
{
    int v,next,w;
}edge[MAXN];
int head[MAXN],e;
int q[MAXN],vis[MAXN],d[MAXN];
void init()
{
    e=0;
    memset(head,-1,sizeof(head));
}
void add(int u,int v,int w)
{
    edge[e].v=v;
    edge[e].w=w;
    edge[e].next=head[u];
    head[u]=e++;
}
void bfs(int u)
{
    memset(vis, 0, sizeof(vis));
    queue<int>Q;
    int p,q;
    d[u]=0;
    vis[u]=1;
    Q.push(u);
    while(Q.size())
    {
        p=Q.front();
        Q.pop();
        for(int i=head[p];i!=-1;i=edge[i].next)
        {
            q=edge[i].v;
            if(!vis[q])
            {
                vis[q]=1;
                d[q]=d[p]+edge[i].w;
                Q.push(q);
                if(mx<d[q]) mx=d[q];
            }
        }
    }
}
void init1(){
    memset(head,-1,sizeof((head)));
    cnt = tot = 0;

}
int main()
{
    while(~scanf("%d%d",&n,&m)){
        init1();
        for(int i=0;i<n-1;i++)
        {
            int x,y;scanf("%d%d",&x,&y);
            Add(x,y,1);
            Add(y,x,1);
        }
        for(int i=0;i<m;i++)
        {
            int x;scanf("%d",&x);
            yes[x]=1;
        }
        int flag=0;
        for(int i=1;i<=n;i++)
            if(yes[i])
            {
                flag=i;
                break;
            }
        dfs(flag,0);
        n=cnt+1;
        init();
        for(int i=0;i<cnt;i++)
        {
            int u=ee[i].x,v=ee[i].y,w=ee[i].w;
            add(u,v,w);
            add(v,u,w);
        }
        bfs(flag);
        printf("%d\n",(mx+1)/2);
    }
    return 0;
}
