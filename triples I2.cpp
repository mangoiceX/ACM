#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (b);i >= (b);++i)
#define INF 1e9
typedef long long LL;
using namespace std;
const int maxn = 1e5 + 10;
int m = 0,k = 0;
LL n = 0;
int bit[70];
void solve(){
	LL tmp = n;
	per(i,0,63){
		bit[i] = tmp & 1ll;
		tmp >>= 1ll;
	}
	vector<int> g1,g2;
	per(i,0,63){
		if(bit[i]){
			int r = (1ll<<i)  % 3;
			if(r == 1){
				g1.push_back(i);
			}else{
				g2.push_back(i);
			}
		}
	}
	int si1 = g1.size(),si2 = g2.size();
	int si0 = min(si1,si2);
	vector<LL> ans;
	LL sum1 = 0;
	per(i,0,si0-1){
		sum1 = ((1ll<<g1[i]) + (1ll<<g2[i]));
	}
	ans.push_back(sum1);
	LL sum2 = 0;
	if(si1 > si2){
		per(i,si1-si2+1-1,si1-1){
			sum2 += (1ll<<g1[i]);
		}
		if((si1-si2) % 3 == 1){
			ans.push_back(sum2 + (1ll<<g2[0]));
		}else if((si1-si2) % 3 == 2){
			ans.push_back(sum2 + (1ll<<g1[0]));
		}else{
			ans.push_back(sum2);
		}

	}else{
		per(i,si2-si1+1-1,si2-1){
			sum2 += (1ll<<g2[i]);
		}
		if((si2-si1) % 3 == 1){
			ans.push_back(sum2 + (1ll<<g1[0]));
		}else if((si2-si1) % 3 == 2){
			ans.push_back(sum2 + (1ll<<g2[0]));
		}else{
			ans.push_back(sum2);
		}
	}
	int sip = ans.size();
	printf("%d ",sip);
	per(i,0,sip-1){
		printf("%lld%c",ans[i],i == sip-1 ? '\n' : ' ');
	}
}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		if(n % 3 == 0){
			printf("1 %lld\n",n);
			continue;
		}
		solve();
	}


	return 0;
}