#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e9
using namespace std;
typedef long long LL;

const int maxn = 2e5 + 10;
// int n = 0,m = 0;
string n;
void solve(){

	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 0;
	// scanf("%d",&T);
	cin >> T;
	while(T--){
		cin >> n;
		int si = n.length();
		int num = 0;
		per(i,0,si-1){
			num = num * 10 + (n[i] - '0');
		}
		string ans;
		per(i,1,num){
			ans += n;
		}
		cout << ans << endl;
		// solve();
	}

	return 0;
}