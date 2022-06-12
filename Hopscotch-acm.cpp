#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
#include<set> 
#include<algorithm>
using namespace std;
const int maxn = 7;
int map[maxn][maxn];
int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};//ÒÆ¶¯
set<int> st;//´æ´¢½á¹û 

void dfs(int x,int y,int cur,int num){
	
	if(cur == 5){
		if(st.find(num) == st.end()){
			st.insert(num);
		}
		return ;
	}
	
	for(int i = 0;i < 4;++i){
		int tx = x + dx[i],ty = y + dy[i];
		if(tx >= 0 && tx < 5 && ty >= 0 && ty < 5){
			dfs(tx,ty,cur + 1,num * 10 + map[tx][ty]);
		}
	}
}
int main(){
	
	for(int i = 0;i < 5;++i){
		for(int j = 0;j < 5;++j){
			cin >> map[i][j];
		}
	}
	
	for(int i = 0;i < 5;++i){
		for(int j = 0;j < 5;++j){
			dfs(i,j,0,map[i][j]);
		}
	}
	cout << st.size() << endl;
	
	
	return 0;
} 
