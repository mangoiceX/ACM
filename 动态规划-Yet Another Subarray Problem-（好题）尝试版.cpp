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

转移方程：dp[i][j]=dp[i-1][j-1]+a[i](j>1)

　　　　　dp[i][j]=max(dp[i-1][m-1]+a[i]-k,a[i]-k)(j==1)
		 dp[i][j]=dp[i-1][m-1] + a[i];
*/
LL a[maxn];

int main(){
	while(~scanf("%d %d %d",&n,&m,&k)){
		per(i,1,n){
			scanf("%I64d",&a[i]);
		}
		per(i,0,n){//初始化条件
			per(j,0,m-1){
				dp[i][j] = -INF;
			}
		}
		LL ans = 0;
		per(i,1,n){
			per(j,0,m-1){
				//j==1 || m==1这个if判断要放在j==0前面
				if(j == 1 || m == 1){//因为m==1的时候，只选择当前一个也会长度%m==1（特别注意）
					dp[i][j] = max(dp[i-1][0] + a[i] - k,a[i] - k);
				}else if(j == 0){
					dp[i][j] = dp[i-1][m-1] + a[i];
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
