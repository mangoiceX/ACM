#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
const int maxn = 2e5;
using namespace std;
int n = 0;
struct node{
	int s,e;
};
node a[maxn+10];
bool cmp(node x,node y){
	return (x.e == y.e ? x.s > y.s : x.e < y.e);
}
void solve(){
	int  now = a[1].e;
	int ans = 1;
	per(i,2,n){
		if(a[i].s >= now){
			++ans;
			now = a[i].e;
		}
	}
	printf("%d\n",ans);
}
int main(){
	while(~scanf("%d",&n)){
		per(i,1,n){
			scanf("%d %d",&a[i].s,&a[i].e);
		}
		sort(a+1,a+1+n,cmp);
		solve();
	}


	return 0;
}