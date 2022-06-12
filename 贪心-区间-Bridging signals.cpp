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

#define inf 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
const int maxn = 4e4;
int n = 0;
struct node{
	int l,r;
};
node time[maxn+10];
bool cmp(node a,node b){
	return a.r != b.r ? a.r < b.r : a.l < b.l;
}
void solve(){
	int ans = 0,l = 0,minv = 0;
	per(i,1,n){
		if(time[i].l >= minv){
			ans++;
			minv = time[i].r;
		}	
	}
	printf("jhaha %d\n",ans);
}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		per(i,1,n){
			int l = i,r = 0;
			scanf("%d",&r);
			//time[i].l = min(l,r);
			//time[i].r = max(l,r);
			time[i].l = l;
			time[i].r = r;
		} 
		sort(time+1,time+1+n,cmp);
		solve();
	}
	
	return 0;
}




