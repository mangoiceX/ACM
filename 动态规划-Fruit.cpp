#include<bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
int dp[maxn][maxn];
#define INF 1e7 
struct node{
	int mi,ma;
};
node num[maxn];
int n = 0,m = 0;
void solve(){
	fill(dp[0],dp[0]+maxn*maxn,0);
	for(int i = 1;i <= m;++i){
		dp[0][i] = -INF;
	}
	/*
	for(int i = 1;i <= n;++i){
		for(int k = 1;k <= num[i].ma;++k){
			for(int j = 1;j <= m;++j){
				if(j <= num[i].mi){
					dp[i][j] = dp[i][j-1];
					continue;
				}
				dp[i][j] = dp[i][j-1] + ((j >= num[i].mi) ? dp[i-1][j-num[i].mi] : 0);
				//if(i-1== 0 && j < k){
				///	dp[i][j]+=1;
				//}
			}
		}
	}
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= m;++j){
			cout << dp[i][j];
		}
		cout << endl;
	}
	*/
	for(int i = num[1].mi;i <= num[1].ma;++i){
		dp[1][i] = 1;
	}
	for(int i = 2;i<= n;++i){
		for(int j = 0;j <= m;++j){
			for(int k = num[i].mi;j + k <= m && k <= num[i].ma;++k){
				
				dp[i][j+k] = dp[i-1][j];
			}
		}
	}
	printf("%d\n",dp[n][m]);
}
int main(){
	while(~scanf("%d %d",&n,&m)){
		for(int i = 1;i <= n;++i){
			scanf("%d %d",&num[i].mi,&num[i].ma);
		}
		solve();
	}
	return 0;
} 
