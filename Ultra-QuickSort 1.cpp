#include<iostream>
#include<cstdio>
#include<algorithm>	
#include<string>
#include<cstring>
#include<set>
using namespace std;
const int maxn = 5e5 + 10;
typedef unsigned long long LL; 
LL data[maxn], temp[maxn];
int n = 0;
LL ans = 0;
void merge(int l,int mid,int r){
	int k = 0;
	int p1 = l,p2 = mid + 1;
	
	while(p1 <= mid && p2 <= r){
		if(data[p2] < data[p1]){
			temp[k++] = data[p2++];
			ans += mid - p1 + 1;
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
	
	for(int i = l;i <= r;++i){
		data[i] = temp[i - l];
	}
	
}

void mergeSort(int l,int r){
	if(l < r){
		int mid = (r - l)/2 + l;
		mergeSort(l,mid);
		mergeSort(mid + 1,r);
		merge(l,mid,r);
	}
}
int main(){
	
	while(cin >> n && n){
		ans = 0;
		for(int i = 0;i < n;++i){
			cin >> data[i];
		}
		mergeSort(0,n - 1);//ÊÇ0 - n-1,²»ÊÇ0 - n 
		cout << ans << endl;
	}
	
	
	
	return 0;
} 
