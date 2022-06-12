/*守望者的逃离，计蒜课，贪心*/ 
#include<iostream>
#include<cstdio>

using namespace std;

void escape(int mana,int space,int timeleft)
{
	int spaceelse = 0,timeleftelse = timeleft;
	while(mana >= 10 &&space - spaceelse >0)		//先狂用闪烁 
	{
		mana -= 10;
		timeleft--;
		spaceelse += 60;
		if(timeleft <= 0)	//时间不够 
		{
			cout<<"No"<<"\n"<<spaceelse;
			return ;
		}
		if(space - spaceelse <= 0)	//距离完成 
		{
			cout<<"Yes"<<"\n"<<timeleftelse - timeleft;
			return ;
		}
	}
	
	while(timeleft > 0 &&	space - spaceelse >0)	//魔法不够 
	{
		if(mana == 0 || mana ==1 && space - spaceelse > 102 && timeleft >= 7)
		{
			timeleft -= 7;
			spaceelse += 120;
		}
		else if(mana >= 2 && mana <= 5 && space - spaceelse > 34 && timeleft >=  3)
		{
			timeleft -= 3;
			spaceelse += 60;
		}
		else if(mana >= 6 && mana <= 9 && space - spaceelse > 17 && timeleft >= 2)
		{
			timeleft -= 2;
			spaceelse += 60;
		}
		else
		{
			timeleft--;
			spaceelse += 17;
		}	
	}
	
	if(timeleft > 0)
		cout<<"Yes"<<"\n"<<timeleftelse - timeleft;	
	else
		cout<<"No"<<"\n"<<spaceelse;
	return ;
}					

int main()
{
	int Mana,Space,Timeleft;
	
	cin>>Mana>>Space>>Timeleft;
	
	escape(Mana,Space,Timeleft);//逃跑计划 
	
	return 0;
}
