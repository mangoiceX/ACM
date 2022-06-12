#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f 
typedef long long LL;
using namespace std;
const int maxn = 1e5;
int n = 0,m = 0;
LL f[maxn+10];
int main(){
	f[0] = 1,f[1] = 1,f[2] = 2,f[3] = 3;
	while(~scanf("%d",&n)){
		per(i,4,n){
			f[i] = f[i-1] +f[i-3];
		}
		printf("%lld\n",f[n]);
	}
	
	return 0;
}
