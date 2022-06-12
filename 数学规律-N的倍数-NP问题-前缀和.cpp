#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
map<int,int> mp;
const int maxn = 5e4 + 10;
int sum[maxn];
int a[maxn];
int n = 0;

int main(){
	while(~scanf("%d",&n)){
		fill(sum,sum+maxn,0);
		mp[0] = 0;
		for(int i = 1;i <= n;++i){
			scanf("%d",&a[i]);
			sum[i] = (sum[i-1] + a[i]) % n;
			if(mp.count(sum[i]) == 1){
				printf("%d\n",i - mp[sum[i]]);
				for(int j = mp[sum[i]] + 1;j <= i;++j){
					printf("%d\n",a[j]);
				}
				return 0;
			}
			mp[sum[i]] = i;
		}
		
	}
	
	return 0;
}
