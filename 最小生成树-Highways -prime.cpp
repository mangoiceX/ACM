#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#define INF  1e5
using namespace std;
const int maxn = 500 + 10;
int n = 0;
bool used[maxn];
int adj[maxn][maxn];
int min_cost[maxn];
int prime(){
	
	fill(used,used + maxn,false);
	fill(min_cost,min_cost + maxn,INF);
	
	min_cost[1] = 0;
	int res = 0;
	int maxe = 0;
	
	while(true){
		int v = -1;
		for(int u = 1;u <= n;++u){
			if(used[u] == false && (v == -1 || min_cost[u] < min_cost[v])){
				v = u;
			}
		}
		
		if(v == -1){
			break;
		}
		
		used[v] = true;
		res += min_cost[v];
		maxe = max(maxe,min_cost[v]);
		
		for(int u = 1;u <= n;++u){
			min_cost[u] = min(min_cost[u],adj[v][u]);
		}
	}
	return maxe;
}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		fill(adj[0],adj[0] + maxn*maxn,INF);
		scanf("%d",&n);
		for(int i = 1;i <= n;++i){
			for(int j = 1;j <= n;++j){
				scanf("%d",&adj[i][j]);
			}
		}
		int ans = prime();
		printf("%d\n",ans);
		//if(T > 0){
		//	printf("\n");
		//}
	}
	
	
	
	
	
	return 0;
}
