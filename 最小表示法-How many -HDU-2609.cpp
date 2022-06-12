#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector> 
using namespace std;
const int maxn = 1e2 + 10; 
///string str[maxn];
char str[maxn],str1[maxn];

int min_rep(char *s){	//��С��ʾ�� 
	int i = 1,j = 0,k = 0;
	int len = strlen(s);
	while(i < len && j < len){
		k = 0;
		while(s[(i + k) % len] == s[(j + k) % len] && k < len){
			++k;
		}
		if(k == len ){
			return min(i , j);
		}
		if(s[(i + k) % len] > s[(j + k) % len]){
			i = max( i + k + 1, j + 1);
		}else{
			j = max(j + k + 1, i + 1);
		}
	}
	return min(i ,j);
	
} 


int main(){
	int n = 0;
	vector<string> st;
	while(scanf("%d",&n) != EOF && n){
		st.clear();
		for(int i = 1;i <= n;++i){
			scanf("%s",str);
			int len1 = strlen(str);
			int pos = min_rep(str);
			
			for(int j = 0;j < len1;++j){//����С��ʾ����ʼ��ת�� 
				str1[j] = str[(pos+j) % len1];//���ת������ 
			}
			//printf("em %s\n",str1);
			string s1(str1);//��charת��Ϊstring 
			st.push_back(s1);
		}
		sort(st.begin(),st.end());//�����ֵ������� 
		int ans = 1;
		for(int i = 1;i < n;++i){//ͳ�Ʋ�ͬ�ĸ��� 
			if(st[i] != st[i-1]){//����string������������ 
				++ans;
			}
		}
		printf("%d\n",ans);
	}	
	
	
	return 0;
}
