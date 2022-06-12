#include<bits/stdc++.h>
using namespace std;
int w = 0,k = 0,h = 0;
void solve(){
	int ans = 0;
	for(int i = 0;i < k;++i){
		ans += ( (w-i*2)*(h-i*2));
		ans -=  (w-(i+1)*2) * (h-(i+1)*2);
		w-= 2;h -= 2;
	}	
	printf("%d\n",ans);
}
	
int main(){
	while(~scanf("%d %d %d",&w,&h,&k)){
		solve();
	}
	return 0;
} 
