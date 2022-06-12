#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 3e5 + 10;
int n = 0,m = 0,q = 0;
int a[maxn];
int be = 1e5;
int ans[maxn];
bool vis[maxn];
void solve(){
	
}
int main(){
	// std::ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	scanf("%d %d",&n,&m);
		memset(vis,false,sizeof(vis)); memset(a,0,sizeof(a));
		per(i,1,n){
			scanf("%d",&a[i+be]);
		}
		per(i,1,m){
			int x = 0;
			scanf("%d",&x);
			a[be--] = x;
		}
		int cnt = 0;
		per(i,be,2e5){
			if(!vis[a[i]] && a[i] != 0){
				ans[++cnt] = a[i];
				vis[a[i]] = true;
			}
		}
		per(i,1,cnt){
			printf("%d ",ans[i]);
		}
		// puts("");
	


	return 0;
}
