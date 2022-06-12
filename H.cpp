#include<stdio.h>
int main(){
	int t,i,a,n,sum;
	scanf("%d\nn",&t); 
	while(t--){	//控制组数
		while(scanf("%d\n",&n)!=EOF){//不定个数数据之和 
			sum=0;
			for(i=0;i<n;i++){
				scanf("%d ",&a);
				sum=sum+a;
			}
			printf("%d",sum);
		}if(t>1)
				printf("\n\n");
	}
	return 0;
}
