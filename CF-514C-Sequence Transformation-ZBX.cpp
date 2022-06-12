#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, prod, cnt;
	scanf("%d",&n);
	if (n == 1){
		printf("1\n");
		return 0;
	}
	if (n == 2){
		printf("1 2\n");
		return 0;
	}
	if (n == 3){
		printf("1 1 3\n");
		return 0;
	}
	for (int i = 1; i <= (n + 1) / 2; i++) printf("1 ");
	prod = 1;
	cnt = 0;
	while (true){
		prod *= 2;
		if (n < prod) break;
		cnt++;
	}
	cnt--;
	prod = 1;
	for (int i = 1; i <= cnt; i++){
		prod *= 2;
		for (int j = prod; j <= n; j += prod * 2){
			printf("%d ",prod);
		}
	}
	//printf("%d\n",n / (1 << cnt) * (1 << cnt));
	//printf("%d\n",((n / prod) % 2 == 1) ? (prod *(n/prod)) : (1 << (cnt + 1)));
	printf("%d\n",(n / prod) * prod);//比如现在是4，所以要删除是2的倍数但不是4的倍数的数 
	return 0;//因为4是最后一个2^m<n;所以删除2的倍数后，只剩下4，前面都打印2，既然只有1个去了 
} 	//我可以选个更大的，那就是被2删除的比n小的最大数，相当于不要4 
