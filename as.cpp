#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
const int maxn = 3e5;
int n = 0,k = 0;
int a[maxn+10];
LL suf[maxn+10];
void solve(){
	LL ans = suf[1];
	sort(suf+2,suf+1+n);
 	rep(i,n,n-k+1+1){
		ans += suf[i];
	}
	printf("%I64d\n",ans);
}
int main(){
	while(~scanf("%d %d",&n,&k)){
		memset(suf,0,sizeof(suf));
		per(i,1,n){
			scanf("%d",&a[i]);
		}
		rep(i,n,1){
			suf[i] = suf[i+1] + a[i];
		}
		solve();
	}
		
	return 0;
}
