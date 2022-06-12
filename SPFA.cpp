#include<bits/stdc++.h>
using namespace std;
#define per(i,a,b) for(int i = (a);i <= (b);++i)
const int maxn = 1e5 + 10;
int d[maxn];
int n = 0,m = 0;
int s = 0,t = 0;
struct node{
	int to,w;
};
vector<node> g[maxn];
bool vis[maxn];

void init(){
	memset(vis,false,sizeof(vis));
	per(i,1,n){
		d[i] = 2e5;
	}
}
void spfa(int x){
	queue<int> que;
	que.push(x);
	d[x] = 0;
	vis[x] = true;
	while(!que.empty()){
		int u = que.front();
		que.pop();
		vis[u] = false;
		int si = g[u].size();
		per(i,0,si-1){
			node& v = g[u][i];
			//cout <<"jaa " << v.w <<endl;
			if(d[u] + v.w < d[v.to]){
				d[v.to] = d[u] + v.w;
				if(!vis[v.to]){
					que.push(v.to);
					vis[v.to] = true;
				}
			}
		}
	}
}
int main(){
	while(~scanf("%d %d",&n,&m)){
		init();
		per(i,1,m){
			int x = 0,y = 0,w = 0;
			scanf("%d %d %d",&x,&y,&w);
			g[y].push_back(node{x,w});
		}
		scanf("%d %d",&s,&t);
		spfa(t);
		per(i,1,n){
			printf("%d\n",d[i]);
		}
		
	}


	return 0;
}