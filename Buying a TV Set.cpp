#include<bits/stdc++.h>
#define INF 0x3f3f3f3f 
using namespace std;
const int maxn = 1e5 + 100;
typedef long long LL;
LL a = 0,b = 0,x = 0,y = 0;
LL gcd(LL a,LL b){
	return b == 0 ? a:gcd(b,a % b);
}
int main(){
	while(~scanf("%I64d%I64d%I64d%I64d",&a,&b,&x,&y)){
		LL cnt = 0;
		LL gc = gcd(max(x,y),min(x,y));
		x = x/gc;y = y/gc;
		LL x1 = x,y1 = y;
		cnt = min((a - x1)/x1,(b - y1)/y1);
		if(x1 <= a && y1 <= b){
			cnt++;
		}
		printf("%I64d\n",cnt);
	}
	
	return 0;
} 
