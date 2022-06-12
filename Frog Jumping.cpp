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
LL n = 0,a = 0,b = 0,k = 0;
void solve(){
	LL ans = 0;
	if(k & 1){
		ans = (a - b) *(k / 2) + a;
	}else{
		ans = (a - b) *(k / 2);
	}
	printf("%I64d\n",ans);
}
int main(){	
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%I64d %I64d %I64d",&a,&b,&k);
		solve();
	}
	
	return 0;
}

