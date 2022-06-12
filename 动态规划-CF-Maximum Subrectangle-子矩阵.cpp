#include<iostream>
#include<cstdio>
#include<vector>
#include<bitset>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<fstream>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define pii pair<int, int>
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define PER(i,x) for(auto i=x.begin();i!=x.end();i++)
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
typedef long long LL;
const double eps=1.0e-5;
const int maxn=2000 + 10;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n = 0,m = 0,x = 0; 
int a[maxn],b[maxn];
LL dp1[maxn],dp2[maxn];//要设置为LL ，不然会爆 
LL pre_sum1[maxn],pre_sum2[maxn];//要设置为LL 
void solve(){
	//mem(dp1,0);mem(dp2,0);
	fill(dp1,dp1+maxn,INF);fill(dp2,dp2+maxn,INF);
	per(i,1,n){//枚举长度，在相同长度下，要求的和最小，所以符合最优子结构性质 
		for(int j = 1;j + i - 1 <= n;++j){
			dp1[i] = min(pre_sum1[j+i-1] - pre_sum1[j-1],dp1[i]);
		}
	}
	per(i,1,m){
		for(int j = 1;j + i - 1 <= m;++j){
			dp2[i] = min(pre_sum2[j+i-1] - pre_sum2[j-1],dp2[i]);
		}
	}
	int maxv = 0;//不能设置为-1，因为没有答案时输出0，所以应设置为0，考虑问题不全面 
	per(i,1,n){
		per(j,1,m){
			if(dp1[i] * dp2[j] <= x){
				maxv = max(maxv ,i * j );
			}
		}
	}
	printf("%d\n",maxv);
}
int main(){
	#ifndef ONLINE_JUDGE
		//freopen("a.txt","r",stdin);
	#endif
	while(~scanf("%d %d",&n,&m)){
		mem(pre_sum1,0);mem(pre_sum2,0);
		per(i,1,n){
			scanf("%d",&a[i]);
			pre_sum1[i] = pre_sum1[i-1] + a[i];//求前缀和 
		} 
		per(i,1,m){
			scanf("%d",&b[i]);
			pre_sum2[i] = pre_sum2[i-1] + b[i];
		} 
		scanf("%d",&x);
		solve();
	}
	
	return 0; 
}
