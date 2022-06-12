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
const int maxn=2e5;
const LL mod=1e9+7;

int n = 0,m = 0,s = 0,t = 0;
void solve(){
	
}
int main(){
	//std::ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&n,&s,&t);
		int ans = 0;
		if(s + t == n){
			printf("%d\n",max(s,t) + 1);
		}else if(s + t == 2*n){
			printf("1\n");
		}else{
			int mi = s+t-n;
			printf("%d\n",max(max(0,s - mi),max(0,t - mi)) + 1);
		}
	}
	return 0;
}
