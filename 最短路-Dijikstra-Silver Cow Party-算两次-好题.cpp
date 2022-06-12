#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 1e8
using namespace std;
const int maxn = 1000 + 10;
int vis[maxn];
int d[maxn],d1[maxn];
int map[maxn][maxn];
int n = 0,m = 0,x = 0;
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
	fill(d,d+maxn,INF);
	fill(vis,vis+maxn,false);
	fill(map[0],map[0]+maxn*maxn,INF);
}
void traverse(){//·����ת 
	for(int i = 1;i <= n;++i){
		for(int j = i+1;j <= n;++j){//j���ܴ�1��ʼ������ת���Σ��൱��û�仯 
			swap(map[i][j],map[j][i]);
		}
	}
}
int main(){
	scanf("%d %d %d",&n,&m,&x);
	init();
	for(int i = 0;i < m;++i){
		int a = 0,b = 0,w = 0;
		scanf("%d %d %d",&a,&b,&w);
		map[a][b] = w;
	}
	dijikstra(x);
	for(int j = 1;j <= n;++j){//�����һ�ε������������һ�ԭd,vis���� 
		d1[j] = d[j];
		d[j] = INF;
		vis[j] = false;
	}
	traverse();
	dijikstra(x);
	int maxv = 0;
	for(int j = 1;j <= n;++j){
		if(d[j] + d1[j] > maxv){
			maxv = d[j] + d1[j];
		}
	}
	printf("%d\n",maxv);
	return 0;
}
 
