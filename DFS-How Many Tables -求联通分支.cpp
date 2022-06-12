#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#define INF  1e5
using namespace std;
const int maxn = 1000 + 10;
int n = 0,m = 0;
int adj[maxn][maxn];
bool used[maxn];
int ans = 0;
void dfs(int u){
	used[u] = true;
	for(int i = 1;i <= n;++i){
		if(adj[u][i] != 0 && used[i] == false){
			dfs(i);
		}
	}
}

int main(){
	int T = 0,x = 0,y = 0;
	scanf("%d",&T);
	while(T--){
		fill(adj[0],adj[0] + maxn*maxn,0);
		fill(used,used+maxn,false);
		ans = 0;
		scanf("%d %d",&n,&m);
		for(int i = 0;i < m;++i){
			scanf("%d %d",&x,&y);
			adj[x][y] = adj[y][x] = 1;
		}
		for(int i = 1;i <= n;++i){
			if(used[i] == false){
				dfs(i);
				++ans;
			}
			
		}
		
		printf("%d\n",ans);
	}
	
	
	
	return 0;
}
