#include<stdio.h> 
int main()
{
	int a,n,b,i;
	scanf("%d",&n);
	while(scanf("%d",&n)!=0){
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",a+b);
	}}
	return 0;
}
