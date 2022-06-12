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
	LL id,val;
};
int n = 0;
LL a[maxn+10],b[maxn+10];
node c[maxn+10];
LL d[maxn+10],biao[maxn+10];
int ans[maxn+10];
LL sum = 0;
bool cmp(node a,node b){
	return a.val != b.val ? a.val < b.val : a.id < b.id;
}
bool operator <(node a,node b){
	return a.val != b.val ? a.val < b.val : a.id < b.id;
}
void solve(){
	int cnt = 0;
	per(i,0,n-1){
		b[i] = sum - a[i];
		if(b[i] & 1){
			continue;
		}
		if(upper_bound(d,d+n,b[i]/2) - lower_bound(d,d+n,b[i]/2) > 1){
			ans[cnt++] = i+1;
			continue; //少了一个continue,会导致后面的重复 
		}
		int t = lower_bound(d,d+n,b[i]/2) - d;
		LL t1 = d[t],t2 = biao[t];
		if(t1 == b[i]/2 && t2 != i+1){
			ans[cnt++] = i+1;
		}
	}
	if(cnt == 0){
		printf("0\n");
	}else{
		printf("%d\n",cnt);
		per(i,0,cnt-1){
			printf("%d%c",ans[i],i == cnt-1 ? '\n':' ');
		}
	}
}
int main(){
	while(~scanf("%d",&n)){//结构体数组的lower_bound和Upper_bound 
		sum = 0;
		per(i,0,n-1){
			scanf("%I64d",&a[i]);
			c[i].val = a[i];c[i].id = i+1;
			sum += a[i];
		}
		sort(c,c+n,cmp);
		per(i,0,n-1){//重新用两个数组将结构体分开 
			d[i] = c[i].val;
			biao[i] = c[i].id;
		}
		solve();
	}
	return 0;
}

