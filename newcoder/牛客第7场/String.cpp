#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
typedef long long LL;
#define INF 1e18
const int maxn = 2e2 + 10;
int n = 0,m = 0; 
char s[maxn];
void solve(){
	vector<char> ans[200];
	int len = strlen(s);
	int p = 0;
	int pre = p;
	int cnt = 0;
	while(p < len){		
		while(p < len && s[p] == '0'){
			++p;
		}
		while(p < len && s[p] == '1'){
			++p;
		}
		++cnt;
		per(j,pre,p-1){
			ans[cnt].push_back(s[j]);
		}
		pre = p;
	}
	per(i,1,cnt){
		int size = ans[i].size();
		per(j,0,size-1){
			printf("%c",ans[i][j]);
		}
		printf(" ");
	}
	puts("");
}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		solve();
	}
	return 0;
}