#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctype.h>

using namespace std;
bool judge(char *str,int len){
	
	if(str[0] != '_' && !isalpha(str[0])){
		return false;
	}
	//int flag = 0;//标记是否有空格 
	for(int i = 1;i < len;i++){
		if(str[i] != '_' && !isalpha(str[i]) && !isalnum(str[i])){
			return false;
		}
	}
	return true;
	
	
	
}

int main(){
		
	int n = 0;
	char str[100];
	//cin >> n; //cin之后要过滤掉换行符 
	//getchar();		//	专门用来读取上次输入的回车符号 
	scanf("%d*c",&n);//可以过滤掉换行符，不需要getchar
	//fflush(stdin);//清空输入流缓冲区的字符 
	//scanf("%d\n",&n);//使用\n过滤回车 
	for(int i = 0;i < n;i++){
		 gets(str);
		//scanf("%s[^\n]",str);
		 int len = strlen(str);
		 if(judge(str,len)){
		 	printf("yes\n");
		 }else{
		 	printf("no\n");
		 }
		 
		 
	}
	
	
	return 0;
} 
