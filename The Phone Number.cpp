#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int main(){
	int n = 0;
	scanf("%d",&n);
	if(n % 2 == 1){
		int flag = 0;
		for(int i = 1,j = n;i <= n/2 && j >= 1;--j){
			if((n-j+1) % 2 == 1){
				a[j] = 2 * i;
				++flag;	
			}else{
				a[j] = 2 * i - 1;
				++flag;
			}
			if(flag % 2 == 0){
				++i;
			}
		}
		a[1] = n;
	}else{
		int flag = 0;
		for(int i = 1,j = n;i <= n/2 && j >= 1;--j){
			if((n-j+1) % 2 == 1){
				a[j] = 2 * i;
				++flag;	
			}else{
				a[j] = 2 * i - 1;
				++flag;
			}
			if(flag % 2 == 0){
				++i;
			}
		}
	}
	
	for(int i = 1;i <= n;++i){
		if(i > 1){
			printf(" ");
		}
		printf("%d",a[i]);
	}
	
	
	return 0;
}
