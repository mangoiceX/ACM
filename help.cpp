#include<bits/stdc++.h>
using namespace std;
#define per(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,a,b) for(int i=(a);i>=(b);i--)
typedef long long LL;
#define INF 0x3f3f3f3f
const int maxn = 1e3;
int a[maxn+10][maxn+10],b[maxn+10][maxn+10],c[maxn+10][maxn+10];
int n = 0;
void solve(){
	//memset(b,INF,sizeof(b));
	memcpy(b,a,sizeof(a));
	per(l,2,n){
		memset(c,INF,sizeof(c));
		per(i,1,n){
			per(j,1,n){
				per(k,1,n){
					c[i][j] = min(a[i][k] + b[k][j],c[i][j]);
				}
			}
		}
		printf("%d\n",l);
		memcpy(b,c,sizeof(c));
		per(i,1,n){
			per(j,1,n){
				printf("%d ",b[i][j]);
			}
			puts("");
		}
	}
}
int main(){
	while(~scanf("%d",&n)){
		memset(a,INF,sizeof(a));
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
6
0 10000 10000 10000 -1 10000
1 10000 10000 2 10000 10000
10000 2 10000 10000 10000 -8
-4 10000 10000 10000 3 10000
10000 7 10000 10000 10000 10000
10000 5 10 10000 10000 10000
*/
