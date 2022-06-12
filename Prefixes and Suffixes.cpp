#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

typedef long long LL;

#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
const int maxn = 200;
int n = 0,m = 0;
struct node{
	int id,l;
};
string str[maxn+10];
string str1 = "a",str2 = "a";
node len[maxn+10];
string ans = "";
bool cmp(node a,node b){
	return a.l > b.l;
}
bool pre(string str3,string str4){
	int i = 0;
	int len1 = str3.size(),len2 = str4.size();
	//cout << "jaja " << len1 << endl;
	while(i < len1 && i < len2){
		//cout << "niam " << str3[i] << " " << str4[i] << endl;
		if(str3[i] != str4[i]){
			return false;
		}
		++i;
	}
	//cout << "haha " << str3 << endl;
	return true;
}
bool suf(string str3,string str4){
	int len1 = str3.size(),len2 = str4.size()-1;
	int i = len1 - 1,j = len2 - 1;
	///cout << "liang " << i << " " << j << endl; 
	//cout << str4[j-1] << endl;
	//cout << str3 << endl;
	//cout << "jaja " << len1 << endl;
	while(i >= 0 && j >= 0){
		if(str3[i] != str4[j]){
			return false;
		}
		--i;--j;
	}
	//cout << "haha " << str3 << endl;
	return true;
}
bool solve1(string s){
	per(i,1,2*(n-1)){
		if(pre(str[i],s)){
			
			ans += "P";
			//cout << "oooo " << str[i] << endl;
		}else if(suf(str[i],s)){
			ans += "S";
		//	cout << "pppp " << str[i] << endl;
		}else{
		//	cout << "fa " << s << " " << str[i] << endl;
			return false;
		}
	}
	return true;
}
void solve(){
	string s;
	s = str1;
	int len1 = str1.size(),len2 = str2.size();
	//cout << len1 << " " << len2 << endl;
	int cnt = 0;
	int i = len1 - 1,j = 0;
	while(i >= 0 && j < len2){
		if(len1 + len2 - cnt == n){
			//cout << "jaj " << j << endl;
			break;
		}
		if(str1[i] != str2[j] && str1[i-1] == str2[j]){
			--i;
		}
		if(str1[i] != str2[j] && str1[i-1] != str2[j]){
			//cout << " jaoi" << endl;
			break;
		}
		cnt++;
		++j;
	}
	//cout << "jaj " << j << endl;
	per(i,j,len2-1){
		s += str2[i];
	}
	//cout << "mimi " << s << endl;
	if(solve1(s)){
		cout << ans << endl;
		return ;
	}else{
		ans = "";
	}
	//cout << "2" << endl;
	s = str2;
	cnt = 0;
	i = len2 - 1,j = 0;
	while(i >= 0 && j < len1-1){
		if(len1 + len2 - cnt == n){
			break;
		}
		if(str2[i] != str1[j]){
			break;
		}
		cnt++;
		--i;++j;
	}
	per(i,j,len1){
		s += str1[i];
	}
	//cout << "haah " << s << endl;
	if(solve1(s)){
		cout << ans << endl;
	}else{
		ans = "";
	}
	//cout << "jian " << endl;
}
int main(){
	while(~scanf("%d",&n)){
		str1 = "a";str2 = "a";
		int io = 0;
		per(i,1,2*(n-1)){
			cin >> str[i];
			len[i].l = str[i].size();	len[i].id = i;
			if(str[i].size() >= str1.size()){
				str1 = str[i];
				io = i;
			}
		}
		sort(len+1,len+1+2*(n-2),cmp);
		per(i,1,2*(n-1)){
			if(str[len[i].id] != str1 || len[i].id != io){
				str2 = str[len[i].id];
				break;
			}
		}
		//cout << "jaa " << str1 << " " << str2 << endl;
		solve();
	}
	
	return 0;
}

