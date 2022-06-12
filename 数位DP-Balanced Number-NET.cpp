#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<ctime>  
#include<cstring>
#include<stack>
#include<cmath>
#include<queue>
#define INF 0x3f3f3f3f
#define eps 1e-9
#define MAXN 100000
using namespace std;
typedef long long ll;
int T;
ll l,r,a[22],dp[22][4000];
ll dfs(int pos,int shaft,int sta,int limit)
{
	if(pos == -1) return sta == 0;
	if(!limit && dp[pos][sta+2000] >= 0) return dp[pos][sta+2000];
	int up = limit? a[pos] : 9;
	ll ans = 0;
	for(int i = 0;i <= up;i++)
	{
		ans += dfs(pos-1,shaft,sta+(pos-shaft)*i,limit && i == up);			
	}  
	if(!limit) dp[pos][sta+2000] = ans;
	return ans;
}
ll solve(ll x)
{
	if(x < 0) return 0;
	int pos = 0;
	while(x)
	{
		a[pos++] = x % 10;
		x /= 10;
	}
	if(!pos) return 1ll; //很隐蔽的错误，x = 0时特殊处理下. 
	ll ans = 0;
	for(int i = 0;i < pos;i++) 
	{
		memset(dp,-1,sizeof(dp));
		ans += dfs(pos-1,i,0,1);
	}
	return ans-pos+1;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%I64d%I64d",&l,&r); 
		printf("%I64d\n",solve(r));//-solve(l-1));
	}
}

