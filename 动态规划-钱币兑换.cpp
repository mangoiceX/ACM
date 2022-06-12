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
const int maxn = 3e5;
int n = 0,m = 0;
int w[maxn],dp[maxn];
void solve(){
	per(i,0,n){
		dp[i] = 0;
	}
	dp[0] = 1;
	per(i,1,m){
		per(j,0,n){
			dp[j] = (j >= w[i] ? dp[j] + dp[j-w[i]] : dp[j]);
		}
	}
	printf("%d\n",dp[n]);
}
int main(){
	while(~scanf("%d %d",&n,&m)){
		per(i,1,m){
			scanf("%d",&w[i]);
		}
		solve();
	}
	
	return 0;
}
/*
4 3
1 2 3

*/

