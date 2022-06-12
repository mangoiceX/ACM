#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#define INF 0x7fffffff
using namespace std;
typedef long long LL;
const int maxn = 20004;
int n = 0,l = 0,r = 0,num = 0,q = 0;
struct Node{
	int num = 0;
	char c;
};
Node node[27];
char str[maxn];
char ch;
int ans = 0;
void solve(int num){
	
	int xunhuan = 0;
	xunhuan = (r - l + 1) / n;
	/*
	if(xunhuan == 0){
		if(r / n > l / n){
			for(int i = l % n - 1;i < r %n + n ;++i){
				if(str[i] == ch){
					++ans;
				}
			}
		}else{
			for(int i = l % n - 1;i < r %n  ;++i){
				if(str[i] == ch){
					++ans;
				}
			}
		}
		*/
	//}else{
		ans += xunhuan * num;
		for(int i = l%n - 1;i < (r-xunhuan*n) % (2 * n) ;++i){
			if(str[i] == ch){
				++ans;
			}
		}
//	}
	
}
int main(){
	int T = 0;
	scanf("%d",&T);
	getchar();
	while(T--){
		scanf("%d %d",&n,&q);
		getchar();
		scanf("%s",str);
		
		for(int j = 0;j < n;++j){
			++node[str[j]-'a'].num;
		}
		for(int j = n;j < 2 * n;++j){
			str[j] = str[j-n];
		}
		for(int i = 0;i < q;++i){
			ans = 0;
			scanf("%d %d %c",&l,&r,&ch);
			
			solve(node[ch-'a'].num);
			printf("%d\n",ans);
		}
		
	}
	

	
	return 0;
} 
