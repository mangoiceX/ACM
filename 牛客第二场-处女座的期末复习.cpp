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
	int s,t;
}; 
node a[maxn+10];
LL pre[maxn+10];
int tim[maxn+10];
bool cmp(node x,node y){
	return x.s < y.s;
}
void solve(){
	per(i,1,n){
		pre[i] = pre[i-1] + a[i].t;
		tim[i] = a[i].s;
	}
	per(i,1,n){
		int loc = lower_bound(tim+1,tim+1+n,pre[i]+2*(i-1)) - tim;
		if(loc > i){
			printf("NO\n");
			return ;
		}
	}
	printf("YES\n");
}
int main(){
	while(~scanf("%d",&n)){
		per(i,1,n){
			scanf("%d",&a[i].t);
		}
		per(i,1,n){
			scanf("%d",&a[i].s);
		}
		sort(a+1,a+1+n,cmp);
		solve();
	}
	
	
	return 0;
}

