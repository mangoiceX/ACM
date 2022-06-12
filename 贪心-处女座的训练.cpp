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
	int p,t;
}; 
node a[maxn+10];
bool cmp(node x,node y){//性价比贪心, x.p/x.t大的先做，另外的排序规则可以任意 
	return (1.0*x.p/x.t == 1.0*y.p/y.t) ? (x.p < y.p) :(1.0*x.p/x.t > 1.0*y.p/y.t);
}

int main(){
	//std::ios::sync_with_stdio(false);
	while(~scanf("%d",&n)){
		LL sum = 0;
		per(i,1,n){
			scanf("%d %d",&a[i].t,&a[i].p);
			sum += a[i].p;
		}
		sort(a+1,a+1+n,cmp);
		LL ans = 0;
		per(i,1,n){
			sum -= a[i].p;
			ans += (sum * a[i].t);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

