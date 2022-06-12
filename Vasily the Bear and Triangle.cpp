#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 10000 + 10;

int main(){
	int m = 0,n = 0;
	int x1 = 0,x2 = 0,y1 = 0,y2 = 0;
	cin >> m >> n;
	if(m < 0){
		x1 = 0-(abs(m) + abs(n));
		y1 = 0;
		x2 = 0;
		if(n < 0){
			y2 = 0-(abs(m) + abs(n));	
		}else{
			y2 = (abs(m) + abs(n));	
		}
	}else{
		x2 = (abs(m) + abs(n));
		y2 = 0;
		x1 = 0;
		if(n < 0){
			y1 = 0-(abs(m) + abs(n));
		}else{
			y1 = (abs(m) + abs(n));	
		}
	}
	
	cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	
	return 0;
}
