#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
const int maxn = 55;

int image[maxn][maxn];

int main(){
	int T = 0,n = 0,m = 0,temp1 = 0,temp2 = 0;
	scanf("%d",&T);
	getchar();
	while(T--){
		char ch;
		temp1 = 0,temp2 = 0;
		scanf("%d %d",&n,&m);
		getchar();
		for(int i = 1;i <= n;++i){
			for(int j = 1;j <= m;++j){
				scanf("%c",&ch);
				if(ch == '0'){
					image[i][j]	= 0;
				}else{
					image[i][j]	= 1;
				}
				
			}
			getchar();
		}
			
		for(int i = 1;i <= n;++i){
			if(image[i][1] == 0){
				temp1++;
			}
			if(image[i][m] == 0){
				temp1++;
			}
		}
		for(int i = 2;i <= m-1;++i){
			if(image[1][i] == 0){
				temp1++;
			}
			if(image[n][i] == 0){
				temp1++;
			}
		}
		
		for(int i = 2;i <= n-1;++i){
			for(int j = 2;j <= m-1;++j){
				if(image[i][j] == 1){
					temp2++;
				}
			}
		}
		if(temp1 == 0){
			printf("0\n");
		}else if(temp2 >= temp1){
			printf("%d\n",temp1);
		}else{
			printf("-1\n");
		}
		
	}
	
	
	return 0;
}
