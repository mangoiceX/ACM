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

typedef long long LL;

#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
const int maxn = 3e5;
int n = 0,m = 0;
int a[maxn+10],b[maxn+10];
int loc[maxn+10];
//set<int> st;
bool vis[maxn+10],used[maxn+10];
void solve(){
	bool fg = true;
	per(i,1,n){
		used[i] = vis[i];
	}
	if(b[n] == 1){
		int r = 1;
		per(i,2,n){
			if(used[i]){
				
				used[b[r++]] = true;
				continue;
			}
			/*
			if(b[r] == i){
				vis[r] = true;
				++r;
				continue;
			}
			*/
			fg = false;
		}
		if(fg){
			printf("%d\n",n-1);
			return ;
		}
	}

	int ans = 0;
	int l = 1,r = 0;
	per(i,1,n){
		if(!vis[i]){
			per(j,r+1,loc[i]){
				//st.insert(b[i]);
				vis[b[j]] = true;
			}
			ans += (loc[i] - r);
			//ans += min(0,loc[i] - r - (i - l));
			//l = (loc[i] - r - (i - l)) >= 0 ? i : ((i - l) - (loc[i] - r) - 1);
			l = (loc[i] - r - (i - l)) >= 0 ? i : (l + (loc[i] - r));
			r = loc[i];
		}
	}
	//cout << "ni " << l <<endl;
	ans += max(0,n-l+1);
	printf("%d\n",ans);
}
int main(){
	while(~scanf("%d",&n)){
		//st.clear(); 
		memset(vis,false,sizeof(vis));memset(used,false,sizeof(used));
		per(i,1,n){
			scanf("%d",&a[i]);
			//st.insert(a[i]);
			vis[a[i]] = true;
		}
		per(i,1,n){
			scanf("%d",&b[i]);
			loc[b[i]] = i;
		}
		solve();
	}
	
	return 0;
}

