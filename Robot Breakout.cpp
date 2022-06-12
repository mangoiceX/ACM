#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 10;
const LL mod = (1e9 + 7);
int n = 0,m = 0,k = 0;
int a[10];
priority_queue<int> st1,st2,st3,st4;
int ansx = 0,ansy = 0;
void han(){
	// if(a[3] == 1 && a[4] == 1 && a[5] == 1 && a[6] == 1){
	// 	continue;
	// }else if(a[3] == 0 && a[4] == 1 && a[5] == 1 && a[6] == 1){
	// 	st1.push(a[1]);
	// }else if(a[3] == 1 && a[4] == 0 && a[5] == 1 && a[6] == 1){
	// 	st1.push(a[2]);
	// }else if(a[3] == 1 && a[4] == 1 && a[5] == 0 && a[6] == 1){
	// 	st1.push(a[1]);
	// }else if(a[3] == 1 && a[4] == 1 && a[5] == 1 && a[6] == 0){
	// 	st1.push(a[2]);
	// }else if(a[3] == 0 && a[4] == 0 && a[5] == 1 && a[6] == 1){

	// }
	if(a[3] == 0){
		st1.push(a[1]);
	}
	if(a[4] == 0){
		st2.push(a[2]);
	}
	if(a[5] == 0){
		st3.push(a[1]);
	}
	if(a[6] == 0){
		st4.push(a[2]);
	}
}
void solve(){

}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		// init();
		per(i,1,6){
			scanf("%d",&a[i]);
			han();
		}
		int x1 = st1.top(),y2 =st2.top(),x3 = st3.top(),y4 = st4.top();
		if(x1 > x3 || y2 < y4){
			puts("0");
		}else{
			printf("%d %d\n",(x1 + x3)/2 ,(y2 + y3)/2);
		}
	}

	return 0;
}