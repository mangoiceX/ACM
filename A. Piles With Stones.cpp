#include<iostream>
#include<cstdio>
#include<algorithm>	
#include<string>
#include<cstring>
#include<set>
using namespace std;
const int maxn = 50 + 10;
struct Node{
	int num;
	int flag = 0;//flag标记是否用过 
	bool operator == (Node b){
		if(this->num != b.num){
			return false;
		}
		if(this->flag != b.flag){
			return false;
		}
		return true;
	}
}; 
//Node node1[maxn],node2[maxn];
multiset<Node> st1,st2;
int main(){
	int n = 0;
	Node temp ;
	scanf("%d",&n);

	for(int i = 0;i < n;++i){
		//cin >> node1[i].num;
		scanf("%d",&temp.num);
		
		st1.insert(temp);
	}
	for(int i = 0;i < n;++i){
		//cin >> node2[i].num;
		scanf("%d",&temp.num);
		st2.insert(temp);
	}
	multiset<Node>::iterator iter1,iter2;
	int fg = 1;
	for(iter1 = st2.begin();iter1 != st2.end();++iter1){
		if( (*iter1).num == 0){
			//(*iter1).num = 1;
			continue;
		}
		iter2 = st1.find(*iter1);
		if(iter2 != st1.end() && (*iter2).flag == 0 ){
			(*iter2).flag = 1;
		}else{
			fg = 0;
			break;
		}
	}
	
	if(fg == 0){
		printf("NO\n");
	}else{
		printf("YES\n");
	}
	
	
	return 0;
}
