#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector> 
using namespace std;
const int maxn = 1e4 + 100;
typedef long long LL;
vector<int> prime;
int e[maxn];
int p = 0,q = 0,r = 0,s = 0; 
bool is_prime[maxn];
void ais(int n){
	fill(is_prime,is_prime+maxn,true);
	is_prime[0] = is_prime[1] = false;
	for(int i = 2;i < maxn;++i){
		if(is_prime[i]){
			prime.push_back(i);
			for(int j = 2*i;j < maxn;j += i){
				is_prime[j] = false;
			}
		}
	}
}
void add_integer(int n,int d){//唯一分解定理的用武之地 
	for(int i = 0;i < prime.size();++i){
		while(n % prime[i] == 0){
			n /= prime[i];
			e[i] += d;
		}
		if(n == 1){
			break;
		}
	}
}
//结果处理n!,d==-1表示除法，d==1表示乘法 
void add_factorial(int n,int d){
	for(int i = 1;i <= n;++i){
		add_integer(i,d);
	}
}
int main(){
	ais(maxn);
	while(~scanf("%d %d %d %d",&p,&q,&r,&s)){
		fill(e,e+maxn,0);
		add_factorial(p,1);
		add_factorial(r,-1);
		add_factorial(s,1);
		add_factorial(q,-1);
		add_factorial(r-s,1);
		add_factorial(p-q,-1);
		double ans = 1;
		for(int i = 0;i < prime.size();++i){//处理剩余的质因数的指数 
			ans *= pow(prime[i],e[i]);
			//cout << "em" << endl;
		}	
		printf("%.5lf\n",ans);
	}
	
	return 0;
} 
