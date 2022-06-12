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
void solve(){
	if(n == 1){
		printf("-1\n");
		return ;
	} 
	if(n == 2){
		printf("2 2\n");
		return ;
	}
	int a = (n+2)/2;
	if(a & 1){
		a += 1;
	}
	printf("%d 2\n",a);
}
int main(){
	while(~scanf("%d",&n)){
		solve();
	}

	return 0;
}

