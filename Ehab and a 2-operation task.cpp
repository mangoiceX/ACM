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
const int maxn = 2e3;
int n = 0,m = 0;
int a[maxn+10];
void solve(){
	a[0] = -1;
	bool flag = true;
	per(i,1,n){
		if(a[i] <= a[i-1]){
			flag = false;
			break;
		}
	}

	if(flag == true){
		printf("0\n");
		return ;
	}
	int b = 1000000;
	printf("%d\n",n+1);
	printf("2 %d 1\n",n);
	printf("1 %d %d\n",n,b);
	per(i,1,n-1){
		printf("2 %d %d\n",i,b-i);//先对前面操作，之后前面就不会受影响。
		//从后面操作会影响前面。 
	}
}
int main(){
	while(~scanf("%d",&n)){
		per(i,1,n){
			scanf("%d",&a[i]);
		}
		solve();
	}

	return 0;
}

