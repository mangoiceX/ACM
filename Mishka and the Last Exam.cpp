#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

typedef long long LL;

#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
const int maxn = 2e5;
int n = 0;
LL b[maxn+100],a[maxn+100];
void solve(){
	a[n+1] = b[1];
	per(i,1,(n/2)){//两边贪心结合 
		if(b[i] - a[n-i+1+1] >= a[i-1]){//贪心选最大的 
			a[n-i+1] = a[n-i+1+1];
			a[i] = b[i] - a[n-i+1];
		}else{//贪心选最小的 
			//a[n-i+1] = min(b[i]-a[i-1],a[n-i+1+1]-a[i-1]);
			//如果b[i] <= a[n-i+1+1]，则与下面AC的版本一样。
			//如果b[i] > a[n-i+1+1],那么a[n-i+1]会比下面的贪心小，而a[i]会变大，相当于区间
			//变得更小了，两边贪心都是失败的，最后还WA8，a[85]超出1e18. 
			//a[i] = b[i] - a[n-i+1];
			a[i] = a[i-1];
			a[n-i+1] = b[i] - a[i];//贪心左边，右边不会超过a[n-i+1+1],因为if条件已经判断了 
		}
	}
	per(i,1,n){
		printf("%I64d%c",a[i],(i == n) ? '\n' : ' ');
	}
}


int main(){
	while(~scanf("%d",&n)){
		per(i,1,n/2){
			scanf("%I64d",&b[i]);
		}
		solve();
	}
	
	
	return 0;
}

