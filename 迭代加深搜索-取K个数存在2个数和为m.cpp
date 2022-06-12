/*
含n个不同整数的数组A和整数m。从A中任意取出k个整数，其中必有两个整数之和等于m。
求k的最小值。编写程序并打印结果
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
int A[maxn+10];
int n = 0,m = 0;
int maxd = 0;
bool check(int *a){//检验maxd个数是否有两个数和为m 
	map<int,int> mp;
	int cnt = 0;
	bool flag = (m % 2 == 0 ? true : false);//m是奇数，特殊处理，没有m/2,因为/是地板除 
	for(int i = 1;i <= maxd;++i){
		mp[a[i]] = 1;
		if(a[i] == m/2){
			++cnt;
		}
	}
	if(cnt >= 2 && flag){//注意a[i] == m/2的情况,m要是偶数，特别处理 
		return true;
	}
	for(int i = 1;i <= maxd;++i){
		if(flag == true && a[i] == m/2){//注意a[i] == m/2的情况,特别处理
			continue;
		}
		if(mp.find(m-a[i]) != mp.end()){//注意a[i] == m/2的情况 
		//if(a[i] != m/2 && mp.count(m-a[i]) == 1){
			return true;
		}
	}
	return false;
}
bool dfs(int depth,int* ans,int cnt){
	if(depth == n){//没有maxd个数，不符合要求 
		if(cnt < maxd){
			return true;
		}
	}
	if(cnt == maxd){//选了maxd个数，检验 
		return check(ans);
	}
	//if(cnt + n - depth < maxd){//最理想化剪枝，及时后面的数全部选择也无法选择出maxd个数 
	//	return true;
	//}
	ans[cnt+1] = A[depth+1];
	if(dfs(depth+1,ans,cnt+1) == false){//只要有一个组合不满足要求就一直返回false 
		return false;
	}
	if(dfs(depth+1,ans,cnt) == false){//不选择这个数 
		return false;	
	}
	return true;//所有组合都满足要求，就返回true 
}
int main(){ 
	while(~scanf("%d",&n)){
		for(int i = 1;i <= n;++i){
			scanf("%d",&A[i]);
		}
		scanf("%d",&m);
		sort(A+1,A+1+n);
		bool flag = false;
		int ans[maxn+10];
		for(maxd = 2;maxd <= n;++maxd){//迭代加深搜索 
			if(dfs(0,ans,0)){
				printf("%d\n",maxd);
				flag = true;
				break;
			}
		
		}
		if(flag == false){
			printf("There is no answer!!!\n");
		}
	}
	
	return 0;
}
