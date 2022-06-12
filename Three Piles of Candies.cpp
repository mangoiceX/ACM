#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 10;
const LL mod = (1e9 + 7);
int n = 0,m = 0,k = 0;
LL a[10];
void solve(){

}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		per(i,1,3){
			scanf("%I64d",&a[i]);
		}
		sort(a+1,a+1+3);
		printf("%I64d\n", (a[3] + a[2] + a[1])/2);
	}

	return 0;
}