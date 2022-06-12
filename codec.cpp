#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
typedef  int LL;
const int maxn = 1000000;
map<LL,LL> mp;
LL num[maxn];
LL ma[maxn];



bool compare(LL a,LL b){
	return a > b;
}
int main(){
	int N = 0;
	cin >> N;
	int cnt = 0,cou = 0;

	LL a;
	mp.clear();
	for(int i = 0;i < N;i++){
		ma[i] = 1;	
	}
	
	for(int i = 0;i < N;i++){
		cin >> a;
		if(cou == 0){
			num[0] = a;	
			cou++;
		}else{
			for(int j = 0;j < cou;j++){
				if(a == num[j]){
					
					break;
				}
			}
			num[cou] = a;
			cou++;
		}
		mp[a] = ma[a];
		ma[a]++;
	}
	sort(num,num + cou,compare);
	LL sum = 0;
	for(int i = N - 1;i >= 0;--i){
		
		sum += mp[num[i]];		
		if(mp[ma[i - 1]] <= sum){
			cnt += mp[num[i-1]];	
			sum -= mp[num[i-1]];
		}else{
			cnt += sum;
			sum = 0;
		}
	}
	
	cout << cnt << endl;
	
	return 0;
}
