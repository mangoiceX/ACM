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

using namespace std;
const int maxn = 3e3;

typedef long long LL;

#define inf 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
pii p[maxn+10];
int n = 0,m = 0;
int dp[maxn+10][maxn+10];
void solve(){
	fill(dp[0],dp[0]+(maxn+10)*(maxn+10),0);
	for(int i = 1;i <= n;++i){
		for(int j = 0;j <= m;++j){

			dp[i][j] = (j - p[i].first >= 0) ? 
			max(dp[i-1][j],dp[i-1][j-p[i].first] + p[i].second) : dp[i-1][j];
		}
	}
	int maxv = -1;
	for(int i = 1;i <= m;++i){
		maxv = max(maxv,dp[n][i]);
	}
	printf("%d\n",maxv);
}
int main(){
	while(~scanf("%d %d",&n,&m)){
		per(i,1,n){
			scanf("%d %d",&p[i].second,&p[i].first); 
		}
		solve();
	}
	
	return 0;
}




