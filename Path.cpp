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
int tot=0,head[maxn];
struct abcd{
	int to,nxt,id;
	ll f;
}table[2*maxn];
void Ginit(){
	tot=0;mem(table);mem(head);
}
void Add(int x,int y,ll z,int id){
	table[++tot].to=y;
	table[tot].f=z;
	table[tot].nxt=head[x];
	table[tot].id=id;
	head[x]=tot;
}
ll d[maxn][2];
int spfa(int s,int idd)
{
	queue<int > Q;
	while(!Q.empty())
		Q.pop();
	Q.push(s);
	d[s][idd]=0;
	do{
		int u=Q.front();
		Q.pop();
		for(int i=head[u];i;i=table[i].nxt){
			if(d[u][idd]+table[i].f<d[table[i].to][idd])
			{
				d[table[i].to][idd]=d[u][idd]+table[i].f;
				Q.push(table[i].to);
			}
		}
	}while(!Q.empty());
	return 1;
}
const int N=10010;
const ll INF=1000000000000000000;
bool used[N];
struct node{ 
	int to;
	ll cap,rev;
};
vector<node> G[N];
void add_edge(int from,int to,ll cap,int idd) {
    G[from].push_back((node){to,cap,(int)(G[to].size())});
    G[to].push_back((node){from,0,(int)(G[from].size()-1)});
}
ll dfs(int s,int t,ll f){
    if(s==t) return f;
     
    for(int i=0;i<G[s].size();i++){
        node &tmp=G[s][i];
        if(used[tmp.to]==false && tmp.cap>0){
            ll d=dfs(tmp.to,t,min(f,tmp.cap));
            if(d>0){
                tmp.cap-=d;
                G[tmp.to][tmp.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
ll EK(int s,int t){
    ll flow=0;
    for(;;){
        memset(used,false,sizeof(used));
        ll tmp=dfs(s,t,INF);
        if(tmp==0) return flow;
        flow+=tmp;
    }
}
void init(){
	for(int i=0;i<N;i++)
		G[i].clear();
	memset(used,0,sizeof(used));
}

ll xx[maxn],yy[maxn],ww[maxn],ju[maxn];
int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		init();
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			ll x,y,z;scanf("%lld%lld%lld",&x,&y,&z);
			Add(x,y,z,i);
			Add(y,x,z,i);
			ww[i]=z;
			xx[i]=x;
			yy[i]=y;
		}
		for(int i=0;i<=n;i++)
			d[i][1]=d[i][0]=INF;
		int s=1,t=n;
		spfa(s,0);
		ll mn=d[t][0];
		Ginit();
		for(int i=1;i<=m;i++)
			Add(yy[i],xx[i],ww[i],i);
		spfa(t,1);
		int cnt=1;
		for(int i=1;i<=m;i++){
			if(ww[i]+d[xx[i]][0]+d[yy[i]][1]==mn){
				add_edge(xx[i],yy[i],ww[i],cnt++);
			}
		}
		printf("%lld\n",EK(s,t));
	}
	
}
