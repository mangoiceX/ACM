#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

#define per(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,a,b) for(int i=(a);i>=(b);i--)
#define inf 0x3f3f3f3f

typedef long long LL;
const int maxn=1e4;
const LL mod=1e9+7;

int n = 0,m = 0;
vector<int> g[maxn+10];
int dfn[maxn+10],low[maxn+10];
int fa[maxn+10],sum[maxn+10],out[maxn+10],stac[maxn+10];
int tim = 0,loc = 0,cnt = 0;
void init(){
	tim = 0,loc = 0,cnt = 0;
	memset(dfn,-1,sizeof(dfn));
	memset(low,-1,sizeof(low));
	memset(fa,-1,sizeof(fa));
	memset(sum,0,sizeof(sum));
	memset(out,0,sizeof(out));//初始化为0，不能是-1 
}
void Tarjan(int u){
	dfn[u] = low[u] = (++tim);
	int size = g[u].size();
	stac[++loc] = u;//模拟栈 
	per(i,0,size-1){
		int v = g[u][i];
		if(dfn[v] == -1){
			Tarjan(v);
			low[u] = min(low[u],low[v]);
		}else if(fa[v] == -1){//该点还不属于一个已知的（最大）强连通分量 
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(dfn[u] == low[u]){//将统一个强连通分量的点缩点，最大强连通子图都会被压缩成一个点 
		int len = loc;
		++cnt;
		while(stac[loc] != u){
			fa[stac[loc--]] = cnt;//出栈 
		}
		fa[stac[loc--]] = cnt;
		sum[cnt] = len - loc;
 	}
}
/*
首先跑一遍有向图的tarjan,边跑边压缩。（将每一个最大强连通子图压缩成一个点） 
压缩之后，统计各点的出度，有且只有一个点出度为0时，解是这个压缩点所包含的原节点的个数，其余情况都是0 
*/ 
int main(){
	//std::ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	while(~scanf("%d %d",&n,&m)){
		init();
		per(i,1,m){
			int x = 0,y = 0;
			scanf("%d %d",&x,&y);
			g[x].push_back(y);
		}
		per(i,1,n){
			if(dfn[i] == -1){
				Tarjan(i);
			}
		}
		per(i,1,n){//计算出度 
			int size = g[i].size();
			per(j,0,size-1){
				int v = g[i][j];
				if(fa[i] != fa[v]){
					++out[fa[i]];
				}
			}
		}
		int x = 0;
		per(i,1,cnt){//只能有一个出度为0的点 
			if(out[i] == 0){
				if(x > 0){
					printf("0\n");
					return 0;
				}
				x = sum[i];
			}
		}
		printf("%d\n",x);
	}
	
	return 0;
}