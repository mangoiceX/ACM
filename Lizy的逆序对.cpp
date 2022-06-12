#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define Sentinel 100000000

typedef long long LL;
const int Max = 1000000;

using namespace std;

int L[Max] , R[Max];
LL cnt = 0;

void merge(int *A,int left,int mid ,int right){
	int n1 = mid - left;
	int n2 = right - mid;
	
	for( int i = 0;i < n1;i++){
		L[i] = A[left + i];
	}
	for( int i = 0;i < n2;i++){
		R[i] = A[mid + i];
	} 
	
	L[n1] = Sentinel;
	R[n2] = Sentinel;
	
	int i = 0 ,j = 0;
	
	for(int k = left; k < right;k++){
		if(L[i] <= R[j] ){
			A[k] = L[i++];
		}else{
			if(i == n1){
				A[k] = R[j++];
				continue;
			}
			A[k] = R[j++];
			cnt++;
		}
	}
}

void mergeSort(int *A, int left ,int right){
	if(left + 1< right){
		int mid = (right - left) / 2 + left;
		mergeSort(A,left,mid);
		mergeSort(A,mid,right);
		merge(A,left,mid,right);
	}
}
int main(){
	int N,size;
	
	scanf("%d",&N);
	while( N-- ){
		cnt = 0;
		scanf("%d",&size);
		int *per = (int *)malloc( (size + 3) * sizeof(int));
		int *temp_per = (int *)malloc( (size + 3) * sizeof(int));;
		
		for(int i = 0;i < size;i++){	
			per[i] = i + 1;
		}		
		
		do{
			for(int i = 0;i < size;i++){
				//cout << per[i];
				temp_per[i] = per[i];
			}
			//cout << endl;
			mergeSort(temp_per ,0,size);
			
		}while(next_permutation( per, per+size) );
		free(per);
		free(temp_per);
		cnt = cnt % (1000000000 + 7);
		cout << cnt << endl;
	}
	
	
	
	return 0;
} 
