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
const int maxn = 2e5;
int n = 0,m = 0;
string str;
struct node{
	int s,e;
};
node same[maxn+10];
string s1 = "RGB";
void solve(){
	char ch = 'P';
	str.push_back(ch);
	int size = str.size();
	int cnt = 0,num = 0,s = 0,e = 0;


	per(i,1,size-1){
		if(str[i] == str[i-1]){
			e = i;
			//cout << i << " " << s << endl;
			//++cnt;
		}else{
			if(e-s+1 >= 2){
				same[++num].s = s; same[num].e = e;
				//cout << "jj " << s << " " << e << endl;
			}
			s = i;e = i;
		}
	}
	//cout << "nima "<< num << endl;
	int ans = 0;
	string ans_str;
	per(i,0,size-2){
		ans_str.push_back(str[i]);
	}
	char tmp;
	for(int i = 1;i <= num;++i){
		int si = (same[i].e - same[i].s + 1);
		//cout << same[i].e << endl;
		ans += ( si / 2);
		if(si & 1){
			per(k,0,2){
				if(s1[k] != str[same[i].s]){
					tmp = s1[k];
					break;
				}	
			}
			for(int j = same[i].s+1;j <= same[i].e-1;j += 2){
				ans_str[j] = tmp;
			}
		}else{
			per(k,0,2){
				//cout << "jiji " << s1[k] <<  " " << str[same[i].s] << " " <<str[same[i].e+1] << endl;
				if(s1[k] != str[same[i].s] && (same[i].e+1 >= size-1 || s1[k] != str[same[i].e+1])){
					//cout << "niam " << k << endl;
					tmp = s1[k];
					break;
				}	
				
			}
			for(int j = same[i].s+1;j <= same[i].e;j += 2){
				ans_str[j] = tmp;
			}	
		}
	}
	//printf("%d\n",ans);
	cout << ans << endl;
	cout << ans_str << endl;
	
}
int main(){
	while(cin >> n){
		cin >> str;
		solve();
	}
	
	
	return 0;
}

