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
int n = 0,s = 0;

int main(){
	while(~scanf("%d %d",&n,&s)){
		int minc = 1e4 + 10;
		LL ans = 0;
		per(i,1,n){
			int c = 0,y = 0;
			scanf("%d %d",&c,&y);
			minc = min(minc + s,c);//维护当前最优代价 
			ans += minc * y;
		}
		printf("%I64d\n",ans);
	}
	
	return 0;
}

