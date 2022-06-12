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
const int maxn = 3e5;
int n = 0,q = 0;
struct node{
	int l,r,size;
};
node a[maxn+10];
int tot = 0;
int num[maxn+10];
int times[4][maxn+10];
bool cmp(node x,node y){
	return (x.l == y.l) ? (x.r < y.r) : (x.l < y.l);
}

int f(int x,int y){
	if(a[x].r < a[y].l){
		return (times[1][a[x].r] - times[1][a[x].l-1]) + (times[1][a[y].r] - times[1][a[y].l-1]);

	}else{
		int res = 0;
		res += (times[1][a[y].l-1] - times[1][a[x].l-1]  +  times[1][max(a[x].r,a[y].r)] - 
		times[1][min(a[x].r,a[y].r)]);
		res += (times[2][min(a[x].r,a[y].r)] - times[2][a[y].l-1]);
		return res;
	}
}
void solve(){
	int ans = 0;
	per(i,1,q){
		per(j,i+1,q){
			int sum = f(i,j);
			if(tot - sum >= ans){
				ans = tot - sum;
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	while(~scanf("%d %d",&n,&q)){
		memset(num,0,sizeof(num));	memset(times,0,sizeof(times));
		tot = 0;
		int r = 0;
		a[0].r = a[0].l = 0;
		per(i,1,q){
			scanf("%d %d",&a[i].l,&a[i].r);
			a[i].size = a[i].r - a[i].l + 1;
			++num[a[i].l]; --num[a[i].r+1];
		}
		per(i,1,n){
			num[i] += num[i-1];
		}
		per(i,1,n){
			times[1][i] = times[1][i-1] + ((num[i] == 1) ? 1 : 0 );
		}
		per(i,1,n){
			times[2][i] = times[2][i-1] + ((num[i] == 2) ? 1 : 0 );
		}
		
		sort(a+1,a+1+q,cmp);
		
		tot = a[1].size;
		int l = a[1].r;
		per(i,2,q){
			if(a[i].l > l){
				tot += a[i].size;
				l = a[i].r;
			}else{
				tot += max(0,a[i].r - l);
				l = max(a[i].r,l);
			} 
		}
		
		solve();
	}

	
	return 0;
}
