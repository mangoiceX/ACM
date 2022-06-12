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
int n = 0;
map<int,int> mp1;
map<int,bool> mp2;
void solve(){
	map<int,bool>::iterator it,it1;
	LL maxv = 0,sum = 0;
	for(it = mp2.begin();it != mp2.end();it++){
		LL temp = it->first;
		sum = temp;
		while(mp1[2*temp] == true){
			temp <<= 1;
			sum += temp;
		}
		maxv = max(maxv,sum);
	}
	printf("%I64d\n",maxv);
}
int main(){
	while(~scanf("%d",&n)){
		mp1.clear();mp2.clear();
		per(i,1,n){
			int x = 0;
			scanf("%d",&x);
			mp1[x]++;
		}
		map<int,int>::iterator it ;
		for(it = mp1.begin();it != mp1.end();it++){
			mp2[it->second] = true;
		} 
		solve();
	}
	
	return 0;
}

