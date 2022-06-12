#include<iostream>
#include<string>
#include<vector>
#include<cstring> 
#include<algorithm>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
const int maxn = 2e2 + 10;
int n = 0;
string s;
struct node{
	int l,r;
};

int min_rep(string& str){
	int i = 1,j = 0,k = 0;
	int n = str.length();
	while(i < n && j < n){
		k = 0;
		while(str[(i+k) % n] == str[(j+k) % n] && k < n){
			++k;
		}
		if(k == n){
			return j;
		}
		if(str[i+k] > str[j+k]){
			if(i +k +1 > j){
				i = i+k+1;	
			}else{
				i = j+1;
			}
			//i = max(i+k+1 ,j + 1);
		}else{
			if(j+k+1 > i){
				j = j+k+1;	
			}else{
				j = i+1;
			}
			//j = max(j+k+1, i+1);
		}
	}
	return i < j? i :j; 
}

int main(){

	std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T = 0;
	cin >> T;
	while(T--){
		cin >> s;
		int len = s.length();
		int fir = 0,las = 0;
		
		vector<node> ans;
		while(las <= len-1){
			rep(i,len-1,fir){
				string tmp;
				per(j,fir,i){
					tmp += s[j];
				}
				if(min_rep(tmp) == 0){
					las = i;
					break;
				}
			}
			ans.push_back(node{fir,las});
			fir = las + 1;
			las=  fir;
		}
		int si = ans.size();
		per(i,0,si-1){
			per(j,ans[i].l,ans[i].r){
				printf("%c",s[j]);
			}
			printf(" ");
		}
		puts("");
	}
	
	return 0;
}
