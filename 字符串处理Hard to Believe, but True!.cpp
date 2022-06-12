#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string> 
#include<cstring>
#include<set>
#include<cmath>
using namespace std;
const int maxn = 1000 + 10;
string s,s1,s2,s3;
int swift(string str){
	int sum = 0;
	int len = str.size();
	int i = len - 1;
	while(str[i] == '0'){//ȥ��ǰ���0 
		--i;
	}
	while(i >= 0){
		sum += ( str[i] - '0') * pow(10,i);
		--i;			//���Ǹı������ˣ�����������ѭ�� 
	}
	return sum;
}
int main(){
	while(cin >> s){
		s1 = s2 = s3 = "";
		int pos1 = 0, pos2 = 0;
		for(int i = 0;i < s.size();++i){//�ҳ�+��=�ŵ�λ�� 
			if(s[i] == '+'){
				pos1 = i;
			}
			if(s[i] == '='){
				pos2 = i;
			}
		}
		//cout <<"em " << pos1 << " "<< pos2 << endl; 
		for(int i = 0;i < pos1;++i){//��ȡ3������ 
			s1 += s[i];
		} 
		//cout << s1 << endl;
		for(int i = pos1+1;i < pos2;++i){
			s2 += s[i];
		}
		//cout << s2 << endl;
		for(int i = pos2+1;i < s.size();++i){
			s3 += s[i];
		}
		//cout << s3 << endl;
		if(swift(s1) + swift(s2) == swift(s3)){
			cout << "True" << endl;
		}else{
			cout << "False" << endl;
		}

	}

	return 0;
}
