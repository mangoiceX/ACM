#include<iostream>
#include<cstdio> 
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 500010;

typedef unsigned long long LL;
LL ans = 0;
LL data[maxn],temp[maxn];
void merge(int size,int l,int mid,int r){
	int k = 0;
	int p1 = l,p2 = mid + 1;
	
	while(p1 <= mid && p2 <= r){
		if(data[p2] < data[p1]){
			temp[k++] = data[p2++];
			ans += mid - p1 + 1;//求逆序对的公式 
		}else{
			temp[k++] = data[p1++];
		}
	}
	
	while(p1 <= mid){
		temp[k++] = data[p1++];
	}
	while(p2 <= r){
		temp[k++] = data[p2++];
	}
	
	for(int k = l;k <= r;++k){
		data[k] = temp[k-l];
	}
	
}

void merge_sort(int size,int l,int r){
	if(l < r){
		int mid = (r - l)/2 + l;
		merge_sort(size,l,mid);
		merge_sort(size,mid+1,r);
		merge(size,l,mid,r);
	}
}
int main(){
	int n = 0;
	while(cin >> n && n){
		ans = 0;
		for(int i = 0;i < n;++i){
			cin >> data[i];
		}		
		merge_sort(n,0,n-1);
		cout << ans << endl;
	}
	
	return 0;
}
