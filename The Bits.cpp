#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;
typedef unsigned long long ULL;
const int maxn = 1e5 + 100;
string str1,str2;
int sum1[maxn],sum2[maxn];
int main(){
	int n = 0;
	cin >> n;
	cin >> str1 ;
	cin >> str2;
	memset(sum1,0,sizeof(sum1));
	memset(sum2,0,sizeof(sum2));
	int cnt1 = 0,cnt2 = 0,cnt3 = 0,cnt4 = 0;
	
	for(int i = n - 1;i >= 0;--i){
		if(str1[i] == '0' && str2[i] == '0' ){
			sum1[i] = cnt1;
		}
		if(str1[i] == '1' && str2[i] == '0' ){
			sum2[i] = cnt3;
		}
		if(str2[i] == '0' && str1[i] == '1'){
			++cnt1;
		}
		if(str2[i] == '1' && str1[i] == '1'){
			++cnt2;
		}
		if(str2[i] == '0' && str1[i] == '0'){
			++cnt3;
		}
		if(str2[i] == '1' && str1[i] == '0'){
			++cnt4;
		}
	}

	ULL ans = 0;
	for(int i = 0;i < n;++i){
		if(str1[i] == '0' && str2[i] == '0'){
			ans += sum1[i] + cnt2;
		}
		if(str1[i] == '1' && str2[i] == '0'){
			ans += sum2[i] + cnt4;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
