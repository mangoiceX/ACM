#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f 
using namespace std;
const int maxn = 1e5;
int n = 0;
map<char,char> mp;

int main(){
	mp['A'] = '1'; mp['B'] = '2'; mp['C'] = '3'; mp['D'] = '4'; 
	while(cin >> n){
		string str,ans;
		getchar();
		per(i,1,n){
			getline(cin,str);
			if(str[2] == 'T'){
				ans.push_back(mp[str[0]]);
			}else if(str[6] == 'T'){
				ans.push_back(mp[str[4]]);
			}else if(str[10] == 'T'){
				ans.push_back(mp[str[8]]);
			}else if(str[14] == 'T'){
				ans.push_back(mp[str[12]]);
			}
		}
		cout << ans << endl;
	}
	
	
	
	return 0;
}
