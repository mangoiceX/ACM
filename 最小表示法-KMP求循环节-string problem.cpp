#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
const int maxn = 1e6 + 10; 
string str;
int len = 0;
int nex[maxn];
void make_nex(){//KMP��nex���� 
	int j = 0,k = -1;
	nex[0] = -1;
	while(j <= len){
		if(k == -1 || str[k] == str[j]){
			if(str[k+1] == str[j+1]){
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
int min_rep(){
	int i = 1,j = 0,k = 0;

	while(j < len && i < len){
		k = 0;			//֮ǰ�������д�� 
		while(str[(i+k) % len] == str[(j+k) % len] && k < len){
			++k;
		}
		if(k == len){
			return min(i,j) + 1;
		}
		if(str[(i+k)%len] > str[(j+k)%len]){
			i = max(i+k+1, j+1);
		}else{
			j = max(j + k + 1, i + 1);
		}
	}
	return min(i,j) + 1;
	
}
int max_rep(){
	int i = 1,j = 0,k = 0;
	
	while(j < len && i < len){
		k = 0; 
		while(str[(i+k) % len] == str[(j+k) % len] && k < len){
			++k;
		}
		if(k == len){
			return min(i,j) + 1;
		}
		if(str[(i+k)%len] < str[(j+k)%len]){
			i = max(i+k+1, j+1) ;
		}else{
			j = max(j + k + 1, i + 1);
		}
	}
	return min(i,j) + 1;
	
	
}
int main(){
	while(cin >> str){
		len = str.size(); 
		memset(nex,0,sizeof(nex));
		make_nex();			//֮ǰ���ǣ����ú����ˣ�Ҳ�����˳�ʼ�� 
		int min_pos = min_rep();
		int  max_pos = max_rep();
		int min_times = 0,max_times = 0;
		int r = len - nex[len];//��ѭ���ڵĴ�С 
		//cout << "enm " << r << endl; 
		if(len % r == 0){//�������жϣ�Ҫ���Ǵ�����ѭ����ȫ��ѭ������ɣ��������� 
			min_times = max_times = len / r;
		}else{
			min_times = max_times = 1;
		}
		//cout << min_rep() << endl;
		cout << min_pos << " " << min_times << " " << max_pos << " " << max_times << endl;
	}
	
	
	
	return 0;
}
