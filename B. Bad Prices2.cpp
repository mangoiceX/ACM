#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 3e5 + 10;
int n = 0,m = 0,q = 0;
int a[maxn];
int minv[maxn];
void init(){
	per(i,0,n+1){
		minv[i] = 1e9;
	}
}
void solve(){
	
}
int main(){
	// std::ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		per(i,1,n){
			scanf("%d",&a[i]);
		}
		rep(i,n,1){
			minv[i] = min(minv[i+1],a[i]);
		}
		int ans = 0;
		per(i,1,n){
			if(a[i] > minv[i]){
				++ans;
			}
		}
		// solve();
		printf("%d\n",ans);
	}

	return 0;
}
