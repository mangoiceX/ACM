#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	double x[10];
	//while(~scanf("%lf %lf %lf %lf",&a[1],&a[2],&a[3],&a[4])){
		//printf("%lf\n",(a[1]+a[2]+a[3])/(a[1]+a[2]+a[3]+a[4]));
	for(int i = 1;i <= 10;++i){
		scanf("%lf",&x[i]);
	}
		double z1= 0.453*x[1]+0.391*x[2]+0.354*x[3]+0.275*x[4]+
		0.245*x[5]+0.38*x[6]+0.312*x[7]+
    0.18*x[8]-0.049*x[9]+0.324*x[10];
    printf("%lf\n",z1);

	
	return 0;
} 
