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
vector<int> g[30];
int a[30];
void solve(){
	
}
int main(){
	//std::ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	while(~scanf("%d",&n)){
		per(i,0,29){
			g[i].clear();
		}
		
		
		scanf("%s",s);
		per(i,0,n-1){
			g[s[i] - 'a'].push_back(i+1);
		}
		scanf("%d",&m);
		char str[maxn];
		per(i,1,m){
			memset(a,0,sizeof(a));
			scanf("%s",str);
			int len = strlen(str);
			per(j,0,len-1){
				++a[str[j] - 'a'];
			}
			int ans = 0;
			per(j,0,25){
				if(a[j] > 0){
					ans = max(ans,g[j][a[j]-1]);
					//cout << ans <<endl;
				}
			}
			printf("%d\n",ans);
		}
	}

	return 0;
}
