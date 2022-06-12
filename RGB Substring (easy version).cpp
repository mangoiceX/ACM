#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
typedef long long LL;
#define INF 1e9
const int maxn = 2e5 + 10;
const LL mod = (1e9 + 7);
int n = 0,m = 0,k = 0;
int ans = INF;
char s[maxn];
char str[maxn];
void init(){
	per(i,0,3000){
		if(i % 3 == 0){
			str[i] = 'R';
		}else if( i % 3 == 1){
			str[i] = 'G';
		}else{
			str[i] = 'B';
		}
	}
}
void solve(){
	
	per(i,0,n-1-k+1){
		int ans1 = 0,ans2 = 0,ans3 = 0;
		per(j,i,i+k-1){
			if(s[j] != str[j-i]){
				++ans1;
			}
		}
		per(j,i,i+k-1){
			if(s[j] != str[j-i+1]){
				++ans2;
			}
		}
		per(j,i,i+k-1){

			if(s[j] != str[j-i+2]){
				++ans3;
			}
		}
		ans = min(ans,min(ans1,min(ans2,ans3)));
	}
	printf("%d\n",ans);
}
int main(){
	int T = 0;
	scanf("%d",&T);
	init();
	while(T--){
		ans = INF;
		scanf("%d %d",&n,&k);
		scanf("%s",s);
		solve();
	}

	return 0;
}