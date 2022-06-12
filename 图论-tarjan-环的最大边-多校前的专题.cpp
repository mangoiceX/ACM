#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
const int maxn = 5e5 + 10;
int n = 0,m = 0;
struct node{
	int to,w;
	node(){}
	node(int x,int y){
		to = x;w = y;
	}
};
vector<node> g[maxn];
int fa[maxn],low[maxn],dfn[maxn],tim = 0,cnt = 0;
bool vis[maxn];
int loc[maxn];
int ans[2000000+10];
int res = -1;
void init(){
	per(i,1,n){
		dfn[i] = -1;
		low[i] = 0;
		fa[maxn] = i;
		g[i].clear();
		vis[i] = false;
	}
	res = 1e4;
	tim = 0;
	cnt = 0;
}
void Tarjan(int u,int pre){
	dfn[u] = low[u] = (++tim);
	int size = g[u].size();
	loc[u] = cnt;
	per(i,0,size-1){
		int v = g[u][i].to;
		if(dfn[v] == -1){
			Tarjan(v,u);
			low[u] = min(low[u],low[v]);
			//ans.push_back(g[u][i].w);
			ans[++cnt] = g[u][i].w;
		}else if(v != pre){
			vis[v] = true;
			low[u] = min(low[u],dfn[v]);
			//ans.push_back(g[u][i].w);
			ans[++cnt] = g[u][i].w;
		}
	}
	if(low[u] == dfn[u]){
		if(vis[u]){
			sort(ans + loc[u] + 1,ans + cnt + 1);
			res = min(res,ans[cnt]);
		}
		cnt = loc[u];
	}
}
void solve(){
	Tarjan(1,-1);
	//per(i,1,n){
	//	printf("%d : %d %d\n",i,dfn[i],low[i]);
	//}
	if(res == 1e4){
		puts("No solution!");
	}else{
		printf("%d\n",res);
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
			g[x].push_back(node(y,w)); g[y].push_back(node(x,w));
		}
		solve();
	}


	return 0;
}
/*
5
7 8 
1 2 3
1 3 10
2 3 4
3 4 1
4 5 1
5 6 5
5 7 11
6 7 2

*/