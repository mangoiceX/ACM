#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath> 
using namespace std;
const int maxn = 10;
int main(){
	double tg = 0,t1 = 0,t2 = 0,u = 0;
	double qua[maxn],time[maxn];
	int num[maxn];
	int cnt = 1;
	//freopen("a.txt","r",stdin);
	printf("Please input u , t1 ,t2 in proper order :\n");
	while(scanf("%lf %lf %lf",&u,&t1,&t2) != EOF){
		tg = (t1 + t2) / 2;
		qua[cnt] = 1.43 * pow(10,5) * (1/u) * 
		(1/pow(((tg * 1.25) * (1 + 0.02 * sqrt(tg * 1.25 + 0.5))),1.5));
		time[cnt] = tg;
		num[cnt] = ceil(qua[cnt] / 1.60);
		printf("%.2lf\n",tg);
		printf("The %dth quantity of electric charge is %.5lf e-19 equals %d e(s)\n",
		cnt,qua[cnt],num[cnt]);
		cnt++;
	}
	
	return 0;
}
