#include<iostream> 
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#include<map>
#include<cmath>
#include<queue>
using namespace std;
const int maxn = 100000 + 10;
string str;
int n = 0,ans = 0;
void solve(){
	int xiao = 0,da = 0;
	for(int i = 0;i < n;++i){
		if(str[i] == 'x'){
			++xiao;
		}else{
			++da;
		}
	}
	ans = abs(xiao - da) /2;
	int cha = ans;
	if(ans != 0){
		if(xiao > da){
			for(int i = 0;i < n;++i){
				if(str[i] == 'x'){
					str[i] = 'X';
					--cha;
				}
				if(cha == 0){
					break;
				}
			}
		}else{
			for(int i = 0;i < n;++i){
				if(str[i] == 'X'){
					str[i] = 'x';
					--cha;
				}
				if(cha == 0){
					break;
				}
			}
		}
	}
	
}

int main(){
	cin >> n;
	cin >> str;
	solve();
	cout << ans << "\n";
	cout << str;
	
	return 0;
}
