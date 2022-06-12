#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#define INF 1000000010;//0x7fffffff;
using namespace std;
const int maxn = 1110;
int n = 0,k = 0;
double y[maxn];
typedef struct thing{
	double v,w;
}TH;
TH thing[maxn];
bool judge(double x){
	for(int i = 0;i < n;++i){
		y[i] = thing[i].v - x * thing[i].w;
	}
	sort(y,y+n);
	double sum  = 0;
	for(int i = 0;i < n - k;++i){
		sum += y[n-1-i];
	}
	return sum >= 0;
}
double solve(){
	double l = 0,r = INF;
	double mid = 0;
	while(r - l >= 10e-15){
		 mid = (r - l)/2 + l;
		if(judge(mid)){
			l = mid;
		}else{
			r = mid;
		}
	}
	return mid;
	
}
int main(){
	while(cin >> n >> k && n >= 1 && k){
		for(int i = 0;i < n;++i){
			cin >> thing[i].v;
		}
		for(int i = 0;i < n;++i){
			cin >> thing[i].w;
		}
		
		printf("%.0lf\n",solve() * 100 );
	}
	
	
	
	return 0;
}
