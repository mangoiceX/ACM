#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
const int maxn = 1000 + 10; 
string str;
int len = 0;
int p[2*maxn];
string Manacher(){
	string t = "$#";
	for(int i = 0;i < str.size();++i){
		t += str[i];
		t += "#";
	}
	
	int mx = 0,id = 0,resLen = 0,resCenter = 0;
	for(int i = 1;i < t.size();++i){
		p[i] = mx > i ? min( p[2*id-i] , mx - i) :1;
		while(t[i + p[i]] == t[i - p[i]]){
			++p[i];
		}
		if(i + p[i] > mx){
			mx = i + p[i];
			id = i;
		}
		if(resLen < p[i]){
			resLen = p[i];
			resCenter = i;
		}
	}
	return str.substr( (resCenter - resLen) / 2 ,resLen - 1 );
}

int main(){
	
	while(cin >> str){
		cout << Manacher() << endl;
	}
	
	return 0;
}
