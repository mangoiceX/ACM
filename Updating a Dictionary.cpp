#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<cstring>
#include<algorithm>
const int maxn = 1000 + 10;
using namespace std;
typedef long long LL;
map<char,LL> mp1,mp2;

int main(){
	
	int t = 0;
	cin >> t;
	string str1,str2;
	for(int i = 0;i < t;++i){
		cin >> str1;
		for(size_t i = 0;i < str1.size();++i){
			if(isalpha(str1[i])){
				mp1[str1[i]] = 1;
			}
		}
		cin >> str2;
		for(size_t i = 0;i < str2.size();++i){
			if(isalpha(str2[i])){
				mp2[str2[i]] = 1;
			}
		}
		map<string,LL>::iterator it1,it2;
		int flag1 = 0,time = 0,flag2 = 0,flag3 = 0;
		if(!mp1.empty()){
			for(it1 = mp1.begin();it1 != mp1.end();++it1){
				flag1 = 0;
				for(it2 = mp2.begin();it2 != mp2.end();++it2){
					if(it1->first == it2->first){
						flag1 = 1;
						break;
					}
				}
				
				if(flag1 == 0){
					++time;
					flag3  = 1;
					if(time == 1){
						cout << "-";
					}
					cout << it1->first;
					if(it1 < mp1.end() - 1){
						cout << ",";
					}
				}
			}
			cout << "\n";
		}
		time = 0;
		if(!mp2.empty()){
			for(it2 = mp2.begin();it2 != mp2.end();++it2){
				flag2 = 0;
				for(it1 = mp1.begin();it1 != mp1.end();++it1){
					if(*it1 == *it2){
						flag2 = 1;
						break;
					}
				}
				
				if(flag2 == 0){
					++time;
			
					if(time == 1){
						cout << "+";
					}
					cout << it2->first;
					if(it1 < mp2.end() - 1){
						cout << ",";
					}
				}
			}
			cout << "\n";
		}
		if(flag3 == 0){
			cout << "No changes" << endl;
		}
		
	}
	
	
	return 0;
}
