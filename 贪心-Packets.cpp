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
const int maxn = 3e5;
int n = 0,m = 0;
int a[7]; 
void solve(){
	int ans = 0;
	ans += a[6];
	ans += a[5];
	a[1] = max(0,a[1] - (6*6-5*5)*a[5]);
	ans += a[4];
	a[2] = max(0,a[2] - (6*6 - 4*4)/(2*2) * a[4]);
	int res4 = (a[4] * 5 * 4 - a[2] * 4) > 0 ? 0 : (a[4] * 5 * 4 - a[2] * 4);
	ans += (a[3] % 4 == 0) ? a[3]/4 : a[3] / 4 + 1;
	int res3 = 6*6 - a[3]%4*9;
	if(res4 >= 0){
		a[1] -= (res3 + res4);
		if(a[1] != 0){
			ans += (a[1] % 36 == 0) ? a[1] / 36 : a[1]/36 + 1;	
		}
		printf("%d\n",ans);
		return ;
	}
	if(res3 == 27){
		a[2] -= 5;
		a[1] -= (res3 - 5 * 4);
	} else if(res3 == 18){
		a[2] -= 3;
		a[1] -= (res3 - 3 * 4);
	}else if(res3 == 9){
		a[2] -= 1;
		a[1] -= (res3 - 1 * 4);
	}
	if(a[2] > 0){
		ans += (a[2] % 9 == 0) ? a[2] / 9 : a[2] /9 + 1;
	}
	if(a[2] > 0 && a[2] % 9 != 0){
		a[1] -= (36 - a[2] % 9 * 4);
	}
	if(a[1] > 0){
		ans += (a[1] % 36 == 0) ? a[1] / 36 : a[1] / 36 + 1;
	}
	printf("%d\n",ans);
}
int main(){
	while(~scanf("%d %d %d %d %d %d",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6]) && 
	(a[1] + a[2] + a[3] + a[4] + a[5] + a[6]) > 0){
		solve();
	}
	return 0;
}

