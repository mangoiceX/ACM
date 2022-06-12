#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1000 + 10;
int dp[maxn];

struct Cow{
	int l,r;
	int val;
};

Cow cow[maxn];
int N = 0,M = 0,R = 0;
bool cmp1(Cow a,Cow b){
	/*
	if(a.l == b.l){
		return a.r < b.r;
	}else{
		return a.l < b.l;
	}
	*/
	/*
 if(a.r!=b.r)
       return a.l<b.l;
    return a.r<b.r;
	*/
	if(a.r == b.r){
		return a.l < b.l;
	}else{
		return a.r < b.r;
	}
}
int main(){
	
	cin >> N >> M >> R;
	for(int i = 1;i <= M;++i){
		cin >> cow[i].l >> cow[i].r >> cow[i].val;
	}
	
	sort(cow + 1,cow + M + 1,cmp1);
	
	//dp[1] = cow[1].val;
	for(int i = 1;i <= M;++i){//dp[i]表示的是选第i个区间时的最大值 
		dp[i] = cow[i].val;
	}
	for(int i = 2;i <= M;++i){
		for(int j = 1;j < i;++j){
			if(cow[i].l - cow[j].r >= R){
				dp[i] = max( dp[j] + cow[i].val, dp[i]);//类似于LIS 
			}
		}
	}
	int maxv = 0;
	for(int i = 1;i <= M;++i){
		maxv = max( maxv,dp[i]);
	}
	cout << maxv << endl;
	
	return 0;
}

