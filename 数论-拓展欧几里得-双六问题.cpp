#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 100;
/*
int ex_gcd(int a,int b,int& x,int& y){//���� 
	if(b == 0){
		x = 1,y = 0;
		return a;
	}else{
		int r = ex_gcd(b,a%b,x,y);//r ����󹫱�������󷵻ص�һ�ε��÷��ص���a,b��gcd 
		int tmp = x;
		x = y;y = tmp - (a/b)*y;//���ʽ�õݹ���ʽд 
		return r;
	}
}
*/
int ex_gcd(int a,int b,int& x,int& y){
	if(b == 0){
		x = 1,y = 0;
		return a;
	}else{
		int r = ex_gcd(b,a%b,y,x);
		y -= (a/b)*x;
		return r; 
	}
} 
int main(){
	int a = 0,b = 0,x = 0,y = 0;
	while(scanf("%d %d",&a,&b) != EOF){
		if(a < b){
			swap(a,b);
		}
		
		if(ex_gcd(a,b,x,y) != 1){
			printf("Impossible\n");
		}else{
			//printf("%d %d\n",x,y);//x,y�����Բ�������ax + by = 1�Ľ� 
			printf("%d %d\n",abs(x) , abs(y));//���ÿ������//����ϸ����������ţ������4����
			//���ﲻ��ϸ���ˣ���������4 11 �����3 0 0 1���������3 1 
		}
	}
	
	return 0;
} 
