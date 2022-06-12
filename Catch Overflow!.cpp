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
char s[10];
LL pre[maxn+10];
LL ans = 0;
int cnt = 0;
void solve(){

}
int main(){
	while(~scanf("%d",&n)){
		ans = 0;cnt = 0;
		pre[0] = 1ll;
		per(i,1,n){
			scanf("%s",s);
			if(s[0] == 'f'){
				scanf("%d",&m);
				//pre[cnt + 1] = (pre[cnt] * m > (1ll<<32)-1) ? -1 : pre[cnt] * m;
				//++cnt; 
				if(pre[cnt] * m < (1ll<<32) && pre[cnt] != -1){
					pre[cnt+1] = 1ll * pre[cnt] * m;
					++cnt;
				}else{
					pre[++cnt] = -1;
				}
			}else if(s[0] == 'a'){
				if(pre[cnt] == -1){
					return puts("OVERFLOW!!!"),0;
				}
				ans += pre[cnt];
				if(ans > (1ll << 32)-1){
					return puts("OVERFLOW!!!"),0;
				}
			}else{
				--cnt;
			}
		}
		printf("%I64d\n",ans);
		//solve();
	}
	
	
	return 0;
}

