#include<iostream>
#include<cstdio>
#include<map>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
const int maxn = 100 + 10;
using namespace std;
struct Node{
	int num;
	int flag = -1; 
	bool operator < (const Node& a)const{
		return num < a.num;
	}
};
priority_queue <Node> node;
int data[maxn];
int main(){
	
	int T = 0,n = 0,m = 0,temp = 0;
	Node noe;
	cin >> T;
	while(T--){
		cin >> n >> m;
		for(int i = 0;i < n;++i){
			 cin >> temp;
			 noe.num = temp;
			 if(i == m){
			 	noe.flag = 1;
			 }else{
			 	noe.flag = 0;
			 }
			 node.push(noe);
		}
		
		int loc = 0;
		while(!node.empty()){
			Node k = node.top();
			cout <<" Êý×Ö£º " << k.num <<" ±ê¼Ç£º" << k.flag << endl;
			node.pop();
		}
		for(int i = 0;i < n;++i){
			Node nod;
			nod = node.top();
			if(nod.flag == 1){
				loc = i;
			}
			node.pop();
		}
		cout << loc + 1<< endl;
		
	}
	
	
	return 0;
}
