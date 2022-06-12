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

typedef unsigned long long LL;

#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
const int maxn = 2e5;
int n = 0;
LL b[maxn+10],a[maxn+10];
void solve(){
	LL pre = 0;a[n+1]=1e18+10;
	per(i,1,(n/2)){
		//a[n-i+1] = ((b[i] > maxv) ? maxv : b[i]);
		if(b[i]-pre>a[n-(i-1)+1]){
			a[n-i+1]=a[n-(i-1)+1];
			a[i]=b[i]-a[n-i+1];
			pre=max(pre,a[i]);
		}else{
			a[i]=pre;
			a[n-i+1]=b[i]-pre;
		}
	}
	per(i,1,n){
		printf("%I64d%c",a[i],(i == n) ? '\n' : ' ');
	}
}
int main(){
	while(~scanf("%d",&n)){
		per(i,1,n/2){
			scanf("%I64d",&b[i]);
		}
		solve();
	}
	
	
	return 0;
}

