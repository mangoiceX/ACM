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
int a[maxn+10];
LL sum = 0;
bool cmp(int a,int b){
	return a > b;
}
void solve(){
	LL ans = 0;
	int cnt = 0,mi = a[1];
	a[n+1] = 0;
	per(i,1,n){
		if(i < n && a[i] == a[i+1]){
			ans += 1;
			mi--;//记录当前要满足的最小高度 
		}else{
			if(mi <= a[i+1]){
				ans += 1;
				mi--;
			}else{
				ans += (mi - a[i+1]);
				mi = a[i+1];
			}
		}
	}
	printf("%I64d\n",sum - ans);
}
int main(){
	while(~scanf("%d %d",&n,&m)){
		sum = 0;
		per(i,1,n){
			scanf("%d",&a[i]);
			sum += a[i];
		}
		sort(a+1,a+1+n,cmp);
		solve();
	}
	
	return 0;
}

