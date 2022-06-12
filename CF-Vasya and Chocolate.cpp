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
int s = 0,a = 0,b = 0,c = 0; 
void solve(){
	LL ans = 0;
	ans += (s/c)*1ll;
	//if(a >= c){
		ans += (s/c/a)*1ll*b;	
//	}
	printf("%I64d\n",ans);	
}

int main(){	
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d %d",&s,&a,&b,&c);
		solve();	
	}

	return 0; 
}
