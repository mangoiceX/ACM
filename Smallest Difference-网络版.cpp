
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char str[30];
int num[15];
int main()
{
	int t,len,i,k;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		gets(str);
		len=strlen(str);
		k=0;
		for(i=0;i<len;++i)
		{
			if(str[i]>='0'&&str[i]<='9')
				num[k++]=str[i]-'0';	
		}
		if(k==2)//处理只有两个数的情况 
		{
			printf("%d\n",num[1]-num[0]);
			continue;
		}
		while(num[0]==0)//第一个数不能以零开头 
			next_permutation(num,num+k);
		int ans=999999999;
		do
		{
			int mid=(k+1)/2;
			if(num[mid])//第二个数不能以零开头 
			{
				int a=0,b=0;
				for(i=0;i<mid;++i)
					a=a*10+num[i];
				for(i=mid;i<k;++i)
					b=b*10+num[i];
				ans=min(ans,abs(a-b));
			}
		}while(next_permutation(num,num+k));
		printf("%d\n",ans);
	}
	return 0;
}

