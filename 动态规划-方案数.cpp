#include<bits/stdc++.h>
using namespace std;
#define per(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,a,b) for(int i=(a);i>=(b);i--)
typedef long long LL;
#define INF 0x3f3f3f3f
const int maxn = 1e3;
int n = 0,m = 0;
int dp[maxn+10];
int val[5] = {0,10,20,50,100};
void solve(){
	memset(dp,0,sizeof(dp));
	dp[0] = 1; 
	per(i,1,4){
		per(j,0,n){
			dp[j] = (j >= val[i] ? max(dp[j] + dp[j-val[i]],dp[j]) : dp[j]);
		}
	}
	printf("%d\n",dp[n]);
}
int main(){
	while(~scanf("%d",&n)){
		solve();
	}
	
	return 0;
}
