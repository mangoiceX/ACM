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
#define INF 2000000010
typedef long long LL;
const double eps=1.0e-5;
const int maxn=1e5 + 50;

int cnt1=0,cnt2=0,cnt3=0,tmp = 0,a[maxn],b[maxn],c[maxn],ma=-inf,flag;
int n = 0,k = 0; 
struct node{
	int val,id;
};
node pre_sum[maxn];
bool cmp(node a,node b){
	return a.val < b.val;	
}
int main(){
	//freopen("a.txt","r",stdin);
	while(~scanf("%d %d",&n,&k) && (n != 0 || k != 0)){
		//mem(pre_sum,0);
		pre_sum[0].val = pre_sum[0].id = 0;
		per(i,1,n){
			scanf("%d",&a[i]);
			pre_sum[i].val = pre_sum[i-1].val + a[i];
			pre_sum[i].id = i;
		} 
		sort(pre_sum,pre_sum+n+1,cmp);//排序时，不能用pre_sum+1 
		//per(i,0,n){//0要算上，否则1-m的区间没有算进去 
		//	cout << "em " << pre_sum[i].val << " " << pre_sum[i].id<< endl; 	
		//}
		int key = 0;
		while(k--){
			scanf("%d",&key);
			int ansl = 0,ansr = 0,ans = 0;	
			int s = 0,e = 1	,minv = inf;
			while(e <= n && s <= n){
				int w = abs(pre_sum[e].val - pre_sum[s].val);
				int q = abs(w - key);
				if(q < minv){
					ans = w;
					minv = q;
					ansl = pre_sum[s].id;ansr = pre_sum[e].id;
				}
				if(w < key){
					e++;
				}else if(w > key){
					s++;
				}else{
					break;
				}
				if(s == e){//相等的时候 
					e++;
				} 
			}
			if(ansl > ansr){
				swap(ansl,ansr);
			}
			printf("%d %d %d\n",ans,ansl+1,ansr);
		}
	}
	
	return 0; 
}
