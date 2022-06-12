#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
const int maxn = 1e5 + 10;
int v1 = 0,v2 = 0,t = 0,d = 0;
int main(){
	while(scanf("%d %d %d %d",&v1,&v2,&t,&d) != EOF){
		int sum = 0;
		for(int i = 0;i < t;++i){
			sum += min(v1 + i*d,v2 + (t-i-1)*d);
		}
		printf("%d\n",sum);
	}	
	
	return 0;
} 
