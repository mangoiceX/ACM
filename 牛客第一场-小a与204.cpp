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
const int maxn = 1e5;
int n = 0;
//int d[5];
int a[maxn+10];
LL pows(int a){
	return 1ll*a*a;
}
bool cmp(int a,int b){
	return a > b;
} 
void solve(){//这种写法代码十分精简 
	LL ans = 0;
	if(n & 1){
		per(i,0,n/2){
			ans += (pows(a[n-i] - a[i]) + pows(a[n-i-1] - a[i]));
		}
	}else{
		per(i,0,n/2-1){
			ans += (pows(a[n-i] - a[i]) + pows(a[n-i-1] - a[i]));
		}
	}
	printf("%lld\n",ans);
}
int main(){
	while(~scanf("%d",&n)){
		//memset(d,0,sizeof(d));
		per(i,1,n){
			scanf("%d",&a[i]);
		}
		a[0] = 0;
		sort(a,a+1+n,cmp);
		solve();
	}
	
	return 0;
}

