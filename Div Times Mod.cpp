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
void solve(){
	vector<int> vec;
	int tmp = n;
	vec.push_back(1);
	for(int i = 2;i <= n;++i){
		if(tmp % i == 0){
			vec.push_back(i);
		}
	}
	int len = vec.size(),minv = INF;
	for(int i = 0;i < len;++i){
		int res = n / vec[i] + vec[i] * k;
		if(res / k == vec[i]){
			minv = min(minv,res);	
		}
	}
	printf("%d\n",minv);
}
int main(){
	while(~scanf("%d %d",&n,&k)){	
		solve();
	}
	
	return 0;
}

