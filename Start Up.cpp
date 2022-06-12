#include<iostream> 
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#include<map>
#include<queue>
using namespace std;
const int maxn = 100000 + 10;
string str;
bool judge(string s){
	int len = s.size();
	
	for(int i = 0; i< len;++i){
		if(s[i] != 'A' && s[i] != 'H' && s[i] != 'I' && s[i] != 'M' && s[i] != 'O' &&
		s[i] != 'T' && s[i] != 'U' && s[i] != 'V' && s[i] != 'W' && s[i] != 'X' && s[i] != 'Y'){
			return false;
		}
	}
	
	for(int i = 0;i < len;++i){
		if(s[i] != s[len - 1 - i]){
			return false;
		}
	}
	return true;
}

int main(){
	
	cin >> str;
	if(judge(str)){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	
	
	
	return 0;
}
