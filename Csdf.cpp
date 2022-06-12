#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 10;
int n = 0,m = 0,q = 0;
LL a = 0,b = 0;
char s[maxn];
void solve(){
	LL ans = 0;
	int pos1 = 0,pos2 = 0;
	int len = strlen(s);
	int cnt0 = 0,cnt1 = 0;
	per(i,0,len-1){
		if(s[i] =='1'){
			pos1 = i;
			break;
		}
		++cnt0;
	}
 
	rep(i,len-1,0){
		if(s[i] =='1'){
			pos2 = i;
			break;
		}
		++cnt1;
	}
	if(cnt1 == cnt0 && cnt1 == len){
		ans = 1ll*(n+1) * b + 1ll * n*a;
		printf("%I64d\n",ans);
		return ;
	}
	ans += 1ll*(cnt0+cnt1) * b;
	ans += 	1ll*(n+2)*a;
	// cout << ans <<endl;
	// cout << pos1 << " " << pos2 << endl;
	per(i,pos1,pos2){
		bool first = true;
		while(i <= pos2 && s[i] == '1'){
			if(first){
				ans += 4*b;
				first = false;
			}else{
				ans += 2*b;
			}
			++i;
		}
		cout << ans <<  " " << i << endl;
		int count = 0;
		while(i <= pos2 && s[i] == '0'){
			++count;
			++i;
		}
		// if(i <= pos2-1 && s[i+1] != '1'){
		if(2*a <= b){
			ans +=  1ll * max((count-1),0) * b + 2*a;
		}else{
			ans += 1ll * max((count-1),0) * 2*b;
		}
		--i;
		// cout << ans << " " << i <<endl;
		// }
 
	}
	printf("%I64d\n",ans);
}
int main(){
	// std::ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %I64d %I64d",&n,&a,&b);
		scanf("%s",s);
		solve();
	}
 
	return 0;
}
/*
12
10 2 5
0000100010
*/