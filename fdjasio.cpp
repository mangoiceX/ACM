#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (b);i >= (b);++i)
#define INF 1e9
using namespace std;
const int maxn = 1e5 + 10;
int n = 0,m = 0,k = 0;
string s;
int pre[maxn],pre1[maxn];
int cnt[10];
int len = 0;
void solve(){
	int len = s.length();
	pre1[0] = cnt[0] = 1;
	cout << len <<endl;
	per(i,0,len-1){
		pre[i] = (i == 1 ? 0 : pre[i-1]) + (s[i] - '0');
		pre[i] %= 3;
		++cnt[pre[i]];
		pre1[i] = cnt[pre[i]];
	}
	int num = 0,pos = 1;
	vector<pair<int,int> > g; 
	int ou = 0;
	per(i,0,len-1){
		if(s[i] == '0'){
			while(i <= len-1 && s[i] == '0'){
				++i;
				++num;
				
			}
			if(num >= 2){
				g.push_back(make_pair(pos,num));
			}else{
				++ou;
			}
			pos = i;num = 0;
		}else{
			num = 0;
			pos = i;
		}
	}

	int ans = 0;
	int si = g.size();
	per(i,0,si-1){
		pair<int,int> now = g[i];
		cout << "ji " << ans << " " <<now.first << " "<< pre1[now.first]-1<< " " << now.second <<endl;
		ans += (pre1[now.first]-1)*(now.second-1);
		cout << "nimei " <<  ans << endl;
		ans += (now.second + 1)*now.second/2;
		// sum += pow(2,now.second) - 1;
	}
	cout << ans << endl;
	printf("%d\n",ans + ou);

}
int main(){

	cin >> s;
	solve();

	return 0;
}