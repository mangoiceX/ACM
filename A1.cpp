#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 3e5 + 10;
int a = 0,b = 0,n = 0,m = 0,q = 0;
int f[maxn];
void solve(){
	
}
int main(){
	// std::ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&a,&b,&n);
		f[0] = a;  f[1] = b; f[2] = a^b;
		printf("%d\n",f[n%3]);
		// solve();
	}

	return 0;
}
