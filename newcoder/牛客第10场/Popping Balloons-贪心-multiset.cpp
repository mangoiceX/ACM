#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
int n = 0,m = 0,r = 0;
int ri[maxn],c[maxn],rf[maxn],cf[maxn];
int be_r[maxn];
int maxx = 0,maxy = 0;
struct node{
	int x,y;
}a[maxn];
void init(){
	maxx = 0,maxy = 0;
	per(i,1,maxn-10){
		r[i] = c[i] = rf[i] = cf[i]  = 0;
		be_r[i] = -1;
	}
}
void cmpx(node no1,node no2){
	return n1.x == n2.x ? n1.y < n2.y : n1.x < n2.x;
}
void solve(){
	multiset<int> st,st1;
	per(i,r,maxy-r){
		st.insert(cf[i]);
	}
	int ans = 0;
	per(i,r,maxx-r){
		st1 = st;
		if(be_r[i-r] != -1){
			int j = be_r[i-r];
			while(a[j].x == i-r){
				if(a[j].y - r >= 0 && a[j].y - r <= maxy-r){
					*st1.lower_bound(cf[a[j].y-r]) = cf[a[j].y-r] - 1;
				}
				if(a[j].y >= 0 && a[j].y <= maxy-r){
					*st1.lower_bound(cf[a[j].y]) = cf[a[j].y] - 1;
				}
				if(a[j].y + r >= 0 && a[j].y + r <= maxy-r){
					*st1.lower_bound(cf[a[j].y+r]) = cf[a[j].y+r] - 1;
				}
				++j;
			}
		}
		if(be_r[i] != -1){
			int j = be_r[i];
			while(a[j].x == i){
				if(a[j].y - r >= 0 && a[j].y - r <= maxy-r){
					*st1.lower_bound(cf[a[j].y-r]) = cf[a[j].y-r] - 1;
				}
				if(a[j].y >= 0 && a[j].y <= maxy-r){
					*st1.lower_bound(cf[a[j].y]) = cf[a[j].y] - 1;
				}
				if(a[j].y + r >= 0 && a[j].y + r <= maxy-r){
					*st1.lower_bound(cf[a[j].y+r]) = cf[a[j].y+r] - 1;
				}
				++j;
			}
		}
		if(be_r[i+r] != -1){
			int j = be_r[i+r];
			while(a[j].x == i+r){
				if(a[j].y - r >= 0 && a[j].y - r <= maxy-r){
					*st1.lower_bound(cf[a[j].y-r]) = cf[a[j].y-r] - 1;
				}
				if(a[j].y >= 0 && a[j].y <= maxy-r){
					*st1.lower_bound(cf[a[j].y]) = cf[a[j].y] - 1;
				}
				if(a[j].y + r >= 0 && a[j].y + r <= maxy-r){
					*st1.lower_bound(cf[a[j].y+r]) = cf[a[j].y+r] - 1;
				}
				++j;
			}
		}
		ans = max(ans,rf[i]+*st1.begin());
	}
	printf("%d\n",ans);
}
int main(){

	while(~scanf("%d %d",&n,&r)){
		init();
		per(i,1,n){
			scanf("%d %d",&a[i].x,&a[i].y);
			++ri[a[i].x]; ++ c[a[i]].y;
			maxx = max(maxx,a[i].x); maxy = max(maxy,a[i].y);
		}
		sort(a+1,a+1+n,cmpx);
		per(i,1,n){
			if(be_r[a[i].x] == -1){
				be_r[a[i].x] = i;
			}
		}
		per(i,r,maxx-r){
			rf[i] = ri[i-r] + ri[i] + ri[i+r];
		}
		per(i,r,maxy-r){
			cf[i] = c[i-r] + c[i] + c[i+r];
		}
	}

	return 0;
}
