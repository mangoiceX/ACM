#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
char str[maxn];
int n = 0;
void solve(){
	for(int i = 1;i < n;++i){
		if(str[i] != str[i-1]){
			printf("YES\n");
			printf("%c%c\n",str[i-1],str[i]);
			return ;
		}
	}
	printf("NO\n");
}
int main(){
	while(~scanf("%d",&n)){
		scanf("%s",str);
		solve();
	}
	
	return 0;
} 
