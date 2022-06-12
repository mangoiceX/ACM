#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
using namespace std;
const int maxn = 1000000000;
set<int> st;
void dfs(long long sum){//注意sum必须是long long ,int 会溢出，陷入死循环 
	if(sum > maxn){
		return ;
	}
	int x = 4,y = 7;
	st.insert(sum);
	dfs(sum * 10 + x);
	dfs(sum * 10 + y);
}
void pre_solve(){
	dfs(4);
	dfs(7);
}
int main(){
	int n = 0;
	pre_solve();
	
	while(scanf("%d",&n) != EOF){
		set<int>::iterator it = st.begin();
		int cnt = 1;
		for(it = st.begin();it != st.end();it++,++cnt){
			if(*it == n){
				break;
			}
		}
		printf("%d\n",cnt);	
	}	
	
	return 0;
} 
