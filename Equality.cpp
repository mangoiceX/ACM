#include<bits/stdc++.h>
#define INF 1e6 
using namespace std;
const int maxn = 1e5 + 100;
typedef long long LL;
char s[maxn];
int a[30];
int n = 0,k = 0;
int main(){
	while(scanf("%d %d",&n,&k) != EOF){
		scanf("%s",s);
		memset(a,0,sizeof(a));
		
		for(int i = 0;i < strlen(s);++i){
			++a[s[i] - 'A'];
		}
		sort(a,a+k);
		printf("%d\n",a[0]*k);
	}
	
	return 0;
}
