//子类型和类型适应
//即使基类指针在访问派生类元素的使用 
#include<iostream>
#include<cmath>
using namespace std;
class Point{
	int x,y;
	public:
		Point(int x1,int y1){
			x=x1;
			y=y1;
		}
		int  readX(void){
			return x;
		}
		int readY(void){
			return y;
		}
		friend double distance(Point &a,Point &b);
}; 
class Circle:public Point{
	int radius;
	public:
		Circle(int x1,int y1,int r):Point(x1,y1){
			radius=r;
		}
		int readR(void){
			return radius;
		}
		friend double distance(Point &a,Point &b);
};
class Rectangle:public Point{
	int width,height;
	public:
		Rectangle(int x0,int y0,int w,int h):Point(x0,y0){
			width=w;
			height=h;
		}
		int readW(void){
			return width;
		}
		int readH(void){
			return height;
		}
		friend double distance(Point &a,Point &b);
};
double distance(Point &a,Point &b)
{
	double dx=a.x-b.x; 
	double dy=a.y-b.y;
	return sqrt(dx*dx+dy*dy);
}
int main()
{
	Circle k(28,36,80),r(72,147,160);
	cout<<"'K'`s X = "<<k.readX()<<" , K`s Y = "<<k.readY()<<endl;
	cout<<"'R'`s X = "<<r.readX()<<" , R`s Y = "<<r.readY()<<endl;
	
	double dc=distance(k,r);
	
	cout<<"The distance of K and R center "<<dc<<endl;
	
	Rectangle rec1(12,22,60,80),rec2(42,124,80,128);
	double dr=distance(rec1,rec2);
	cout<<"The distance of rec1 and rec2 center "<<dr<<endl;
}

