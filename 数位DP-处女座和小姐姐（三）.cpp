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
const int maxn = 32;
LL l = 0,r = 0; 
int d[maxn+10];
LL dp[maxn+10][2];
LL dfs(int pos,int sta,bool lim){
	if(pos == 0){
		return sta ? 1 : 0;
	}
	if(!lim && dp[pos][sta] != 0){
		return dp[pos][sta];
	}
	int up = lim ? d[pos] : 9;
	LL tmp = 0;
	for(int i = 0;i <= up;++i){
		tmp += dfs(pos-1,(i == 6 || sta == 1) ? 1 : 0,lim && i == d[pos]);
	}
	if(!lim){
		dp[pos][sta] = tmp;
	}
	return tmp;
}
LL solve(LL x){
	memset(dp,0,sizeof(dp));
	LL tmp = x;
	int cnt = 0;
	while(tmp > 0){
		d[++cnt] = tmp % 10;
		tmp /= 10;
	}
	d[cnt+1] = 0;
	return dfs(cnt,0,true);
}
int main(){
	//std::ios::sync_with_stdio(false);
	while(~scanf("%lld %lld",&l,&r)){
		printf("%lld\n",solve(r) - solve(l-1));
	}
	
	return 0;
}

