#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 100;
/*
int ex_gcd(int a,int b,int& x,int& y){//引用 
	if(b == 0){
		x = 1,y = 0;
		return a;
	}else{
		int r = ex_gcd(b,a%b,x,y);//r 是最大公倍数，最后返回第一次调用返回的是a,b的gcd 
		int tmp = x;
		x = y;y = tmp - (a/b)*y;//表达式用递归形式写 
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
			//printf("%d %d\n",x,y);//x,y是线性不定方程ax + by = 1的解 
			printf("%d %d\n",abs(x) , abs(y));//输出每个整数//如果严格区分正负号，就输出4个数
			//这里不详细改了，比如输入4 11 ，输出3 0 0 1，这里输出3 1 
		}
	}
	
	return 0;
} 
