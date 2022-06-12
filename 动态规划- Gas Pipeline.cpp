#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 10;
int q = 0;
int n = 0,m = 0;
LL a,b;
char s[maxn];
LL dp[maxn][2];
void init(){
	per(i,0,n){
		dp[i][0] = dp[i][1] = INF;
	}
}
void solve(){
	dp[0][0] = b;
	dp[0][1] = INF;
	per(i,0,n-1){
		if(s[i] == '0'){
			dp[i+1][0] = min(dp[i][0]+a+b,dp[i][1]+2*a+b);
			dp[i+1][1] = min(dp[i][0]+2*(a+b),dp[i][1]+a+2*b);
		}else{
			dp[i+1][1] = dp[i][1] + a+2*b;
			dp[i+1][0] = INF;
		}
	}
	printf("%I64d\n",dp[n][0]);
}
int main(){
	// std::ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %I64d %I64d",&n,&a,&b);
		init();
		scanf("%s",s);
		solve();
	}

	return 0;
}
