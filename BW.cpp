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
char s[maxn];
int a[30];
void solve(){
	per(i,0,n-1){
		a[s[i] - 'a'] = min(i+1,a[s[i] - 'a']);
	}
}
int main(){
	//std::ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	while(~scanf("%d",&n)){
		per(i,0,29){
			a[i] = 4e6;
		}
		scanf("%s",s);
		solve();
		scanf("%d",&m);
		char str[maxn];
		per(i,1,m){
			scanf("%s",str);
			int len = strlen(str);
			int ans = 0;
			per(j,0,len-1){
				ans = max(a[str[j] - 'a'],ans);
			}
			printf("%d\n",ans);
		}
		
	}
	
	return 0;
}
