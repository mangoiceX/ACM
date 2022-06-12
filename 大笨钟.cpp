#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f 
using namespace std;
const int maxn = 1e5;
string str;
int h = 0,mi = 0;
int main(){
	while(cin >> str){
		h = (str[0] - '0') * 10 + (str[1] - '0');
		mi = (str[3] - '0') * 10 + (str[4] - '0');
		int time = h*100 + mi;
		if(time >= 0 && time <= 1200){
			cout << "Only " << str << ".  Too early to Dang.\n";
		}else{
			int cnt = (mi == 0 ? h : (h+1)) - 12;
			per(i,1,cnt){
				cout << "Dang";
			}
			cout << "\n";
		}
	}
	
	return 0;
}
