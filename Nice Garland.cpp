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
const int maxn = 3e5;
int n = 0,m = 0;
string str;
string str1[7] = {"ni","RGB","RBG","BGR","BRG","GBR","GRB",};
//str1[1] = "RGB",str1[2] = "RBG",str1[3] = "BGR",str1[4] = "BRG",
//str1[5] = "GBR",str1[6] = "GRB";
void solve(){
	int ans = 3e5;
	string ans_str; 
	for(int k = 1;k <= 6;++k){
		int cnt = 0;
		string tmp;
		for(int i = 0;i < n/3;++i){
			if(str[3*i] != str1[k][0]){
				//tmp.push_back(str[3*i]);
				++cnt;
			}
			if(str[3*i+1] != str1[k][1]){
				//tmp.push_back(str[3*i+1]);
				++cnt;
			}
			if(str[3*i+2] != str1[k][2]){
				//tmp.push_back(str[3*i+2]);
				++cnt;
			}
			tmp.push_back(str1[k][0]);	tmp.push_back(str1[k][1]);	tmp.push_back(str1[k][2]);
		}
		if(n % 3 != 0){
			if(n % 3 == 1){
				tmp.push_back(str1[k][0]);
				if(str[n-1] != str1[k][0]){			
					++cnt;
				}
			}
			if(n % 3 == 2){
				tmp.push_back(str1[k][0]);
				tmp.push_back(str1[k][1]);
				if(str[n-1] != str1[k][1]){
				
					++cnt;
				}
				if(str[n-2] != str1[k][0]){
		
					++cnt;
				}
			}
		}
		if(cnt < ans){
			ans = cnt;
			ans_str = tmp;
		}
		//cnt = max(cnt,ans);
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

