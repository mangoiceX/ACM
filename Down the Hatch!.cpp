#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 10000 + 10;
int n = 0;
string str;
int main(){
	cin >> n;
	cin >> str;
	int ans = 0;
	for(int i = 4 - 1;i < str.size();++i){
		if(i % n == 0){
			if(str[i-1] == str[i-2] && str[i-1] == str[i-3]){
				++ans;
			}
		}
	}
	cout << ans << endl;
	
	
	return 0;
}
