#include<bits/stdc++.h>
#define pii pair<int,int>
typedef long long LL;
using namespace std;
const int maxn = 1e4,ma = 1e6;
int n = 0;
int a[maxn+10];
pii p[ma + maxn + 10];
bool is_prime[ma+maxn+10];
bool cmp(pii a,pii b){
	return a.first == b.first ? a.second < b.second : a.first < b.first;
}
void ais(){
	fill(is_prime,is_prime+ma+maxn+10,true);
	for(int i = 2;i <= ma + maxn;++i){
		if(is_prime[i]){
			for(int j = i*i;j <= ma+maxn;j += i){
				is_prime[j] = false;
			}
		}
	}
}
void get_ouler(){
	for(int i = 1;i <= ma+maxn;++i){ 
		if(i == 1){
			p[i].first = 1;p[i].second = i;
			continue;
		}
		if(is_prime[i] && i != 1){//是质数时 
			p[i].first = i - 1;p[i].second = i;
			continue; 
		}
		if(i % 2 == 0 && (i/2) % 2 == 1){//欧拉函数的性质 
			p[i].first = p[i/2].first;p[i].second = i;
			continue;
		}
		int tmp = i,res = i;
		for(int j = 2;j * j <= tmp;++j){//质因数分解 
			if(tmp % j == 0){
				while(tmp % j == 0){
					tmp /= j;
				}
				res -= res/j; 
			}
		}
		if(tmp > 1){
			res -= res/tmp;
		}
		p[i].first = res;p[i].second = i;
	}
	p[1].first = 0;//记得重置，这是为了与题意相符合 
}
int main(){
	int T = 0,kase = 0;
	get_ouler();
	//sort(p+1,p+ma+maxn+1,cmp);
	scanf("%d",&T);
	while(T--){
		LL mi = 0;
		scanf("%d",&n);
		for(int i = 1;i <= n;++i){
			scanf("%d",&a[i]);
			//mi += p[lower_bound(p+1,p+ma+maxn+1,make_pair(a[i],-1),cmp) - p].second;
			int tmp = a[i] + 1;
			while(true){
				if(p[tmp].first >= a[i]){
					mi += p[tmp].second;
					break;
				}
				++tmp;
			}
		}
		printf("Case %d: %lld Xukha\n",++kase,mi);	
	}
	
	return 0;
}
