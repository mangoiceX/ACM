#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e9
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10,ma = 200;
int n = 0,m = 0,q = 0;
LL a[maxn];
bool vis[ma];
bool used[ma][ma];
int dist[ma];
vector<int> mp[ma];
void init(){
	memset(vis,false,sizeof(vis)); memset(used,false,sizeof(used));
	per(i,0,63){
		mp[i].clear();
		dist[i] = INF;
	}
}
int bfs(int s,int t){
	dist[s] = 0;
	queue<int> que;
	que.push(s);
	vis[s] = true;
	while(!que.empty()){
		int u = que.front();
		que.pop();
		int si = mp[u].size();
		per(i,0,si-1){
			int v = mp[u][i];
			if(!vis[v] && !(u == s && v == t)){
				dist[v] = dist[u] + 1;
				que.push(v);
				vis[v] = true;
			}
		}
	}
	return dist[t];
}
void solve(){

	vector<LL> g[64];
	 per(i,1,n){
	 	LL tmp = a[i];
	 	int j = 0;
	 	while(tmp > 0){
	 		if(tmp & 1){
	 			g[j].push_back(a[i]);
	 		}
	 		tmp >>= 1;
	 		++j;
	 	}
	}

	per(i,0,63){
	 	if(g[i].size() >= 3){
	 		printf("3\n");
	 		return ;
	 	}
	}
	set<LL> st;
	per(i,0,63){
		int si = g[i].size();
		per(j,0,si-1){
			st.insert(g[i][j]);
		}
	}
	vector<LL> ans;
	set<LL>::iterator it;
	for(it = st.begin();it != st.end();++it){
		ans.push_back(*it);
	}
	int si = ans.size();
	per(i,0,si-1){
		per(j,i+1,si-1){
			if((ans[i] & ans[j]) != 0){
				mp[i].push_back(j); mp[j].push_back(i);
			}
		}
	}
	int res = 100;
	per(i,0,si-1){
		int size = mp[i].size();
		per(j,0,size-1){
			int v = mp[i][j];
			if(!used[i][v]){
				memset(vis,false,sizeof(vis));
				per(i,0,63){
					dist[i] = INF;
				}
				res = min(res,bfs(i,v)+1);
				used[i][v] = true;
				if(res == 3){
					puts("3");
					return ;
				}
			}
		}
	}
	if(res == 100){
		puts("-1");
	}else{
		printf("%d\n",res);
	}

}
int main(){
	// std::ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	while(~scanf("%d",&n)){
		init();
		per(i,1,n){
			scanf("%I64d",&a[i]);
		}
		solve();
	}
	
	return 0;
}
/*
5
565299879350784 4508014854799360  4503635094929409 18014810826352646 306526525186934784 
*/