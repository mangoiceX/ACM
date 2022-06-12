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

using namespace std;
const int maxn = 1e3;

typedef long long LL;

#define inf 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
double INF = 1.0;
LL v[maxn+10],w[maxn+10];
int n = 0,k = 0;
double y[maxn+10];
bool check(double x){
	for(int i = 0;i < n;++i){
		y[i] = v[i] - x*w[i];
	}
	sort(y,y+n);
	double sum = 0;
	for(int i = 0;i < k;++i){
		sum += y[n - i - 1];
	}
	//cout << "haha " << sum << endl;
	return sum >= 0;
}
void solve(){
	double lb = 0,rb = INF,mid = 0;
	for(int i = 0;i < 2000;++i){
		mid = (lb + rb)/2;
		//cout << "nima " << mid << endl;
		if(check(mid)){
			lb = mid;
		}else{
			rb = mid;
		}
	}
	//cout << lb << " " << mid << " " << rb << endl;
	/*
	int flag1 = 0;
	if(int(mid*100000) % 10 >= 5){
		flag1 = 1;
	}
	int flag2 = 0;
	if(int(mid*10000 + flag1) % 10 >= 5){
		flag2 = 1;
	}
	*/
	int flag = 0;
	if(int(mid*1000) % 10 >= 5){
		flag = 1;
	}
	//rb = 0.835;
	printf("%d\n",int(mid * 100) / 1 + flag);
} 	
int main(){
	while(~scanf("%d %d",&n,&k) && (n != 0 || k != 0)){
		k = n - k;
		/*
		if(k == 0){
			printf("0\n");
			continue;
		}
		*/
		/*
		if(k == 0){
			printf("100\n")
		}
		*/
		for(int i = 0;i < n;++i){
			scanf("%lld",&v[i]);
		}
		for(int i = 0;i < n;++i){
			scanf("%lld",&w[i]);
		}
		solve();
	}
	
	return 0;
}




