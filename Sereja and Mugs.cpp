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
const int maxn = 100 + 10;
int mug[maxn];
int n = 0,s = 0;
int main(){
	cin >> n >> s;
	for(int i = 0;i < n;++i){
		cin >> mug[i];
	}
	sort(mug,mug + n);
	int v  = 0;
	for(int i = 0;i < n - 1;++i){
		v += mug[i];
	}
	if(v <= s){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	
	return 0;
}
