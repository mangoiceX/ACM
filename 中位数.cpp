#include<iostream>
#include<cstdio> 
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 10010;
int milk[maxn];

int main(){
	int n = 0;
	while(cin >> n && n){
		
		for(int i = 0;i < n;++i){
			cin >> milk[i];
		}
		sort(milk,milk + n);
		cout << milk[n/2 ] << endl;
	}
	return 0;
}
