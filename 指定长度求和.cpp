#include<stdio.h> 
int main(){
	int m,n,a[10],sum=0,i;
	scanf("%d ",&n);
	while(scanf("%d ",&n)!=0){
	/*	while(scanf("%d ",&m)!=EOF){*/
			for(i=0;i<n;i++)
				scanf("%d ",&a[i]);
	for(i=0;i<n;i++)
		sum=sum+a[i];
		printf("%d\n",sum);
		scanf("%d\n",&n);
	}
	return 0;
}
