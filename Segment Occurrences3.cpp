#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(false);cin.tie(0);
#define pii pair<int,int>
#define vi vector<int>
#define vc vector<char>
#define mii map<int,int>
#define si(a) scanf("%d",&a)
#define ss(a) scanf("%s",&a)
#define sl(a) scanf("%I64d",&a);
#define slf(a) scanf("%lf",&a);
#define CLEAR(a,b) memset(a,b,sizeof(a))
#define pi acos(-1)

typedef long long ll;
typedef unsigned long long ull;

const int INF=0x3f3f3f3f;
const int N=2e5+5;
using namespace std;

int n = 0,m = 0,q = 0,l = 0,r = 0;
string str1,str2;
bool vis[1010];
int main(){
	
	ios::sync_with_stdio(false);
	
	cin >> n >> m >> q;
	cin >> str1 >> str2;
	memset(vis,false,sizeof(vis));
	if(n < m){			//特殊情况预处理，可以避免不必要的计算，提高效率 
		while(q--){
			cin >> l >> r;
			cout << "0" << endl;
		}
		
	}else{
		
		for(int i = 0;i <= str1.size() - m;++i){
			if(str1[i] == str2[0]){
			
				vis[i] = true;
				for(int k = i;k < i + m;++k){
					if(str1[k] != str2[k-i]){
						vis[i] = false;
						break;
					}
				}
				
			}
		}
		//for(int i = 0;i < str1.size();++i){
		//	cout << vis[i] << " ";
		//}
		//cout << endl; 
		while(q--){
			int cnt = 0;
			cin >> l >> r;
			if(r - l + 1 < m){
				cout << "0" << endl;
				continue;
			}
			for(int i = l-1;i <= r - 1 - m + 1;++i){
				if(vis[i] == true){
					++cnt;
				}
			}
			cout << cnt << endl;
		}
		
	}
	
	
	
	return 0;
} 
