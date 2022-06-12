#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;
const int maxn = 1e5 + 10;
int nex[maxn];
string str1,str2;

void make_nex(){
	int j = 0,k = -1;
	nex[0] = -1;
	int len = str2.size();
	while(j < len){
		if(k == -1 || str2[k] == str2[j]){
			if(str2[k+1] == str2[j+1]){
				nex[j+1] = nex[k+1];
				++j,++k; 
			}else{
				nex[j+1] = k+1;
				++j,++k;
			}
		}else{
			k = nex[k];
		}
	}
	
}
bool kmp(){
	int i = 0,j = 0;
	//size_t i = 0,j = 0;//出现神仙数 
	int len1 = str1.size(),len2 = str2.size();//必须将size_t类型转化为int类型，否则比较时，会出错 
	while(i < len1 && j < len2){
	//while(i < str1.size() && j < str2.size()){//出错，只比较一次就退出了 
		if(j == -1 || str1[i] == str2[j]){
			++i,++j;
		}else{
			j = nex[j];
		}
	}
	//cout << i << " " << j << endl;
	if(j == len2){
		return true;
	}else{
		return false;
	}
}
int main(){
	
	while(cin >> str1 >> str2){
		memset(nex,0,sizeof(nex));
		if(str1.size() < str2.size()){
			cout << "no" << endl;
			//cout << "1" << endl;
			continue;
		}
		str1 = str1 + str1;
		make_nex();
		if(kmp()){
			cout << "yes" << endl;
		}else{
			cout << "no" << endl;
		}
		
		
	}
	
	
	return 0;
} 
