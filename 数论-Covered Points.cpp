#include<bits/stdc++.h>
#include<algorithm> 
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 100;
int n = 0;
int x1 = 0,y1 = 0,x2 = 0,y2 = 0;//关键是去重 
int gcd(int a,int b){
	/*
	if(b == 0){
		return a;
	}else{
		return gcd(b,a%b);
	}
	*/
	return b == 0 ? a : gcd(b,a%b);
}
LL solve(){
	int x = abs(x1-x2),y = abs(y1-y2);
	if(x < y){//swap(abs(x1-x2) , abs(y1-y2))是错误的	
		swap(x,y);
	}
	int num = gcd(x, y);
	return num;
}
int main(){
	while(scanf("%d",&n) != EOF){
		LL sum = 0;
		for(int i = 0;i < n;++i){
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			sum += (solve() + 1);
			//cout << "em " << solve() << endl;
		}
		printf("%I64d\n",sum);
	}
	
	return 0;
} 
