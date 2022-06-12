#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e9
using namespace std;
typedef long long LL;

const int maxn = 3e3 + 10;
int n = 0,m = 0;
char s[maxn],t[maxn];
int dp[maxn][maxn];//dp[i][j]表示s串中的第i个对应t串中的第t个，当然也包含
//也包含不对有关的情况，也就是想背包一样，选与不选，且是数量<=m,大于m的可以后面直接计算
const int mod = 998244353;
void init(){
	per(i,0,n){
		per(j,0,m){//要初始化到m,n,因为i从n-1开始，但是是从i+1转移过来
			//所以会出现n
			dp[i][j] = 0;
		}
	}
}
int fac[maxn],inv[maxn];
void pre_solve(int N){
    fac[0]=fac[1]=inv[0]=inv[1]=1;
    for(int i=2;i<=N;i++) 
		fac[i]=(LL)fac[i-1]*i%mod;
    for(int i=2;i<=N;i++) 
		inv[i]=(LL)(mod-mod/i)*inv[mod%i]%mod;
    for(int i=2;i<=N;i++) 
		inv[i]=(LL)inv[i]*inv[i-1]%mod;
}
int C(int n,int m){
	if(n<m) return 0;
    return (LL)fac[n]*inv[m]%mod*inv[n-m]%mod;
}

void solve(){
	rep(i,n-1,0){
		rep(j,m-1,0){
			if(s[i] > t[j]){
				//不选+选了之后后面可以乱选，但不是dp[i+1][j+1],因为DP记录的是要准确选的方案
				dp[i][j] = (dp[i+1][j] + C(n-1-i,m-1-j)) % mod;
			}else if(s[i] == t[j]){
				//不选+选
				dp[i][j] = (dp[i+1][j] + dp[i+1][j+1]) % mod;
			}else{
				dp[i][j] = dp[i+1][j];
			}
		}
	}
	int ans = dp[0][0];
	rep(i,n-1,0){
		if(s[i] != '0' && n-1-i+1 > m){//选择>m的，去除前导0
			for(int j = m;j <= n-1-i;++j){
				ans = (ans + C(n-1-i,j)) % mod;
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	pre_solve(3000);
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		init();
		scanf("%s",s); scanf("%s",t);
		solve();
	}

	return 0;
}