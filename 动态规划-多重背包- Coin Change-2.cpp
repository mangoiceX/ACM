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
			for(int l = 0;l*a[i] <= j;++l){
				dp[i][j] = (dp[i][j] % mod+ dp[i-1][j-l*a[i]] % mod) % mod;
			}	
		}
	}
	/* 
	int i = 0,j = 0,l = 0;
	for(i = 1;i <= n;++i){
		for(l = 1;(l << 1 )< k/a[i];l<<=1){
			//for(j = k;j >= l*a[i];--j){
			for(j = l*a[i];j <= k ;++j){
				dp[i][j] = (dp[i][j] % mod+ dp[i-1][j-l*a[i]] % mod) % mod;
			}
		}
		int m = k/a[i] - l + 1;
		for(j = m*a[i];j <= k;++j){
			dp[i][j] = (dp[i][j] % mod+ dp[i-1][j-m*a[i]] % mod) % mod;
		} 
	}
	*/
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
		for(int i = 0;i <= n;++i){
			cout << i << endl;
			for(int j = 0;j <= k;++j){
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		printf("Case %d: %d\n",++kase,dp[n][k]);
	}	
	
	return 0;
} 
