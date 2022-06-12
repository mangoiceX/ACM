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
int a[maxn+10];
bool vis[maxn+10];
int num0 = 0,loc = 0;
void solve(){
	int ans = 0;
	int j = n;
	for(int i = loc+1;i <= n && i < j;){
		if(a[i] + a[j] == k){
			++i;--j;
			++ans;
		}else if(a[i] + a[j] < k){
			++i;
		}else{
			--j;
		}
	}
	printf("%d\n",ans*2+num0/2*2);
}
int main(){
	//std::ios::sync_with_stdio(false);
	while(~scanf("%d %d",&n,&k)){
		num0  = 0;
		per(i,1,n){
			scanf("%d",&a[i]);
			a[i] %= k;
			if(a[i] == 0){
				++num0;
			}
		}
		sort(a+1,a+1+n);
		
		loc = 0;
		per(i,1,n){
			if(a[i] != 0){
				break;
			}
			++loc;
		}
		solve();
	}
	
	return 0;
}

