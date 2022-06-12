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
int n = 0,k = 0;
char str[maxn+10];
void solve(){
	int num[30];
	memset(num,0,sizeof(num));
	int cnt = 1;
	per(i,1,n-1){
		if(str[i] == str[i-1]){
			if(cnt >= k){
				++num[str[i-1] - 'a'];
				cnt = 0;	
			}
			++cnt;
		}else{
			if(cnt >= k){
				++num[str[i-1] - 'a'];	
			}
			cnt = 1;
		}
	}
	int maxv = -1;
	if(cnt >= k){
		++num[str[n-1] - 'a'];
	}
	per(i,0,25){
		maxv = max(maxv,num[i]);
	}
	printf("%d\n",maxv);
	
}
int main(){
	while(~scanf("%d %d",&n,&k)){
		scanf("%s",str);
		solve();
	}
	
	return 0;
}

