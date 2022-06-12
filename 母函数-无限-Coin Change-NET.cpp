#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 250 + 10;
int val[6] = {0,1,5,10,25,50};

int temp[101][maxn],sup[101][maxn];
int ans[maxn];
int n = 0;
void solve(){
	fill(sup[0],sup[0]+101*maxn,0);
	fill(temp[0],temp[0]+101*maxn,0);
	for(int i = 0;i <= 100;++i){
		sup[i][i] = 1;
	}
	for(int i = 2;i <= 5;++i){
		for(int j = 0;j <= maxn-10;++j){
			for(int k = 0;k*val[i] + j <= maxn-10;++k){
				for(int l = 0;l <= 100;++l){
					if(k + l <= 100){//不知道数量如何表示出来，可以直接加一个循环 
						temp[k+l][j+k*val[i]] += sup[l][j];
					}
				}
			}
		}
		for(int k = 0;k <= 100;++k){
			for(int j = 0;j <= maxn-10;++j){
				sup[k][j] = temp[k][j];
				temp[k][j] = 0;
			}
		}
	}
	fill(ans,ans+maxn,0);
	for(int i = 0;i <= 250;++i){
		for(int j = 0;j <= 100;++j){
			ans[i] += sup[j][i]; 
		}
	}
}
int main(){
	solve();
	while(~scanf("%d",&n)){
		printf("%d\n",ans[n]);	
	}
	
	return 0;
}
