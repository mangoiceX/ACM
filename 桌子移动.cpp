/*hdu*/
#include<stdio.h>
#include<stdlib.h>

struct 	Room
{
	int a,b;		//��������
	int ia,ib;
	int dis;		//ռ�����ȳ��� 
}room[200];

void selectsort(Room v[],int n)
{
	int i,j,k;
	Room temp;
	for(i = 0;i < n;i++)						//��Ƭѡ������,���� 
	{
		k = i;
		for(j = i+1;j < n;j++)
			if(v[j].dis < v[k].dis)
				k = j;
		if(k != i)
			temp = v[i],v[i] = v[k],v[k] = temp;
	}
}


int main()
{
	int t = 0,n=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i = 0;i < n;i++)
		{
			scanf("%d %d",&room[i].a,&room[i].b);
			if(room[i].a % 2 == 0)					//��żΪ�� 
				room[i].ia = room[i].a / 2;
			else
				room[i].ia = room[i].a;
			if(room[i].b % 2 == 0)
				room[i].ib = room[i].b / 2;
			else
				room[i].ib = room[i].b;
			room[i].dis = fabs(room[i].ia - room[i].ib);
		}
		
		selectsort(room);
		
		for(int i = 0;) 
		
		
		
		
		
	}
	
	
	
	
}
