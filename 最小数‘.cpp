#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
const int maxn = 2e5;
using namespace std;
int a[10] = {0};
char s[10] = {'0','1','2','3','4','5','6','7','8','9'};
void solve(){
	string ans;
	per(i,1,9){
		if(a[i] > 0){
			ans += s[i];
			--a[i];
			break;
		}
	}
	per(i,0,9){
		while(a[i] > 0){
			ans += s[i];
			--a[i];
		}
	}
	cout << ans << endl;
}
int main(){
	int n = 0;
	cin >> n;
	per(i,1,n){
		cout << "Credibility and Integrity";
		if(i != n){
			cout << " ";
		}else{
			cout << endl;
		}
	}
	
	return 0;
}