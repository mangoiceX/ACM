#include <stdio.h>
int main(){
	int b[100],i=0,j,k=0,jump,m=0,max=0;
	char c,a[100]; 
	while((c=getchar())!='\n')
	{
		a[i]=c;
		i++;
	}
	for(j=k;j<=i;j++)
	{
		if(a[j]=='A'||a[j]=='E'||a[j]=='I'||a[j]=='O'||a[j]=='U'||a[j]=='Y')
		{
			for(k=j+1;k<=i;k++)
			{
				jump=0;
				if(a[k]=='A'||a[k]=='E'||a[k]=='I'||a[k]=='O'||a[k]=='U'||a[k]=='Y')
				{	
					jump=k-j;
					if(max<jump)
						max=jump;
					break;
				}		 
			}	
		
		}
	
	}
	printf("%d",max);
	return 0;
} 
