#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int x1 = 0,y1 = 0,x2 = 0,y2 = 0;
int gcd(int x,int y){
	int ma = max(x,y),mi = min(x,y);
	if(mi == 0){
		return ma;
	}else{
		return gcd(mi,ma % mi);
	}
	//return y == 0 ? x : gcd(y,x % y); 
} 
int main(){
	while(cin >> x1 >> y1 >> x2 >> y2){
		int num = gcd(abs(x1 - x2),abs(y1 - y2));
		//int m = abs(x1 - x2) / num,n = abs(y1 - y2) / num;
		int m = (x2 - x1) / num,n = (y2 - y1) / num;//ֱ�Ӽ������ùܴ�С�������Ͳ������ܶ���ж��� 
		//cout << m << " " << n << endl;
		//int x = min(x1,x2),y = min(y1,y2);
		int x = x1,y = y1;//���ñȽϴ�С���Լ����Ծ��������������������˽� 
		while(x + m!= x2 && y + n != y2){//�Լ��е����˺þ� 
			x += m;y += n;
			cout << "(" << x << ", " << y << ")" << endl; 
		}
	}	
	
	return 0;
} 
