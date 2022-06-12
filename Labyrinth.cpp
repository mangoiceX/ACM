#include<iostream>
#include<cstdio>
#include<vector>
#include<bitset>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<fstream>
#include<cstdlib>
#include<algorithm>

using namespace std;

//#define pii pair<int, int>
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define PER(i,x) for(auto i=x.begin();i!=x.end();i++)
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
typedef long long LL;
typedef pair<int,int> pii;
const double eps=1.0e-5;
const int maxn=2000 + 10;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n = 0,m = 0; 
int s0 = 0,t0 = 0;
int lm = 0,rm = 0;
int a[maxn];
char mp[maxn][maxn];
vector<int> vt[maxn];
struct node{
	int r,l;
};
node loc[maxn];
bool judge(int r,int c){
	if(r <= s0){
		if(s0 - r > lm){
			return false;
		}
		if(s0 - loc[r].l <= 2*(loc[r].r - s0)-1){
			return true;
		}else{
			return (rm <= loc[r].r - s0 + loc[r].r - r - 1) && (lm <= loc[r].r - r);
		}
	}else{
		if(r - s0 > rm){
			return false;
		}
		if(2*(s0 - loc[r].l )-1>= loc[r].r - s0){
			return true;
		}else{
			return (lm <= s0 - loc[r].l + r - loc[r].r -1) && (rm <= r - loc[r].l);
		}
	}
}
void solve(){
	int ans = 0;
	per(i,1,n){
		per(j,1,m){
			if(mp[i][j] == '*'){
				continue;
			}
			if(judge(i,j)){
				cout << "haha " << i << " " << j << endl;
				ans++;
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	#ifndef ONLINE_JUDGE
		//freopen("a.txt","r",stdin);
	#endif
	while(~scanf("%d %d",&n,&m)){
		scanf("%d %d",&s0,&t0);
		scanf("%d %d",&lm,&rm);
		int maxx = 2e3 + 100,minx = 0;
		per(i,1,n){
			int minv = 0,maxv = 2e3 + 100;
			getchar();
			per(j,1,m){
				scanf("%c",&mp[i][j]);
				if(mp[i][j] == '.'){
					vt[i].push_back(j);
				}
				if(i <= s0){
					
					maxv = min(maxv , i);
				}else{
					minv = max(minv,i);
					
				}
			}
			maxx = min(maxx , maxv);
			minx = max(minx,minv);
			if(i <= s0){
				loc[s0-i].l = maxx;loc[s0-i].r = minx;
			}else{
				loc[i].l = maxx;loc[i].r = minx;
			}
			
		}
		solve();
	}
	
	return 0; 
}
