#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
int n = 0,m = 0;
char s[maxn];
void solve(){
	int ans[10] = {0};
	per(i,0,n-1){
		if(s[i] == 'L'){
			per(j,0,9){
				if(ans[j] == 0){
					ans[j] = 1;
					break;
				}
			}
		}else if(s[i] == 'R'){
			rep(j,9,0){
				if(ans[j] == 0){
					ans[j] = 1;
					break;
				}
			}
		}else{
			ans[s[i] - '0'] = 0;
		}
	}
	per(i,0,9){
		printf("%d",ans[i]);
	}
	puts("");
}
int main(){
	
	while(~scanf("%d",&n)){
		scanf("%s",s);
		solve();
	}

	return 0;
}
