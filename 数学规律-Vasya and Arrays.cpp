#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 3e5 + 10;//我又被欺骗了，模拟害死人 
int n = 0,m = 0;
int a[maxn],b[maxn];
int main(){
	LL sum1 = 0,sum2 = 0;
	scanf("%d",&n);
	for(int i = 1;i <= n;++i){
		scanf("%d",&a[i]);
		sum1 += a[i];
	}
	scanf("%d",&m);
	for(int i = 1;i <= m;++i){
		scanf("%d",&b[i]);
		sum2 += b[i];
	}
	if(sum1 != sum2){
		printf("-1\n");
		return 0;
	}
	int j = 1,cnt = 0;
	sum1 = 0,sum2 = 0;
	for(int i = 1;i <= n;++i){//如果第一个序列的和小于第二个时，for循环是的第一个一直加 
		sum1 += a[i];
		while(sum2 < sum1){//第一个序列的和大于第二个时，第二个一直加 
			sum2 += b[j++];
		}
		if(sum2 == sum1){//相等就计数加一，和重置为0 
			sum1 = sum2 = 0;
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}

