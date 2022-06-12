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
	while(j < len2){//是j < m而不是m-1,虽然j <m-1也AC了，j < m不用担心越界 
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
			++ans;	//返回上一次重复的地方 
			j = nex[j];	//相对于KMP-减布花，稍微调一下位置，就对了 
			/*比如样例： 利用对称性，深入理解那个nex[k]的含义便知道了 
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
