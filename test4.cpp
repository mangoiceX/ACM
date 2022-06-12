#include<iostream>
#include<stdio.h>
using namespace std;
//返回整数[0,n]内拥有的质素数组
int* prime(int n){
	int  *primes = new int [n];
	int count = 1; 
	//质素大于 1 
	bool flag = true;
	for(int i = 2;i < n;i++){
		for(int j = 2;j <= i/2;j++)
			if( i % j == 0 ){
				flag = false;
				break;
		}
		if(flag)
			primes[count++] = i;
		else{
			flag = true;
		}
				
	}
	primes[0] = count;
	return primes;	
}
//返回参数 (整数)n , 拥有的约数个数
int count(int n,int *primes){
	int *a = new int [n/2];
	int count = 0;
	for(int i = 1;n != 1 && i < primes[0];){
		if(n % primes[i] == 0){
			n = n / primes[i];
			a[count++] = primes[i];
		}
		else
		i++;
	}
	int tmp = 1;
	int sum = 1;
	for(int i = 0;i < count;i++){
		if(a[i] == a[i+1])
			tmp++;
		else{
			sum *= (tmp+1);
			tmp = 1;
		} 
	}
	return sum;
}
int main(){
	int t = 0;
	scanf("%d",&t);
	while(t--){
		int b,c;
		scanf("%d",&b);
	        int *primes = prime(b);
	        int a = 1;
		if(a == b )
			c = count(a,primes);
		else{
			int x = 0;
			int	tmp = 0;
			for(int i = a;i <= b; i++) {
				int t = count(i,primes);
				if(tmp < t )
				x = i,tmp = t;
			}
			c = tmp;
		}
		printf("%d\n",c);
	}
	return 0;
} 