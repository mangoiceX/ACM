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

#define inf 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
const int maxn = 3e5;
LL n = 0;
void solve(){
	LL temp = n;
	LL cnt = 0;
	while(true){
		if(int(sqrt(temp+0.5)) < 2){
			printf("%I64d\n",cnt+1);
			return ;
		}
		per(i,2,int(sqrt(temp+0.5))){
			if(temp % 2 == 0){
				cnt += temp / i;
				printf("%I64d\n",cnt);
				return ;
			}
			if(temp % i == 0){
				cnt += 1;
				temp -= i;
				break;
			}
			if(i == int(sqrt(temp + 0.5))){
				printf("%I64d\n",cnt+1);
				return ;
			}
		}
	}
}
int main(){
	while(~scanf("%I64d",&n)){
		solve();
	}
	
	return 0;
}




