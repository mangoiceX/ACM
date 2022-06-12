#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int m = 0;
const int maxn = 1000;
void solve(){
	int ans = 5*(m - 32)/9;
	printf("Celsius = %d\n",ans);
}
int main(){
	while(~scanf("%d",&m)){
		solve();
	}
	
	
	return 0;
}
