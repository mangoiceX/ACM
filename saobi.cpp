#include<bits/stdc++.h>
using namespace std;
int people = 0;
double price = 0;
int main(){
	while(~scanf("%d %lf",&people,&price)){
		if(people < 50){
			printf("%.2lf\n",people*price);
		}else if(people >= 50 && people < 100){
			printf("%.2lf\n",people*price*0.9);
		}else{
			printf("%.2lf\n",people*price*0.85);
		}

	}

	return 0;
}