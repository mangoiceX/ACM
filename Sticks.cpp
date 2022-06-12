#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
typedef unsigned long long LL;
const int maxn = 100 + 5;
bool vis[maxn];
int data[maxn];
int n = 0;

bool dfs(int pos,int res,int len){
	if(pos == 0 && res == 0){//全部拼接成功 
		return true;
	}
	if(pos != 0 && res == 0){//一根拼接成功 
		res = len;
	}
	for(int i = n - 1;i >= 0;--i){//先拼长的，可能情况比先拼短的少 
		if(vis[i] == 0 && data[i] <= res){
			vis[i] = 1;
			if(dfs(pos - 1,res - data[i],len)){
				return true;
			}
			vis[i] = 0;
			//不是决定性的剪枝 
			if(vis[i - 1] == 0 && data[i - 1] == data[i]){//如果后面一个长度一样，则不用拼了，restart 
				continue;
			}
			//决定性剪枝 ，长度相同不会重复尝试。 
			if(res == data[i] || res == len){//剩下的刚好拼成一根棍子，但是都没有成功
			//即使后来用更短的多跟棍子替代，也无法成功，所以在此处直接判断现在的拼法没前途，restart
			//因为即使被短棍子替代，后面拼棍子时，还是要用到
			//比如len = 10,data[i]=5，可以被后面的3+2取代，但是后续要成功的话，还是要有x+5=10，
			//来把5这根棍子用掉，所以两种拼法的结果是一样的
			 
				return false;
			}
		}
	}
	return false;
	
}
/*
bool dfs(int pos, int res, int len) {
	if (pos == 0 && res == 0)
		return true;
	if (res == 0)
		res = len;
	for (int i = n - 1; i >= 0; i--){
		if (vis[i] || data[i] > res)
			continue;
		vis[i] = true;
		if (dfs(pos - 1, res - data[i], len))
			return true;
		vis[i] = false;
		if (res == data[i] || res == len)//重要的剪枝，长度相同不会重复尝试。
			return false;
	}
	return false;
}
*/
int main(){
	std::ios::sync_with_stdio(false);
	while(cin >> n && n){
		
		for(int i = 0;i < n;++i){
			cin >> data[i];
		}
		
		sort(data,data + n);
		int sum = 0;
		
		for(int i = 0;i < n;++i){
			sum += data[i]; 
		}
		int  i = 0;
		for(i = data[n - 1]; i <= sum / 2;++i){//确定搜索范围 
			memset(vis,0,sizeof(vis));
			if(sum % i != 0){
				continue;
			}
			if(dfs(n,i,i)){
				cout << i << endl;
				break;
			}
		}
		if(i > sum / 2){
			cout << sum << endl;
		}
	}
	
	
	
	return 0;
} 
