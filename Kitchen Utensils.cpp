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
int n = 0,k = 0;
map<int,int> mp;
void solve(){
	int maxv = 0;
	map<int,int>::iterator it;
	for(it = mp.begin();it != mp.end();it++){
		maxv = max(maxv , it->second);	
	}
	int ans = mp.size() * (maxv % k == 0 ? maxv : ((maxv/k + 1) * k)) - n;
	printf("%d\n",ans);
}
int main(){
	while(~scanf("%d %d",&n,&k)){
		mp.clear();
		per(i,1,n){
			int x = 0;
			scanf("%d",&x);
			mp[x]++;
		}
		solve();
	}
	
	return 0;
}

