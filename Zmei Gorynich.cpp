#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 1e2 + 10;
int n = 0,m = 0,q = 0;
LL x = 0;

struct node{
	LL val,s,t;
}a[maxn];
bool cmp(node m,node y){
	return m.val == y.val ? m.s > y.s : m.val < y.val;
}
void solve(){
	
}
int main(){
	// std::ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	
	int T = 0;
	scanf("%d",&T);
	while(T--){
		LL mx = 0;
		scanf("%d %I64d",&n,&x);
		per(i,1,n){
			scanf("%I64d %I64d",&a[i].s,&a[i].t);
			a[i].val= a[i].s - a[i].t;	
			mx = max(mx,a[i].s);
		}
		sort(a+1,a+1+n,cmp);
		if(a[n].val <= 0){
			bool fg = true;
			per(i,1,n){
				if(a[i].s >= x){
					fg = false;
					break;
				}
			}
			if(fg){
				puts("-1");	
			}else{
				printf("1\n");
			}
			continue;
		}
		LL rest = x - mx;
		if(rest % a[n].val == 0){
			printf("%I64d\n",rest / a[n].val + 1);
		}else{
			printf("%I64d\n",rest / a[n].val + 1 + 1);
		}
		// printf("%I64d\n",(x - mx));
		// if(x % a[n].val == 0){
		// 	LL ans = x / a[n].val;
		// 	ans -= (a[n].s / a[n].val);
		// 	printf("%I64d\n",ans);
		// }else{
		// 	LL ans = x/a[n].val + 1;
		// 	if(x % a[n].val + a[n].val <= a[n].s){
		// 		ans -= 1;
		// 	}
		// 	// if(x % a[n].val <= a[n].s){
		// 	// 	ans -= 1;
		// 	// }
		// 	printf("%I64d\n",ans);
		// }
		// solve();
	}

	return 0;
}
