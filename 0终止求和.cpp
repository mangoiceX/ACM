#include<stdio.h> 
int main()
{
	int a,b,c,i;
	while(scanf("%d%d",&a,&b)!=EOF){
		if(a==0&&b==0)
			continue;
		else
		printf("%d\n",a+b);
	}
	return 0;
}
