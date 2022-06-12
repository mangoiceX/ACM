
#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    //while(~scanf("%lld",&n)){
	for(int j = 1;j <= 1e3;++j){
    	long long f1=1,f2=1,f3;
	    for(int i=3;i<=j;i++) {
	        f3=f1+f2;
	        f1=f2;
	        f2=f3;
	    }
	    printf("%d %lld\n",j,f3*f3-f1*f1-f1*f3);
	}
    
    return 0;
}
