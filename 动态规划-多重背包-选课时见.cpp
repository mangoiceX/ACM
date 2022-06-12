#include<bits/stdc++.h>
using namespace std;
const int  maxn = 10 + 10;
int dp[maxn][50];
int n = 0,k = 0;
struct node{
	int val,num;
};
node cur[10];
void solve(){
	fill(dp[0],dp[0]+maxn*50,0);
	for(int i = 0;i <= k;++i){
		dp[i][0] = 1;
	}
	for(int i = 1;i <= k;++i){
		for(int j = 1;j <= n;++j){
			for(int l = 0;l <= cur[i].num && l*cur[i].val <= j;++l){
				dp[i][j] += dp[i-1][j-l*cur[i].val];
			}
		}
	}
	printf("%d\n",dp[k][n]);
}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&k);
		for(int i = 1;i <= k;++i){
			scanf("%d %d",&cur[i].val,&cur[i].num);
		}
		solve();
	}
	return 0;
}
