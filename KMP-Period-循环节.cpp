#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;
const int maxn = 1e6 + 10;
//string str,str1;
char str[maxn];
int nex[maxn];
void make_nex(){
	int j = 0,k = -1;
	nex[0] = -1;
	//int len = str.size(); 
	int len = strlen(str);
	while(j < len){
		if(k == -1 || str[k] == str[j]){
			//if(str[k+1] == str[j+1]){
			//	nex[j+1] = nex[k+1];//�����֦�����ص����ص����������ѭ���ڵ�ѭ���ڣ�һ���һ�� 
			//	++j,++k;
		//	}else{
				nex[j+1] = k+1; //ֱ�ӷ��ص������ѭ���ڣ������Ϳ��Լ���1-j��ѭ���� 
				++j,++k;
		//	}
		}else{
			k = nex[k];
		}
	}
}
/*
int kmp(){
	int i = 0,j = 0;
	int len1 = str.size(),len2 = str1.size();
	while(i < len1 && j < len2){
		if(j == -1 || str[i] == str1[j]){
			++i,++j;
		}else{
			j = nex[j];
		}
	}
	if(j == len2){
		return i - j;
	}else{
		return -1;
	}
	
}
*/
//�� cin ��cout �ᳬʱ��scanf,printf����AC������string�ĳ�char 
int main(){
	int n = 0,kase = 0;
//	ios::sync_with_stdio(false);
	//while(cin >> n && n){
	while(scanf("%d",&n) !=	EOF && n){
		//cin >> str;
		scanf("%s",str);
		//cout << str;
		make_nex();
		//cout << "Test case #" << ++kase << endl;
		printf("Test case #%d\n",++kase);
		for(int i = 1;i < n;++i){
			int len = i + 1 - nex[i+1];
			cout << len << endl;
			if( (i+1)%len == 0 && len != (i+1)){
				printf("%d %d\n",i+1,(i+1)/len);
			}
		}
		printf("\n");
	}
	
	
	
	
	return 0;
} 
