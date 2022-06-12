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
LL n = 0,m = 0,k = 0;
void solve(){
	LL ans = 0,res = n;
	while(res > 0){
		ans += (res % k);
		res = res - (res % k);
		if(res == 0){
			break;
		}
		LL a = 1;
		while(res != 0 && res % (1ll*LL(pow(k,a)) ) == 0){
			++a;
		}
		ans += (a-1);
		res = res / pow(k,a-1);
		if(res == 0){
			break;
		}
	}
	printf("%I64d\n",ans);
}
int main(){
	
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%I64d %I64d",&n,&k);
		solve();
	}
	
	return 0;
}

