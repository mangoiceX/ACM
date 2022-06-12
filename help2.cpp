#include<bits/stdc++.h>
using namespace std;
#define per(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,a,b) for(int i=(a);i>=(b);i--)
typedef long long LL;
#define INF 0x3f3f3f3f
const int maxn = 1e3;
int n = 0,m = 0;
int a[maxn+10][maxn+10];
void solve(){
//memcpy(b,a,sizeof(a));
	per(k,1,n){
		per(i,1,n){
			per(j,1,n){
				a[i][j] = min(a[i][k] + a[k][j], a[i][j]);
			}
		}
		printf("%d\n",k);
		per(i,1,n){
			per(j,1,n){
				printf("%d ",a[i][j]);
			}
			puts("");
		}	
	}
		
}
int main(){
	while(~scanf("%d",&n)){
		per(i,1,n){
			per(j,1,n){
				scanf("%d",&a[i][j]);
			}
		}
		per(i,1,n){
			a[i][i] = 0;
		}
		solve();
	}
	
	return 0;
}
/*
5
0 3 8 10000 -4
10000 0 10000 1 7
10000 4 0 10000 10000
2 10000 -5 0 10000
10000 10000 10000 6 0

6
0 10000 10000 10000 -1 10000
1 10000 10000 2 10000 10000
10000 2 10000 10000 10000 -8
-4 10000 10000 10000 3 10000
10000 7 10000 10000 10000 10000
10000 5 10 10000 10000 10000
*/
