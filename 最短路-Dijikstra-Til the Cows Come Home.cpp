#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 1e7
using namespace std;
const int maxn = 1000 + 10;
int t = 0,n = 0;
int d[maxn];
bool used[maxn];
int adj[maxn][maxn];
void dijikstra(int s){
	d[s] = 0;
	//used[s] = true;//这里不能初始化为true,带入试一下 
	while(true){
		int v = -1;
		for(int u = 1;u <= n;++u){
			if(used[u] == false && (v == -1 || d[u] < d[v])){
				v = u;
			}
		}
		if(v == -1){
			break;
		}
		used[v] = true;
		
		for(int u = 1;u <= n;++u){
			if( d[v] + adj[v][u] < d[u]){
				d[u] = d[v] + adj[v][u];
			}
		}
	}
}
void init(){
	
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= n;++j){
			adj[i][j] = adj[j][i] = INF;
		}
		//d[i] = INF;
	}
	fill(d+1,d + n + 1,INF);
	fill(used + 1,used+n+1,false);
	//fill(adj[0],adj[0] + maxn * maxn)
}
int main(){
	while(scanf("%d %d",&t,&n) != EOF){
		init();
		for(int i = 0;i < t;++i){
			int x = 0,y = 0,dist = 0;
			scanf("%d %d %d",&x,&y,&dist);
			adj[x][y] = adj[y][x] = min(adj[x][y],dist);//可能有重复的边，要去最小值 ,导致我WA了一次 
		}
		dijikstra(1);
		printf("%d\n",d[n]);
	}
	
	
	return 0;
} 
