#include<iostream>
#include<cstdio>
#include<algorithm>	
#include<string>
#include<cstring>
#include<set>
using namespace std;
const int maxn = 50 + 10;

int st1[maxn],st2[maxn];

int main(){
	int n = 0;
	int sum1= 0,sum2 = 0;
	scanf("%d",&n);

	for(int i = 0;i < n;++i){
		scanf("%d",&st1[i]);
		sum1 += st1[i];	
	}
	for(int i = 0;i < n;++i){
		scanf("%d",&st2[i]);
		sum2 += st2[i];
	}
	if(sum2 > sum1){
		printf("NO\n");
	}else{
		printf("YES\n");
	}
	
	
	return 0;
}
