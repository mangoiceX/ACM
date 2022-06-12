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
int n = 0,l = 0,r = 0,d = 0;
void solve(){
	if(d < l || d > r){
		printf("%d\n",d);
		return ;
	}
	printf("%d\n",(r/d+1)*d);
}
int main(){
	
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&l,&r,&d);
		solve();
	}
	
	return 0;
}

