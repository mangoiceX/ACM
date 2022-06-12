#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
const int maxn = 10100;
vector< vector<int> > vec(30);
char str[maxn];
int n = 0,ans = 0;
void solve(int l,int r,char ch){
	int cycle = 0;
	cycle = (r - l + 1) / n;
	int re = 0,le = 0;
	ans += vec[ch - 'a'].size() * cycle;
	vector<int >::iterator up1,up2;
	if(r / n == l / n){
		le = l % n,re = r % n;
		up1 = upper_bound(vec[ch - 'a'].begin(),vec[ch - 'a'].end(),le);
		up2 = upper_bound(vec[ch - 'a'].begin(),vec[ch - 'a'].end(),re);
		ans += up2 - up1;
	}else{
		le = l % n,re = r % n ;
		up1 = upper_bound(vec[ch - 'a'].begin(),vec[ch - 'a'].end(),le);
		up2 = upper_bound(vec[ch - 'a'].begin(),vec[ch - 'a'].end(),re);
		ans += vec[ch - 'a'].end() - up1 +  up2 - vec[ch - 'a'].begin() + 1;
	}
	
}
int main(){
	int T = 0,q = 0,l = 0,r = 0;
	char ch;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&q);
		scanf("%s",str);
		
		for(int i = 0;i < n;++i){	//存储各个字母出现的位置 
			vec[str[i] - 'a'].push_back(i + 1);
		}
		for(int i = 0;i < q;++i){
			ans = 0;	
			scanf("%d %d %c",&l,&r,&ch);
			solve(l,r,ch);
			printf("%d\n",ans);
		}	
		
	}
	
	
	
	return 0;
}
