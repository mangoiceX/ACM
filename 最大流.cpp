#include<bits/stdc++.h>
using namespace std;
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (b);i >= (b);--i)
typedef long long LL;
#define INF 0x3f3f3f3f
const int maxn = 1e5 + 10;
int n = 0,m = 0;
int s = 0,t = 0,cnt0 = 0,cnt1 = 0,cnt2 = 0;
int head0[maxn*2],head1[maxn*2],head2[maxn*2];//
int d[2][maxn];//分别存储s和t到其他所有点的距离
int dist[maxn];//bfs
struct edge{
	int from,to,w,nex;
};
edge e[2][maxn*2],e2[maxn*2];
struct node{
	int from,to,w;
};
node ef[maxn];
int vis[maxn];
void init(){
	cnt0 = cnt1 = cnt2 = 0;
	per(i,1,2*m){
		head1[i] = head0[i] = head2[i] = -1;
		e[0][i].nex = e[1][i].nex = e2[i].nex = -1;
	}
	per(i,1,n){
		d[0][i] = d[1][i] = INF;
		vis[i] = false;
	}
}
void add_edge(int from,int to,int w,int id){
	if(id == 0){
		e[1][++cnt1] = edge{from,to,w,head1[from]};
		head1[from] = cnt1;
		e[0][++cnt0] = edge{to,from,w,head0[to]};
		head0[to] = cnt0;
	}else{
		e2[++cnt2] = edge{from,to,w ,head2[from]};	
		head2[from] = cnt2;
		e2[++cnt2] = edge{to,from,0,head2[to]};		
		head2[to] = cnt2;
	}	
}

void spfa(int x,int id){
	d[id][x] = 0;
	queue<int> que;
	que.push(x);
	while(!que.empty()){
		int u = que.front();
		que.pop();
		for(int i = (id == 0 ? head1[u] : head0[u]);i != -1;i = e[int(id^1)][i].nex){
			edge& ed = e[int(id^1)][i];
			if(d[id][u] + ed.w < d[id][ed.to]){
				d[id][ed.to] = d[id][u] + ed.w;
				que.push(ed.to); 
			}
			//if(!vis[ed.to]){//这样求出来的最短路会部分错误，不知道为什么
			//	vis[ed.to] = true;
				//que.push(ed.to);
			//}
		}
	}
}
void findpath(){
	per(i,1,m){
		node& v = ef[i];
		if(d[0][v.from] + d[1][v.to] + v.w == d[0][t]){
			add_edge(v.from,v.to,1,1);
		}
	}
}

void bfs(){
	per(i,1,n){
		vis[i] = false;
		dist[i] = -1;
	}
	queue<int> que;
	que.push(s);
	vis[s] = true;
	dist[s] = 0;
	while(!que.empty()){
		int u = que.front();
		que.pop();
		for(int i = head2[u];i != -1;i = e2[i].nex){
			edge& ed = e2[i];
			if(!vis[ed.to] && ed.w > 0){
				que.push(ed.to);
				vis[ed.to] = true;
				dist[ed.to] = dist[u] + 1;
			}	
		}
	}
}
int dfs(int u,int f){
	if(u == t){
		return f;
	}
	vis[u] = true;
	for(int i = head2[u];i != -1;i = e2[i].nex){
		edge& ed = e2[i];
		if(!vis[ed.to] && dist[ed.to] == dist[ed.from] + 1 && ed.w > 0){
			int d = dfs(ed.to,min(f,ed.w));
			if(d > 0){
				ed.w -= d;
				e2[int(i^1)].w += d;
				return d;
			}
		}
	}
	return 0;
}
int maxflow(int s,int t){
	int flow = 0;
	while(true){

		bfs();
		if(dist[t] == -1){
			cout << t << endl;
			return flow;
		}

		memset(vis,false,sizeof(vis));
		int f = 0;
		while((f = dfs(s,INF)) > 0){

			flow += f;
		}
	}
}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		init();
		per(i,1,m){
			int x = 0,y = 0,w = 0;
			scanf("%d %d %d",&x,&y,&w);
			add_edge(x,y,w,0);
			ef[i] = node{x,y,w};
		}
		scanf("%d %d",&s,&t);

		spfa(s,0);

		per(i,1,n){
			vis[i] = false;
		}
		spfa(t,1);

		per(i,1,n){
			vis[i] = false;
		}
		findpath();
		per(i,1,n){
			cout <<d[0][i] << " ji  " << d[1][i] <<endl;
		}
		int ans = maxflow(s,t);
		printf("bebebebbe                 %d\n",ans);
	}


	return 0;
}