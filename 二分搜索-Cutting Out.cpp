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
int n = 0,k = 0;
int a[maxn+10];
map<int,int> mp;
struct node{
	int val,time;
};
node data[maxn+10];
int cnt = 0;
bool cmp(node a,node b){
	return a.time > b.time;
}
bool check(int kk){
	int ans = 0;
	per(i,1,k){
		ans	+= (data[i].time / kk);
	}
	return ans >= k;
}
void solve(){
	
	int l = 0,r = maxn+10;//r要设置为n+1,而不是n,要么干脆设置为manx+10 
	while(l + 1 < r){
		int mid = (l + r) >> 1;
		if(check(mid)){
			l = mid;//不要写成mid+1,写成l = mid可以向夹逼准则一样 
		}else{
			r = mid;
		}
	}
	

	int cnt = 0;
	per(i,1,k){
		per(j,1,data[i].time/l){
			if(cnt >= k){
				printf("\n");
				return ;
			}
			cnt++;
			printf("%d%c",data[i].val,' ');
		}	
	}
	printf("\n");
}
int main(){
	while(~scanf("%d %d",&n,&k)){
		mp.clear();
		per(i,1,n){
			scanf("%d",&a[i]);
			mp[a[i]]++;
		}
		cnt = 0;
		map<int,int>::iterator it = mp.begin();
		for(it = mp.begin();it != mp.end();it++){
			data[++cnt].val = it->first;
			data[cnt].time = it->second;
		}
		sort(data+1,data+1+n,cmp);
		solve();
	}
	return 0;
}

