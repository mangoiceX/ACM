#include<stdio.h>
int main(){
	int t,i,a,n,sum;
	scanf("%d",&t); 
	while(t--){	//��������
	//	while(scanf("%d",&n)!=EOF){//������������֮�� 
	scanf("%d",&n);
			sum=0;
			for(i=0;i<n;i++){
				scanf("%d",&a);
				sum=sum+a;
			}
			printf("%d\n",sum);
			if(t>=1)
				printf("\n");
	//	}
	}
	return 0;
}
