#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 10;
const LL mod = (1e9 + 7);
int n = 0,m = 0,k = 0;
int suf0[maxn],suf1[maxn],suf2[maxn];
char s[maxn];
int ans1 = -1,ans2 = -1;
void solve1(){
	// int pre1[maxn],pre0[maxn];
	int cnt0 = 0,cnt1 = 0;
	per(i,1,n){
		// pre1[i] = pre1[i-1] + s[i] == '1';
		// pre0[i] = pre0[i-1] + s[i] == '0';
		cnt0 = cnt0 + (s[i] == '0');
		cnt1 = cnt1 + (s[i] == '1');
	}
	// cout << "ja " << cnt0 <<" " << cnt1 << endl;
	ans2 = 2*min(cnt0,cnt1);
}
void solve2(){
	
	memset(suf0,0,sizeof(suf0)); memset(suf1,0,sizeof(suf1)); memset(suf2,0,sizeof(suf2));
	rep(i,n,1){
		suf0[i] = suf0[i+1] + (s[i] == '0');
		suf1[i] = suf1[i+1] + (s[i] == '1');
		suf2[i] = suf1[i] - suf0[i];
	}
	map<int,int> mp;
	int sum = 0;
	mp[0] = n+1;
	rep(i,n,1){
		sum = suf2[i];
		if(mp[sum]){
			ans1 = max(ans1,mp[sum] - i);
			continue;
		}
		mp[sum] = i;
	}
}
int main(){
	while(~scanf("%d",&n)){
		ans1 = ans2 = 0;
		scanf("%s",s+1);
		solve2();
		solve1();
		printf("%d %d\n",ans1,ans2);
	}

	return 0;
}