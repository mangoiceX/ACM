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
const int maxn = 1e5;
int n = 0,m = 0;
struct node{
	int s,r;
};
node a[maxn+10];
map<int,int> mp;
int loc[maxn+10],pre_sum[maxn+10];
bool cmp(node a,node b){
	return (a.s == b.s) ? a.r > b.r : a.s < b.s ; 
}
bool cmp2(node a,node b){
	return (a.s == b.s) ? a.r > b.r : mp[a.s] < mp[b.s]; 
}
void solve(){
	int size = 1;
	loc[1] = 1;
	pre_sum[0] = 0;
	pre_sum[1] = a[1].r;
	per(i,2,n){
		pre_sum[i] = pre_sum[i-1] + a[i].r;
		while(a[i].s == a[i-1].s && i <= n){
			++i;
			pre_sum[i] = pre_sum[i-1] + a[i].r;
		}
		if(i <= n){
			loc[++size] = i;
		}
	} 
	sort(a+1,a+1+n,cmp2);
	map<int,int>::iterator it,it1;
	int ans = -1;
	for(it = mp.begin();it != mp.end();it++){
		int sum = 0;
		int size1 = it->second;
		for(it1 = it;it1 != mp.end();it1++){
			int lo = loc[it1->first];
			sum += (pre_sum[lo+size1-1] - pre_sum[lo-1]);
		}
		ans = max(ans,sum);
	}
	if(ans <= 0){
		printf("0\n");
		return ;
	}
	
	printf("%d\n",ans);
	
}
int main(){
	while(~scanf("%d %d",&n,&m)){
		mp.clear();
		per(i,1,n){
			int x = 0,y = 0;
			scanf("%d %d",&a[i].s,&a[i].r);
			mp[a[i].s]++;
		}
		sort(a+1,a+1+n,cmp);
		
		solve();
	}
	
	return 0;
}

