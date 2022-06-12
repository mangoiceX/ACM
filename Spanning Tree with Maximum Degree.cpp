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
const int maxn = 3e5;
int n = 0,m = 0; 
vector<int> vt[maxn+10];
bool vis[maxn+10];

void bfs(int u){
	queue<int > q;//使用标准哭的queue 
	q.push(u);
	while( ! q.empty() ){
		u = q.front();
		q.pop();
		vis[u] = true;
		int size = vt[u].size();
		for(int i = 0;i < size;++i){
			if(!vis[vt[u][i]]){
				printf("%d %d\n",u,vt[u][i]);
				q.push(vt[u][i]);
			}
		}
	}
}


int main(){
	//std::ios::sync_with_stdio(false);
	while(~scanf("%d %d",&n,&m)){
		memset(vis,false,sizeof(vis));
		per(i,1,m){
			int u = 0,v = 0;
			scanf("%d %d",&u,&v);
			vt[u].push_back(v);
			vt[v].push_back(u);
		}
		int maxv = 0,id = 0;
		per(i,1,n){
			if(vt[i].size() > maxv){
				maxv = vt[i].size();
				id = i;
			}
		}
		//cout << id << endl;
		bfs(id);
	}
	
	return 0;
}

