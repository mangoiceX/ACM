#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (b);i >= (b);++i)
#define INF 1e9
using namespace std;
const int maxn = 1e5 + 10;
int n = 0,m = 0,k = 0;
int cnt[2];
int head[2][maxn];
struct Edge{
	int to,nex;
}e[2][maxn];
bool vis[maxn];
map<int,int> mp;
int dist[maxn];
void add_edge(int from,int to,int id){
	e[id][++cnt[id]].to = to;
	e[id][cnt[id]].nex = head[id][from];
	head[id][from] = cnt[id];
}
void init(){
	cnt[0] = cnt[1] = 0;
	memset(head,-1,sizeof(head)); memset(vis,false,sizeof(false));
	memset(dist,0,sizeof(dist));
	mp.clear();
}
bool dfs(int s){
	bool fg = false;
	vis[s] = true;
	for(int i = head[0][s];i != -1;i = e[0][i].nex){
		if(vis[e[0][i].to]){
			continue;
		}
		if(dfs(e[0][i].to)){
			fg = true;
			add_edge(s,e[0][i].to,1); add_edge(e[0][i].to,s,1);
		}
	}
	if(mp[s] == 1 || fg){
		return true;
	}
	return false;
}
int bfs(int s){
	queue<int> que;
	que.push(s);
	dist[s] = 0;
	vis[s] = true;
	while(!que.empty()){
		int u = que.front();
		que.pop();
		for(int i = head[0][u];i != -1;i = e[0][i].nex){
			int v = e[0][i].to;
			if(vis[v]){
				continue;
			}
			que.push(v);
			dist[v] = dist[u] + 1;
			vis[v] = true;
		}
	}
	int no = s,maxv = 0;
	per(i,1,n){
		if(dist[i] > maxv && mp[i] == 1){
			maxv = dist[i];
			no = i;
		}
	}
	return no;
}
int main(){
	while(~scanf("%d %d",&n,&k)){
		init();
		per(i,1,n-1){
			int x = 0,y = 0;
			scanf("%d %d",&x,&y);
			add_edge(x,y,0); add_edge(y,x,0);
		}
		int p = 0;
		per(i,1,k){
			int x = 0;
			scanf("%d",&x);
			mp[x] = 1;
			p = x;
		}
		// dfs(p);//DFS建图出现问题
		memset(vis,false,sizeof(vis)); memset(dist,0,sizeof(dist));
		int x = bfs(p);
		memset(vis,false,sizeof(vis)); memset(dist,0,sizeof(dist));
		int y = bfs(x);
		printf("%d\n",(dist[y] + 1)/2);
	}

	return 0;
}
/*
5 2
1 2
1 3
3 4
1 5
2 3
*/