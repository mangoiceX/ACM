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
int n = 0,x = 0,y = 0;
int a[maxn+10];
int gcd(int b,int c){
	return		 c == 0 ? b : gcd(c,b%c);
}
void solve(){
	int maxv = 0;
	per(i,2,n){
		if(a[i] == a[i-1]){
			maxv = a[i];
		}
	}
	y = a[n];
	rep(i,n-1,1){
		if(gcd(y,a[i]) == maxv){
			x = a[i];
			break;
		}
	}
	printf("%d %d\n",x,y);
}
int main(){
	while(~scanf("%d",&n)){
		per(i,1,n){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		solve();
	}
	
	return 0;
}

