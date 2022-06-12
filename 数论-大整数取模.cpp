#include<bits/stdc++.h>
using namespace std;
char n[110];
int m = 0; 
int main(){
	while(~scanf("%s %d",n,&m)){
		int len = strlen(n);
		int ans = 0;
		for(int i = 0;i < len;++i){
			ans = (int)(((long long)ans * (10 % m) + n[i] - '0') % m);
		}
		printf("%d\n",ans);
	}
	
	return 0;
} 
