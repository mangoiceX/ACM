#include<bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
int dp[maxn][maxn][maxn];//dp[i][j][k]表示使用了i种水果，有了j个盘，在第i种水果使用了k个 
struct node{
	int mi,ma;
};
node num[maxn];
#define INF 1e6
int n = 0,m = 0;
void solve(){
	fill(dp[0][0],dp[0][0]+maxn*maxn*maxn,0);
	for(int i = 1;i <= m;++i){//非法状态初始化为-1 
		dp[0][i][0] = -INF;
	}
	
	for(int i = num[1].mi;i <= num[1].ma;++i){//第一个盘子的初始化 
		dp[1][i][i] = 1;
	}
	for(int i = 2;i<= n;++i){
		for(int j = 0;j <= m;++j){
			for(int k = num[i].mi;j +k <= m && k <= num[i].ma;++k){
				for(int l = num[i-1].mi;l <= num[i-1].ma;++l){
					if(dp[i-1][j][l] == -INF){
						continue;
					}
					dp[i][j+k][k] += dp[i-1][j][l];//由第i-1种转移而来，所以要遍历i-1种的情况 
				}
			
			}
		}
	}
	int ans = 0;
	for(int i = num[n].mi;i <= num[n].ma;++i){//第n种水果使用了i个的种数 
		ans += dp[n][m][i];//答案要把他们加起来 
	}
	printf("%d\n",ans);
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
