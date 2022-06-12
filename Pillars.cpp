#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 10;
const LL mod = (1e9 + 7);
int n = 0,m = 0,k = 0;
int a[maxn];
int maxv = -1,pos = 0;
void solve(){
	per(i,pos+1,n){
		if(a[i-1] < a[i]){
			puts("NO");
			return ;
		}
	}
	rep(i,pos-1,1){
		if(a[i] > a[i+1]){
			puts("NO");
			return ;
		}
	}
	puts("YES");
}
int main(){


	while(~scanf("%d",&n)){
		per(i,1,n){
			scanf("%d",&a[i]);
			if(a[i] > maxv){
				maxv = a[i];
				pos = i;
			}
		}
		solve();
	}

	return 0;
}