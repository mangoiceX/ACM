#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

bool test(string str){
	int num = str.size() - 1;
	
	if(str[num] != 'a' && str[num] != 'o' && str[num] != 'u' && str[num] != 'i' && 
		str[num] != 'e' && str[num] != 'n'){
			return false;
		}
	for(size_t i = 0;i < str.size()-1;i++){
		
		if(str[i] != 'a' && str[i] != 'o' && str[i] != 'u' && str[i] != 'i' && 
		str[i] != 'e' && str[i] != 'n'){
			if(str[i + 1] != 'a' && str[i + 1] != 'o' &&str[i + 1] != 'u' &&
			str[i + 1] != 'i' && str[i + 1] != 'e' ){
				return false;
			}
			
		}
	}
	
	return true;
	
	
}


int main(){
	
	string str;
	cin >> str;
	if(test(str)){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	
	
	
	return 0;
}

