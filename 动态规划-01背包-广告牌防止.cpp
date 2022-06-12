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
const int maxn = 3e5 + 10;
int n = 0,m = 0;
int w[maxn],r[maxn];
int dp[maxn];
int dis = 5;
void solve(){
	per(i,1,n){
		dp[i] = 0;
	}
	per(i,1,n){
		per(j,	0,i-1){
			if(w[i] - w[j]<= dis){
				break;
			}
			dp[i] = max(dp[i],max(dp[i-1],dp[j] + r[i]));
		}
	}
	printf("%d\n",dp[n]);
}
int main(){
	while(~scanf("%d",&n)){
		per(i,1,n){
			scanf("%d",&w[i]);
		}
		per(i,1,n){
			scanf("%d",&r[i]);
		}
		solve();
	}
	
	return 0;
}

/*
4
6 7 12 14
5 6 5 1
*/