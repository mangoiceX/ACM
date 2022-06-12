#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 10;
int n = 0,m = 0;
int a[maxn];
bool vis[maxn];
void solve(){

}
int main(){

	while(~scanf("%d",&n)){
		per(i,1,n){
			scanf("%d",&a[i]);
		}
		memset(vis,false,sizeof(vis));
		vis[0]  = true;
		sort(a+1,a+1+n);
		int ans = 0;
		per(i,1,n){
			if(!vis[a[i]-1]){
				vis[a[i]-1] = true;
				++ans;
			}else if(!vis[a[i]]){
				vis[a[i]] = true; 
				++ans;
			}else if(!vis[a[i]+1]){
				vis[a[i]+1] = true;
				++ans;
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}
