#include<bits/stdc++.h>
#define per(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int maxn = 16000;
int n = 0;
bool is_prime[maxn + 10];
void get_prime(){
	fill(is_prime,is_prime+maxn+10,true);
	is_prime[1] = false; is_prime[2] = true;
	int m = sqrt(maxn+0.5); 
	for(int i = 2;i <= m;++i){
		if(is_prime[i]){
			for(int j = i * i;j <= maxn;j += i){
				is_prime[j] = false;
			}
		}
	}
	is_prime[2] = false;
}
int main(){
	//while(~scanf("%d",&n)){
	get_prime();
	int kase = 0;
	while(~scanf("%d",&n) && n > 0){
		//printf("%d: %s",++kase,is_prime[n] ? "yes\n" : "no\n");
		per(i,2,n){
			if(is_prime[i]){
				printf("%d ",i);
				if(i % 20 == 0){
					puts("");
				}
			}
		}
		puts("");
	}
	
	return 0;
} 
