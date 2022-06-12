#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
int n = 0;
int a[30];
int len = 0;
void print(){
	per(i,0,len-1){
		printf("%d%c",a[i],i == len-1 ? '\n' : ' ');
	}
}
void solve(){
	int cnt = 1;
	// print();
	do{
		++cnt;
		print();
		if(cnt == len+1){
			break;
		}
	}while(next_permutation(a,a+len));
}
int main(){
	while(~scanf("%d",&n)){
		len = pow(2,n);
		per(i,0,len/2-1){
			a[i] = -1;
		} 
		per(i,len/2,len-1){
			a[i] = 1;
		}
		solve();
	}


	return 0;
}