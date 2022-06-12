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

using namespace std;
const int maxn = 3e5;

typedef long long LL;

#define inf 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)

int a = 0,b = 0;
map<int,int> mp;
int dp[maxn][maxn];
int gcd(int x,int y){
	return y == 0 ? x : gcd(y,x%y);
}
int lcm(int x,int y){
	return x/gcd(x,y)*y;
}
void solve(){
	mp.clear();
	int temp = b;
	for(int i = 2;i * i <= temp;++i){//质因数分解 
		while(temp % i == 0){
			temp /= i;
			mp[i]++;
		}
	}
	if(temp > 1){
		mp[temp]++;
	}
	map<int,int>::iterator it;
	if(mp.size() == 1){
		printf("-1 -1\n");
		return;
	} 
	
	for(int i = 1;i <= mp.size();++i){
		for(int j = 0;j <= mp[i];++j){
			for(int k = 0;k <= mp[i];++k){
				
			}
		}
	}
	
	for(int i = 1;i < a;++i){
		if(lcm(i,a-i) == b){
			printf("%d %d\n",i,a-i);
			return ;
		}
	}
	printf("-1 -1\n");
}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&a,&b);
		solve();
	}
	
	return 0;
}




