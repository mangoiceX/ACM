#include<bits/stdc++.h>
// #include<iostream>
// #include<cstdio>
// #include<vector>
// #include<cstring>
using namespace std;
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
const int maxn = 1e5 + 10;
#define INF 0x3f3f3f
typedef long long LL;
LL n = 0,m = 0;
LL dp[maxn][2][2];
LL a[maxn][2];
void solve(){
	memset(dp,0,sizeof(dp));
	per(i,1,n){
		per(j,0,1){
			if(j == 1){
				dp[i][1][1] = max(dp[i-1][0][0] + a[i][j],);
				dp[i][1][0] = max(dp[i-1][0][0],dp[i-1][j][1]);
			}
			
		}
	}
	LL x = max(dp[n][0][0],dp[n][0][1]),y = max(dp[n][1][0],dp[n][1][1]);
	printf("%I64d\n",x + y);
}
int main(){
	while(~scanf("%d",&n)){
		per(i,1,n){
			scanf("%I64d",&a[i][0]);
		}
		per(i,1,n){
			scanf("%I64d",&a[i][1]);
		}
		solve();
	}

	return 0;
}