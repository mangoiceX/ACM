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

#define inf 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
#define ESP 1e-6
const int maxn = 3e5;
int d = 0;
void solve(){
	if(d < 4 && d != 0){
		printf("N\n");
		return ;
	}
	if(d == 0){
		printf("Y 0.000000000 0.000000000\n");
		return ;
	}
	double a = ( d + sqrt(d*(d-4)) ) / 2;
	double b = ( d - sqrt(d*(d-4)) ) / 2;
	printf("Y %.9lf %.9lf\n",a,b);
}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&d);
		solve();
	}
	
	return 0;
}




