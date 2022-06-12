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
char str[27] = {'a','a','b','c','d','e','f','g','h','i','j','k',
'l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
void solve(){
	int minv = n / k;
	int cnt = 0;
	for(int i = 1;i <= k;++i){
		for(int j = 1;j <= minv;++j){
			printf("%c",str[i]);
		}
	}
	cnt = n % k;
	for(int i = 0;i < cnt;++i){
		printf("%c",str[k]);
	}
	printf("\n");
}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&k);
		solve();
	}
	
	return 0;
}

