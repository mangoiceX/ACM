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
const int maxn = 50,ma = 180*50;
int n = 0,t = 0; 
int max_time = 0;
int a[maxn+10];
struct node{
	int num,time;
	bool operator < (const node &it)const{
		return num < it.num || (num == it.num && time < it.time);
	}
};
node dp[maxn+10][ma+10];
void solve(){
	memset(dp,0,sizeof(dp));
	per(i,1,n){
		rep(j,max_time,0){//之前这里没有到0,而只是到a[i]，导致出错
		//比如a[1]=20,a[2]=50,第一次循环知道20，第二次只循环到50，其实第二次的20-50之间的j也可以循环
		//因为这些虽然小于50,但是还是可以由之前的状态转化过来，这里还是要记录，而一味的时候就不用记录了
		//因为20-30是保留下来了，无后效性 
			if(j < a[i]){
				dp[i][j] = dp[i-1][j];
				continue;
			}
			node tmp;
			tmp.num  = dp[i-1][j-a[i]].num + 1;
			tmp.time = dp[i-1][j-a[i]].time + a[i];
			dp[i][j] = (dp[i-1][j] < tmp ? tmp : dp[i-1][j]);
		}
	}

}
int main(){
	//std::ios::sync_with_stdio(false);
	int T = 0,kase = 0;
	scanf("%d",&T);
	while(T--){
		int sum = 0;
		scanf("%d %d",&n,&t);
		per(i,1,n){
			scanf("%d",&a[i]);
			sum += a[i];
		}
		max_time = min(t-1,sum);
		solve();
		printf("Case %d: %d %d\n",++kase,dp[n][max_time].num+1,dp[n][max_time].time + 678);
	}
	
	return 0;
}

