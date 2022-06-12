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


void mergeSort(int *A,int *c, int l,int r){
	/*f(left + 1< right){
		int mid = (right - left) / 2 + left;
		mergeSort(A,left,mid);
		mergeSort(A,mid,right);
		merge(A,left,mid,right);
	}*/
	int mid, i ,j,temp;
	if( r > l + 1){
		mid = (l + r) / 2;
		mergeSort(A,c,l,mid);
		mergeSort(A,c,mid,r);
		temp = l;
		for(i = 1, j = mid;i < mid && j < r;){
			if(A[i] > A[j]){
				c[temp++] = A[j++];
				cnt += mid - i; 
			}else{
				c[temp++] = A[i++];
			}
		}
		if(j < r){
			for(;j < r;++j){
				c[temp++] = A[j];
			}
		}else{
			for(;i< mid;++i){
				c[temp++] = A[i];
				
			}
		}
		for(i = 1;i < r;++i){
			A[i] = c[i];
		}
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
			mergeSort(temp_per,temp_per,0,size);
			
		}while(next_permutation( per, per+size) );
		free(per);
		free(temp_per);
		cnt = cnt % (1000000000 + 7);
		cout << cnt << endl;
	}
	
	
	
	return 0;
} 
