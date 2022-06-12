#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f 
using namespace std;
const int maxn = 1e5;
int n = 0,m = 0;
int p[11] = {0,4,5,6,9,10,17,17,20,24,30};
int c = 1;
int dp[maxn+10];
void solve(){
	memset(dp,0,sizeof(dp));
	
	per(i,1,n){
		per(j,0,i){
			dp[i] = max(dp[i],dp[i-j]+p[j]- ((j == i || j == 0) ? 0 : c));
		}
	}
	
	per(i,1,n){
		printf("%d%c",dp[i],i == n ? '\n' :' ');
	}
}
int main(){
	while(~scanf("%d",&n)){
		solve();
	}
	
	return 0;
}
