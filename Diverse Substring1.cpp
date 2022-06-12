#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
typedef long long LL;
int n = 0;
int a[30];
char str[maxn];
void solve(){
	for(int i = 0;i < n;++i){
		for(int j = i+1;j < n;++j){
			char ans[maxn];
			int cnt = 0;
			fill(a,a+27,0);
			for(int k = i;k <= j;++k){
				ans[cnt++] = str[k];
				a[str[k] - 'a']++;
				if(a[str[k] - 'a'] > (j-i+1)/2){
					break;
				}
				if(k == j){
					ans[cnt++] = '\0';
					printf("YES\n");
					printf("%s\n",ans);
					return ;
				}
			}
			
		}
	}
	printf("NO\n");
}
int main(){
	while(~scanf("%d",&n)){
		getchar(); 
		scanf("%s",str);
		solve();
	}
	
	return 0;
}
