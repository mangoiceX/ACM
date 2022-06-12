#include<bits/stdc++.h>
using namespace std;
string s;
int t = 0,n = 0;
int id(char ch){
	return ch - 'a';
}
bool judge(){
	for(int i = 0;i < n;++i){
		if(abs(id(s[i]) - id(s[n-1-i])) != 0 &&  abs(id(s[i]) - id(s[n-1-i])) != 2){
			return false;
		}
	}
	return true;
}
int main(){
	cin >> t;
	while(t--){
		cin >> n;
		cin >> s;
		if(judge()){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
	
	
	
	return 0;
}
