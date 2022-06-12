
#include <bits/stdc++.h> 
using namespace std;
 
int a[]={1,3,3};
int n = 3;
 
void print(){
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
//第x个数与第y个数交换时，要求[x,y)中没有与第y个数相等的数。 
bool isswap(int x,int y){
	for(int i=x;i<y;i++){
		if(a[i] == a[y])	return false;
	}
	return true;
}
 
void swap(int u,int v){
	int t=a[u];
	a[u]=a[v];
	a[v]=t;
}
 
void prem(int k){
	if(k == n-1){
		print();
		return;
	}
	for(int i=k;i<n;i++){
		if(isswap(k,i)){
			swap(k,i);
			prem(k+1);
			swap(k,i);
		}
	}
}
 
int main(){
	prem(0);
	
	return 0;
}

