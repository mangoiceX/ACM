#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (b);i >= (b);++i)
#define INF 1e9
typedef long long LL;
using namespace std;
const int maxn = 1e5 + 10;
int n = 0,m = 0,k = 0;
LL a = 0;
int bit[70];
LL b1[70],b2[70];
void solve(){
	LL tmp = a;
	int cnt = 0;
	while(tmp){
		bit[cnt++] = tmp & 1;
		tmp >>= 1;
	}
	LL x = 1ll;
	int cnt1 = 0,cnt2 = 0;
	per(i,0,cnt-1){
		if(bit[i]){
			if(x % 3 == 1){
				b1[++cnt1] = x;
			}else{
				b2[++cnt2] = x;
			}
		}
		x <<= 1;
	}

	if(a % 3 == 1){
		if(cnt1 >= 2){
			printf("2 %lld %lld\n",a-b1[1],a-b1[2]);
		}else if(cnt1 == 1){
			printf("2 %lld %lld\n",a-b1[1],b1[1] + b2[1]);
		}else{
			printf("2 %lld %lld\n",a-b2[1]-b2[2],b2[1]+b2[2]+b2[3]);
		}
	}else{
		if(cnt2 >= 2){
			printf("2 %lld %lld\n",a-b2[1],a-b2[2]);
		}else if(cnt2 == 1){
			printf("2 %lld %lld\n",a-b2[1],b2[1]+b1[1]);
		}else{
			printf("2 %lld %lld\n",a-b1[1]-b1[2],b1[1]+b1[2]+b1[3]);
		}
	}
}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&a);
		if(a % 3 == 0){
			printf("1 %lld\n",a);
			continue;
		}
		solve();
	}


	return 0;
}