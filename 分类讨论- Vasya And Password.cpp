#include<iostream>
#include<cstdio>
#include<vector>
#include<bitset>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<fstream>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define pii pair<int, int>
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define PER(i,x) for(auto i=x.begin();i!=x.end();i++)
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
typedef long long LL;
const double eps=1.0e-5;
const int maxn=2e5 + 10;

int cnt1=0,cnt2=0,cnt3=0,n = 0,tmp = 0,a[maxn],b[maxn],c[maxn],ma=-inf,flag;
string str;
void solve(){
	int len = str.size();
	cnt1 = cnt2 = cnt3 = 0;
	per(i,0,len - 1){
		if(str[i] >= 'a' && str[i] <= 'z'){
			a[cnt1++] = i;
		}else if(str[i] >= 'A' && str[i] <= 'Z'){
			b[cnt2++] = i;
		}else{
			c[cnt3++] = i;
		}
	}
	if(cnt1 > 0 && cnt2 > 0 && cnt3 > 0){
		cout << str << endl;
		return ;
	}
	if(cnt1 == 0  && cnt2 > 0 && cnt3 > 0){
		if(cnt2 > 1){
			str[b[cnt2-1]] = 'a';
			cout << str << endl;
			return ;
		}
		if(cnt3 > 1){
			str[c[cnt3-1]] = 'a';
			cout << str << endl;
			return ;
		}
	}
	
	if(cnt2 == 0  && cnt1 > 0 && cnt3 > 0){
		if(cnt1 > 1){
			str[a[cnt1-1]] = 'A';
			cout << str << endl;
			return ;
		}
		if(cnt3 > 1){
			str[c[cnt3-1]] = 'A';
			cout << str << endl;
			return ;
		}
	
	}
	
	if(cnt3 == 0  && cnt1 > 0 && cnt2 > 0){
		if(cnt1 > 1){
			str[a[cnt1-1]] = '1';
			cout << str << endl;
			return ; 
		}
		if(cnt2 > 1){
			str[b[cnt2-1]] = '1';
			cout << str << endl;
			return ;
		}
	}
	if(cnt1 == 0 && cnt2 == 0){
		str[c[cnt3-1]] = 'a';
		str[c[cnt3-2]] = 'A';
		cout << str <<endl;
		return ;
	}
	if(cnt1 == 0 && cnt3 == 0){
		str[b[cnt2-1]] = 'a';
		str[b[cnt2-2]] = '1';
		cout << str <<endl;
		return ;
	}
	if(cnt3 == 0 && cnt2 == 0){
		str[a[cnt1-1]] = 'A';
		str[a[cnt1-2]] = '1';
		cout << str <<endl;
		return ;
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	int T = 0;
	//scanf("%d",&T); 
	cin >> T;
	while(T--){
		cin >> str;
		solve();
	}
	
	return 0; 
}
