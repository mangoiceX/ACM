#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 2e9
using namespace std;
typedef long long LL;
const int maxn = 3e2;
int n = 0,m = 0;
struct edge{
	int to,cap,rev;
};
vector<edge> g[maxn+10];
int iter[maxn+10],level[maxn+10];
bool vis[maxn+10];
int mp[300][300];////
void add_edge(int from,int to,int cap){
	if(mp[from][to] == -1){

		g[from].push_back(edge{to,cap,g[to].size()});
		mp[from][to] = g[from].size() -1;
	}else{
		g[from][mp[from][to]].cap += cap;
	}
	if(mp[to][from] == -1){
		g[to].push_back(edge{from,0,g[from].size()-1});
		mp[to][from] = g[to].size() -1;
	}
	
}
void bfs(int s){
	memset(vis,false,sizeof(vis)); 
	queue<int> que;
	que.push(s);
	vis[s] = true;
	level[s] = 0;
	while(!que.empty()){
		int u = que.front(); que.pop();
		int size = g[u].size();
		per(i,0,size-1){
			edge& e = g[u][i];
			if(e.cap > 0 && !vis[e.to]){
				que.push(e.to);
				vis[e.to] = true;
				level[e.to] = level[u] + 1;
			}
		}
	}
}

int dfs(int s,int t,int f){
	if(s == t){
		return f;
	}
	int size = g[s].size();
	for(int& i = iter[s];i <= size-1;++i){
		edge& e = g[s][i];
		if(e.cap > 0 && level[e.to] > level[s] ){
			int d = dfs(e.to,t,min(f,e.cap));
			if(d > 0){
				g[e.to][e.rev].cap += d;
				e.cap -= d;
				return d;
			}
		}
	}
	return 0;
}
LL max_flow(int s,int t){
	LL flow = 0;
	while(true){
		int f = 0;
		memset(level,-1,sizeof(level));
		bfs(s);
		memset(iter,0,sizeof(iter));
		if(level[t] == -1){	
			return flow;
		}
		while((f = dfs(s,t,INF)) > 0){
			flow += f;
		}
	}
	return 0;
}
int main(){
	while(~scanf("%d %d",&n,&m)){
		per(i,1,m){//The input includes several cases. 
			g[i].clear();//要在这里清零
		}
		memset(mp,-1,sizeof(mp));
		per(i,1,n){
			int x = 0,y = 0,w = 0;
			scanf("%d %d %d",&x,&y,&w);
			add_edge(x,y,w);
		}
		LL ans = max_flow(1,m);
		printf("%lld\n",ans);
	}


	return 0;
}