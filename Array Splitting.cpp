#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int maxn = 3e5 + 10;
const LL mod = (1e9 + 7);
int n = 0,m = 0,k = 0;
LL a[maxn],b[maxn];
void solve(){


}
int main(){

	while(~scanf("%d %d",&n,&k)){
		b[1] = 0;
		LL sum = 0;
		per(i,1,n){
			scanf("%I64d",&a[i]);
			if(i >= 2){
				b[i] = a[i] - a[i-1];
				sum += b[i];
			}
		}
		sort(b+1,b+1+n);
		rep(i,n,n-(k-1)+1){
			sum -= b[i];
		}
		printf("%I64d\n",sum);
		// solve();
	}

	return 0;
}