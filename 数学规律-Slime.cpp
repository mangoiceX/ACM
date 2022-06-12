#include<bits/stdc++.h>
using namespace std;
typedef long long LL;//这种可以找几个简单的例子，看出规律 
const int maxn = 5e5 + 100;//寻找不变的规律，表面上看起来很复杂，抓住问题的本质就很简单了 
int a[maxn];
/*
用min不断减去相邻的+数，max不断减去相邻的-数，最后的值就是max_sum 
排序后，首先是最大值和最小值是确定的，max是加，min是减，然后讨论中间的数，若全是-，则用max减去它们，
//若全是+，则用min减去它们，若有-有+，则用自身的-减去相邻的+ 
*/ 
int n = 0;//
int main(){
	while(scanf("%d",&n) != EOF){
		for(int i = 1;i <= n;++i){
			scanf("%d",&a[i]);
		}
		if(n == 1){
			printf("%d\n",a[1]);
			continue; 
		}
		sort(a + 1,a + 1 + n);//排序 
		LL sum = 0;
		sum += a[n];//最大值肯定是相加 
		sum -= a[1];//最小值是相减 
		for(int i = 2;i <= n - 1;++i){//其他的就是取绝对值 
			sum += abs(a[i]);
		}
		printf("%I64d\n",sum);
	}

	return 0;
} 
