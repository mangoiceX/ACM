#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 2e5 + 10;
int data[maxn];
int page[maxn];
int n = 0,m = 0;
int main(){
	
	scanf("%d %d",&n,&m);
	memset(page,0,sizeof(page));
	for(int i = 1;i <= n;++i){
		scanf("%d",&data[i]);
	}
	
	int sum = 0,res = 0;
	
	for(int i = 1;i <= n;++i){
		sum = data[i] + res;
		page[i] = sum / m;
		res = sum % m;
		sum = 0;
	}
	
	for(int i = 1;i <= n;++i){
		if(i > 1){
			printf(" ");
		}
		printf("%d",page[i]);
	}
	
	
	return 0;
} 
