#include<bits/stdc++.h> 
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 10;
map<LL,LL> mp[11];//定义多维map 
int n = 0,k = 0;
LL a[maxn];
int main(){
	while(scanf("%d %d",&n,&k) != EOF){
		//mp.clear();
		for(int i = 0;i < 11;++i){//注意要清楚每个一维的map 
			mp[i].clear();
		}
		for(int i = 1;i <= n;++i){
			scanf("%I64d",&a[i]);
			LL x = a[i];
			for(int j = 1;j <= 10;++j){//预处理，每个数分别向左移动j位mod k 的余数，
										//方便后面直接查找 
				x *= 10;
				x %= k;
				++mp[j][x];
			}
		}
		LL sum = 0;
		for(int i = 1;i <= n;++i){
			LL t = a[i] % k;
			int len = log10(a[i]) + 1;//求出该数的数位(也就是他加在其他数后面时，其他数移动的位数) 
			sum += mp[len][(k - t) % k];//查找移动len位，余数与t互补 
			LL x = 1;
			for(int j = 1;j <= len;++j){//排除是本身的情况 
				x = (x * 10) % k;
			}
			if(((a[i] * x)%k + a[i]%k)%k == 0){
				--sum;
			}
		}
		printf("%I64d\n",sum);
	}
	
	return 0;
}
