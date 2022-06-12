#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<map>
using namespace std;
int swift(string str){
	int len = str.size();
	int sum = 0;
	for(int i = 0;i < len;++i){
		sum += (str[i] - '0')*pow(10,len - i - 1);
	}
	return sum;
}
bool judge(string str){
	int len = str.size();
	for(int i = 0;i < len;++i){
		if( ! ( isdigit(str[i]) ) ){
			return false;
		}
	}
	if(str == "1000"){
		return true;
	}
	if(str != "0" && len >= 1 && len <= 3){
		return true;
	}
	return false; 
}
int main(){
	string m ,n ;
	int flag1 = 0,flag2 = 0;
	cin >> m >> n;
	if(judge(m)){
		flag1 = 1;
	}
	if(judge(n)){
		flag2 = 1;
	}
	if(flag1 == 1){
		cout << m <<  " + ";
	}else{
		cout << "?" <<  " + ";
	}
	if(flag2 == 1){
		cout << n << " = ";
	}else{
		cout << "?" << " = ";
	}
	if(flag1 == 1 && flag2 == 1){
		
		cout << swift(m)+ swift(n) << endl;
	}else{
		cout << "?" << endl;
	}
	
	return 0;
}
