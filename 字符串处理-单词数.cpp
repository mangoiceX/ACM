#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<set>
using namespace std;
const int maxn = 1e4 + 10;

int main(){
	set<string> st;
	string s,str;
	int flag = 0;
	while(getline(cin , s)){
		st.clear();
		if(s == "#"){
			break;
		}
		for(int i = 0;i < s.size();++i){
			str = "";
			flag = 0;
			while(s[i] >= 'a' && s[i] <= 'z'){//��ȡ���� 
				str += s[i];
				flag = 1;
				++i;
			} 
			if(flag == 1){//�е��� 
				st.insert(str);
			}
		}
		cout << st.size() << endl;
	}
	
	
	
	return 0;
}
