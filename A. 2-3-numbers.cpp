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
int l = 0,r = 0; 
void solve(){
	int ans = 0,i = 0;
	while(pow(3,i) <= r){
		ans += (floor(log2(r/pow(3,i)) + 1) -  max(0.0,(l == 1 ? 0 : floor(log2((l-1)/pow(3,i)) + 1))));
		//floor是double，取max是防止负数的出现 ，有log2函数，但没有log3函数，所以改变枚举方式 
		++i;
	}
	printf("%d\n",ans);
}
int main(){
	//std::ios::sync_with_stdio(false);
	while(~scanf("%d %d",&l,&r)){
		solve();
	}
	
	return 0;
}

