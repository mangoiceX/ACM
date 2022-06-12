#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string> 
#include<cstring>
#include<set>
#define INF 0x6ffffff
using namespace std;
typedef unsigned long long LL;
const LL maxn = 1e9;
LL n = 0,k = 0,s = 0;
int main(){
	
	scanf("%lld %lld %lld",&n,&k,&s);
	LL big = n - 1,restd = s,restb = k;
	if(k * (n - 1) < s){
		printf("NO\n");
	}else{
		int  k = 0;
		while( (restd <= restb * big ) && (restb <= restd) && (restb > 1)){
			if(restd < big){
				break;
			}
			if(k % 2 == 0){
				printf(" %lld ",n);
	
			}else{
				printf(" 1 ");
		
			}
			restd -= big;
			restb -= 1;
			k++;
		} 
		int j = 0;
		while(restb > 1){
			if(k % 2 == 0){// 1
				if(j % 2 == 0){
					printf(" 2 ");
					++j;
					restd -= 1;
					restb -= 1;
				}else{
					printf(" 1 ");
					++j;
					restd -= 1;
					restb -= 1;
				}
				++k;
			}else{
				if(j % 2 == 0){
					printf(" 9 ");
					++j;
					restd -= 1;
					restb -= 1;
				}else{
					printf(" 10 ");
					++j;
					restd -= 1;
					restb -= 1;
				}
				++k;
			}
		}
		
		if(k % 2 == 0){
			if(j % 2 == 1){
				printf(" %lld",9 - restd);
			}else{
				printf(" %lld",10 - restd);
			}
		}else{
			if(j % 2 == 1){
				printf(" ll%d",2 + restd);
			}else{
				printf(" ll%d",1 + restd);
			}
		}
		
			
		
	}
	
	
	
	return 0;
}
