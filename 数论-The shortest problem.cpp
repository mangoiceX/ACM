#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define INF 1e6
using namespace std;//提交时要选G++,选c++会超时，之前WA了那么多次，就是这个原因，想哭 
int n = 0,t = 0;

int main(){
	int kase = 0;
	while(scanf("%d %d",&n,&t) != EOF && (n != -1 || t != -1)){
		int sum = 0,mod = n % 11;//mod的初始值 
		while(t--){
			while(n > 0){//计算sum 
				sum += (n % 10);
				n /= 10;
			}
			int temp1 = sum,cnt = 1;
			n = sum;//后面加的是sum 
			while(temp1 > 0){//计算sum的位数 
				cnt *= 10;
				temp1 /= 10;
			}
			mod = (mod * cnt + sum) % 11;//此处mod11,控制大小 
		}
		if(mod == 0){ 
			printf("Case #%d: Yes\n",++kase);
		}else{
			printf("Case #%d: No\n",++kase);
		}
	}
	return 0;
}
