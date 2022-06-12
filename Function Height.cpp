#include<bits/stdc++.h>
#define INF 1e6 
using namespace std;
const int maxn = 1e6 + 100;
typedef long long LL;
LL n = 0,k = 0;
int main(){
	while(cin >> n >> k){
		if(k % n > 0){
			cout << k / n + 1 << endl;
		}else{
			cout << k / n << endl;
		}
		//cout << ceil((double) k / (double)n ) << endl; 
	}
	return 0;
} 
