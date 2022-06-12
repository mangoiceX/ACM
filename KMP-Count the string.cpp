#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
/*
题意：输出所有前缀出现的次数。

拿到这题的时候我是没有头绪的。当然，DP问题本来就是一个玄学，再加上这题还得用到KMP算法对字符串进行
处理，很难想到用DP去求解(当然也可能是小编我太渣了)，我们用dp[i]表示i前面所出现的前缀重复的次
数，因为KMP算法中next数组的定义，next[i]就是在i前面前缀重复的上一个位置，
这个说法可能不怎么好理解，这里小编再做一个详细的解释，就比如aabaabaabaab这个字符串，
next[6] = 3,next[9] = 6,next[12] = 6，因为next数组表示的是前缀后缀最大匹配长度，
所以如果i-next[i]就是前缀的长度，而next[i]的值就是在这个字符串中上一次重复到这个前缀的位置。
说到这里可能有人要问小编，这有什么用呢？得到了这个我就可以写出一个状态转移方程了，
dp[i] = dp[next[i]] + 1;DP问题从来都是玄学……想到了这里的话这道题就可以dp迭代一下子就完成了。


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
			//	nex[j+1] = nex[k+1];//这里剪枝，返回到返回到了最近最大的循环节的循环节，一半的一半 
			//	++j,++k;
		//	}else{
			nex[j+1] = k+1; //直接返回到最近的循环节，这样就可以计算i-j的循环节 
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
//用 cin 和cout 会超时，scanf,printf可以AC，但是string改成char 
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
