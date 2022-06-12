#include<iostream> 
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#include<map>
#include<cmath>
#include<queue>
using namespace std;
const int maxn = 100000 + 10;
int n = 0,ans = 0;
int data[maxn];
void solve(){
	int sum = 0;
	for(int i = 0;i < n;++i){
		sum += data[i];
		if(sum < 0){
			++ans;
			sum = 0;
		}
		
	}	
}
int main(){
	
	cin >> n;
	for(int i = 0;i < n;++i){
		cin >> data[i];
	}
	solve();
	cout << ans << endl;
	
	return 0;
}
