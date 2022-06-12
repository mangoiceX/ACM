#include<bits/stdc++.h>
#define INF 1e6 
using namespace std;
const int maxn = 1e6 + 100;
typedef long long LL;
LL x = 0,y = 0,k = 0;
int main(){
	int q = 0;
	while(scanf("%d",&q) != EOF){
		for(int i = 0;i < q;++i){
			scanf("%I64d %I64d %I64d",&x,&y,&k);
			if(k < (abs(abs(x)-abs(y)) + min(abs(x),abs(y)) ) ){ //|| k > ( abs(x) + abs(y))){
				printf("-1\n");
				continue;
			}
			if(x == y){
				if((k - abs(x) ) % 2 == 0){
					printf("%I64d\n",k);
					continue;
				}else{
					printf("%I64d\n",abs(x) + k - abs(x) - 2);
					continue;
				}
			}
			LL ans = k - abs(abs(x)-abs(y));
			if((abs(abs(x)-abs(y)) ) % 2 == 0){
				ans += abs(abs(x)-abs(y));
				printf("%I64d\n",ans);
			}else{
				ans += abs(abs(x)-abs(y)) - 1;
				printf("%I64d\n",ans);
			}
		
		//	printf("%I64d\n",ans);
			/*
			LL sum = k - ( abs(abs(x)-abs(y)) + min(abs(x),abs(y)) );  
			if((k - ( abs(abs(x)-abs(y)) + min(abs(x),abs(y)) ) )  % 2 == 0){
				LL ans = min(abs(x),abs(y)) + sum;
				printf("%I64d\n",ans);
			}else{
				LL ans = min(abs(x),abs(y)) + sum;
				printf("ni%I64d\n",ans);
			}
			//printf("in\n");
			*/
		}
		
	}
	
	
	return 0;
} 
