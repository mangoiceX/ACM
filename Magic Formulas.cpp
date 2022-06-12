#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std; 
const int maxn = 1e6 + 10;
int data[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n = 0,temp = 0;
	//cin >> n;
	scanf("%d",&n);
	for(int i = 1;i <= n;++i){
		//cin >> temp;
		scanf("%d",&temp);
		for(int j = 1;j <= n;++j){
			temp ^= (i % j);
		} 
		data[i] = temp;
	}
	int ans = data[1];
	for(int i = 2;i <= n;++i){
		ans ^= data[i];
	}
	cout << ans << endl;
	return 0;
}
