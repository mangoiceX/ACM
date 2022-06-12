#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 7;
const int size = 5;
int data[maxn][maxn];
set<int> st;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void dfs(int x,int y,int cur,int num){
	if(cur == 5){
		if(st.find(num) == st.end()){
			st.insert(num);
		}
		return ;
	}

	for(int i = 0;i < 4;++i){
		int tx = x + dx[i],ty = y + dy[i];
		if(tx < 0 || tx >= size || ty < 0 || ty >= size){
			continue;
		}
		//num = num * 10 + data[tx][ty];//不能再当前函数过程中改变num的值，
		//因为后续的回溯操作要送到该值 
		dfs(tx,ty,cur + 1,num * 10 + data[tx][ty]);	
	}
	
}
int main(){
	for(int i = 0;i < size;++i){
		for(int j = 0;j < size;++j){
			cin >> data[i][j];
		}	
	}
	
	for(int i = 0;i < size;++i){
		for(int j = 0;j < size;++j){

			dfs(i,j,0,data[i][j]);
		}
	}
	cout << st.size() << endl;
	
	return 0;
}
