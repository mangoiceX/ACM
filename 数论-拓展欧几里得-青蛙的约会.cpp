//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;
LL x = 0,y = 0,m = 0,n = 0,l = 0,k1 = 0,k2 = 0;
LL gcd(LL a,LL b){
	return b == 0 ? a : gcd(b,a % b); 
}
LL ex_gcd(LL a,LL b,LL &x,LL &y){
	if(b == 0){
		x = 1;y = 0;
		return a;
	}else{
		LL r = ex_gcd(b,a%b,x,y);
		LL tmp = x;
		x = y;y = tmp - (a/b)*y;
		return r;
	}
}
int main(){
	while(~scanf("%lld %lld %lld %lld %lld",&x,&y,&m,&n,&l)){

		LL a = n-m,b = l,c = x - y;
		LL r = gcd(a,b);
		
		if(c % r != 0){
			puts("Impossible");
			continue;
		}
		//a /= r;b /= r;
		c /= r;
		k1 = k2 = 0;
		ex_gcd(a,b,k1,k2);
		
		LL ans = (c*k1) % b;//����������Ϊ֮ǰ�����ax+by==gcd(a,b)�Ľ�,
		//����ԭ���̵Ľ�
		//Ҫ*c,�������https://www.cnblogs.com/jackge/archive/2013/04/22/3034925.html 
		if(ans < 0){
			ans += b;//%b��Ϊ����x0,Ȼ������С�������� 
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
