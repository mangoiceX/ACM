#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#define INF  1e5
using namespace std;
const int maxn = 1000 + 100;
int n = 0;
struct Node{
	int biao;
	int num;
};
Node data[maxn];
bool judge(){
	for(int i = 1;i <= n;++i){
		if(data[i].num >= 2){
			//cout << i << " ";
			printf("%d ",i);
			return false;
		}
	}
	return true;
}
void solve(int p){
	++data[p].num;
	int t = p;
	while(judge()){
		int aim = data[t].biao;
		++data[aim].num;
		t = aim;
	}
}
void dfs(int p){
	++data[p].num;
	if(data[p].num >= 2){
		printf("%d ",p);
		return ;
	}
	dfs(data[p].biao);
}
int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;++i){
		//cin >> data[i].biao;
		scanf("%d",&data[i].biao);
	}
	for(int i = 1;i <= n;++i){
		dfs(i);
		for(int j = 1;j <= n;++j){
			data[j].num = 0;
		}
	}
	
	
	
	return 0;
}
