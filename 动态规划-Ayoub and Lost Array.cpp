#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

typedef long long LL;

#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
const int maxn = 2e5;
const int mod = 1e9 + 7;
int n = 0,l = 0,r = 0;
LL dp[maxn+10][4];//要使用longlong，否则WA，结果不对 
int num[4];
void solve(){
	memset(dp,0,sizeof(dp));
	l -= 1;//这里L要减1，便于计算区间之间的个数 
	int le = l % 3,re = r % 3;
	num[0] = r/3 - l/3;
	num[1] = ((re >= 1) ? (r/3+1) : (r/3) ) - ((le < 1) ? l/3 : (l/3 + 1));
	//num[2] = r - l - (num[0] + num[1]);
	num[2] = ((re >= 2) ? (r/3+1) : (r/3)) - ((le < 2) ? l/3 : (l/3+1));
	dp[1][0] = num[0];dp[1][1] = num[1];dp[1][2] = num[2];
	per(i,2,n){
		dp[i][0] = (dp[i-1][0]*num[0]%mod +dp[i-1][1]*num[2]%mod +dp[i-1][2]*num[1]%mod) % mod;
		
		dp[i][1] = (dp[i-1][0]*num[1]%mod +dp[i-1][1]*num[0]%mod + dp[i-1][2]*num[2]%mod) % mod;
		
		dp[i][2] = (dp[i-1][0]*num[2]%mod + dp[i-1][1]*num[1]%mod + dp[i-1][2]*num[0]%mod) % mod;
	}
	printf("%I64d\n",dp[n][0]);
}
int main(){
	while(~scanf("%d %d %d",&n,&l,&r)){
		
		solve();
	}
		
	return 0;
}

