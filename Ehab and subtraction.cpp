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
const int maxn = 1e5;
int n = 0,k = 0;
int a[maxn+10];
void solve(){
	int sum = a[1];
	printf("%d\n",a[1]);
	k -= 1;
	while(k--){
		int loc = upper_bound(a+1,a+1+n,sum) - a;
		if(loc > n ){
			printf("0\n");
			continue;
		}
		printf("%d\n",a[loc] - sum);
		sum += (a[loc] - sum);
	}
}
int main(){
	while(~scanf("%d %d",&n,&k)){
		per(i,1,n){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		solve();
	}
	
	return 0;
}

