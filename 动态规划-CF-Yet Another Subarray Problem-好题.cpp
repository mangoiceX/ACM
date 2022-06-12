#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 3e5 + 10;
int n = 0,m = 0,k = 0;
LL dp[maxn][11];//dp[i][j] 表示以第i个数为右端点，长度%m == j的区间的最大值。
//将区间长度%m相等的区间划分到同一个等价类中，其中，比较特殊的时临界条件，m-1到0还有从无到1，
//此时要-k
/*
题解:考虑dp的做法,dp[i][j]代表以第i个数为右端点，长度求余m的值为j时的最大值。

转移方程：dp[i][j]=dp[i-1][j-1]+a[i](j>0)

　　　　　dp[i][j]=max(dp[i-1][m-1]+a[i]-k,a[i]-k)(j==0)
*/
LL a[maxn];

int main(){
	while(~scanf("%d %d %d",&n,&m,&k)){
		per(i,1,n){
			scanf("%I64d",&a[i]);
		}
		per(i,0,n){
			per(j,0,m-1){
				dp[i][j] = -INF;
			}
		}
		dp[0][m-1] = 0;
		//初始化条件
		LL ans = 0;
		per(i,1,n){
			per(j,0,m-1){
				if(j == 0){
					dp[i][j] = max(dp[i-1][m-1] + a[i] - k,a[i] - k);
	//重新只选一个的时候是在j==0时，根据dp[i][j]的递推式
				}else{
					dp[i][j] = dp[i-1][j-1] + a[i];
				}
				ans = max(ans,dp[i][j]);
			}
		}
		printf("%I64d\n",ans);

	}



	return 0;
}