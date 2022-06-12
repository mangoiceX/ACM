#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 3e5 + 10;
int n = 0,m = 0,q = 0;
int a[100][100];
bool vis[60][60];
vector<int> ansx,ansy;
void solve(){
	
}
int main(){
	// std::ios::sync_with_stdio(false);3 3


	// cin.tie(0);cout.tie(0);
	scanf("%d %d",&n,&m);
		// vector<int> ans;
		// per(i,1,2500){
		// 	ans.push_back(i);
		// }
		// printf("%d\n",ans.size());
		bool fg = false,gg = false;
		per(i,1,n){
			per(j,1,m){
				scanf("%d",&a[i][j]);
				if(a[i][j] == 1){
					fg = true;
				}
			}
		}
		
		per(i,1,n-1){
			per(j,1,m-1){
				if(a[i][j] == 1 && a[i+1][j] == 1 && a[i][j+1] == 1 && a[i+1][j+1] == 1){
					ansx.push_back(i);ansy.push_back(j);
					vis[i][j] = true; vis[i+1][j] = true; vis[i][j+1] = true; vis[i+1][j+1] = true;
				}else{
					if(a[i][j] == 1 && !vis[i][j]){
						gg = true;
					}
				}
			}
		}
		if(gg){
			puts("-1");
			return 0;
		}
		int si = ansx.size();
		if(si == 0 && fg){
			puts("-1");
			return 0;
		}
		printf("%d\n",si);
		per(i,0,si-1){
			printf("%d %d\n",ansx[i],ansy[i]);
		}
		// solve();
	// }
	

	return 0;
}
