#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
char s[maxn];
// void solve(){
// 	char str[maxn];
// 	map<char,int> mp;
// 	int len = strlen(s);
// 	int ans = 0;
// 	int si = 0;
// 	str[si++] = s[0];
// 	mp[0] = 1;
// 	per(i,1,len-1){
// 		// mp[s[i]] = i;
// 		// int j = i+1;
// 		int cnt = mp[si-1] % 3;
// 		while(i < len && s[i] == str[si-1]){
// 			++cnt; ++i;
// 		}
// 		ans += (cnt/3);
// 		mp[si-1] = cnt%3;
// 		// per(k,1,cnt%3){
// 		// 	str[si++] = s[i];
// 		// }
// 		if(!(cnt%3)){
// 			--si;
// 		}
// 		if(i == len){
// 			break;
// 		}
// 		str[si++] = s[i];
// 		mp[si-1] = 1 + (si-2 >= 0 ? (str[i-1] == tr[i-2] ? mp[si-2]));
// 		cout << str << endl;
// 		// cnt = cnt % 3;
// 		// i = j-1;
// 	}
// 	printf("%d\n",ans);
// }
bool check(char* ss,int len){
	// int len = strlen(ss);
	// cout << "jaja " << ss << len << endl;
	if(ss[len-1] == ss[len-2] && ss[len-1] == ss[len-3]){
		return true;
	}
	return false;
}
void solve(){
	char str[maxn];
	int si = 0,ans = 0;
	int len = strlen(s);
	per(i,0,len-1){
		str[si++] = s[i];
		if(si >= 3){
			// cout << str  << " " << si<< endl;
			if(check(str,si)){
				// cout <<  "hjaha " <<str << endl;
				si -= 3;
				++ans;
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%s",s);
	solve();

	return 0;
}