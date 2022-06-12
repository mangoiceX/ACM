#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 40 + 10;
int n = 0,m = 0;
LL s = 0;
LL a[maxn],pre[maxn];
bool vis[maxn];
LL tot = 0;
LL gi(){
    char a=getchar();LL b=0;
    while(a<'0'||a>'9')a=getchar();
    while(a>='0'&&a<='9')b=b*10+a-'0',a=getchar();
    return b;
}
bool dfs(int depth,LL sum){
	if(sum == s){
		// puts("nfodas");
		per(i,1,depth){
			if(vis[i]){
				printf("1");
			}else{
				printf("0");
			}
		}
		per(i,depth+1,n){
			printf("0");
		}
		puts("");
		return true;5
	}
	if(sum > s){
		return false;
	}
	if(depth == n){
		if(sum == s){
			per(i,1,n){
				if(vis[i]){
					printf("1");
				}else{
					printf("0");
				}
			}
			puts("");
			return true;
		}
		return false;
	}
	if(sum + tot - pre[depth] < s){
		return false;
	}
	if(sum + tot - pre[depth] == s){
		// puts("haha");
		per(i,1,depth){
			if(vis[i]){
				printf("1");
			}else{
				printf("0");
			}
		}
		per(i,depth+1,n){
			printf("1");
		}
		puts("");
		return true;
	}
	vis[depth+1] = true;
	if(dfs(depth+1,sum + a[depth+1])){
		return true;
	}
	vis[depth+1] = false;
	if(dfs(depth+1,sum)){
		return true;
	}
	return false;
}
int main(){

	// scanf("%d %lld",&n,&s);
	scanf("%d",&n);
	s = gi();
		per(i,1,n){
		a[i] = gi();
		pre[i] = pre[i-1] + a[i];
		tot += a[i];
	}
	dfs(0,0);

	return 0;
}
