#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<set>
#define INF 2e5 + 100
using namespace std;
string s,t;
int n = 0,m = 0;
bool judge(){
	int pos = 0,f = 0;
	int i = 0,j = 0;
	for(i = 0;i < s.size();++i){
		if(s[i] == '*'){
			pos = i;
			f = 1;
			break;
		}
	}
	if(f == 0){
		if(s.size() != t.size()){
			return false;
		}
		for(i = 0;i < s.size();++i){
			if(s[i] != t[i]){
				return false;
			}
		}	
	}
	int flag = 0;
	for(i = 0;i < pos;++i){
		if(s[i] != t[i]){
			return false;
		}
	}
	if(f == 1){
		flag = pos;	
	}else{
		flag = -1;
		return true;
	}
	
	for(i = s.size() - 1,j = t.size() - 1;i > (f == 1?pos : -1);--i,--j){
		if( j < flag || s[i] != t[j] ){
			return false;
		}
	}
	return true;
}
int main(){
	while(cin >> n >> m && n && m){
		cin >> s >> t;
		if(judge()){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
	
	
	
	return 0;
} 
