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
int n = 0,m = 0;
int a[maxn+10];
int sum = 0;
void solve(){
	int ans = 0;
	per(i,1,n){
		ans += a[i];
	}
	if(ans == sum / 2){
		printf("-1\n");
	}else{
		per(i,1,2*n){
			printf("%d%c",a[i],i == 2*n ? '\n' : ' ');
		}
	}
}
int main(){
	while(~scanf("%d",&n)){
		sum = 0;
		per(i,1,2*n){
			scanf("%d",&a[i]);
			sum += a[i];
		}
		sort(a+1,a+1+2*n);
		if(sum & 1){
			per(i,1,2*n){
				printf("%d%c",a[i],i == 2*n ? '\n' : ' ');
			}
			continue;
		}
		solve();
	}
	
	return 0;
}

