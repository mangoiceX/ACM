#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int maxn = 1e3 + 10;
const LL mod = (1e9 + 7);
double esp = 20.0;
const int maxv = 999000010;
struct node{
	int x,y;
	// bool operator < (const node& no){
	// 	return this->x == no.x ? (this->y > n2o.y) : (this->x < no.x);
	// }
}a[maxn];
int n = 0,m = 0,k = 0;
bool cmp(node no1,node no2){
	return no1.x == no2.x ? no1.y > no2.y : no1.x < no2.x;
}
void solve(){
	int mid = n/2;
	int l = mid,r = mid;
	while(l > 1 && a[l-1].x == a[mid].x){
		--l;
	}
	while(r < n && a[r+1].x == a[mid].x){
		++r;
	}

	if(r == mid){
		printf("%d %d %d %d\n",a[mid].x,-maxv,a[mid].x+1,maxv);
		return ;
	}

	long double k1 = (maxv*1.0 - (a[mid].y*1.0-0.5))*1.0/1;

	int mi = -1000000000;
	int yy = ceil((a[mid].y*1.0-0.5) - k1 * 1);
	int now = max(mi,yy);
	printf("%d %d %d %d\n",a[mid].x-1,now,a[mid].x+1,maxv);
}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		per(i,1,n){
			scanf("%d %d",&a[i].x,&a[i].y);
		}
		sort(a+1,a+1+n,cmp);
		solve();
	}
	return 0;
}