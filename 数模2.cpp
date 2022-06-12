#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
using namespace std;
double a[10],b[10],ans[10];
int n = 0;
int main(){
	while(~scanf("%d",&n)){
		per(i,1,n){
			scanf("%lf",&a[i]);
		}
		per(i,1,n){
			scanf("%lf",&b[i]);
		}
		double sum = 0;
		per(i,1,n){
			ans[i] = a[i] * b[i];
			sum += ans[i];
		}
		per(i,1,n){
			printf("%lf%c",ans[i]/sum,i == n ? '\n' : ' ');
		}
		
	}
	
	return 0;
}
/*
wx
0.32 0.41 0.27
ws
0.41  0.44 0.14
wt
0.36 0.38 0.24
wp
0.25 0.31 0.43
wq
0.14 0.18 0.66
wr
0.60 0.24 0.16
wf
0.05 0.31 0.16 0.42
wt(ÐÂµÄ£©
0.26 0.28 0.17 0.27 
*/
