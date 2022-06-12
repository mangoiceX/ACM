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
const int maxn = 1<<12;
int n = 0,m = 0; 
bool dp[maxn+10];
int p[maxn+10];
void solve(){
	
	if(p[1] <= p[n]){
		printf("-1\n");
		return ;
	}
	memset(dp,false,sizeof(dp)); 
	int a[maxn+10],cnt = 0;
	per(i,2,n-1){
	//for(int i = 2;i <= n-1;++i){
		if(p[i] < p[1] && p[i] > p[n]){
			a[++cnt] = p[i];
		}
	}
	dp[p[1] ^ p[n]] = true;//p[1]不能初始化为true 
	per(i,1,cnt){
	//for(int i = 1;i <= cnt;++i){
		rep(j,maxn-1,0){//这里要从maxn-1开始，也就是2^12-1开始，否则异或运算会超出2^12的范围 
		//for(int j = maxn-1;j >= 0;--j){
			dp[j] |= dp[j^a[i]];//j = x^a[i]则 x = j ^ a[i] 
		}
	}
	int maxv = 0;
	rep(i,maxn-1,1){
		if(dp[i] == true){
			maxv = i;
			break;
		}
	}
	printf("%d\n",maxv);
}
int main(){
	//std::ios::sync_with_stdio(false);
	while(~scanf("%d",&n)){
		per(i,1,n){
			scanf("%d",&p[i]);
		}
		solve();
	}
	
	return 0;
}

