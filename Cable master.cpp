#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
const int maxn = 10005;
int N = 0, K = 0;
double sum = 0;
double data[maxn];

bool judge(double x){
	int num = 0;
	for(int i = 0;i < N;++i){
		num += int(data[i]/x);
	}
	return num >= K;
}

void solve(){
	double l = 0.01,r = sum / K;
	double mid = 0;
	//for(int i = 0;i < 1000;i++){//循环次数作为终止条件 
	while(r - l > 10e-5){
		mid = (r - l) / 2 + l;
		if(judge(mid)){
			l = mid;
		}else{
			r = mid;
		}
	}
	printf("%.2f\n",floor(r*100)/100 );//选择r而不是mid 或者 l 
}
int main(){
	while(scanf("%d %d",&N,&K) != EOF){
		sum = 0;
		for(int i = 0;i < N;++i){
			scanf("%lf",&data[i]);
			sum += data[i];
		}
		solve();
	} 
	
	
	
	
	return 0;
}
