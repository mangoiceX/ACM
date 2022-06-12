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
const int maxn = 3e5;
LL n = 0,m = 0,d = 0,x = 0; 
void solve(){
	LL l = 1,r = x,ans = 0;
	while(l <= r){//注意边界问题 
		LL mid = (r - l)/2 + l;
		LL sum = n * mid + mid * (mid-1)*d/2;
		if(sum < m){
			l = mid + 1;
		}else{
			ans = mid;
			r = mid - 1;
		}
	}
	printf("%lld\n",ans); 
}
int main(){
	//std::ios::sync_with_stdio(false);
	while(~scanf("%lld %lld %lld %lld",&n,&m,&d,&x)){
		
		solve();
	}
	
	return 0;
}

