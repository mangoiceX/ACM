#include<bits/stdc++.h>
using namespace std;
const int maxn = 8e3 ;
bool vis[maxn+100];
int a =0 ,b = 0,c = 0;
void solve(){
	fill(vis,vis+maxn+100,false);
	for(int i = 0;i <= a;++i){
		vis[i] = true;
	}
	for(int i = 0;i <= b;++i){
		for(int j = 0;j <= a;++j){
			if(vis[j]){
				vis[j+i*2] = true;	
			}
		}
	}
	for(int i = 0;i <= c;++i){
		for(int j = 0;j <= a + 2 * b;++j){//化3层循环为两层循环 
			if(vis[j]){//所以要加上这个判断条件，因为是不连续的 
				vis[j+5*i] = true;
			}
		}
	}
	for(int i = 1;i <= 1*a+2*b+5*c+1;++i){
		if(vis[i] == false){
			printf("%d\n",i);
			return ;
		}
	}
}
int main(){
	while(~scanf("%d %d %d",&a,&b,&c) && (a != 0 || b != 0 || c != 0)){
		solve();
	}
	
	return 0;
} 
