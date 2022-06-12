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
int p3[5] = {0,5,3,1};
void solve(){
	int ans = 0;
	ans += (a[6] + a[5] + a[4]);
	//ans += (a[3] / 4 + (a[3] % 4 == 0) ? 0 : 1);//后面的表达式整体要加上括号 
	ans += (a[3] / 4 + ((a[3] % 4 == 0) ? 0 : 1));
	int n2 = (a[4] * 5 + p3[a[3] % 4]);
	if(a[2] > n2){
		ans += ((a[2] - n2) / 9 + ((a[2] - n2) % 9 == 0 ? 0 : 1));	
	}
	int n1 = ans*36 - (a[2]*4 + a[3]*9 + a[4]*16 + a[5]*25 + a[6]*36);
	//1由其他的取反 
	if(a[1] > n1){
		ans += ((a[1] - n1) / 36 + ((a[1] - n1) % 36 == 0 ? 0 : 1));
	}
	printf("%d\n",ans);
}
int main(){
	while(~scanf("%d %d %d %d %d %d",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6])){
		if((a[1] + a[2] + a[3] + a[4] + a[5] + a[6]) <= 0){
			break;
		}
		solve();
	}
	
	return 0;
}

