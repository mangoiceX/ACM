#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f
typedef long long LL;
using namespace std;
const int maxn = 3e5;
int n = 0,m = 0,cnt = 0;
bool vis[maxn+10];
int f[maxn+10];
int ran[maxn+10];
bool flag = true; 
struct node{
	int from,to,w,id;
};
node edge[maxn+10];
vector<int> g[maxn+10];
void init(){
	memset(ran,0,sizeof(ran));
	per(i,1,n){
		f[i] = i;
	}
}
void dfs(int s){
	vis[s] = true;
	int size = g[s].size();
	per(i,0,size-1){
		int v = g[s][i];
		if(!vis[v]){
			dfs(v);
		}
	}
}
int find(int u){
	if(f[u] == u){
		return u;
	}
	return f[u] = find(f[u]);
}
bool same(int a,int b){
	return find(a) == find(b);
}
void unite(int u,int v){
	v = find(v);u = find(u);
	if(v == u){
		return ;
	}else{
		if(ran[u] > ran[v]){
			f[v] = u;
		}else{
			f[u] = v;
			if(ran[u] == ran[v]){
				++ran[v];
			}
		}
	}
}
bool cmp(node a,node b){
	return a.w < b.w;
}
int kruskal(){
	memset(vis,false,sizeof(vis));
	init();
	int cnt = 0,i = 1,ans = 0;
	while(i <= n*(n-1)/2){
		if(cnt == n-1){
			break;
		}
		if(same(edge[i].from,edge[i].to)){
			++i;
			continue;
		}
		ans += (edge[i].id == 1 ? 0 :edge[i].w);
		vis[i] = true;
		unite(edge[i].to,edge[i].from);
		++cnt;
		++i;
	}
	return ans;
}

int main(){
	while(~scanf("%d",&n)){
		int time = n*(n-1)/2;
		cout << " " << time <<endl;
		per(i,1,time){
			int u = 0,v = 0,w = 0,id = 0;
			scanf("%d %d %d %d",&u,&v,&w,&id);
			edge[i].from = u;edge[i].to = v;edge[i].w = w;edge[i].id = id;
		}
		sort(edge+1,edge+1+m,cmp);

		int ans0 = kruskal();
		
	}
	
	return 0;
} 
