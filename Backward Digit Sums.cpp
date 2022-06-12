#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int n = 0,key = 0;
const int maxn = 12;

int data[maxn],a[maxn];
bool judge(){
	for(int i = 1;i <= n;++i){
		a[i] = data[i];
	}
	for(int k = n;k >= 1;--k){
		for(int i = k;i >= 2;--i){
			a[k - i + 1] += a[k - i + 2];
		}
	}
	if(a[1] == key){
		return true;
	}else{
		return false;
	}
}
void solve(){
	do{
		if(judge()){
			for(int i = 1;i <= n;++i){
				if(i - 1 > 0){
					cout << " ";
				}
				cout << data[i];
			}
			cout << endl;
			break;
		}
		
	}while(next_permutation(data + 1,data + n + 1));
	
	
	
}
int main(){
	while(cin >> n >> key && n && key){
		
		for(int i = 1;i <= n;++i){
			data[i] = i;
		}
		solve();
	}
	
	
	
	return 0;
}
