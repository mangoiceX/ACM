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
const int maxn = 2e5;
int n = 0,m = 0;
map<int,int> mp;
int a[maxn+10];
int size = 0;
void solve(){
	int maxv = 0,sum = 0,temp = 0,loc = 0;
	per(i,1,maxn){
		sum = 0,temp = i,loc = 0;
		//还有就是赋值运算符"="优先级低，所以外面那个()不可缺少，否则loc会== 1.
		//先赋值给loc，然后在()，再比较,lower_boind里面有Loc是为了补重复以前的 
		while((loc = (lower_bound(a+1+loc,a+1+size,temp)- a) )<= size){
			//loc = lower_bound(a+1+loc,a+1+size,temp) - a;//这样又会将lower_bound
			//计算一次，浪费时间（因为之前已经计算过一次） 
			sum += temp;
			temp <<= 1;
		}
		maxv = max(maxv,sum);
	}
	printf("%d\n",maxv);
}
int main(){
	while(~scanf("%d",&n)){
		mp.clear();
		per(i,1,n){
			int x = 0;
			scanf("%d",&x);
			mp[x]++;
		}
		map<int,int>::iterator it;
		size = 0;
		for(it = mp.begin();it != mp.end();it++){
			a[++size] = it->second;
		}
		sort(a+1,a+1+size);
		solve();
	}
	return 0;
}

