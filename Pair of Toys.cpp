#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<set>
#define INF 2e5 + 100
using namespace std;
typedef unsigned long long ULL;
ULL n = 0,k = 0;
ULL solve(){
	if(k > 2*n - 1){
		return 0;
	}
	if(k % 2 == 0){
		//return min(n,k) - (k - (k/2 -1)) + 1;
		if(n < k - 1){
			ULL a = k - n;
			return k - k/2 - a;
		}else{
			return k - k/2 - 1;
		}
	}else{
		if(n < k - 1){
			ULL a = k - n;
			return k - k/2 - a;
		}else{
			return k - k/2 - 1;
		}
		
	//	return min(n,k) - (k - (k/2)) + 1
	}
	
}
int main(){

	//while(scanf("%d %d",&n,&k)){
	while(cin >> n >> k){
		cout << solve() << endl;
	}
	
	return 0;
}
