#include<bits/stdc++.h>

#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f
typedef long long LL;

using namespace std;
const int maxn = 3e5;
int n = 0,m = 0,q = 0;
struct node{
	int to,w;
	node(){
	}
	node(int a,int b){
		to = a;w = b;
	}
};
vector<node> g[maxn+10];
int num[maxn+10];
bool vis[maxn+10];
void dfs(int s,int w){
	vis[s] = true;
	++num[w];
	int size = g[s].size();
	per(i,0,size-1){
		node v = g[s][i];
		if(!vis[v.to]){
			dfs(v.to,(w+v.w) % q);
		}
	}
}
int main(){
	while(~scanf("%d %d %d",&n,&m,&q)){
		per(i,1,n){
			int u = 0,v = 0,w = 0;
			scanf("%d %d %d",&u,&v,&w);
			g[u].push_back(node(v,w));g[v].push_back(node(u,w));
		}
		memset(vis,false,sizeof(vis));
		dfs(1,0);
		num[0] -= 1;
		LL sum = 0;
		per(i,1,q-1){
			sum += (num[i] * i);
		}	
		printf("%lld\n",sum%q);
	}	
	
	return 0;
} 
