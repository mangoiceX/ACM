#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
const int maxn = 100010;
int data[maxn],ans = 0,n = 0,m = 0;
void solve(){
	int weizhi = 0;
	for(int i = 1;i <= n;++i){
		if(data[i] != -1){
			weizhi = i;
		}
	}
	
	for(int i = weizhi;i >= 1;--i){
		if(data[i] == 0){
			data[i-1] = data[i] + m - 1;
		}else{
			data[i-1] = data[i] - 1;
		}
	}
	
	for(int i = weizhi;i <=n;++i){
		data[i+1] = (data[i] + 1) % m;
	}
	
}
int main(){
	int T = 0;
	scanf("%d",&T);
	getchar();
	while(T--){
		ans = 0;
		scanf("%d %d",&n,&m);
		for(int i = 1;i <= n;++i){
			scanf("%d",&data[i]);
		}
		solve();
		for(int i = 1;i <= n;++i){
			if(i > 1){
				printf(" ");
			}
			printf("%d",data[i]);
		}
		printf("\n");
	
	}
	

	
	return 0;
} 
