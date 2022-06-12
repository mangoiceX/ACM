#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

const int MAXN = 2e6;
bool is_prime[MAXN+10];//标记是否是素数
vector<int> prime;//记录素数
void pre_solve(){//预处理出1e6以内素数
	//欧拉筛选法，O(n)复杂度
	memset(is_prime,true,sizeof(is_prime));
	is_prime[1] = false;
	for(int i = 2;i <= MAXN;++i){
		if(is_prime[i]){
			prime.push_back(i);
		}
		for(int j = 0;j < prime.size() && i*prime[j] <= MAXN;++j){
			is_prime[i*prime[j]] = false;
			if(i % prime[j] == 0){
				break;
			}
		}
	}
}
int main(){
	pre_solve();
	int n = 0;
	while(~scanf("%d",&n)){
		if(n <= MAXN){
			int loc = lower_bound(prime.begin(),prime.end(),n) - prime.begin();//在事先得到的素数中，二分查找
			printf("%d\n",loc);
		}else{
			int tmp = int(n*log10(exp(1))/int(log10(n)));
			printf("The approximate value is %d\n",tmp);//使用素数公式估计
		}
	}



	return 0;
}