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

typedef long long LL;

#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
const int maxn = 2e5;
int n = 0,m = 0;
LL b[maxn+10],a[maxn+10];
LL min1(LL x,LL y){
	if(x < y){
		return x;
	}
	return y;
}
void solve(){
	LL maxv = b[1];
	per(i,1,n/2){
		//a[n-i+1] = ((b[i] > maxv) ? maxv : b[i]);
		if(b[i] > maxv){
			a[n-i+1] = maxv;
		}else{
			a[n-i+1] = b[i];
		}
		a[i] = b[i] - a[n-i+1];
		maxv = min1(maxv,b[i]);
	}
	per(i,1,n){
		//printf("%I64d%c",a[i],(i == n) ? '\n' : ' ');
		cout << a[i] << " " ;
	}
}
int main(){
	while(cin >> n){
		per(i,1,n/2){
			//scanf("%I64d",&b[i]);
			cin >> b[i];
		}
		solve();
	}
	
	
	return 0;
}

