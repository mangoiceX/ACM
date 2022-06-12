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
const int maxn = 100;
int n = 0,x = 0,y = 0;
int a[maxn+10];
void solve(){
	if(x > y){
		printf("%d\n",n);
		return ;
	}
	a[n+1] = INF;//这里要设置末尾极端情况，因为upper_bound(所有数都小于x),会指向最后一个数的
	//下一位置,这是会比实际位置多1，这种特殊情况只要设置末尾，就可以将特殊情况一般化处理 
	int ans = upper_bound(a+1,a+1+n,x) - a;//这里不是找lower_bound，而是upper_bound
	while(ans > 0 && a[ans] > x){
		ans--;
	}
	printf("%d\n",(ans+1)/2);
}
int main(){
	while(~scanf("%d %d %d",&n,&x,&y)){
		per(i,1,n){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		solve();
	}
	
	return 0;
}

