#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
/*
���⣺�������ǰ׺���ֵĴ�����

�õ������ʱ������û��ͷ���ġ���Ȼ��DP���Ȿ������һ����ѧ���ټ������⻹���õ�KMP�㷨���ַ�������
���������뵽��DPȥ���(��ȻҲ������С����̫����)��������dp[i]��ʾiǰ�������ֵ�ǰ׺�ظ��Ĵ�
������ΪKMP�㷨��next����Ķ��壬next[i]������iǰ��ǰ׺�ظ�����һ��λ�ã�
���˵�����ܲ���ô����⣬����С������һ����ϸ�Ľ��ͣ��ͱ���aabaabaabaab����ַ�����
next[6] = 3,next[9] = 6,next[12] = 6����Ϊnext�����ʾ����ǰ׺��׺���ƥ�䳤�ȣ�
�������i-next[i]����ǰ׺�ĳ��ȣ���next[i]��ֵ����������ַ�������һ���ظ������ǰ׺��λ�á�
˵�������������Ҫ��С�࣬����ʲô���أ��õ�������ҾͿ���д��һ��״̬ת�Ʒ����ˣ�
dp[i] = dp[next[i]] + 1;DP�������������ѧ�����뵽������Ļ������Ϳ���dp����һ���Ӿ�����ˡ�


*/ 

using namespace std;
const int maxn = 2e5 + 10;
//string str,str1;
char str[maxn];
int nex[maxn];
int dp[maxn],n = 0; 
void make_nex(){
	int j = 0,k = -1;
	nex[0] = -1;
	//int len = str.size(); 
	//int len = strlen(str) - 1;
	while(j < n){
		if(k == -1 || str[k] == str[j]){
			//if(str[k+1] == str[j+1]){
			//	nex[j+1] = nex[k+1];//�����֦�����ص����ص����������ѭ���ڵ�ѭ���ڣ�һ���һ�� 
			//	++j,++k;
		//	}else{
			nex[j+1] = k+1; //ֱ�ӷ��ص������ѭ���ڣ������Ϳ��Լ���i-j��ѭ���� 
			++j,++k;
		//	}
		}else{
			k = nex[k];
		}
	}
}

void get_next(){
	int k = -1;
	nex[1] = 0;
	for(int i = 2;i <= n;++i){
		while(k != 0 && str[i] != str[k+1]){
			k = nex[k];
		}
		if(str[k+1] == str[i]){
			++k;
		}
		nex[i] = k;
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
	int T = 0;
//	ios::sync_with_stdio(false);
	//while(cin >> n && n){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		//cin >> str;
		scanf("%s",str);
		//cout << str;
		make_nex();
		//get_next();
		//cout << "Test case #" << ++kase << endl;
		//printf("Test case #%d\n",++kase);
		//for(int i = 0;i <= n;++i){
	//		cout << nex[i] << " ";
	//	}
	//	cout << endl;
		int ans = 0;
		memset(dp,0,sizeof(dp));
		for(int i = 1;i <= n;++i){
			dp[i] += (dp[nex[i]] + 1) % 10007;
			//cout << dp[i] << " ";	
			ans = (ans + dp[i]) % 10007;
		}
	//	for(int i = 0;i <= n;++i){
		//	cout << dp[i] << " ";
	//	}
		//cout << endl;
		printf("%d\n",ans);
	}
	
	
	
	
	return 0;
} 
/*
int main(){
	int T = 0;
//	ios::sync_with_stdio(false);
	//while(cin >> n && n){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		//cin >> str;
		scanf("%s",str+1);
		//cout << str;
		//make_nex();
		get_next();
		//cout << "Test case #" << ++kase << endl;
		//printf("Test case #%d\n",++kase);
		//for(int i = 1;i <= n;++i){
		//	cout << nex[i] << " ";
	//	}
		//cout << endl;
		int ans = 0;
		memset(dp,0,sizeof(dp));
		for(int i = 1;i <= n;++i){
			dp[i] += (dp[nex[i]] + 1) % 10007;	
			ans = (ans + dp[i]) % 10007;
		}
		printf("%d\n",ans);
	}
	
	
	
	
	return 0;
} 
*/
