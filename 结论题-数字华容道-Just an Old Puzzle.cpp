#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 3e5 + 10;
int n = 0,m = 0;
int c = 0,r = 0;
int a[20];
void solve(){
	int cnt = 0;
	per(i,1,16){
		per(j,1,i-1){
			if(a[i] == 0 ){//0的逆序对不计算
				continue;//|| a[j] == 0
			}
			if(a[j] > a[i]){
				++cnt;
			}
		}
	}
	if(abs(r-4) % 2 == (cnt % 2)){
		puts("Yes");
	}else{
		puts("No");
	}
}
int main(){

	int T = 0;
	scanf("%d",&T);
	while(T--){
		per(i,1,4){
			per(j,1,4){
				scanf("%d",&a[(i-1)*4+j]);
				if(a[(i-1)*4+j] == 0){
					r = i,c = j;
				}
			}
		}
		solve();
	}

	return 0;
}
