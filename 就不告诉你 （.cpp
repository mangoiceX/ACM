#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f 
using namespace std;
const int maxn = 1e5;
int a = 0,b = 0;
int main(){
	while(cin >> a >> b){
		int res = a*b;
		while(res % 10 == 0){
			res /= 10;
		}
		while(res > 0){
			cout << res%10;
			res /= 10;
		}
		cout <<"\n";
	}
	
	
	return 0;
}
