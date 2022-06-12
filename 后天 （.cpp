#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f 
using namespace std;
const int maxn = 1e5;
int n = 0;
int main(){
	while(~scanf("%d",&n)){
		printf("%d\n",((n+2) % 7 == 0 ? 7 : (n+2)%7));
	}
	
	
	return 0;
}
