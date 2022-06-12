#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
const int maxn = 100010;
typedef long long LL;
int data[maxn],n = 0;
LL ans = 0;
void solve(){
	for(int i = 1;i <= n;++i){
		int temp = INF;
		for(int size = 0;i + size <= n;++size){	
			temp = temp & data[i + size];
			ans = ans + temp;
		}
	}	
}
int main(){
	int T = 0;
	scanf("%d",&T);
	getchar();
	while(T--){
		ans = 0;
		scanf("%d",&n);
		getchar();
		for(int i = 1;i <= n;++i){
			scanf("%d",&data[i]);
		}
		solve();
		printf("%lld\n",ans);
	}
	

	
	return 0;
} 
