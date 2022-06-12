#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;
const int maxn = 1e5 + 10;
int nex[maxn];
string str1,str2;
int ans = 0;
void make_nex(){
	int j = 0,k = -1;
	nex[0] = -1;
	int len2 = str2.size();
	while(j < len2){//��j < m������m-1,��Ȼj <m-1ҲAC�ˣ�j < m���õ���Խ�� 
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
void  kmp(){
	make_nex();
	int i = 0,j = 0;
	int len1 = str1.size(),len2 = str2.size();
	while(i < len1){
		 
		while(i < len1 && j < len2){
			if(str1[i] == str2[j] || j == -1){
				++i,++j;
			}else{
				j = nex[j];
			}
			
		}
		if(j == len2){
			++ans;	//������һ���ظ��ĵط� 
			j = nex[j];	//�����KMP-����������΢��һ��λ�ã��Ͷ��� 
			/*���������� ���öԳ��ԣ���������Ǹ�nex[k]�ĺ����֪���� 
			AZA
			AZAZAZA
			*/
		}else{
			return ;
		}
		
	}
	
}

int main(){
	int T = 0;
	cin >> T;
	while(T--){
		cin >> str2 >> str1;
		ans = 0;
		memset(nex,0,sizeof(nex));
		make_nex();
		kmp();
		cout << ans << endl;
	}
	
	
}
