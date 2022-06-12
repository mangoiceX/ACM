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
int n = 0,m = 0;
int a[maxn+10];
int lm = 0,rm = 0;
int pre_odd[maxn+10],pre_even[maxn+10];
struct node{
	int v,id;
};
node b[maxn+10];
bool vis[maxn+10];
bool cmp(node x,node y){
	return x.v == y.v ? x.id < y.id : x.v < y.v;
}
void swap(int x,int y){
	int tmp = a[x];
	a[x] = a[y];
	a[y] = tmp;
	//cout << x << " " << y << endl;
}
void solve(){
	int l = 0,r = 0;
	memset(vis,false,sizeof(vis));
	per(i,1,n){
		if(b[i].v & 1 ){
			if(r < rm && !vis[pre_even[r+1]] && !vis[b[i].id] &&
			 (b[i].v < a[pre_even[r+1]] && b[i].id > pre_even[r+1]) ){
				swap(b[i].id,pre_even[++r]);
				vis[pre_even[r]] = true;
			}
			
		}else{
			if(l < lm && !vis[pre_odd[l+1]] && !vis[b[i].id] &&
				(b[i].v < a[pre_odd[l+1]] && b[i].id > pre_odd[l+1])){
				swap(b[i].id,pre_odd[++l]);
				vis[pre_even[l]] = true;
			}
		}
	}
	per(i,1,n){
		printf("%d%c",a[i],i == n ? '\n' : ' ');
	}
}
int main(){
	while(~scanf("%d",&n)){
		per(i,1,n){
			scanf("%d",&a[i]);
		}

		lm = 0,rm = 0;
		per(i,1,n){
			if(a[i] & 1){
				pre_odd[++lm] = i;
			}else{
				pre_even[++rm] = i;
			}
			b[i].v = a[i];b[i].id = i;
		}
		sort(b+1,b+1+n,cmp);
		solve();
	}
	
	return 0;
}

