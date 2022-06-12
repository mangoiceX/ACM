#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 8e7 ;
int data[maxn];
int ans[maxn];
int main(){
	int n = 0,m = 0;
	scanf("%d %d",&n,&m);
	for(int i = 1;i < maxn;++i){
		data[i] = -1;
	}
	int x = 0;
	for(int i = 1;i <= n;++i){
		scanf("%d",&x);
		data[x] = 0;
	}	
	unsigned long long sum = 0;
	int k = 1,num = 0;
	while(sum <= m){
		if(data[k] == -1){	
			if(sum + k > m){
				break;
			}
			//printf("%d ",k);
			ans[num++] = k;
			sum += k;
		}
		++k;
	}
	printf("%d\n",num);
	for(int i = 0;i < num;++i){
		printf("%d ",ans[i]);
	}
	printf("\n");
	
	return 0;
}

