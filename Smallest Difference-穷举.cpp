#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
const int maxn = 12;
int n = 0,ans = 0;
char str[30];
int data[maxn];

void solve(){
	if(n == 2){
		ans = data[1] - data[0];
		printf("%d\n",ans);
		return ;
	}
	
	while(data[0] == 0){//保证开头的数不是0 
	//函数next_permutation()是按照字典序产生排列的，
	//并且是从数组中当前的字典序开始依次增大直至到最大字典序。 
		next_permutation(data,data + n);//先把开头是0的，穷举完 
	}
	ans = INF;
	
	do{
		int mid = (n + 1)/2;//中间的数
		if(data[mid] != 0){
			int a = 0,b = 0; 
			for(int i = 0;i < mid;++i){	//n是奇数时，a的位数多一位 
				a = a * 10 + data[i];
			}
			for(int i = mid;i < n;++i){
				b = b * 10 + data[i];
			}
			ans = min(ans,abs(a-b));
		} 
		
	}while(next_permutation(data,data + n));
	
	printf("%d\n",ans);
}

int main(){
	int t= 0;
	//cin >> t;//cin与getchar(),gets(),不能一起使用 
	scanf("%d",&t);
	getchar();
	while(t--){
		gets(str); //此处要用gets读取一行，而不能用cin 去读 
		int len = strlen(str);
		for(int i = 0;i < len;++i){
			if(str[i] >= '0' && str[i] <= '9'){
				data[n++] = str[i] - '0';//n最后等于数的个数 
			}
		}
		solve();
	}	
	return 0;	
} 
