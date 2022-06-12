#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL gcd(LL x,LL y){
	return (x % y == 0) ? y : (gcd(y,x%y));
}
int main(){
	LL x = 0,y = 0,a = 0,b = 0;
	while(~scanf("%lld %lld %lld %lld",&x,&a,&y,&b)){
		if(x / a > y / b){
			puts(">");
			continue;
		}else if(x / a < y/b){
			puts("<");
			continue;
		}
		x %= a;y%= b;
		LL gc0 = gcd(x,a),gc1 = gcd(y,b);
		x /= gc0; a /= gc0; y/= gc1; b/= gc1;
		x %= a;y %= b;
		if(x*b < y*a){
			puts("<");
		}else if(x*b > y*a){
			puts(">");
		}else{
			puts("=");
		}
	}
	
	
	return 0;
} 
