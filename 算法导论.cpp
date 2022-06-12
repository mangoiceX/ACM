#include<bits/stdc++.h>
using namespace std;
int main(){
	int n = 0,m = 0,k = 0;//处理n个不同的整数，可以鸽巢原理  
	printf("Please input n:\n");
	scanf("%d",&n);
	int* a = new int[n+1];
	printf("Please input your array:\n");
	for(int i = 1;i <= n;++i){
		scanf("%d",&a[i]);
	}
	printf("Please input m:\n");
	scanf("%d",&m);
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;++i){
		for(int j = i+1;j <= n;++j){
			if(a[i] + a[j] == m){
				++k;
			} 
		}
	}
	if(k == 0){
		printf("There is no answer!!!\n");
		return 0;
	}
	printf("The answer is %d\n",n - k + 1);
	
	return 0;
}
