#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
const int maxn = 1000100;
struct Node{
	int num = -1;
	int times = 0;
};
int ans = 0,n = 0;
Node data[maxn];

int main(){
	int T = 0;
	scanf("%d",&T);
	getchar();
	while(T--){
		scanf("%d",&n);
		getchar();
		ans = 0;
		for(int i = 1;i <= n;++i){
			data[i].num = -1;
			data[i].times = 0;
		}
		for(int i = 1;i <= n ;++i){
			scanf("%d",&data[i].num);
		}
		
		int max = data[1].num;
		for(int i = 2;i <= n - 1;++i){
			if(data[i].num >= max){
				data[i].times++;
				max = data[i].num;
			}
			
		}
		int min = data[n].num;
		for(int i = n-1;i >= 2;--i){
			if(data[i].num <= min){
				data[i].times++;
				min = data[i].num;
			}
			
		}
		for(int i = 2;i <= n-1;++i){
			if(data[i].times == 2){
				++ans;
			}
		}
		printf("%d\n",ans);
	}
	

	
	return 0;
} 
