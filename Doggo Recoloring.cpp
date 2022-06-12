#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10; 
int n = 0;
string s;
map<char,int> mp;
bool judge(){
	if(n < 2){
		return true;
	}
	mp.clear();
	for(int i = 0;i < n;++i){
		++mp[s[i]];
	}
	map<char,int>::iterator it = mp.begin();
	for(it = mp.begin();it != mp.end();it++){
		if(it->second >= 2){
			return true;
		}
	}
	return false;
}
int main(){
	
	while(cin >> n){
		cin >> s;
		if(judge()){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}
	
	
	return 0;
}
