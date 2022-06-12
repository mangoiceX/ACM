#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
typedef long long LL;

int main(){
	LL a = 0,b = 0;
	while(cin >> a >> b){
		LL x = max(a,b),y = min(a,b);
		LL p = (x+y) / (x%y + y);
		LL q = (x % y + y);
		cout << 2 * (p + q) << endl;
	}
	return 0;
}
