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
int n = 0,m = 0;
LL f[maxn+10],e[maxn+10],a[maxn+10];
int lor[maxn+10] = {0},lol[maxn+10] = {0};
const LL ma = pow(2,32) - 1;

int main(){
	while(~scanf("%d",&n)){
		int c0 = 0,c1 = 0,c2 = 0;
		LL mul = 1,ans = 0;
		per(i,1,n){
			char s[10];
			scanf("%s",s);
			if(s[0] == 'f'){
				scanf("%d",&m);
				f[++c0] = m;
				mul *= m;
				lol[c0] = c2+1;
			}else if(s[0] == 'e'){
				e[++c1] = 1;
			}else{
				a[++c2] = mul;
				lor[c0] = c2;
			}
			cout << " " << ans << " " << mul<< endl;
			if(c1 >= 1){
				if(c2 <= 0){
					mul /= f[c0--];
					cout << mul << endl;
					--c1;
					continue;
				}

				per(i,lol[c0],lor[c0]){
					ans += a[i];
					cout << a[i] << endl;
					cout << ans <<" " << c1 << " " << c2 << endl;
					if(ans > ma){
						puts("OVERFLOW!!!");
						return 0;
					}
					cout << "niama " << mul << endl;
				}
				mul /= f[c0--];	

				c1 = 0;
				c2 = lol[c0+1] - 1;
				lol[c0+1] = lor[c0+1] = 0;
			}
			if(c1 == c0 && c0 == 0 && c2 == 1){
				c2 = 0;
				ans += 1;
			}
		}
		printf("%I64d\n",ans);
	}
	
	return 0;
}
/*
6
for 4
add
for 5
add
end
end
40
*/
