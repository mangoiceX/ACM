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
LL n = 0,a = 0,b = 0;
void solve(){

}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%I64d %I64d %I64d",&n,&a,&b);
		if((b*1.0 / 2) < (a*1.0)){
			LL ans = n/2*b;
			if(n & 1){
				ans += a;
			}
			printf("%I64d\n",ans);	
		}else{
			printf("%I64d\n",a*n);
		}
	}
	
	return 0;
}

