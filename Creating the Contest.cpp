#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 100;
LL d[maxn];
int n = 0;
int solve(){
	int maxv = 0,cnt = 0;
	d[0] = 1e9;
	for(int i = 1;i <= n;++i){
		if(d[i] <= d[i - 1] * 2){
			++cnt;
		}else{
			maxv = max(maxv,cnt);
			cnt = 1;
		}
	}
	maxv = max(cnt,maxv);//最后一次没有执行else语句时，要添加，比如整个序列都满足条件时 
	return maxv;
}
int main(){
	
	while(cin >> n){
		for(int i = 1;i <= n;++i){
			cin >> d[i];
		}
		cout << solve() << endl;
	}	
	return 0;
}
