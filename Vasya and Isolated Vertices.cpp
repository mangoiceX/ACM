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
LL n = 0,m = 0; 
void solve(){
	if(m == 0){
		printf("%I64d %I64d\n",n,n);
		return ;
	}
	int flag = 0;
	if(n & 1){
		flag = 1;
	}
	printf("%I64d ",max(((n/2 - m)*2+flag),1ll*0));
	//printf("%I64d\n",max(n-1-m,1ll*0));
	LL t = 1;
	while((t-1)*t/2<m){
		t++;
	}
	printf("%I64d\n",max(n-t,1ll*0));
}
int main(){
	while(~scanf("%I64d %I64d",&n,&m)){
		solve();
	}
	
	return 0; 
}
