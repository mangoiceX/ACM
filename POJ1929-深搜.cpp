#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX = 20 + 3;
char pic[MAX][MAX];
int idx[MAX][MAX];
int mov[2][3] = { { 0,1,-1}, { 0,1 ,-1} };
int m = 0,n = 0;
int cnt = 0;

void dfs(int u1,int v1){
	
	if(u1 < 0 || u1 >= n || v1 < 0 || v1 >= m)	return ;
	if(pic[u1][v1] == '#' || idx[u1][v1] > 0) return ;
	
	idx[u1][v1] = 1;
	cnt += 1;
	
	for(int du = -1;du <= 1;du++){
		for(int dv = -1;dv <= 1;dv++){
	
			if((du == 1 || du == -1) && dv ==0){
				dfs(u1 + du,v1);
			}
		
			if((dv == 1 || dv == -1) && du ==0){
				dfs(u1,v1 + dv);
			}
		
				
		}
	}
	
} 

int main(){
	
	int u = 0,v = 0;//记录@的位置 
	
	while(scanf("%d %d", &m,&n) == 2 && m && n){
		cnt = 0;
		getchar();
		memset(idx,0,sizeof(idx));
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				scanf("%c",&pic[i][j]);
				if(pic[i][j] == '@' ){
					u = i;//行 
					v = j;//列 
				}
			}
			getchar();
		}
		
		dfs(u,v);
		cout << cnt << endl;
	}

	
	return 0; 
}
