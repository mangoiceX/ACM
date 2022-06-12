#include <iostream>
#include <cstdio>
#include <cstring>
#define eps 1e-9
#define maxn 1005
using namespace std;
int n,m;
double ans;
int a[maxn],b[maxn];
 
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	b[n+1] = b[1];
	ans = 1;
	for(int i=1;i<=n;i++){
		ans -= ans/a[i];
		ans -= ans/b[i+1];
	}
	//cout << ans << endl; 
	if(ans == 0)puts("-1"); 
	//if(ans < esp) puts("-1"); 
	else printf("%.10lf\n",m/ans-m);
	return 0;
}
 

