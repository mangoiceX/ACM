#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define INF 0x3f3f3f3f//刚才又是这里设置太小了 
using namespace std;
const int maxn = 100 + 10;
bool vis[maxn];
int d[maxn];
int map[maxn][maxn];
int n = 0,m = 0;
void dijikstra(int s){
	d[s] = 0;
	while(true){
		int v = -1;
		for(int i = 1;i <= n;++i){
			if(vis[i] == false && (v == -1 || d[i] < d[v])){
				v = i;
			}
		}
		if(v == -1){
			break;
		}
		vis[v] = true;
		for(int i = 1;i <= n;++i){
			if(vis[i] == false && (d[v] + map[v][i]) < d[i]){
				d[i] = d[v] + map[v][i];
			}
		}
	}
}
void init(){
	fill(map[0],map[0]+maxn*maxn,INF);
	fill(vis,vis+maxn,false);
	fill(d,d+maxn,INF);
}
int main(){
	while(scanf("%d %d",&n,&m) != EOF && (m != 0 || n!= 0)){
		init();
		for(int i = 0;i < m;++i){
			int a = 0,b = 0,w = 0;
			scanf("%d %d %d",&a,&b,&w);
			map[a][b] = map[b][a] = w;
		}
		dijikstra(1);
		printf("%d\n",d[n]);
	}
	
	
	return 0;
}
