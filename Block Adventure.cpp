#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a;i >= (b);--i))
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 1e2 + 10;
int n = 0,m = 0,k = 0;
int a[maxn];
bool solve(){
	LL res = m;
	per(i,2,n){
		if(a[i-1] >= a[i]){
			res += (a[i-1] - max(0,(a[i] - k)) );
		}else{
			res -= (max(0,a[i] - k) - a[i-1]);
		}
		if(res < 0){
			return false;
		}
	}
	return true;
}
int main(){
	
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&n,&m,&k);
		per(i,1,n){
			scanf("%d",&a[i]);
		}
		if(solve()){
			puts("YES");
		}else{
			puts("NO");
		}

	}
	return 0;
}
