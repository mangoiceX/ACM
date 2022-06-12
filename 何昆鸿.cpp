#include<iostream>
#include<cstring>
#include <algorithm>
using namespace std;

int dfs(int*t[201], int m, int* mark , int v, int minv){
	mark[v] = 1;
	if(v == m){
		return minv;
	}else{
		for(int i = 1; i <= m; i++){
			if((mark[i] == 0) && t[v][i] > 0){
				int d = dfs(t, m, mark, i, min(minv,t[v][i]));
				if(d > 0){
					t[v][i] = t[v][i] - d;
					t[i][v] = t[i][v] + d;
					return d;
				}
			}
		}	
	}
	return 0;
}


int main(){
	int n, m;
	int* t[201];
	int *min = new int;
	int mark[201] = {0};
	int si,ei,ci;
	long long maxflow;
	for (int i = 0; i < 201; i++){
		t[i] = new int[201];
	}

	while(cin >> n){
		cin >> m;
		for (int i = 0; i < 201; i++){
			for (int j = 0; j < 201; j++){
				t[i][j] = 0;
			}
		}
		
		memset(mark,0,sizeof(mark));
		for(int i = 0; i < n; i++){
			cin >> si >> ei >> ci;
			t[si][ei] += ci;
		}
		
		
		int f = 10000000;
		
		maxflow = 0;
		while(true){
			int f = dfs(t,m,mark,1,10000000);
			maxflow = maxflow + f;
			if(f <= 0){
				break;
			}
			for(int i = 1; i <= m; i++){
				mark[i] = 0;
			}
		}
		
		cout << maxflow << endl;;
	}
}
