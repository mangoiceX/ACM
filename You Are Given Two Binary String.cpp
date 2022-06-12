#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
typedef long long LL;
#define INF 1e18
const int maxn = 2e5 + 10;
int n = 0,m = 0; 
char s1[maxn],s2[maxn];
void solve(){
	int len1 = strlen(s1),len2 = strlen(s2);
	int pos1 = 0,pos2 = 0;
	
	rep(i,len2-1,0){
		if(s2[i] == '1'){
			pos2 = i;
			break;
		}
	}
	pos2 = len2 - pos2;
	rep(i,len1-1-pos2+1,0){
		if(s1[i] == '1'){
			pos1 = i;
			break;
		}
	}
	pos1 = len1 - pos1; 
	printf("%d\n",max(pos1 - pos2,0));
}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%s %s",s1,s2);
		solve();
	}
	return 0;
}