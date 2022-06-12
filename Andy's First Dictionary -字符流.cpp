#include<iostream>
#include<set>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;

int main(){
	set<string> st;
	string s,buf;
	while(cin >> s){
		int size = s.size();
		for(int i = 0;i < size;++i){
			if(isalpha(s[i])){
				s[i] = tolower(s[i]);
			}else{
				s[i] = ' ';
			}
		}
		stringstream str(s);
		while(str >> buf){
			st.insert(buf);
		}
	}
	for(set<string>::iterator it = st.begin();it != st.end();++it){
		cout << *it << '\n';
	}
	
	return 0;
} 
