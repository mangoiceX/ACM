#include<bits/stdc++.h>
using namespace std;
unsigned int SA, SB, SC;
int mod = 0,n = 0;
const int maxn = 2e7;
int a[maxn+1];
unsigned int Rand(){
	SA ^= SA << 16;
	SA ^= SA >> 5;
	SA ^= SA << 1;
	unsigned int t = SA;
	SA = SB;
	SB = SC;
	SC ^= t ^ SA;
	return SC;
}
void solve(){
	int s = 1;
	int ans = 0;
	for(int i = 1;i <= n;++i){
		while(i <= n && a[i] >= (i - s)){
			++ans;
			++i;
		}
		s = i;
		ans += 3;
	}
	cout << ans << endl;
}
int main(){
	cin>>n>>mod>>SA>>SB>>SC;
	for(int i = 1;i <= n;++i){
	 	a[i] = Rand() % mod + 1;	
	}
	for(int i = 1;i <= n;++i){
		printf("%d ",a[i]);
	}
	puts("");
	solve();
}
/*
5 5
5 6 4
4 4 2 5 1
7
*/
