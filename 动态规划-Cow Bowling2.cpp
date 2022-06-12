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
const int maxn = 350;
int n = 0,m = 0;
int a[maxn+10][maxn+10]; 
int dp[maxn+10];
void solve(){
	fill(dp,dp+maxn+10,0);
	per(i,1,n){
		dp[i] = a[n][i];
	}
	rep(i,n-1,1){
		per(j,1,i){
			dp[j] = max(dp[j],dp[j+1]) + a[i][j];
		}
	}
	printf("%d\n",dp[1]);
}
int main(){
	while(~scanf("%d",&n)){
		per(i,1,n){
			per(j,1,i){
				scanf("%d",&a[i][j]); 
			}
		}
		solve();
	}
	
	return 0;
}

