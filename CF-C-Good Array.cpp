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
struct node{
	int val,id;
};
node a[maxn+10];
int n = 0;
LL sum = 0;
int ans[maxn+10];
bool cmp(node a,node b){
	return a.val == b.val ? a.id < b.id : a.val < b.val;
}
void solve(){
	int cnt = 0;
	per(i,1,n){
		if( (sum - a[i].val) & 1){
			continue;
		}
		if(i != n && (sum - a[i].val) / 2 == a[n].val){
			ans[++cnt] = a[i].id;
		}
		if(i == n && (sum - a[i].val) / 2 == a[n-1].val){
			ans[++cnt] = a[i].id;
		}
	}
	if(cnt == 0){
		printf("0\n");
	}else{
		printf("%d\n",cnt);
		per(i,1,cnt){
			printf("%d%c",ans[i],i == cnt ? '\n' : ' ');
		}
	}
}
int main(){
	while(~scanf("%d",&n)){
		sum = 0;
		per(i,1,n){
			scanf("%d",&a[i].val);
			sum += a[i].val;
			a[i].id = i;
		}
		sort(a+1,a+1+n,cmp);
		solve();
	}
	
	return 0;
}

