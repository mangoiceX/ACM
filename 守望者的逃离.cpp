/*�����ߵ����룬����Σ�̰��*/ 
#include<iostream>
#include<cstdio>

using namespace std;

void escape(int mana,int space,int timeleft)
{
	int spaceelse = 0,timeleftelse = timeleft;
	while(mana >= 10 &&space - spaceelse >0)		//�ȿ�����˸ 
	{
		mana -= 10;
		timeleft--;
		spaceelse += 60;
		if(timeleft <= 0)	//ʱ�䲻�� 
		{
			cout<<"No"<<"\n"<<spaceelse;
			return ;
		}
		if(space - spaceelse <= 0)	//������� 
		{
			cout<<"Yes"<<"\n"<<timeleftelse - timeleft;
			return ;
		}
	}
	
	while(timeleft > 0 &&	space - spaceelse >0)	//ħ������ 
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
	
	escape(Mana,Space,Timeleft);//���ܼƻ� 
	
	return 0;
}
