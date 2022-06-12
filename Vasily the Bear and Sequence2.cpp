#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 2e5 + 100;

int data[maxn],ans[maxn];
int n = 0;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1;i <= n;++i){
		cin >> data[i];
	}
	for(int i = 30;i >= 0;--i){
		int temp = (1 << i) - 1;//除了最高位是0，后面的全是1，用来提取该位后面的数 
		int cnt = 0;
		for(int j = 1;j <= n;++j){
			if(data[j] & (1 << i)){//最高位是1 
				temp = temp & data[j];//最高位后面的数不断做&运算 
				ans[++cnt] = data[j];
			}
		}
		if(temp == 0){//判断后面的能否全部变成0 
			cout << cnt << endl;
			for(int k = 1;k <= cnt;++k){
				if(k > 1){
					cout << " ";
				}
				cout << ans[k];
			}
			cout << endl;
			break;
		}
		
	}
		
	return 0;
}
