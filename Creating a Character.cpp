#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 3e5 + 10;
int n = 0,m = 0,q = 0,s = 0,t = 0,e = 0;
void solve(){
	if(s + e <= t){
		puts("0");
		return ;
	}
	int sum = s+e+t;
	int ans = 0;
	int mid = sum / 2;
	if(sum & 1){
		if(s >= mid){
			ans = e + 1;
			if(s == mid){
				ans -= 1;
			}
			printf("%d\n",ans);
		}else{
			ans = e - (mid - s);
			printf("%d\n",ans);
		}
	}else{	
		if(s >= mid){
			ans = e + 1;
			if(s == mid){
				ans -= 1;
			}
			printf("%d\n",ans);
		}else{
			ans = e - (mid - s);
			printf("%d\n",ans);
		}
	}
}
int main(){
	// std::ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&s,&t,&e);
		// printf("%d\n",);
		// solve();
		// int ans = 0;
		// ans = e - abs((s+e+t+1)/2 - s);
		// if((s+t+e) & 1){
		// 	ans += 1;
		// }
		// printf("%d\n",ans)
		solve();
	}

	return 0;
}
