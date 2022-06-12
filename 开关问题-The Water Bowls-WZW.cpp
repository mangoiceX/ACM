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

#define pii pair<int, int>
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define PER(i,x) for(auto i=x.begin();i!=x.end();i++)
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
typedef long long ll;
const double eps=1.0e-5;
const int maxn=200000+10;

int a[25],ans=inf,f[25];

void solve(int k){
	int res=0;
	mem(f,0);
	per(i,1,20) if(k&(1<<(20-i))) {f[i]++;f[i-1]++;if(i>1&&(f[i-1]+a[i-1])%2) return;f[i+1]++;res++;}
	per(i,1,20) if((a[i]+f[i])%2) return;
	ans=min(ans,res);
}

int main(){
	//freopen("C:\\Users\\MAC\\Desktop\\in.txt","r",stdin);
	per(i,1,20) scanf("%d",&a[i]);
	per(i,0,(1<<20)-1) solve(i);
	printf("%d\n",ans);
}
