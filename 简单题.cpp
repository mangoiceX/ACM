#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

typedef long long LL;

#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
const int maxn = 1e3 + 10;
int n = 0,m = 0;
vector<int> g[maxn];
int s = 0,t = 0;
int ans = 0;
bool vis[maxn];
void init(){
	per(i,1,n){
		g[i].clear();
		vis[i] = false;
	}
	ans = 0;
}
void bfs(){
	queue<int> que;
	que.push(s);
	vis[s] = true;
	bool fg = false;
	while(!que.empty()){
		int u = que.front();
		que.pop();
		int si = g[u].size();
		per(i,0,si-1){

			int v = g[u][i];
			if(v == t){
				fg = true;
				++ans;
				continue;
			}
			if(!vis[v] && !fg){
				que.push(v);
				vis[v] = true;
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	int i = 5;
	int q = 0;
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&n,&m);
		init();
		per(i,1,m){
			int u = 0,v = 0;
			scanf("%d %d",&u,&v);
			g[u].push_back(v);
		}
		scanf("%d %d",&s,&t);
		bfs();

	}		
	
	return 0;
}

