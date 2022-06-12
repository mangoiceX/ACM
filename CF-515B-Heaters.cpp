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
const int maxn=3e5 + 10;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n = 0,r = 0; 
int a[maxn],pos[maxn];
void solve(){
	int i = 1,ans = 0,s = 1;
	while(i <= n){
		s = i;
		int maxv = -1;
		while(i <= n && i <= s + r - 1){
			if(a[i] == 1){
				maxv = max(maxv,i);
			}
			i++;
		}
		if(maxv == -1){
			printf("-1\n");
			return ;
		}
		int p = maxv;
		ans++;
		while(i <= n && i <= p + r - 1){
			i++;
		}
	}
	printf("%d\n",ans);
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("a.txt","r",stdin);
	#endif
	while(~scanf("%d %d",&n,&r)){
		per(i,1,n){
			scanf("%d",&a[i]);
		} 
		solve(); 
	}
	
	return 0; 
}
