#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
const int maxn = 1e5 + 10;
int nex[maxn];
string str1,str2;
int n = 0,k = 0;
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

int main(){
	
	while(cin >> n >> k){
		cin >> str2;
		memset(nex,0,sizeof(nex));
		make_nex();
		str1 = str2;
		for(int j = 0;j < k - 1;++j){
			for(int i = nex[n];i < n;++i){
				str1 += str2[i];
			}
		}
		cout << str1 << endl;
	}
	return 0;
}
