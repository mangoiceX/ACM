 #include<iostream>
#include<cstdio>
#include<vector>
#include<bitset>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<fstream>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define pii pair<int, int>
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define PER(i,x) for(auto i=x.begin();i!=x.end();i++)
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
typedef long long LL;
const double eps=1.0e-5;
const int maxn=1e6 + 10;

int cnt1=0,cnt2=0,cnt3=0,tmp = 0,a[maxn],b[maxn],c[maxn],ma=-inf,flag;
int n = 0; 
struct node{
	int val,id;
};
node pre_sum[maxn];
bool cmp(node a,node b){
	if(a.val == b.val){
		return a.id < b.id;
	}
	return a.val < b.val;
}
int main(){
	//freopen("a.txt","r",stdin);
	while(~scanf("%d",&n) && n){
		pre_sum[0].val = pre_sum[0].id = 0; 
		int flag = 0,minc;
		int minv = inf;
		per(i,1,n){
			scanf("%d",&a[i]);
			pre_sum[i].val = pre_sum[i-1].val + a[i];
			pre_sum[i].id = i;
			if(pre_sum[i].val == 0){
				flag = 1;
				minv = 0;minc = i;
			}
		} 
		if(flag == 0){
			minc = 1;
		}
		int ans = min(minv,pre_sum[1].val) ;
		sort(pre_sum+1,pre_sum+n+1,cmp);
		
		int s = 1,e = 2;
		while(s <= n && e <= n){
			int w = abs(pre_sum[e].val - pre_sum[s].val);
			int cnt = abs(pre_sum[e].id - pre_sum[s].id) ;
			if(w < minv || (w == minv && cnt < minc)){
				minv = ans = w;
				minc = cnt;
			}
			if(s < e-1){
				s++;
			}else{
				e++;
			}
		}
		printf("%d %d\n",ans,minc);
	}
	
	return 0; 
}
