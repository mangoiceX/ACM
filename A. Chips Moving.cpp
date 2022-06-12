#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 3e5 + 10;
int n = 0,m = 0,q = 0;
int a[maxn];
void solve(){
	
}
int main(){
	// std::ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	while(~scanf("%d",&n)){
		int cnt1 = 0,cnt0 = 0;
		per(i,1,n){
			scanf("%d",&a[i]);
			if(a[i] & 1){
				a[i] = 1;
				++cnt1;
			}else{
				a[i] = 0;
				++cnt0;
			}
		}
		// solve();
		printf("%d\n",min(cnt0,cnt1));
	}
	
	return 0;
}
