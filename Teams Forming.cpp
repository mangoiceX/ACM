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
int n = 0,m = 0;
int a[maxn+10];
void solve(){
	int minv = 1e6;
	per(i,0,n-1){
		int sum = 0;
		int cnt = 1;
		for(int j = i;cnt <= n/2;++cnt){
			sum += ( abs(a[(j+1)%n] - a[j%n]) );
			j += 2;
		}
		minv = min(sum,minv);
	}
	printf("%d\n",minv);
}
int main(){
	while(~scanf("%d",&n)){
		per(i,0,n-1){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		solve();
	}
	
	return 0;
}

