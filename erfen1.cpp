#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;

double bs(double A[], int a, int b){
	double R = 0, L = 0;
	
	for(int i = 0;i < a;i++){
		R += A[i];
	}
	R /= b;
	L = 0.01;
	
	int count = 0;
	double mid = 0;
	//int y = 1000;
	while(R - L >= 10e-4){
	//while(y--){
		mid = floor((L + (R - L)/2)*100)/100;
		
		for(int i = 0;i < a;i++){
			count += int(A[i] / mid);
		}
		if(count < b){
			R = mid;
		}else if(count >= b){
			L = mid;
		}
		count = 0;
	}		
	return mid; 
}

int main(){
	int a, b;
	double cube[10000];
	while(cin >> a >> b){
		//double cube[a];
		
		for(int i = 0;i < a;i++){
			scanf("%lf", &cube[i]);
		}
		//sort(cube,cube+a);
		printf("%.2f\n", floor(bs(cube, a ,b) *100)/100 );
	}	
	return 0;
}

