#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctype.h>

using namespace std;
bool judge(char *str,int len){
	
	if(str[0] != '_' && !isalpha(str[0])){
		return false;
	}
	//int flag = 0;//����Ƿ��пո� 
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
	//cin >> n; //cin֮��Ҫ���˵����з� 
	//getchar();		//	ר��������ȡ�ϴ�����Ļس����� 
	scanf("%d*c",&n);//���Թ��˵����з�������Ҫgetchar
	//fflush(stdin);//������������������ַ� 
	//scanf("%d\n",&n);//ʹ��\n���˻س� 
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
