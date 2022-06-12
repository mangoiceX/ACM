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
const int maxn=1e6 + 10;

using namespace std;

ll solve(ll a,ll b,ll m)
{
    if(b==0) return 1;
	ll temp=solve(a,b/2,m);
	temp=temp*temp%m;
	if(b%2==1) temp=temp*a%m;
	return temp;
}

int main()
{
	int z;
    ll a,b,m,ans,h;
	cin >> z;
	while(z--)
	{
		ans=0;
		cin >> m >> h;
		while(h--)
		{
			cin >> a >> b;
			ans=(ans+solve(a,b,m))%m;
		}
		printf("%lld\n",ans);
	}
}

