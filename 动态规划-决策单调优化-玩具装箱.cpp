#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 5e4 + 10;
// int n = 0,m = 0,q = 0
LL c[maxn],pre_sum[maxn];
int Q[maxn],head = 0,tail = 0;
LL dp[maxn];
LL n = 0,l= 0;
inline LL a(int k){
	return pre_sum[k] + k;
}
inline LL b(int k){
	return a(k) + l + 1;
}
inline LL X(int i){
	return b(i);
}
inline LL Y(int i){
	return dp[i] + b(i) * b(i);
}
inline double slope(int i,int j){
	return (Y(i) - Y(j))*1.0 / (X(i) - X(j));
}

int main(){
	// std::ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	while(~scanf("%lld %lld",&n,&l)){
		memset(pre_sum,0,sizeof(pre_sum));
		dp[0] = 0;//这个初值是0
		per(i,1,n){
			scanf("%lld",&c[i]);
			pre_sum[i] = pre_sum[i-1] + c[i]; 
		}
		per(i,1,n){
			int loc = 0;
			dp[i] = INF; //记得赋初值
			per(j,0,i-1){//要从0开始也就是所有的都分为一堆的情况
				if(dp[j] + pow((i-(j+1) + pre_sum[i] - pre_sum[j] - l),2) <= dp[i]){
					dp[i] = dp[j] + pow((i-(j+1) + pre_sum[i] - pre_sum[j] - l),2);
					loc = j;
				}
			}
			printf("nihao %d\n",loc);//决策单调性观察
		}
		printf("%lld\n",dp[n]);
	}

	return 0;
}
