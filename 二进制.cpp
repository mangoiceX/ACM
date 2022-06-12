#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
typedef long long LL;
const int maxn = 100;
LL dp[30];
int d[30];
int pre0[maxn],suf0[maxn],suf1[maxn];
int n = 0;
LL q_pow(int x){
	LL ans = 1;
	while(x > 0){
		ans <<= 1;
		x >>= 1;
	}
	return ans;
}
void pre_solve(){
	dp[0] = 0;
	per(i,1,20){
		dp[i] = 2*dp[i-1] + q_pow(i-1);
	}
}

void solve(){
	int cnt = 0;
	int tmp = n;
	while(tmp > 0){
		d[cnt++] = tmp & 1;
		tmp >>= 1;
	}
	rep(i,cnt-1-1,0){
		pre0[i] = pre0[i+1] + (d[i] == 0 ? 1 : 0);
	}
	per(i,1,cnt-1-1){
		suf0[i] = suf0[i-1] + (d[i-1] == 0 ? 1 : 0);
	}
	per(i,1,cnt-1-1){
		suf1[i] = suf1[i-1] + (d[i-1] == 1 ? 1 : 0);
	}
	// rep(i,cnt-1-1,0){
	// 	printf("%d\n",pre0[i]);
	// }
	LL ans1 = 0,ans2 = 0;
	bool flag = false;
	rep(i,cnt-2,0){
		ans1 += dp[i];//类似数位DP，低位全部合法
		if(d[i] == 1){//处理最高位
			// ans2 += (dp[i] + q_pow(i)*(pre0[i]+1) + q_pow(i)*1);//
			ans2 += (i-1>=0?q_pow(i):1)*(pre0[i]+1) + i*(i-1>=0?q_pow(i-1):0); 
			// ans2 += q_pow(i)*(pre0[i]+1) + i*(i-1>=0?q_pow(i-1):0);  
			// printf("ni %lld\n",ans2);
			if(suf1[i] > 0){
				ans2 += (suf0[i]+pre0[i]+(suf1[i] > 0 ? 1 : 0)) * ((suf1[i] > 0 ? 1 : 0)*q_pow(suf1[i]-1)) + (suf1[i]-2>0? q_pow(max(0,suf1[i]-1-1)) : 0)  ;
				// printf("hifdkasj %lld\n",(suf0[i]+pre0[i]+1) * (1*q_pow(suf1[i]-1)));
				// printf("%d hjiojo \n", (suf1[i]-2>0? q_pow(max(0,suf1[i]-1-1)) : 0) );
				// printf("ans2 %d\n",ans2);
			}else{
				// printf("%d\n",ans2);
				ans2 += pre0[i] + suf0[i];
				// printf("%d\n",ans2);
			}
			// ans2 += (q_pow(i)*(pre0[i]+1) + i*(i-1>=0?q_pow(2,i-1):0)+    (suf0[i]+pre0[i]+1) * q_pow(2,suf1[i]-1) + (suf1[i]>=0? q_pow(2,max(0,suf1[i]-1-1)) : 0)  );
			//      这位为0时，后面任意，（高位0+本身0）*后面的种数      这位为1时，（高位0+低位0）*种类（低位1的任意） + 低位1的任意时的0的种数
			flag = true;
		}
	}
	if(!flag){//特殊处理：如果最高位后面没有1了，那么加上这些0
		ans2 += pre0[0];
	}
	printf("%lld %lld %lld\n",ans1,ans2,ans1 + ans2);
}
int main(){
	pre_solve();
	while(~scanf("%d",&n)){
		memset(pre0,0,sizeof(pre0));
		memset(suf0,0,sizeof(suf0));
		memset(suf1,0,sizeof(suf1));
		solve();
	}
	return 0;
}