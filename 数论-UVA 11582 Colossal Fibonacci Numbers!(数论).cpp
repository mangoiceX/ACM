#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<set>
#include<ctime>
#define eps 1e-6
#define LL long long
#define ULL unsigned long long
#define pii (pair<int, int>)
//#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
 
const int maxn = 1000 + 100;
//const int INF = 0x3f3f3f3f;
ULL a, b;
int n;
int f[maxn*maxn];
 
ULL pow_mod(ULL a, ULL p, ULL n) {
	if(p == 0) return 1;
	ULL ans = pow_mod(a, p/2, n);
	ans = ans * ans % n;
	if(p%2 == 1) ans = ans * a % n;
	return ans;
} 
 
int main() {
    //freopen("input.txt", "r", stdin);
	int T; cin >> T;
	while(T--) {
		cin >> a >> b >> n;
		f[0] = 0, f[1] = 1%n;
		int loop = 1;
		for(int i = 2; i <= n*n+100; i++) {
			f[i] = (f[i-1]+f[i-2]) % n;
			if(f[i]==f[1] && f[i-1]==f[0]) {
				loop = i - 1;
				break;
			}
		}
		for(int i = 0;i < loop;++i){
				cout << "em " <<  i << " lo "<< f[i] << endl;
		}
		ULL ans = pow_mod(a%loop, b, (ULL)loop);
		cout << "em " << ans << " lo " << loop<< endl; 
		cout << f[ans] << endl;
	} 
    return 0;
}
