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
const int maxn=1e6 + 10;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int cnt1=0,cnt2=0,cnt3=0,tmp = 0,a[maxn],b[maxn],c[maxn],ma=-inf,flag;
int n = 0;
const int size = 3e5 + 10;
int prime[size]; 
bool is_prime[maxn];
int cnt = 0;
void ouler(){
	cnt = 0;
	fill(prime,prime+size,0);
	fill(is_prime,is_prime + maxn,true);
	per(i,2,maxn-1){
		if(is_prime[i]){
			prime[cnt++] = i;
			} 
		for(int j = 0;j < cnt && i * prime[j] < maxn;++j){
			is_prime[i * prime[j]] = false;
			if(i % prime[j] == 0){
				break;
			}
		}
	
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		//freopen("a.txt","r",stdin);
	#endif
	ouler();
	while(~scanf("%d",&n)){
		/*
		per(i,0,cnt){
			if(prime[i] > n){
				printf("%d\n",i);
				break;
			}
			if(prime[i] == n){
				printf("%d\n",i + 1);
				break;
			}
		
		} 
		*/
		int loc = upper_bound(prime,prime + cnt,n) - prime;
		printf("%d\n",loc);
	}
	
	return 0; 
}
