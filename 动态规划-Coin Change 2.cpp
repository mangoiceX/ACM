#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n = 0,k = 0;
int a[110];
int dp[110][10000];
const int mod = 100000007;
void solve(){
	fill(dp[0],dp[0]+110 * 10000,0);
	for(int i = 0;i <= n;++i){
		dp[i][0] = 1;
	}
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= k;++j){
			if(j < a[i]){
				dp[i][j] = dp[i-1][j];
			}else{
				dp[i][j] = (dp[i][j] % mod+ dp[i-1][j-a[i]] % mod) % mod;
			}
		}
	}
}
int main(){
	int T = 0,kase = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&k);
		for(int i = 1;i <= n;++i){
			scanf("%d",&a[i]);
		}
		solve();
		
		printf("Case %d: %d\n",++kase,dp[n][k]);
	}	
	
	return 0;
} 
