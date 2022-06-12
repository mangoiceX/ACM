#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f 
using namespace std;
const int maxn = 1e5;
int n = 0,m = 0;
string str,ch;
int main(){
	while(cin >> n >> ch){
		getchar();
		getline(cin,str);
		if(str.size() >= n){
			per(i,str.size() - n,str.size()-1){
				cout << str[i];
			}
			cout << "\n";
		}else{
			per(i,1,n - str.size()){
				cout << ch;
			}
			cout << str <<endl;
		}
	}
	
	return 0;
}
