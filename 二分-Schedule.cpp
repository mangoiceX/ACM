// #include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
const int maxn = 1e5 + 10;
typedef long long LL;
int n = 0,m = 0;
struct node{
	int s,e;
	// bool operator < (const node& b){
	// 	return (this->s == b.s) ? (this->e < b.e) : (this->s < b.s);
	// }
}a[maxn];
int en[maxn],st[maxn];
bool cmp(node x,node y){
	return (x.s == y.s) ? (x.e < y.e) : (x.s < y.s);
}
int lb(int x,int cnt){
	int l = 1,r = cnt;
	int mid = 0;
	int ans = 0;
	while(l <= r){
		mid = (l + r) >> 1;
		if(en[mid] > x){
			r = mid - 1;
		}else{
			ans = mid;
			l = mid + 1;
		}
	}
	return ans;
}
void solve(){
	int cnt = 0;
	en[++cnt] = a[1].e;
	st[cnt] = a[1].s;
	per(i,2,n){ 		
		// int loc = lb(en+1,en+1+cnt+1,a[i].s) - en - 1;
		int loc = lb(a[i].s,cnt);
		// cout << loc <<endl;
		if(loc == 0){
			en[++cnt] = a[i].e;
			st[cnt] = a[i].s;
		}else{
			en[loc] = a[i].e;
		}
		sort(en+1,en+1+cnt);
		// per(i,1,cnt){
		// 	cout << "nima " << en[i] <<endl;
		// }
		// cout << "ji" << endl;
	}
	
	int ans = 0;
	per(i,1,cnt){
		ans += (en[i] - st[i]);
	}
	printf("%d %d\n",cnt,ans);
}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		per(i,1,n){
			scanf("%d %d",&a[i].s,&a[i].e);
		}
		sort(a+1,a+1+n,cmp);
		solve();
	}

	return 0;
}