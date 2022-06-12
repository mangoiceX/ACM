#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5;

int a[maxn+10];
int n = 0,z = 0;
int main(){
	while(~scanf("%d %d",&n,&z)){
		for(int i = 1;i <= n;++i){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		int l = 0,r = n/2;
		int mid = 0,ans = 0;
		while(l <= r){
			mid = (l + r) / 2;
			int sum = 0;
			for(int i = 1;i <= mid;++i){
				if(a[n-mid+i] - a[i] >= z){
					++sum;
				}
			}
			if(sum == mid){
				ans = mid; 
				l = mid + 1;
			}else{
				r = mid - 1;
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
} 
