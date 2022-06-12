#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 3e5 + 10;
LL n = 0,m = 0;
int q = 0;
int num[20];
int pre[20];
void solve(){
	
}
int main(){
	// std::ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%lld %lld",&n,&m);
		LL gg = n/m;
		LL ge = m % 10ll;
		LL sum = 0;
		per(i,1,9){
			num[i] = (ge * i) % 10;
			pre[i] = num[i] + pre[i-1];
			sum += num[i];
		}
		LL ans = gg/10 * sum;
		ans += pre[gg%10];
		printf("%lld\n",ans);
	}

	return 0;
}
