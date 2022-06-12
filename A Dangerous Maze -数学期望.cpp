#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#define INF 0x7fffffff
using namespace std;
const int maxn = 2002 + 10;

int gcd(int a,int b){
	return b == 0?a : gcd(b,a%b);
}
//公式的推导牛逼，突然感觉到了数学的力量了 
/*
有题目可知，离开这里的方法是无穷多种，所以一般的期望公式是没办法列出来的

我们先设离开这里的期望值是E;

很明显E=(t1+t2+……+tn + G1+G2+……+Gm)/(n+m);ps:t代表直接选到正数离开，
G代表包含负数 离开迷宫的情况

负数想要构成离开的条件就必须要和一个可以离开的情况构成搭配，
则Gm = abs(NEGATIVEm) + E;

则明显E = (t1+t2+……+tn + (abs(T1)+E)+(abs(T2)+E)+……+(abs(Tm)+E))/n 
→ E = (t1+t2+……+tn+abs(T1)+abs(T2)+……+abs(Tm))/(n-m);

特殊情况 n-m =0 时，答案为inf

*/
int main(){
	
	int T = 0,n = 0,temp = 0,kase = 0;	
	scanf("%d",&T);
	while(T--){
		int sum = 0,m = 0,nn = 0;
		scanf("%d",&n);
		for(int i = 0;i < n;++i){
			scanf("%d",&temp);
			if(temp < 0){
				++m;
			}
			sum += abs(temp);
		}
		nn = n - m;
		if(n - m == 0){
			printf("Case %d: inf\n",++kase);
		}else{
			int gg = gcd(sum,nn);//求他们的最大公约数 
				
			printf("Case %d: %d/%d\n",++kase,sum/gg,nn/gg);
		}
	}
	
	
	return 0;
}
