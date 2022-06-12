#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 3e5 + 10;
int n = 0,m = 0,q = 0;
int a[60][60];
bool vis[60][60];
void solve(){
	int ans = 0;
	vector<int> ansx,ansy;
	bool fg = true;
	per(i,1,n){
		per(j,1,m){
			if(a[i][j] == 1){
				fg = false;
				break;
			}
		}
	}
	if(fg){
		puts("0");
		return ;
	}
	per(i,1,n-1){
		per(j,1,m-1){
			if(a[i][j] == 1 && a[i+1][j] == 1 && a[i][j+1] == 1 && a[i+1][j+1] == 1){
				if(!vis[i][j] || !vis[i+1][j] || !vis[i][j+1] || !vis[i+1][j+1]){//避免重复欠佳答案
					++ans;
					ansx.push_back(i); ansy.push_back(j);
				}
				vis[i][j] = true; vis[i+1][j] = true; vis[i][j+1] = true; vis[i+1][j+1] = true;
			}
		}
	}
	fg = true;
	per(i,1,n){
		per(j,1,m){
			if(a[i][j] == 1 && !vis[i][j]){
				fg = false;
			}
		}
	}
	if(!fg){
		puts("-1");
		return ;
	}
	printf("%d\n",ans);
	per(i,0,ans-1){
		printf("%d %d\n",ansx[i],ansy[i]);
	}
}

int main(){
	// std::ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	while(~scanf("%d %d",&n,&m)){
		memset(vis,false,sizeof(vis));
		per(i,1,n){
			per(j,1,m){
				scanf("%d",&a[i][j]);
			}
		}
		solve();
	}

	return 0;
}
