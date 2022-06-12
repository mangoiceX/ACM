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
const int maxn = 5e5;
int n = 0,m = 0;
int a[maxn+10];
int b[7] = {0,4,8,15,16,23,42};
vector<int> g[50];
bool vis[maxn+10];
void solve(){
	int l4 = 0,l8 = 0,l15 = 0,l16 = 0,l23 = 0,l42 = 0;
	int si4 = g[4].size(),si8 = g[8].size(),si15 = g[15].size(),si16 = g[16].size(),
	si23 = g[23].size(),si42 = g[42].size();
	int ans = 0;
	while(l4 < si4 && l8 < si8 && l15 < si15 && l16 < si16 && l23 < si23 && l42 < si42){
		/*
		while(l4 < si4 && g[4][l4] < loc){
			++l4;
		}
		if(l4 == si4){
			break;
		}
		*/
		int loc = g[4][l4++];
		while(l8 < si8 && g[8][l8] < loc){
			
			++l8;
		}
		if(l8 == si8){
			break;
		}
		loc = g[8][l8++];
		while(l15 < si15 && g[15][l15] < loc){
			
			++l15;
		}
		if(l15 == si15){
			break;
		}
		loc = g[15][l15++];

		while(l16 < si16 && g[16][l16] < loc){
			++l16;
		}
		if(l16 == si16){
			break;
		}
		loc = g[16][l16++];

		while(l23 < si23 && g[23][l23] < loc){
			++l23;
		}
		if(l23 == si23){
			break;
		}
		loc = g[23][l23++];

		while(l42 < si42 && g[42][l42] < loc){
			++l42;
		}
		if(l42 == si42){
			break;
		}
		loc = g[42][l42++];
		++ans;
	}
	printf("%d\n",n - ans * 6);
}
int main(){
	while(~scanf("%d",&n)){
		per(i,1,49){
			g[i].clear();
		}
		per(i,1,n){
			scanf("%d",&a[i]);
			g[a[i]].push_back(i);
		}
		solve();
	}
	
	return 0;
}

