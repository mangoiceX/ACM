/*HDU1050*/

#include<stdio.h>
#include<string.h>

#define SIZE 405

int main()
{
	int count[SIZE];
	int testnum = 0,temp = 0,n = 0;
	int from = 0,to = 0;		//��ʼ���� 
	
	scanf("%d",&testnum); 
	while(testnum-- && testnum >=0)
	{
		memset(count,0,sizeof(count));
		
		scanf("%d",&n);
		for(int i = 0;i < n;i++)
		{
			scanf("%d %d",&from,&to);
			if(from > to)			//exchage
				temp = from,from = to,to = temp;
			if(from % 2 == 0)	
				count[from - 1]++;
			if(to % 2 == 1)
				count[to + 1]++;
		
		for(int j = from;j <= to;j++)			//�����������غ� 
			count[j]++;
		}
			
		int max = 0;
		for(int i = 0;i < SIZE;i++)
			max = count[i] > max ? count[i]:max;
			//if(count[i] > max)
			//	max = count[i]; 
		printf("%d\n",max * 10);
	}	
	return 0;
}
