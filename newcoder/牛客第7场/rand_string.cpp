#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
typedef long long LL;
#define INF 1e18

int main(){
	int T = 0;
	srand(time(NULL));
	T = rand() % 30 + 1;
	printf("%d\n",T);
	while(T--){
		int len = rand() % 20 + 1;
		per(i,1,len){
			printf("%d",rand()%2);
		}
		puts("");
	}


	return 0;
}