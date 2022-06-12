#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
int n = 0,c = 0,k = 0;
const LL mod = 998244353;
int a[maxn];
int cnt[maxn],pos[maxn];
int cnt2[maxn],pos2[maxn];
vector<int> g[maxn],g2[maxn];
void init(){
	per(i,1,c){
		cnt[i] = cnt2[i] = 0;
		g[i].clear();g2[i].clear();
	}
}
void solve(){
	per(i,1,n){
		if(cnt[a[i]] < k-1){
			pos[i] = -1;
			g[a[i]].push_back(i);
			++cnt[a[i]];
		}else if(cnt[a[i]] >= k-1){
			int si = g[a[i]].size();
			pos[i] = g[a[i]][si-k+1];
			g[a[i]].push_back(i);
		}
	}
	rep(i,n,1){
		if(cnt2[a[i]] < k){
			++cnt2[a[i]];
			pos2[i] = -1;
			g2[a[i]].push_back(i);
		}else if(cnt2[a[i]] >= k){
			int si = g2[a[i]].size();
			pos2[i] = g2[a[i]][si-k+1];
			g2[a[i]].push_back(i);
		}
	}

	stack<int> st;
	int ans = 0;
	bool vis[maxn];
	memset(vis,false,sizeof(vis));
	per(i,1,n){
		bool fg = true;
		vis[a[i]] = true;
		if(pos[i] == -1){
			continue;
		}
		cout << "nima" << endl;
		while(!st.empty() && st.top() > pos[i]){
			per(j,pos[i],st.top()-1){
				if(vis[a[j]] && pos2[j] > i){
					fg = false;
					break;
				}
			}
			st.pop();
		}
		if(fg){
			st.push(pos[i]);
			// cout << i << " " <<pos[i] << " " << st.top()<< endl;
			if(!st.empty()){
				ans = max(ans,i - st.top() + 1);
			}	
		}
		
	}
	printf("%d\n",ans);

}
int main(){
	while(~scanf("%d %d %d",&n,&c,&k)){
		init();
		per(i,1,n){
			scanf("%d",&a[i]);
		}
		solve();
	}

	return 0;
}