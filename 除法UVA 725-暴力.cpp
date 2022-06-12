#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

bool judge_only(int m,int n){	//
	int flag[10];
	if(n > 98765){
		return false;
	}
	//memset(flag,0,flag + 10);
	for(int i = 0;i < 10;i++){
		flag[i] = 0;
	}	
	if(m < 10000){
		flag[0] = 1;
	}
	while(m > 0){
		flag[m%10] = 1;
		m /= 10;
	}
	
	while(n > 0){
		flag[n%10] = 1;
		n /= 10;
	}
	int sum = 0;
	for(int i = 0;i < 10;i++){
		sum += flag[i];
	}
	/*
	if(sum == 10){
		return true;
	}
	else{
		return false;
	}*/
	return (sum == 10);
}
int main(){
	int n = 0;
	int T = 0;
	
	while(~scanf("%d",&n) && n){
		if( T++ ){
			printf("\n");
			}
		int cnt = 0;
		for(int i = 1234;i < 50000;++i){
			if( judge_only(i , i*n) ){
				printf("%05d / %05d = %d\n",i*n,i,n);
				++cnt;
			}
		}
		if(cnt == 0){
			printf("There are no solutions for %d.\n",n);
		}
		
	}
	
	return 0;
}
