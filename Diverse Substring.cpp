#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
typedef long long LL;
int n = 0;
//int a[maxn];
//char b[maxn];
char str[maxn];
/*
void solve(){
	fill(a,a+maxn,0);
	//int cnt = 0;
	set<int> st;
	for(int i = 0;i < strlen(str);++i){
		a[str[i]-'a']++;
		if(a[str[i]-'a'] > n/2){
			st.insert(str[i]-'a');
		}
	}
	for(int i = 0;i < strlen(str);++i){
		if(st.find(str[i] - 'a') == st.end()){
			printf("YES\n");
			printf("%c\n",str[i]);
			return ;
		}
	}
	printf("NO\n");
}
void solve(){
	
	for(int i = 0;i < n;++i){
		char ans[maxn];
		fill(a,a+maxn,0);
		int cnt = 0;
		for(int j = i;j < n;++j){
			ans[cnt++] = str[j];
			a[str[j] - 'a']++;
			if(a[str[j] - 'a'] > (n-i+1)/2){
				break;
			}
			if(a[str[j] - 'a'] > (j-i)/2){
				continue;
			}
			
		}
	}
}
*/
void solve(){
	set<int> st[maxn];
	for(int i = 0;i < n;++i){
		for(int j = 0;j <= i;++j){
			st[i].insert(str[j]-'a');
		}
	}
	for(int i = 0;i < n;++i){
		for(int j = i+1;j < n;++j){
			set<int> st1 = st[j];
			set<int>::iterator it;
			for(it = st[i].begin();it != st[i].end();it++){
				st1.erase(*it);
			}
			if(st1.size() <= 2){
				continue;
			}else{
				printf("YES\n");
				for(int k = i;k <= j;++k){
					printf("%c",str[k]);
				}
				printf("\n");
				return ;
			}
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
