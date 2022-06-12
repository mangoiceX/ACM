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
const int maxn = 1e3;
int n = 0,m = 0;
int a[maxn+10]; 
void solve1(){
	printf("%d ",a[(n+1)/2]+1);
	int mid = a[(n+1)/2]+1;
	int sum = 0;
	per(i,1,(n+1)/2 - 1){
		sum += min(abs(mid - 1 - a[i]),mid - a[i]);
	}
	per(i,(n+1)/2 + 1,n){
		sum += min(abs(mid + 1 - a[i]),abs(mid - a[i]));
	}
	printf("%d\n",sum);
}
void solve(){
	int minv = 1e6,id = 0;
	per(i,1,100){
		int sum = 0;
		per(j,1,n){
			sum += (i >= a[j] ? min(abs(i - 1 - a[j]),abs(i - a[j])) : a[j] - i - 1);
		}
		if(sum < minv){
			id = i;
			minv = sum;
		}
	}
	printf("%d %d\n",id,minv);
}
int main(){
	while(~scanf("%d",&n)){
		per(i,1,n){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		solve();
	}
	
	return 0;
}

