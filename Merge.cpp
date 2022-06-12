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
int n = 0,m = 0;
int a[maxn+10];
int cnt[10];
void solve(){
	int ans = 0;
	ans += cnt[0];

	if(cnt[2] <= cnt[1]){
		ans += cnt[2];
		cnt[1] -= cnt[2];
		ans += (cnt[1] / 3);
	}else{
		ans += cnt[1];
		cnt[2] -= cnt[1];
		ans += (cnt[2] / 3);
	}
	printf("%d\n",ans);
}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		memset(cnt,0,sizeof(cnt));
		scanf("%d",&n);
		per(i,1,n){
			scanf("%d",&a[i]);
			a[i] %= 3;
			++cnt[a[i]];
		}
		solve();
	}
	
	return 0;
}

