#include<bits/stdc++.h>
#define INF 1e6 
using namespace std;
const int maxn = 1e6 + 100;
typedef long long LL;
LL sum = 0,s1 = 0,s2 = 0;
int n = 0;
int main(){
	while(scanf("%d",&n) != EOF){
		sum = (n + 1) * n / 2;
		if(n == 1 || n == 2){
			printf("No\n");
			continue;
		}
		if(n == 3){
			printf("Yes\n");
			printf("1 2\n");
			printf("2 1 3\n");
			continue;
		}
		
		int m = (n%2 == 0) ? n/2 : (n+1)/2;
		printf("Yes\n");
		printf("1 %d\n",m);
		printf("%d",n - 1);
		for(int i = 1;i <= n;++i){
			if(i != m){
				printf(" %d",i);	
			}
		}
		printf("\n");
	}
	
	return 0;
}
