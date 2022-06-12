#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 5e2 + 10;
int n = 0,m = 0;
LL k = 0;
LL f[maxn];
char s1[7] = "COFFEE",s2[8] = "CHICKEN";
void pre_solve(){
	memset(f,-1,sizeof(f));
	f[1] = 6;f[2] = 7;
	per(i,3,500){
		f[i] = f[i-2] + f[i-1];
		if(f[i] > 1e12){
			break;
		}
	}
}
void dfs(int depth,LL pos){
	if(depth == 1){
		printf("%c",s1[pos-1]);
		return ;
	}
	if(depth == 2){
		printf("%c",s2[pos-1]);
		return ;
	}
	if(pos <= f[depth-2] || f[depth-2] == -1){
		dfs(depth-2,pos);
	}else{
		dfs(depth-1,pos - f[depth-2]);
	}
}
int main(){
	// ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	pre_solve();
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %lld",&n,&k);
		for(LL i = k;i < k+10;++i){
			if(f[n] != -1 && i > f[n]){
				break;
			}
			dfs(n,i);
		}
		puts("");
	}
	return 0;
}
