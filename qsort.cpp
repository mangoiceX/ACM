#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

typedef long long LL;

#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
const int maxn = 3e5;
int n = 0,m = 0;
int a[maxn+10];
int findpivotindex(int i,int j){
	return (i + j) / 2;
}
void swap(int* arr,int i,int j){
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}
int partition(int *arr,int l,int r,int pivot){
	do{
		while(arr[++l] < pivot);
		while((l < r) && (arr[--r] > pivot));
		swap(arr,l,r);
	}while(l < r);
	return l;
}
/*
void qsort(int *arr,int i,int j){
	if(j <= i){
		return ;
	}
	int pivotindex = findpivotindex(i,j);
	swap(arr,pivotindex,j);
	int k = partition(arr,i-1,j,arr[j]);
	swap(arr,k,j);
	qsort(arr,i,k-1);
	qsort(arr,k+1,j);
}
*/
void qsort(int* arr,int i,int j,int k0){
	if(j <= i){
		return ;
	}
	int pivotindex = findpivotindex(i,j);
	swap(arr,pivotindex,j);
	int k = partition(arr,i-1,j,arr[j]);
	swap(arr,k,j);
	/*
	per(i,0,n-1){
		printf("%d%c",a[i],(i == n - 1) ? '\n' : ' ');
	}
	*/
	if(k == k0 || k == (k0 - 1)){
		qsort(arr,i,k-1,k0);
	}else if(k > k0){
		qsort(arr,i,k-1,k0);
	}else{
		qsort(arr,i,k-1,k0);
		qsort(arr,k+1,j,k0);
	}
}
int main(){
	int k0 = 0;
	while(~scanf("%d",&n)){
		per(i,0,n-1){
			scanf("%d",&a[i]);
		}
		scanf("%d",&k0);
		qsort(a,0,n-1,k0);
		per(i,0,n-1){
			printf("%d%c",a[i],(i == n - 1) ? '\n' : ' ');
		}
	}
	return 0;
}

