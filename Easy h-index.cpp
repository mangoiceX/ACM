#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 3e5 + 10;
int n = 0,m = 0,q = 0;
int a[maxn];
LL suf[maxn];
void solve(){
	
}
int main(){
	// std::ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	while(~scanf("%d",&n)){
		memset(suf,0,sizeof(suf));
		per(i,0,n){
			scanf("%d",&a[i]);
		}
		rep(i,n,0){
			suf[i] = suf[i+1] + a[i];
		}
		int ans = 0;
		rep(i,n,0){
			if(suf[i] >= i){
				ans = i;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
