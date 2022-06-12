#include<bits/stdc++.h>
using namespace std;
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
const int maxn = 1e5+10;
int g[26][maxn];
bool mark[26];
int n = 0;
int max_len = 0;
int ch[26] = {'a','b','c','d','e','f','g','h','i','j',
'k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
struct Data{
	char data[maxn];	
}s[25];
int val[26];
int fg[26];
int kase = 0;
const int mod = (1e9 + 7);
bool cmp(const Data& e1,const Data& e2){
	cout << "ni" <<endl;
	if (strcmp(e1.data, e2.data) < 0)  
        return true;  
    return false;  
}
int q_mul(int a,int b){
	int res = 0;
	while(b > 0){
		if(b & 1){
			res = (res + a) % mod;
		}
		a = a + a;
		b >>= 1;
	}
	return res;
}
int q_power(int a,int b){
	int res = 1;
	while(b > 0){
		if(b&1){
			res = q_mul(res,a);
		}
		a = q_mul(a,a);
		b >>= 1;
	}
	return res;
}
void solve(){
	memset(fg,false,sizeof(fg));
	per(i,0,25){
		per(j,0,max_len-1){
			if(g[i][j] < 26){
				continue;
			}
			g[i][j+1] += (g[i][j] / 26);
			g[i][j] %= 26;
		}
		g[i][max_len + 1] =  ch[i];
	}

	per(i,0,25){
		per(j,0,max_len){
			s[i].data[j] = ch[g[i][j]];
		}
	}
	cout <<"ahaa" << endl;
	sort(s,s+26,cmp);
	cout << "nihao" << endl;
	per(i,0,25){
		if(mark[i]){
			val[i] = 0;
			fg[i] = true;
			break;
		}
	}

	rep(i,25,0){
		if(!fg[i]){
			val[s[i].data[max_len+1] - 'a'] = i;
		}
	}
	int ans = 0;
	per(i,0,25){
		per(j,0,max_len){
			ans = (ans + q_power(26,j)) % mod;
		}
	}
	printf("Case #%d: %d\n",++kase,ans);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while(~scanf("%d",&n)){
		memset(g,0,sizeof(g));
		memset(mark,true,sizeof(mark));
		per(i,1,n){
			string str;
			cin >> str;
			int len = str.length();
			max_len = max(len,max_len);
			if(len > 1){
				mark[str[0] - 'a'] = false;
			}
			++g[str[0] - 'a'][0];
			per(i,1,len-1){
				++g[str[0] - 'a'][i];
			}
			solve();
		}
	}

	return 0;
}
