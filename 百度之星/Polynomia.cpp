#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 3e5 + 10;
int n = 0,m = 0;
int a[maxn],b[maxn];
int gcd(int x,int y){
	return  y == 0 ? x : gcd(y,x%y);
}
void solve(){
	rep(i,n,1){
		if(a[i] == 0 && b[i] != 0){
			printf("0/1\n");
			return ;
		}else if(a[i] != 0 && b[i] == 0){
			printf("1/0\n");
			return ;
		}else if(a[i] != 0 && b[i] != 0){
			int gc = gcd(a[i],b[i]);
			printf("%d/%d\n",a[i]/gc,b[i]/gc);
			return ;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		per(i,1,n){
			scanf("%d",&a[i]);
		}
		per(i,1,n){
			scanf("%d",&b[i]);
		}
		solve();
	}

	return 0;
}
