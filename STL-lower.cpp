#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 100;
int a[maxn];
int n = 0;
int solve(int x){
	int l = 1,r = n,mid = 0;
	int loc = 0;
	while(l <= r){//这里用<=与下面的r = mid-1,l = mid+1,和a[]数组下标从1->n是意义对应的 
		mid = (r - l)/2 + l;
		if(a[mid] == x){
			loc = mid;
			r = mid - 1;
		}else if(a[mid] < x){
			loc = mid;
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	//if(loc == 0){
	//	return a[mid] < x ? 
//		return l - 1;
//	}
	cout << "en " << l << " " << mid  << " " << r << endl;
	if(a[mid] == x){
		return loc;
	}else if(a[mid] < x){
		return l - 1;
	}else{
		return r + 1;
	}
//	return a[mid] <= x ? 
//	return loc;
}
int main(){
	while(cin >> n){
		for(int i = 1;i <= n;++i){//注意是从1->n 
			cin >> a[i];
		}
		sort(a + 1,a + n + 1);
		int key = 0;
		while(cin >> key){
			cout << solve(key)<< endl;	
		}
	}
	return 0;
}
