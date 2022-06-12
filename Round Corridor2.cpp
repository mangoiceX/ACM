#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a;i >= (b);--i))
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 3e5 + 10;
LL n = 0,m = 0;
int q = 0;
int sx = 0,ex = 0;
LL sy = 0,ey = 0;
LL gcd(LL x,LL y){
	return y == 0 ? x : gcd(y,x%y);
}

int main(){
	
	while(~scanf("%I64d %I64d %d",&n,&m,&q)){
		while(q--){
			scanf("%d %I64d %d %I64d",&sx,&sy,&ex,&ey);
			LL gc = gcd(n,m);
			LL cnt[3];
			cnt[1] = n/gc,cnt[2] = m/gc;
			if((sy-1)/cnt[sx] ^ (ey-1)/cnt[ex]){
				puts("NO");
			}else{
				puts("YES");
			}
		}
		// solve();
	}

	return 0;
}
