#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 100;
typedef long long LL;
int fa[maxn];//存储a的因子
LL a = 0,b = 0;
LL solve(LL part,LL sum){
	int cnt = 0;
	for(LL i = 1;i * i <= part;++i){//保存part的因子(小于sqrt(n)的因子)，
										//大于sqrt(n)的因子,会重复计算 
		if(part % i == 0){
			fa[++cnt] = i;
		}
	}
	LL ans = 2*sum + 2;//设置初始值 
	for(LL i = 1;i * i <= sum;++i){
		if(sum % i == 0){
			LL size = 1; 
			while(fa[size] <= i && size <= cnt){//part和sum较短的边满足的关系 
				if(part/fa[size] <= sum/i){//part和sum较长的边 足的关系 
					ans = min(ans,2*(i + sum/i));
					//++size; //放在if外面，要不然陷入死循环 ，又是粗心大意 
				}
				++size;
			}
		}
	}
	return ans;
}
int main(){
	while(scanf("%I64d %I64d",&a,&b) != EOF){
		LL ans = min(solve(a,a+b),solve(b,a+b));//分别枚举a,b是小矩形的情况 
		printf("%I64d\n",ans); 
	}
	
	return 0;
} 
