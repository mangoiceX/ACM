#include<bits/stdc++.h>
// #include<iostream>
// #include<cstdio>
// #include<vector>
// #include<cstring>
using namespace std;
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
const int maxn = 2e5 + 10;
#define INF 0x3f3f3f
typedef long long LL;
int n = 0,m = 0;
LL dp[maxn][2];
LL a[maxn],b[maxn];
void solve(){
	per(i,1,n){
		dp[i][0] = max(dp[i-1][1],dp[i-2][1]) + a[i];
		dp[i][1] = max(dp[i-1][0],dp[i-2][0]) + b[i];
	}
	printf("%I64d\n",max(dp[n][0],dp[n][1]));
}
int main(){

	while(~scanf("%d",&n)){
		memset(dp,0,sizeof(dp));
		per(i,1,n){
			scanf("%I64d",&a[i]);
		}
		per(i,1,n){
			scanf("%I64d",&b[i]);	
		}
		solve();
	}

	return 0;
}