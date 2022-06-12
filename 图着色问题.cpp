#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f 
using namespace std;
const int maxn = 500;
int n = 0,m = 0;
int v = 0,k = 0,e = 0;
vector<int> g[maxn+10];
int c[maxn+10];
bool vis[maxn+10];
bool flag = false;
void dfs(int s){
	vis[s] = true;
	int size = g[s].size();
	per(i,0,size-1){
		int v = g[s][i];
		if(c[v] == c[s]){
			flag = true;
			return ;
		}
	}
	per(i,0,size-1){
		int v = g[s][i];
		if(!vis[v]){
			dfs(v);
		}
	}
}
string str;
int main(){
	while(~scanf("%d %d %d",&v,&e,&k)){
		per(i,1,e){
			int u = 0,x = 0;
			scanf("%d %d",&u,&x);
			g[u].push_back(x);g[x].push_back(u);
		}
		scanf("%d",&n);
		per(j,1,n){
			flag = false;
			memset(vis,false,sizeof(vis));
			set<int> st;
			per(i,1,v){
				scanf("%d",&c[i]);
				st.insert(c[i]);
			}
			if(st.size() != k){
				printf("No\n");
				continue;
			}
			bool f = false;
			per(i,1,v){
				if(!vis[i]){
					dfs(i);
					if(flag){
						printf("No\n");
						f = true;
						break;
					}
				}
			}
			if(f){
				continue;
			}
			printf("Yes\n");
		}	
	}
	
	return 0;
}
