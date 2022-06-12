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
#include<cmath>

using namespace std;

typedef long long LL;

#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
const int maxn = 3e5;
int n = 0,m = 0; 
char s1[10],s2[10],s3[10];
int num1[3],num2[3];
void solve(){
	num1[1] = (s1[0] - '0')*10 + (s1[1] - '0');
	num1[2] = (s1[3] - '0')*10 + (s1[4] - '0');
	
	num2[1] = (s2[0] - '0')*10 + (s2[1] - '0');
	num2[2] = (s2[3] - '0')*10 + (s2[4] - '0');
	
	int sum = (num2[1] - (num1[1]+1))*60;
	sum += (num2[2] + 60 - num1[2]);
	sum /= 2;
	
	per(i,1,sum){
		num1[2] += 1;
		if(num1[2] == 60){
			num1[1] += 1;
			num1[2] = 0;
		}
	}
	if(num1[1] < 10){
		printf("0");
	}
	printf("%d:",num1[1]);
	if(num1[2] < 10){
		printf("0");
	}
	printf("%d",num1[2]);
}
int main(){
	//std::ios::sync_with_stdio(false);
	scanf("%s",s1);
	scanf("%s",s2);
	solve();
	
	return 0;
}

