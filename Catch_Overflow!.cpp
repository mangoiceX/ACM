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
const int maxn = 1e5;
int n = 0;
char s[10];
LL mul = 1;
int m[maxn+10];

int main(){
	while(~scanf("%d",&n)){
		LL ans = 0;
		bool fg = false;
		int cnt = 0,times = 0;
		mul = 1;
		per(i,1,n){
			scanf("%s",s);
			if(s[0] == 'f'){
				scanf("%d",&m[++cnt]);
				if(mul * m[cnt] > (1ll<<32)-1 || fg){//如果之前也是超出，那么也记录,所以要|| fg
					fg = true;
					++times;
					continue;
				}
				mul *= m[cnt];
			}else if(s[0] == 'a'){
				ans += mul;
				if(ans > (1ll<<32)-1 || fg == true){
					return puts("OVERFLOW!!!"),0;
				}
			}else{
				if(times > 0){
					--times;
					--cnt;
					if(times == 0){
						fg = false;
					}
					continue;
				}else{
					fg = false;
				}
				mul /= m[cnt--];
			}
		}
		printf("%I64d\n",ans);
	}
	
	return 0;
}
/*

13
for 100
for 100
for 100
for 100
for 100
for 2
end
add
end
end
end
end
end
*/