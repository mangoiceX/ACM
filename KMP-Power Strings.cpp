#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;
const int maxn = 1e6 + 10;
char str[maxn]; 
int nex[maxn];
//string str;
void make_nex(){
	int j = 0,k = -1;
	nex[0] = -1;
	//int len2 = str.size();
	int len2 = strlen(str);
	while(j < len2){//是j < m而不是m-1,j <m-1也WA了，j < m不用担心越界 
		
		if(k == -1 || str[k] == str[j] ){
			if(str[k+1] == str[j+1]){
				nex[j+1] = nex[k+1];
				++k,++j;
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
	//str = " ";
	//cout << str << endl;
	//while(scanf("%s",s) != EOF && s[0] != '.'){
	while(scanf("%s",str) != EOF ){
	//while(cin >> str && str[0] != '.'){
		if(str[0] == '.'){
			break;
		}
		memset(nex,0,sizeof(nex));
		make_nex();
		//int len = str.size();
		
		int len = strlen(str);
		int ans = len - nex[len];//循环节的大小 
		if(len % ans == 0 && len / ans > 1){
			printf("%d\n",len/ans);
		}else{
			printf("1\n");
		}
		
		//cout << len/ans << endl;
		
	}
	
	
}
