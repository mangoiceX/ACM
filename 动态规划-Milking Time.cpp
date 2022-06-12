#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1e6 + 10;
int dp[maxn];

struct Cow{
	int l,r;
	int val;
};

Cow cow[1010];
int N = 0,M = 0,R = 0;
bool cmp1(Cow a,Cow b){
	if(a.r != b.r){
		return a.r < b.r;
	}else{
		return a.l < b.l;
	}
	/*
 if(a.l==b.l)
        return a.r<b.r;
    return a.l<b.l;
	*/
}
int main(){
	
	cin >> N >> M >> R;
	for(int i = 1;i <= M;++i){
		cin >> cow[i].l >> cow[i].r >> cow[i].val;
	}
	
	sort(cow + 1,cow + M + 1,cmp1);
	
	for(int i = 1;i <= cow[1].r - 1;++i){
		dp[i] = 0;
	}
	for(int i = 1;i <= M;++i){
		dp[cow[i].r] = cow[i].val;
	}
	
	dp[cow[1].r] = cow[1].val;
	cow[0].l = cow[0].r =  cow[0].val = 0;
	int cnt = 2;
	for(int i = cow[1].r;i <= N;++i){
		if(i == cow[cnt].r){
			if(cow[cnt].l - cow[cnt-1].r >= R){
				dp[i] = dp[i-1] + cow[cnt].val;
			}else{
				int k = cnt - 1;
				while(cow[cnt].l - cow[k].r < R && k > 0){
					--k;
				}
				if(k < 1){
					k = 0;
				}
				dp[i] = max( dp[i-1], dp[cow[k].r] + cow[cnt].val);
			}
			if(cow[cnt].r == cow[cnt+1].r){
				--i;
			}
			++cnt;
		}else{
			dp[i] = max(dp[i-1],dp[i]);
		}
	}
//	for(int i = 1;i <= N;++i){
	//	cout << dp[i] << " ";
	//}
	//cout << endl;
	
	
	cout << dp[N] << endl;
	
	
	return 0;
}

