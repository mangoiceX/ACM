#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int n = 0,m = 0;
int a[maxn],b[maxn];
int main(){
	while(~scanf("%d %d",&n,&m)){
		for(int i = 1;i <= n;++i){
			scanf("%d",&a[i]);
		}
		for(int i = 1;i <= n;++i){
			scanf("%d",&b[i]);
		}
		b[n+1] = b[1]; 
		double ans = 1;
		for(int i = 1;i <= n;++i){
			ans -= ans/a[i];
			ans -= ans/b[i+1]; 
		}
		//if(ans < esp) puts("-1");//<esp其实相当于==0，double类型的近似等于0 
		if(ans <= 0){
			printf("-1\n");
		}else{
			printf("%.10lf\n",m/ans - m);
		}
	}
	
	return 0;
}

