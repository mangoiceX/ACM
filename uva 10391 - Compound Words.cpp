#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
const int maxn = 120000;
using namespace std;

map<string,bool> a_hash;
string str[maxn];

int main(){
	int cnt = 0;
	a_hash.clear();
	
	while(cin >> str[cnt]){
	//while(scanf("%s",&str[cnt]) != -1)
		a_hash[str[cnt]] = 1;
		cnt++;
	}
	
	string a,b;
	for(int i = 0;i < cnt;i++){
		for(size_t j = 0;j < str[i].size();j++){
			
			a = str[i].substr(0,j);
			if(a_hash[a] != 1){
				continue;
			}
			
			b = str[i].substr(j);
			if(a_hash[b] != 1){
				continue;
			}
			
			cout << str[i] << endl;
			break;
		}
	}
	
	
	return 0;
}

