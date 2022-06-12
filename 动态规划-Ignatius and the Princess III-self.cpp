#include<bits/stdc++.h>
using namespace std;
const int maxn = 125;
int dp[maxn+5][maxn + 5];
int n = 0;
void solve(){
	fill(dp[0],dp[0]+(maxn+5)*(maxn+5),0);//详情见背包九讲的初始化问题 
	//for(int i = 0;i <= maxn;++i){//初始化，这是合法状态 
	//	dp[1][i] = 1;
	//}
	for(int i = 1;i <= maxn;++i){//恰好装满 
		dp[i][0] = 1;
	}
	for(int i = 1;i <= maxn;++i){
		for(int j = 1;j <= maxn;++j){
			dp[i][j] = dp[i-1][j] + (j >= i ? dp[i][j-i]:0);
		}
	}
}
int main(){
	solve();
	while(~scanf("%d",&n)){
		printf("%d\n",dp[n][n]);
	}
	return 0;
}
