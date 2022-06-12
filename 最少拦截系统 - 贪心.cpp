#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string> 
#include<cstring>
#include<set>
#define INF 0x7fffffff
using namespace std;
const int maxn = 100000 + 10;
int a[maxn];
int main(){
	int n = 0;
	while(cin >> n && n){
		for(int i = 1;i <= n;++i){
			cin >> a[i];
		}
		
		int ans = 1,i = 0,j = 0;
		for(i = 2;i <= n;++i){
			int flag = 1;
			for(j = 1;j <= ans;++j){//第i套的当前最小值存在第i个位置 
				if(a[i] < a[j]){		//找到大于的导弹系统 
					a[j] = a[i];
					flag = 0;
					break;
				}
			}
			if(flag == 1){		//找不到导弹系统，新建一个，在后面新加一个导弹系统 
				a[j] = a[i];//j已经++，所以不用再j+1 
				ans++;
			}
		}
		cout << ans << endl; 
	}
	
	
	
	
	
	
	return 0;
} 
