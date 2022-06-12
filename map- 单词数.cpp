#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
using namespace std;
const int maxn = 1e4 + 10;
//map<string,int> mp;
//string str;
char str[maxn];
char b[300][20];
char ch[30];
//string ch;
int main(){

	//while(cin >> str && str[0] != '#'){
	while(gets(str) && strcmp(str,"#") != 0){
		int ans = 0;
		int len = strlen(str);
		int pos = 0;
		while(pos < len){
			sscanf(str + pos,"%s",ch);
			//ch[ch.size()] = '\0';
			pos += strlen(ch) + 1;
			//printf("oo %d\n",mp["you"]);
			//if(mp[ch] != 1){
			//	++ans;
		//	}
			//printf("em  %s\n",ch);
		//	mp[ch] = 1;
			int i = 0;
			for(i = 0;i < ans;++i){
				if(strcmp(ch,b[i]) == 0){
					break;
				}
			}
			if(i == ans){
				strcpy(b[ans++],ch);
			}
		}
		//cout << ans << endl;
		printf("%d\n",ans);
	}
	
	
	return 0;
} 
