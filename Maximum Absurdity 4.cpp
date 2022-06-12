#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 2e5 + 100;
typedef unsigned long long LL; 
int data[maxn];
LL sum[maxn];
LL res[maxn];
int main(){
	int n = 0,k = 0;
	cin >> n >> k;
	memset(sum,0,sizeof(sum));
	for(int i = 1;i <= n;i++){
		cin >> data[i];
		sum[i] = sum[i-1] + data[i];//计算前缀和 
	}
	
	for(int i = 1;i <= n - k + 1;++i){
		res[i] = sum[i + k - 1] - sum[i - 1];//从i开始，后面k个数的和 
	}
	
	int left[maxn];
	left[1] = 1;
	int maxl = 1;
	for(int i = 1;i <= n-k+1;++i){
		//从前往后，right[i]表示的是从1到i区间和最大的区间的开始下标 
		if(res[i] > res[maxl]){
			maxl = i;
		}
		left[i] = maxl;
	}
	
	int right[maxn];
	right[n-k+1] = n-k+1;
	int maxr = n-k+1;
	for(int i = n-k+1;i >= 1;--i){
		//从后往前，right[i]表示的是从i到n区间和最大的区间的开始下标 
		if(res[i] >= res[maxr]){//这里是>= ，因为要求最小的下标，当区间和相等时，选择小的 
		
			maxr = i;
		}
		right[i] = maxr;
	}
	LL maxv = 0;
	int l = 0,r = 0;
	for(int i = 1;i <= n-k+1-k;++i){
		int j = i + k;
		if( (res[left[i]] + res[right[j]] ) > maxv){
			maxv = res[left[i]] + res[right[j]];
			l = left[i],r = right[j];
		}
	}
	cout << l << " " << r << endl;
	
	return 0;
}
