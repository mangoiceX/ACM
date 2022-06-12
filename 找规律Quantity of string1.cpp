#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#define INF  1e5
#define mod 1000000007
using namespace std;
const int maxn = 1000 + 10;
int n = 0,m = 0,k = 0;
typedef long long ULL;

int main(){
	ULL ans = 1;
	//scanf("%d %d %d",&n,&m,&k);
	cin >> n >> m >> k;
	if(k == 1 || k > n){
		for(int i = 1;i <= n;++i){
			ans = ans * m % mod;
		}
		//ans = ULL(pow(m,n) )% mod;
	}else if(k == n){
		//ans = ULL(pow(m,(n+1)/2) )% mod;
		for(int i = 1;i <= (n+1)/2;++i){
			ans = ans * m % mod;
		}
	}else if(k % 2 == 0 && k != n && k != 1 && k < n){
		ans = m;
	}else if(k %2 == 1 && k != n && k != 1 && k < n){
		ans = m * m % mod;
	}
	//printf("%I64d\n",ans);
	cout << ans << endl;
	return 0;
}
