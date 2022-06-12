 //#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn = 65000 + 10;
int n = 0;
bool is_prime[maxn];
void ais(){
	fill(is_prime,is_prime+maxn,true);
	is_prime[0] = is_prime[1] = false;
	for(int i = 2;i <= maxn;++i){
		if(is_prime[i]){
			for(int j = 2*i;j <= maxn;j += i){
				is_prime[j] = false;
			}
		}
	}
}
LL mod_pow(LL x,LL n,LL mod){//x的n次方 
	LL ans = 1;
	while(n > 0){
		if(n & 1){
			ans = ans * x % mod;
		}
		x = x * x % mod;
		n >>= 1;
	}
	return ans;
}
bool judge(){
	for(LL i = 2;i < n;++i){
		if(mod_pow(i,n,n) % n != (i % n)){
			return false;
		}
	}
	return true;
}
int main(){
	ais();
	while(~scanf("%d",&n) && n){//n使用LL类型，用%I64d输入输出，会出现PE 
		if(is_prime[n]){
			printf("%d is normal.\n",n);
			continue;
		}
		if(judge()){
			printf("The number %d is a Carmichael number.\n",n);
		}else{
			printf("%d is normal.\n",n);
		}
	}
	return 0;
}
