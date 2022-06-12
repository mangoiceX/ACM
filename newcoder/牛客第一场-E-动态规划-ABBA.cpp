#include<bits/stdc++.h>
// #include<iostream>
// #include<cstdio>
// #include<vector>
// #include<cstring>
using namespace std;
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
typedef long long LL;
const int maxn = 2e3 + 10;
const LL mod = (1e9 + 7);
#define INF 0x3f3f3f
typedef long long LL;
int n = 0,m = 0;
int dp[maxn][maxn];
int main(){
	while(~scanf("%d %d",&n,&m)){
		per(i,0,n+m){
			per(j,0,n+m){
				dp[i][j] = 0;
			}
		}
		dp[0][0] = 1;
		per(i,0,n+m){
			per(j,0,n+m){
				if(i+1-n <= j){//保证是合法前缀
					dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % mod;
				}
				if(j+1-m <= i){
					dp[i][j+1] = (dp[i][j+1] + dp[i][j]) % mod;
				}
			}
		}
		printf("%d\n",dp[n+m][n+m]);
	}

	return 0;
}