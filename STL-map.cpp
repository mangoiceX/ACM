#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
using namespace std;
const int maxn = 1e4 + 100;

int main(){
	//
	map<int,const char*> mp;
	//����Ԫ�� 
	mp.insert(make_pair(1,"ONE"));
	mp.insert(make_pair(10,"TEN"));
	mp[100] = "HUNDRED";
	//����Ԫ�� 
	map<int,const char*>::iterator it;
	it = mp.find(1);
	puts(it->second);
	
	it = mp.find(2);
	if(it == mp.end()){
		puts("not found\n");//puts֮����ƶ����� 
	}else{
		puts(it->second);
	}
	
	puts(mp[10]);
	mp.erase(10);
	//
	for(it = mp.begin();it != mp.end();it++){
		printf("%d: %s\n",it->first,it->second);
	}
		
	return 0;
}
 
