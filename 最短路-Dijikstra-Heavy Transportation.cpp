#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 1e6 + 10//之前设置为1e5，而边的最大值是1e6,所以不能保证说先便利的是开始节点 
//这个又改了我好久 
using namespace std;
const int maxn = 2e3 + 100;
int n = 0,m = 0;
int adj[maxn][maxn];
bool used[maxn];
int d[maxn];

void Dj(int s){

	d[s] = INF;//不是设置为0 
	while(true){
		int v = -1;
		for(int i = 1;i <= n;++i){
			if(used[i] == false && (v == -1 || d[i] > d[v])){
				v = i;
			}
		}
		if(v == -1){
			break;
		}
		used[v] = true;
		for(int i = 1;i <= n;++i){
			if(used[i] == false && min(d[v],adj[v][i]) > d[i]){//松弛操作 
				d[i] = min(d[v],adj[v][i]);
			}
		}
	}
}
void init(){
	fill(adj[0],adj[0] + maxn * maxn,-2);
	fill(used,used + maxn,false);
	fill(d,d+maxn,-1);
}
int main(){
	//freopen("a.txt","r",stdin);
	int T = 0,kase = 0;
	cin >> T;
	while(T--){
		init();
		cin >> n >> m;
		for(int i = 0;i < m;++i){
			int a = 0,b = 0,w = 0;
			cin >> a >> b >> w;
			adj[a][b] = adj[b][a] = w;
		}
		Dj(1);
		cout << "Scenario #" << ++kase << ":\n" << d[n] <<"\n" <<  endl;
	}
	
	return 0;
} 
