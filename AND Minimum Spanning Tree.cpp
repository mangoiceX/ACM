#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e9
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 10;
const LL mod = (1e9 + 7);
int n = 0,k = 0;

void solve(){
	int ans = 0;
	int loc[maxn];
	int tmp = n,cnt = 0;
	while(tmp > 0){
		tmp >>= 1;
		++cnt;
	}
	per(i,2,n){
		bool fg = true;
		// int pos = 0;
		per(j,0,cnt-1){
			int tmp = i;
			// if((tmp >>j) == 0){
			// 	break;
			// }
			if(((tmp>>j) & 1) == 0){
				loc[i] = pow(2,j);
				fg = false;
				break;
			}
		}
		if(fg){
			ans += 1;
			loc[i] = 1;
		}
	}
	printf("%d\n",ans);
	per(i,2,n){
		printf("%d%c",loc[i],i == n ? '\n' : ' ');
	}
	// puts("");
}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		solve();
	}

	return 0;
}