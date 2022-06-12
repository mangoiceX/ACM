#include<stdio.h>
const int maxn = 1e2 + 100;
int a[maxn][maxn],b[maxn][maxn],c[maxn][maxn];
int n = 0,m = 0;
void input(){//输入
	for(int i = 1;i <= m;++i){
		for(int j = 1;j <= n;++j){
			scanf("%d",&a[i][j]);
		}
	}	
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= m;++j){
			scanf("%d",&b[i][j]);
		}
	}	
}
void solve(){
	for(int i = 1;i <= m;++i){//相乘的第一个矩阵的行号 
		for(int j = 1;j <= m;++j){//乘的第二个矩阵的列号，结果矩阵刚好就是m*m的矩阵 
			for(int k = 1;k <= n;++k){//矩阵乘法 
				c[i][j] += a[i][k]*b[k][j];
			}
		}
	}
}
void show(){//输出结果矩阵 
	for(int i = 1;i <= m;++i){
		for(int j = 1;j <= m;++j){
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
} 
int main(){
	while(scanf("%d %d",&m,&n) != EOF){
		input();//矩阵a：m*n,矩阵b:n*m 
		solve();
		show();
	}

	return 0;
}
