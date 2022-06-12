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
const int maxn = 1e3;
int n = 0,m = 0,r = 0;
struct node{
	int s,t,e;
};
node cow[maxn+10];
int dp[maxn+10];//dp[i]表示从1到i选取了i时的最大值 
bool cmp(node a,node b){//结束时间排序，而不是开始时间 
	return (a.t != b.t) ? a.t < b.t : a.s < b.s;
}
void solve(){
	fill(dp,dp+maxn+10,0);
	int ans = -1;
	per(i,1,m){
		dp[i] = cow[i].e;
		rep(j,i-1,1){
			if(cow[j].t + r <= cow[i].s){
				dp[i] = max(dp[j] + cow[i].e,dp[i]);//选取前面最大的 
			}
		}
		ans = max(ans,dp[i]);
	}
	printf("%d\n",ans);
}
int main(){
	while(~scanf("%d %d %d",&n,&m,&r)){
		per(i,1,m){
			scanf("%d %d %d",&cow[i].s,&cow[i].t,&cow[i].e);
		}
		sort(cow+1,cow+1+m,cmp);
		solve();
	}
	
	
	return 0;
}

