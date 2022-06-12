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
const int maxn = 1e2;
int n = 0;
int a[maxn+10],b[maxn+10];
void solve(){
	int ans1 = 0,ans2 = 0;
	per(i,3,n){
		if(a[i-2] == 1 && a[i-1] == 0 && a[i] == 1){
			ans1++;
			a[i] = 0;
		}
	}

	rep(i,n-2,1){
		if(b[i+2] == 1 && b[i+1] == 0 && b[i] == 1){
			ans2++;
			b[i] = 0;
		}
	}
	printf("%d\n",min(ans1,ans2));
}
int main(){
	while(~scanf("%d",&n)){
		per(i,1,n){
			scanf("%d",&a[i]);
			b[i] = a[i];
		}
		solve();
	}
	
	return 0;
}

