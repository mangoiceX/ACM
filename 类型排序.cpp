#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f 
using namespace std;
const int maxn = 1e5;
int n = 0,m = 0;
string name;
int main(){
	while(cin >> n){
		int maxv = -1;
		string ans;
		per(i,1,n){
			int x = 0;
			cin >> x >>name;
			if( x > maxv){
				maxv = x;
				ans = name;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
