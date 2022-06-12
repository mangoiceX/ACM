#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
typedef long long LL;
LL dp[30];
int d[30];
int n = 0;

void solve(){
	LL ans = 0;
	per(i,1,n){
		int tmp = i;
		while(tmp > 0){
			ans += !(tmp & 1);
			tmp >>= 1;
		}
	}
	printf("%lld\n",ans);
}
int main(){
	while(~scanf("%d",&n)){
		solve();
	}
	return 0;
}