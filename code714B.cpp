#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
void solve(string str1){
 	size_t len = str1.size();
	size_t flag = len; 
	for(size_t i = 0;i < len ;i++){	//找到第一个2的位置	
		if(str1[i] == '2'){
			flag = i;
			break;//
		}
	}
		
	for(size_t j = 0;j < flag;j++){//输出第一个2前面的所有0 
			if(str1[j] == '0'){//
				cout << str1[j];
			}
			
		}
		for(size_t j = 0;j < flag;j++){  //然后输出第一个2前面的所有1
			if(str1[j] == '1'){//
				cout << str1[j];
			}	
		}
		
		for(size_t j = flag+1;j<len;j++){//然后输出第一个2后面的所有1
			if(str1[j] == '1'){
				cout << str1[j];
			}
		}
	
	for(size_t j = flag;j < len;j++){
			if(str1[j] == '0' || str1[j] == '2'){
				cout << str1[j];
			}
		}
	
	
}


int main(){
	string str;
	cin >> str;
	solve(str);
	
	
	
	return 0;
} 
