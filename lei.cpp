#include<iostream>
#include<cstdio>

using namespace std;

class Data
{
	void set(int d);
	int get()
	{
		return data;
	}
	
	public:
		int a,b;
		int data;
	protected:
		int c,d;
	private:
		int e,f;
}A,B;

Data* func2(Data *p1,Data *p2)
{
	if(p1->data > p2->data)
		return p1;
	else
		return p2;	
}

Data& func3(Data &r1,Data &r2)
{
	if(r1.data < r2.data)
		return r1;
	else
		return r2;
}

int main()
{
	A.data = 100;
	B.data = 180;
	printf("%d\n",func2(&A,&B)->data);
	printf("%d\n",func3(A,B).data);
	
	return 0;	
}
