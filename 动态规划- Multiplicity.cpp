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
const int maxn = 1e5;
int n = 0,m = 0;
int a[maxn+10];
vector<int> vt[maxn+10]; 
int dp[maxn*10+10];//这里是1e6，不是1e5 
//#define mod 1000000007  // 
//#define mod 1000000000 + 7//这个会出现莫名的错误,因为define只是把式子带入，这里少了括号 
const int mod = 1000000007;
void solve(){
	fill(dp,dp+maxn+10,0);
	per(i,1,n){
		per(j,1,sqrt(a[i])){//分解因数 
			if(a[i]%j == 0){
				vt[i].push_back(j);
				if(a[i] != j*j){
					vt[i].push_back(a[i]/j);
				}
			}	
		}
		sort(vt[i].begin(),vt[i].end());
	}
	dp[0] = 1;
	per(i,1,n){
		rep(j,vt[i].size()-1,0){
		//for(int j = vt[i].size()-1;j >= 0;--j){
			dp[vt[i][j]] = (dp[vt[i][j]] + dp[vt[i][j]-1]) % mod;
		}
	}
	LL ans = 0;
	per(i,1,n){
		ans = (ans + dp[i]) % mod;
	}
	printf("%I64d\n",ans);
}
int main(){
	while(~scanf("%d",&n)){
		per(i,1,n){
			vt[i].clear();
		}
		per(i,1,n){
			scanf("%d",&a[i]);
		}
		solve();
	}

	return 0;
}

