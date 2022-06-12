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
LL n = 0,b = 0; 

int main(){

	//std::ios::sync_with_stdio(false);
	
	while(~scanf("%I64d %I64d",&n,&b)){
		LL ans = 1000000000000000000LL;
				
		//per(i,2,b){//变分解质因数，边处理，节约空间 
		for(LL i = 2;i <= b;++i){//变分解质因数，边处理，节约空间 
			if(1ll*i*i > b){//说明b是质数 
				i = b; 
			}
			int cnt = 0;
			while(b % i == 0){
				b /= i;
				++cnt;
			}
			if(cnt == 0){
				continue;
			}
			LL tmp = 0,mul = 1;
			/*
			while(mul <= n/i){//不是mul <= n是为了防止mul超过longlong 
				mul *= i; 
				tmp += (n/mul);
				
			}
			*/
			LL c = n;
			while(c > 0){//还不如这样直接 
				tmp += (c/i);
				c /= i;
			}
			ans = min(ans,tmp / cnt);
		}
		printf("%I64d\n",ans);
	}
	
	return 0;
}

