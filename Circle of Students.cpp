#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 3e5 + 10;
int n = 0,m = 0;
int a[maxn];
void solve(){

} 
int main(){

	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int pos = 0;
		per(i,1,n){
			scanf("%d",&a[i]);
			if(a[i] == 1){
				pos = i;
			}
		}
		bool fg1 = true,fg2 = true;
		for(int i = 1;i <= n-1;++i){
			int p = (pos + i == n ? n : (pos + i)%n);
			if(a[p] != 1+i){
				fg1 = false;
				break;
			}
		}
		per(i,1,n-1){
			int p = (pos - i == 0 ? n : (pos- i + n)%n);
			// cout << p << endl;
			if(a[p] != 1+i){
				fg2 = false;
				break;
			}
		}
		if(fg1 || fg2){
			puts("YES");
		}else{
			puts("NO");
		}
	}

	return 0;
}
