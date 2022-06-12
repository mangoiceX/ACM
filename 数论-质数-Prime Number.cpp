#include<iostream>
#include<cstdio>
#include<vector>
#include<bitset>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<fstream>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define pii pair<int, int>
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define PER(i,x) for(auto i=x.begin();i!=x.end();i++)
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
typedef long long LL;
const double eps=1.0e-5;
const int maxn=2e5 + 10;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int cnt1=0,cnt2=0,cnt3=0,tmp = 0,a[maxn],ma=-inf;
int n = 0,cnt = 0;
int prime[maxn]; 
void get_prime(){
	cnt = 1;
	prime[0] = 2;
	per(i,3,maxn-1){
		int flag = 0;
		//per(j,0,cnt){
		//从<=sqrt(i+0.5)的范围内寻找质数 ,唯一分解定理 ，相对于欧拉筛选和埃式筛选法节省空间 
		for(int j = 0;prime[j] * prime[j] <= i;++j){
			if(i % prime[j] == 0){
				flag = 1;
				break;
			}
		}
		if(flag == 0){
			prime[cnt++] = i;
		}
	}
}
int main(){
	#ifndef ONLINE_JUDGE
		//freopen("a.txt","r",stdin);
	#endif
	get_prime();
	while(~scanf("%d",&n)){
		int loc = upper_bound(prime,prime+cnt,n) - prime;
		printf("%d\n",loc);
	}
	
	return 0; 
}
