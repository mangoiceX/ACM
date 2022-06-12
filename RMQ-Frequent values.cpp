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
int n = 0,q = 0; 
int a[maxn+10];
int num[maxn+10];//维护额外信息 

int dp[maxn+10][20];
void RMQ(){
	per(i,1,n){
		dp[i][0] = num[i];
	}
	for(int j = 1;(1 << j) <= n;++j){
		for(int i = 1;i + (1<<j-1) <= n;++i){
			dp[i][j] = max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
		}
	}
}
int query(int l,int r){
	if(l > r){
		return 0;
	}
	int k = 0;
	while((1<<(k+1)) <= (r - l + 1)){
		++k;
	}
	return max(dp[l][k],dp[r-(1<<k)+1][k]);
}
int main(){
	//std::ios::sync_with_stdio(false);
	while(~scanf("%d",&n) && n){
		scanf("%d",&q);
		memset(num,0,sizeof(num));
		per(i,1,n){
			scanf("%d",&a[i]);
		}
		per(i,1,n){
			if(a[i] == a[i-1] && i != 1){
				num[i] = num[i-1] + 1;
			}else{
				num[i] = 1;
			}
		}
		RMQ();
		per(i,1,q){
			int l = 0,r = 0;
			scanf("%d %d",&l,&r);
			int t = l;//初始值要特别计算 
			while(t <= r && a[t] == a[t-1]){
				++t;
			} 
			int ma = query(t,r);
			int ans = max(ma,t-l);
			printf("%d\n",ans);
		}
	}
	

	return 0;
}

