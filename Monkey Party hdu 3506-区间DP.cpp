#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#define INF 0x7fffffff
using namespace std;
const int maxn = 2002 + 10;

int dp[maxn][maxn];
int sum[maxn][maxn],mark[maxn][maxn];
int data[maxn];
//dp[i][j]表示第i个猴子到第j个猴子认识的总代价
//mark[i][j]标示最小分割点处的k值  用于四边形加速
//sum[i][j]i到j花费总和

int main(){
	int n = 0;
	while(scanf("%d",&n) != EOF && n){
		
		for(int i = 1;i <= n;++i){
			 scanf("%d",&data[i]);
			 data[i+n] = data[i];//2*n将环形转化为线性 
		}
		
		for(int i = 1;i < 2 * n;++i){		//初始化 
			dp[i][i] = 0;
			mark[i][i] = i;
			for(int j = i;j <= i + n;++j){
				sum[i][j] = sum[i][j-1] + data[j];
			}
		}
		
		for(int len = 2;len <= n;++len){//区间长度 
			for(int i = 1;i + len <= 2*n+1;++i){
			//起点也要从后面一段开始，表面上是重复计算 ，但是后面的mark[i][j]要用到i>n的时候
			//所以 重复计算是为了算出后面的mark 
				int j = len + i - 1;
				dp[i][j] = INF;
				for(int k = mark[i][j-1];k <= mark[i+1][j];++k){
					int temp = dp[i][k] + dp[k+1][j] + sum[i][j]; //状态转移方程 
					if(temp < dp[i][j]){
						dp[i][j] = temp;
						mark[i][j] = k;
					}
				} 
			}
		}
		
		int ans = INF;
		for(int i = 1;i <= n;++i){
			ans = min( ans , dp[i][i+n-1]);//遍历不同的起点 
		}
		printf("%d\n",ans);
	}
	
	
	
	
	return 0;
}
