#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 3e5 + 10;
int n = 0,m = 0,q = 0;
int b = 0,p = 0,f = 0,h = 0,c =0;
void solve(){
	
}
int main(){
	// std::ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&b,&p,&f);
		scanf("%d %d",&h,&c);
		int ans = 0;
		if(h >= c){
			ans += h * min(b/2,p);
			b -= 2 * min(b/2,p);
			ans += c * min(b/2,f);
		}else{
			ans += c * min(b/2,f);
			b -= 2 * min(b/2,f);
			ans += h * min(b/2,p);
		}
		printf("%d\n",ans);
	}

	return 0;
}
