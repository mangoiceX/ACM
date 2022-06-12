#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#define INF  1e5
using namespace std;
typedef long long LL;
const int maxn = 1000 + 100;
LL q = 0;
int solve(LL p){
	if(p == 1){
		return 0;
	}
	LL x = p,temp = 1;
	int num = 0;
	for(LL i = 2;i * i <= p;++i){
		while(x % i == 0){
			++num;
			if(num <= 2){
				temp *= i;
				x /= i;
			}else{
				break;
			}
		}
		if(num > 2){
			break;
		}
	}
	if(x > 1){
		++num;
	}
	if(num == 1){//本身是质数 
		return 0;
	}else if(num == 2){//两个因子之积等于原来的数 ，本身是合数 
		return -1;
	}else{
		return temp;
	}
 
}
int main(){
	cin >> q;
	LL ans = solve(q);
	if(ans == -1){
		cout << "2" << endl;
	}else{
		cout << "1\n" << ans << endl;
	}
	
	
	
	return 0;
} 
