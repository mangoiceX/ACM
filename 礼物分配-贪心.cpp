/*计蒜客-贪心-纪念品分组*/ 
#include<iostream>
//#include<cstdio>
#include<algorithm>
//#include<queue>
//#include<vector>

using namespace std;

int main()
{
	int num = 0,great_money = 0,i = 0,count = 0;
	//input 
	cin>>great_money;
	cin>>num;
	int *prices = new int[num];
	for(i = 0;i < num;i++)
		cin>>*(prices+i);
	//core	
	sort(prices,prices + num);		//排序 
	for(int j = num-1,i = 0;j >= i;j--)
	{
		if(*(prices + i) + *(prices + j) <= great_money)
		{
			count++;
			i++;
		}
		else
			count++;
	}
	cout<<count;
	delete [] prices; 
	return 0;
}

 
