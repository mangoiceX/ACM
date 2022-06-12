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

#define pii pair<int, int>
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,a,b) for(int i=(a);i>=(b);i--)
#define pi acos(-1.0)
#define INF 0x3f3f3f3f
typedef long long LL;

const double eps=1.0e-5;
const int maxn=2e5 + 10;
const LL mod=1e9+7;

int n = 0,m = 0;
int a[3][maxn];
void solve(){
	
}
int main(){
	//std::ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	while(~scanf("%d %d",&n,&m)){
		int mark[maxn] = {0};
		per(i,1,m){
			scanf("%d %d %d",&a[0][i],&a[1][i],&a[2][i]);
			if(a[0][i]){
				per(j,a[1][i],a[2][i]-1){
					mark[j] = 1;
				}
			}
		}
		per(i,1,m){
			bool fg = true;
			if(!a[0][i]){
				per(j,a[1][i],a[2][i]-1){
					if(!mark[j]){
						fg = false;
						break;
					}
				}
				if(fg){
					puts("NO");
					return 0;
				}
			}
			
		}
		int ans[maxn];
		ans[1] = n;
		per(i,1,n){
			if(mark[i]){
				ans[i+1] = ans[i]; 
			}else{
				ans[i+1] = ans[i] - 1;
			}
		}
		puts("YES");
		per(i,1,n){
			printf("%d%c",ans[i],i == n ? '\n' : ' ');
		}
	}
	
	
	return 0;
}
