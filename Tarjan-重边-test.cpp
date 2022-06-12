#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e4;
int n = 0,m = 0;
int fa[maxn+10];
int dfn[maxn+10],low[maxn+10];
bool is_cut[maxn+10];
int tim = 0,cnt = 0,ans = 0;
int head[maxn+10];
struct node{
	int to,next,w;
	node(){}
	node(int to1,int next1 = -1,int w1 = 0){
		to = to1;next = next1;w = w1;
	}
}edge[maxn+10];
void add_edge(int from,int to,int w){
	edge[++cnt] = node(to,head[from],w);
	head[from] = cnt;
}
void init(){
	tim = cnt =ans = 0;
	memset(dfn,-1,sizeof(dfn));
	memset(low,-1,sizeof(low));
	memset(fa,-1,sizeof(fa));
	memset(is_cut,false,sizeof(is_cut));
	memset(head,-1,sizeof(head));
}
void Tarjan(int u,int father){
	//cout<<"ha " <<cnt << endl;
	fa[u] = father;
	dfn[u] = low[u] = (++tim);
	for(int i = head[u];i != -1;i = edge[i].next){
		//cout << "i " << i << endl;
		node e = edge[i];
		int v = e.to;
		cout<< v << endl;
		if(dfn[v] == -1){
			Tarjan(v,u);
			low[u] = min(low[v],low[u]);
		}else if(v != father){/*假如v是u的父亲的话，那么这就是无向边中的重边，有重边那么一定不是桥*/
			low[u] = min(low[u],dfn[v]);//dfn[v]可能！=low[v]，所以不能用low[v]代替dfn[v],否则会上翻过头了。
		}
	}
}
void count(){
	for(int i = 1;i <= n;++i){
		if(dfn[i] == -1){
			Tarjan(i,0);
		}
	}
	/*
	int rootson = 0;
	for(int i = 2;i <= n;++i){
		int v = fa[i];
		if(v == 1){//统计根节点子树的个数，根节点的子树个数>=2,就是割点
			++rootson;
		}else{
			if(low[i] >= dfn[v]){//割点的条件 
				is_cut[v] = true;
			}
		}
	}
	*/
	
	for(int i = 1;i <= n;++i){
		int v = fa[i];
		if(v > 0 && low[i] > dfn[v]){//桥（割边）的条件 
			++ans;
		}
	}
}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		init();
		for(int i = 1;i <= m;++i){
			int x = 0,y = 0;
			scanf("%d %d",&x,&y);
			add_edge(x,y,1); add_edge(y,x,1);
		}

		count();
	}	
	
	
	return 0;
}