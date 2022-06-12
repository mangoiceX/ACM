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
const int maxn = 1e4;
int n = 0,m = 0; 
struct node{
	int s,e;
}; 
node a[maxn+10];
void solve(){//思维能力还是不行，总想着细致模拟，把问题想得太复杂，太细节化,这就是大佬和弱鸡的区别
	LL ans = 0;
	per(i,1,n){
		if(min(a[i].s,a[i].e) < max(a[i-1].s,a[i-1].e)){
			continue;
		}
		if(a[i-1].s == a[i-1].e){//如果前面的比分相等，那么他在上一次计算就已经算过了，每一次都是[]闭区间，
		//如果不相等，那么上一次用的是min(a[i-1].s,a[i-1].e),而这一次使用的是max(a[i-1].s,a[i-1].e)
		//因为a[i-1].s != a[i-1].e,所以两者不相等，所以断电不会重复算 
			ans += (min(a[i].s,a[i].e) - max(a[i-1].s,a[i-1].e));
		}else{
			ans += (min(a[i].s,a[i].e) - max(a[i-1].s,a[i-1].e) + 1);
		}
	}
	printf("%I64d\n",ans+1);//最后+1,加上0 0 
}
int main(){
	//std::ios::sync_with_stdio(false);
	while(~scanf("%d",&n)){
		a[0].s = a[0].e = 0;
		per(i,1,n){
			scanf("%d %d",&a[i].s,&a[i].e);
		}
		solve();
	}
	
	return 0;
}

