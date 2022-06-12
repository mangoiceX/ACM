#include<stdio.h>
int main(){
	int t=100,i,a,sum; 
	while(t--){	//控制组数//不定个数数据之和 
			sum=0;
			for(i=0;i<2;i++){
				scanf("%d",&a);
				sum=sum+a;
			}
			printf("%d\n\n",sum);
	}
	return 0;
}
