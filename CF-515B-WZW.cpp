#include<bits/stdc++.h>

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
const int maxn=100000+10;

int n,a[1005],r;

int main()
{
	scanf("%d%d",&n,&r);
	per(i,1,n) scanf("%d",&a[i]);
	
	int last=1,ans=0,pre = 0;
    while(last<=n){
		
		int flag=inf;
		int j = 0 ;
		for( j=last-r+1;j<=last+r-1;j++){
			if(j<=n&&j>=1&&a[j]==1){
				flag=j;
				//cout <<"hi " << j << endl; 
			}
		}
		//cout << j << endl;
		if(flag==inf) return printf("-1\n");
		
		last=flag+r;
		if(last == pre){
			last += 1;
		}
		pre = last;
		//cout<<"haha " << last << endl;
		ans++;
	}
	printf("%d\n",ans);
}
