#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 1000;

class heap{
	private:
		void siftdown(int pos){
			while(!isLeaf(pos)){
				int j = leftChild(pos);
				int rc = rightChild(pos);
				if((rc < n) && (Heap[rc] < Heap[j])){
					j = rc;
				}
				if(Heap[pos] <= Heap[j]){
					return ;
				}
				int tmp = Heap[pos];
				Heap[pos] = Heap[j];Heap[j] = tmp;
				pos = j;
			}
		}
	public:
		int* Heap;
		int n;
		heap(){
		}
		heap(int num){
			Heap = new int[num+10];
			n = num;
			buildHeap();
		}
		int size(){
			return n;
		}
		bool isLeaf(int pos){
			return (pos >= n/2) && (pos < n);
		}
		int leftChild(int pos){
			return 2*pos+1;
		}
		int rightChild(int pos){
			return 2*pos+2;
		}
		int parent(int pos){
			return (pos-1)/2;
		}
		void buildHeap(){
			for(int i = n/2-1;i >= 0;--i){
				siftdown(i);
			}
		}
		void insert(int& it){
			int curr = n++;
			Heap[curr] = it;
			int pos = parent[curr];
			while(curr != 0 && (Heap[curr] < Heap[pos])){
				int tmp = Heap[curr];
				Heap[curr] = Heap[pos];Heap[pos] = tmp;
				curr = pos;
			}
		}
};
int main(){
	int m = 0,ni = 0;
	scanf("%d %d",&m,&ni);
	heap(m);
	char str[maxn+10];
	for(int i = 0;i < m;++i){
		int x = 0;
		scanf("%d",&x);
		heap.insert(x);
	}
	for(int j = 0;j < ni;++j){
		scanf("%s",str);
		int size = strlen(str);
		if(size == 13){
			if((str[0] - '0') == Heap[0]){
				printf("T\n");
			}else{
				printf("F\n");
			}
		}else if(size == 20){
			for(int i = 0;i < m-1;++i){
				if((Heap[i] == str[0] && Heap[i+1] == str[6] && (i&1)) ||
				 (Heap[i] == str[6] && Heap[i+1] == str[0] && (i&1)) ){
				 	printf("T\n");
				 }else{
				 	printf("F\n");
				 }
			}
		}else if(size == 17){
			for(int i = 0;i < m;++i){
				if(Heap[i] == str[16]){
					if(Heap[parent[i]] == str[0]){
						printf("T\n");
					}else{
						printf("F\n");
					}
				}
			}
		}else{
			for(int i = 0;i < m;++i){
				if(Heap[i] == str[0]){
					if(Heap[parent[i]] == str[19]){
						printf("T\n");
					}else{
						printf("F\n");
					}
				}
			}	
		}
	}
	
	return 0;
} 
