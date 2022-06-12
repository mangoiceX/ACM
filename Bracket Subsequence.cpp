#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<set>
#define INF 2e5 + 100
using namespace std;
string s,t;
int n = 0,m = 0;
const int maxn = 2e5 + 100;
int pos[maxn],p[maxn];
void solve(){
	int k = 0;
	for(int i = 0;i < s.size() - 1;++i){
		if(s[i] == '(' && s[i+1] == ')'){
			pos[k++] = i;
		}
	}
	
	int len = s.size();
	for(int i = 0;i < k && len > m;++i){
		int j = 1;
		while(pos[i]-j +1 >= 0 && pos[i] + j < s.size() &&
		s[pos[i]-j + 1] == '(' && s[pos[i]+j] == ')'&& len > m){
			p[pos[i]-j+1] = 1;
			p[pos[i]+j] = 1;
			//t -= t[pos[i]-j+1];
			//t -=  t[pos[i]+j];
			++j;
			len -= 2;
			//cout << "me " << len << endl;
		}
	}
	for(int i = 0,j = s.size()-1;i < j && len > m;){
		
		if(p[i] != 1 && p[j] != 1 && s[i] == '(' && s[j] == ')'){
			p[i] = p[j] = 1;
			++i,--j;
			len -= 2;
		}
		while(p[i] == 1 || s[i] == ')'){
			++i;
		}
		while(p[j] == 1 || s[j] == '('){
			--j;
		}
	}
	//cout << t << endl;
	for(int i = 0;i < s.size();++i){
		//cout << "en "<< p[i];
		if(p[i] != 1){
			cout << s[i];
		}
	}
	cout << endl;
}
int main(){
	while(cin >> n >> m){
		memset(p,0,sizeof(p));
		memset(pos,0,sizeof(pos));
		cin >> s;
		//t = s;
		solve();
	}
	
	return 0;
}
