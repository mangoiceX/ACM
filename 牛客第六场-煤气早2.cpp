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
LL n = 0,m = 0,d = 0,x = 0; 
void solve(){
	if(d == 0){
		printf("%d\n",(int)ceil(m * 1.0 / n));
		return ;
	}
	int ans = (int)ceil( ( sqrt((2.0*n-d)*(2.0*n-d) + 8.0*m*d) - (2.0*n - d)) / (2.0*d));//类型转换出了问题 
	//sqrt()函数参数只能是float和double类型，int会报错，pow()也是的，但是dev c++容错性强，不会报错 
	printf("%d\n",ans);
}
int main(){
	//std::ios::sync_with_stdio(false);
	while(~scanf("%lld %lld %lld %lld",&n,&m,&d,&x)){
		
		solve();
	}
	
	return 0;
}

