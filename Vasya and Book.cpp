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
int n = 0,m = 0,d = 0,x = 0,y = 0;
void solve(){
	if(x == y){
		printf("0\n");
		return ;
	}
	if(abs(y - x) % d == 0){
		printf("%d\n",abs(y - x) / d);
		return ;
	}
	int dx = d - x % d,dy = d - (n-x) % d;
	int min1 = 0;
	min1 += (x / d + ((x % d == 1 || x % d == 0) ? 0 : 1));
	if(abs(y - 1) % d == 0){
		min1 += ((y-1) / d);
	}else{
		min1 = INF;
	}
	int min2 = 0;
	min2 += ((n-x) / d + (( (n-x) % d == 0) ? 0 : 1));
	if(abs(n - y) % d == 0){
		min2 += ((n-y) / d);
	}else{
		min2 = INF;
	}
	if(min1 == INF && min2 == INF){
		printf("-1\n");
		return ;
	}
	printf("%d\n",min(min1,min2));
}
int main(){

	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d %d",&n,&x,&y,&d);
		solve();
	}
	
	return 0;
}

