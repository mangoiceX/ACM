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
LL n = 0,m = 0;
void solve(){
	int a[10] = {0};
	while(n % 2 == 0){
		n /= 2;
		++a[2];
	}
	while(n % 3 == 0){
		n /= 3;
		++a[3];
	}
	while(n % 5 == 0){
		n /= 5;
		++a[5];
	}
	if(n > 1){
		printf("-1\n");
		return ;
	}
	printf("%d\n",a[2] + a[3] * 2 + a[5] * 3);
}
int main(){
	int q = 0;
	scanf("%d",&q);
	while(q--){
		scanf("%I64d",&n);
		solve();
	}
	
	return 0;
}

