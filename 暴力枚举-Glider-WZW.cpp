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

int n,h,b[maxn];

struct node{
	int x,y;
}a[maxn];

int main()
{
	//freopen("C:\\Users\\MAC\\Desktop\\in.txt","r",stdin);
	scanf("%d%d",&n,&h);
	per(i,1,n) scanf("%d%d",&a[i].x,&a[i].y);
	
	int l=1,r=1,ans=0;
	int sum=a[1].y-a[1].x,tmp=0;
	while(l<=n){
		while(tmp+a[r+1].x-a[r].y<=h&&r<n)
		    tmp+=a[r+1].x-a[r].y,sum+=a[r+1].y-a[r].y,r++;
		ans=max(ans,sum+h-tmp-(h==tmp?(a[r].y-a[r].x):0));
		l++;
		sum-=(a[l].x-a[l-1].x);tmp-=(a[l].x-a[l-1].y);
		
	}
	printf("%d\n",ans);

}
