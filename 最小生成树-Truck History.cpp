#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#define INF  1e5
using namespace std;
const int maxn = 2000 + 10;
char str[maxn][10];
bool used[maxn];
int adj[maxn][maxn];
int min_cost[maxn];
int n = 0;
int cal(char * str1,char* str2){
	int ans = 0;
	for(int i = 0;i < 7;++i){
		if(str1[i] != str2[i]){
			++ans;
		}
	}
	return ans;
}
int prime(){
	
	min_cost[1] = 0;
	int res = 0;
	
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
		
		for(int u = 1;u <= n;++u){
			min_cost[u] = min ( min_cost[u], adj[v][u]);
		}
	}
	return res;
}
int main(){
	
	while(scanf("%d",&n) != EOF && n){
		fill(adj[0],adj[0]+maxn*10,INF);
		fill(used,used+maxn,false);
		fill(min_cost,min_cost+maxn,INF);
		
		for(int i = 1;i <= n;++i){
			scanf("%s",str[i]);
		}
		for(int i = 1;i <= n-1;++i){
			for(int j = i + 1;j <= n;++j){
				adj[i][j] = adj[j][i] = cal(str[i],str[j]);
			}
		}
		
		printf("The highest possible quality is 1/%d.\n",prime());
	}
		
	
	
	
	
	return 0;
} 
