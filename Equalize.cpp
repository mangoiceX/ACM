#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 100;
string s1,s2;
int n = 0;
int main(){
	while(cin >> n){
		cin >> s1 >> s2;
		s1 += "9";
		s2 += "9";
		int ans = 0;
		for(int i = 0;i < n;++i){
			//cout << i << endl;
			if((s1[i] == '0' && s2[i] == '1') && (s1[i+1] == '1' && s2[i+1] == '0')){
				ans += 1;
				i += 1;
				continue;
			}
			if((s1[i] == '1' && s2[i] == '0') && (s1[i+1] == '0' && s2[i+1] == '1')){
				ans += 1;
				i += 1;
				//cout << "en "<<i << endl;
				continue;
			}
			if(s1[i] != s2[i]){
				ans += 1;
			}
		}	
		cout << ans << endl;

	}
	return 0;
} 
