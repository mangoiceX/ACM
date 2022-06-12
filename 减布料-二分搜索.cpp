#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#define INF 10010 
using namespace std;
const int maxn = 10010;
int n = 0,k = 0;
double data[maxn];
bool judge(double x){
	int num = 0;
	for(int i = 0;i < n;i++){
		num += int(data[i]/x);
	}
	return num >= k;
}
int main(){
	
	while(cin >> n >> k){
		double sum = 0;
		for(int i = 0;i < n;i++){
			//cin >> data[i];
			scanf("%lf",&data[i]);
			sum += data[i];
		}
		double left = 0.01,right = sum/k,mid = 0;
		int times = 1000;
		while(times--){//多次循环，增加精度，使变化的数变化的部分在0.001 
		//while(right - left > 0.01){
			mid = (right - left)/2 + left;
			if(judge(mid)){
				left = mid;
			}else{
				right = mid;
			}
 		}
		printf("%.2f\n",floor(mid* 100) / 100 );
	}
	
	return 0;
}
