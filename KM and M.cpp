#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 3e5 + 10;
int n = 0,m = 0;
const int mod = (1e9+7);
void solve(){

}
int main(){
	for(int n = 1;n <= 20;++n){
		for(int m = 1;m <= 20;++m){
			int ans = 0;
			per(i,1,n){
				ans = (ans + ((i*m)&m)) % mod;
			}
			printf("n = %d m = %d ans = %d\n",n,m,ans);
		}
	}

	return 0;
}
