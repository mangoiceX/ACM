#include<stdio.h>
const int maxn = 1e2 + 100;
int a[maxn][maxn],b[maxn][maxn],c[maxn][maxn];
int n = 0,m = 0;
void input(){//����
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
	for(int i = 1;i <= m;++i){//��˵ĵ�һ��������к� 
		for(int j = 1;j <= m;++j){//�˵ĵڶ���������кţ��������պþ���m*m�ľ��� 
			for(int k = 1;k <= n;++k){//����˷� 
				c[i][j] += a[i][k]*b[k][j];
			}
		}
	}
}
void show(){//���������� 
	for(int i = 1;i <= m;++i){
		for(int j = 1;j <= m;++j){
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
} 
int main(){
	while(scanf("%d %d",&m,&n) != EOF){
		input();//����a��m*n,����b:n*m 
		solve();
		show();
	}

	return 0;
}
