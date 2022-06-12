#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (b);i >= (b);++i)
#define INF 1e9
typedef long long LL;
using namespace std;
const int maxn = 1e5 + 10;
int n = 0,m = 0,k = 0;
int cnt[10];
int pre[maxn],pre_cnt[maxn];
string s;
void solve(){
	int len = s.length();
	pre_cnt[0] = cnt[0] = 1;
	per(i,0,len-1){
		pre[i] = (i == 0 ? 0 : pre[i-1]) + (s[i] - '0');
		pre[i] %= 3;
		++cnt[pre[i]];
		pre_cnt[i] = cnt[pre[i]];
	}
	int num = 0,pos = 0;
	vector<pair<int,int> > g; 
	int ou = 0;
	int pp = 0;
	LL ans = 0;
	while(pp < len && s[pp] == '0'){
		++pp;
	}
	ans += 1ll*(pp+1)*pp/2;
	per(i,pp,len-1){
		if(s[i] == '0'){
			while(i <= len-1 && s[i] == '0'){
				++i;
				++num;
			}
			if(num >= 2){
				g.push_back(make_pair(pos,num));
			}else{
				++ou;
			}
			pos = i;num = 0;
		}else{
			pos = i;num = 0;
		}
	}
	int si = g.size();
	per(i,0,si-1){
		pair<int,int> now = g[i];
		ans += 1ll*max(0,(pre_cnt[now.first]-1))*(now.second-1);
		ans += 1ll*(now.second + 1)*now.second/2;
	}
	printf("%lld\n",ans+ou);
}
void init(){
	memset(pre,0,sizeof(pre));
	memset(pre_cnt,0,sizeof(pre_cnt));
	memset(cnt,0,sizeof(cnt));
}
int main(){
	while(cin >> s){
		init();
		solve();
	}

	return 0;
}