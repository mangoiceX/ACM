#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std; 
const int maxn = 2e5 + 10;
int n = 0,t = 0,c = 0;

int main(){
	ios::sync_with_stdio(false);
	int temp = 0,flag = 1;
	while(cin >> n >> t >> c){
		
		int ans = 0;
		for(int i = 1;i <= n;++i){
			cin >> temp;
			if(temp > t){
				flag = i + 1;
			}else if(i - flag >= c -1){
				++ans;
			}
		}
		
		cout << ans << endl;
	}
	
	return 0;
}
