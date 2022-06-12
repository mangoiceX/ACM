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
int n = 0,m = 0; 
struct node{
	int t,p;
};
node a[maxn+10];
LL pre[maxn+10];
bool cmp(node x,node y){
	return (x.p == y.p) ? x.t < y.t : x.p > y.p;//如果p相等，则t小的放前面 
}
void solve(){//按照b从大到小，再a从小到大是错误的贪心 
	memset(pre,0,sizeof(pre));
	LL ans = 0;
	per(i,1,n){
		pre[i] = pre[i-1] + a[i].p;
	}
	per(i,1,n){
		ans += ((pre[n] - pre[i]) * a[i].t);
	}
	printf("%lld\n",ans);
}
int main(){
	//std::ios::sync_with_stdio(false);
	while(~scanf("%d",&n)){
		per(i,1,n){
			scanf("%d %d",&a[i].t,&a[i].p);
		} 
		sort(a+1,a+1+n,cmp);
		solve();
	}
	
	return 0;
}

