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
}; 
Node node1[maxn],node2[maxn];
bool cmp(Node a,Node b){
	return a.num < b.num;
}
int main(){
	int n = 0;
	Node temp ;
	scanf("%d",&n);

	for(int i = 0;i < n;++i){
		//cin >> node1[i].num;
		scanf("%d",&node1[i].num);	
	}
	for(int i = 0;i < n;++i){
		//cin >> node2[i].num;
		scanf("%d",&node2[i].num);
		//st2.insert(temp);
	}
	int fg = 0;
	sort(node1,node1 + n,cmp);
	sort(node2,node2 + n,cmp);
	int cnt1 = 0,cnt2 = 0;
	for(int i = 0;i < n;++i){
		if(node1[i].num == 0){
			++cnt1;
		}else{
			break;
		}	
	}
	for(int i = 0;i < n;++i){
		if(node2[i].num == 0){
			++cnt2;
		}else{
			break;
		}	
	}
	if(cnt2 < cnt1){
		printf("NO\n");
	}else{
		
	fg += cnt2 ;
	for(int i =0 + cnt2;i < n;++i){
		for(int j = 0 + cnt1;j < n;++j){
			if(node2[i].num == node1[j].num && node1[j].flag == 0){
				node1[j].flag = 1;
				++fg;
				break;
			}
		}
	}
	if(fg != n){
		printf("NO\n");
	}else{
		printf("YES\n");
	}
}
	
	return 0;
}
