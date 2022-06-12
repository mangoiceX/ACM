#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
int n = 0,h = 0;
int presum[maxn],pre[maxn];
int rec[maxn];
int main(){
	while(~scanf("%d %d",&n,&h)){
		rec[1] = 0,presum[0] = 0,pre[0] = 0;
		int l = 0,r = 0,pre_r = 0;
		for(int i = 1;i <= n;++i){
			scanf("%d %d",&l,&r);
			rec[i] = r - l;
			presum[i] = presum[i-1] + rec[i];
			if(i == 1){
				pre_r = l;
			}
			pre[i] = pre[i-1] + l - pre_r;
			pre_r = r;
		}
		int maxv = 0;
		for(int i = 1;i <= n;++i){
			int loc = lower_bound(pre+1,pre+n+1,h+pre[i]) - pre - 1;
			maxv = max(maxv,presum[loc] - presum[i - 1]);
		}
		printf("%d\n",maxv + h);
	}
	return 0;
} 
