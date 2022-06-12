#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f 
using namespace std;
const int maxn = 2e5;
int n = 0,m = 0;
int a[maxn+10];
int ans = 0; 
void merge(int l,int mid,int r){
	int tmp[maxn+10];
	int p1 = l,p2 = mid + 1,k = 0;
	bool fg = true;
	while(p1 <= mid && p2 <= r){
		if(a[p1] <= a[p2]){
			tmp[++k] = a[p1++];
		}else{
			tmp[++k] = a[p2++];
			// ans += (mid - p1 + 1);
			if(fg){
				ans += 1;
			}		
		}
	}
	while(p1 <= mid){
		tmp[++k] = a[p1++];
	}
	while(p2 <= r){
		tmp[++k] = a[p2++];
	}
	per(i,l,r){
		a[i] = tmp[i-l+1];
	}
}
void merge_sort(int l,int r){
	int mid = (r - l)/2 + l;
	if(l < r){
		merge_sort(l,mid);
		merge_sort(mid+1,r);
		merge(l,mid,r);	
	}
} 
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ans = 0;
		per(i,1,n){
			scanf("%d",&a[i]);
		}
		merge_sort(1,n);
		printf("%d\n",ans);
	}
	
	return 0;
}
