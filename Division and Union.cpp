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

#define INF 1e6
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
const int maxn = 1e5;
int n = 0,m = 0;
struct node{
	int l,r;
};
node seg[maxn+10];
bool cmp(node a,node b){
	return (a.l == b.l) ? (a.r < b.r) : (a.l < b.l);
} 
void solve(){
	int ans[maxn+10];
	
	int l1 = 0,r1 = INF,l2 = 0,r2 = INF;
	ans[1] = 1,l1 = max(l1,seg[1].l);r1 = min(r1,seg[1].r);
	bool cntr = false;
	for(int i = 2;i <= n;++i){
		bool f1 = false,f2 = false;
		if(seg[i].l <= r1 && seg[i].r >= l1){
			ans[i] = 1;l1 = max(l1,seg[i].l);r1 = min(r1,seg[i].r);
			f1 = true;
		}
		if(cntr == false && f1 == false){
			cntr = true;
			ans[i] = 2;l2 = max(l2,seg[i].l);r2 = min(r2,seg[i].r);
			continue;
		}
		if(cntr == true && seg[i].l <= r2 && seg[i].r >= l2){
			ans[i] = 2;l2 = max(l2,seg[i].l);r2 = min(r2,seg[i].r);
			f2 = true;
		}
		if(f1 == false && f2 == false){
			ans[i] = 1;l1 = max(l1,seg[i].l);r1 = min(r1,seg[i].r);
		}
		if(f1 && f2){
			printf("-1\n");
			return ;
		}
	}
	if(cntr == false){
		printf("-1\n");
		return ;
	}
	for(int i = 1;i <= n;++i){
		printf("%d%c",ans[i],(i == n) ? '\n' : ' ');
	}
}
int main(){
	
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i = 1;i <= n;++i){
			scanf("%d %d",&seg[i].l,&seg[i].r);
		}
		sort(seg+1,seg+1+n,cmp);
		solve();
	}
	
	return 0;
}

