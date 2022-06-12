#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<set>
using namespace std;
const int maxn = 1e4 + 100;
struct node{
	int cnt;
	node *nex[10];
	node(){
		cnt = 0;
		memset(nex,0,sizeof(nex));
	}
};

node* root = new node;

void insert(string s){
	node* p = root;
	int len = s.size();
	for(int i = 0;i < len;++i){
		if(p->nex[s[i] - '0'] == NULL){
			node* tmp = new node;
			p->nex[s[i] - '0'] = tmp;
		}
		p = p->nex[s[i] - '0'];
		++p->cnt;
		//cout << "en "<<p->cnt <<endl;
	}
}

int search(string s){
	node* p = root;
	int len = s.size();
	for(int i = 0;i < len;++i){
		if(p->nex[s[i] - '0'] == NULL){
			return 0;
		}
		p = p->nex[s[i] - '0'];
		//if(p == NULL){
		//	return p->cnt;
		//}
	}
	//cout << "mo " << p->cnt << endl; 
	return p->cnt;
}
void del(node* root){
	if(root == NULL){
		return ;
	}else{
		for(int i = 0;i < 10;++i){
			if(root->nex[i]){
				del(root->nex[i]);
			}
		}
	}
	delete root;
}
int main(){
	int T = 0,n = 0,flag = 0;
	string str[maxn];
	cin >> T;
	while(T--){
		flag = 0;
		cin >> n;
		for(int i = 0;i < n;++i){
			cin >> str[i];
			/*
			if(search(str) != 0){
				//cout << "NO" << endl;
				//flag = 1;
			}else{
				insert(str);
			}
			*/
			insert(str[i]);//先全部预处理，在查询 
		}
		for(int i = 0;i < n;++i){
			if(search(str[i]) > 1){//表明他是别人的前缀 
				flag = 1;
			}
		}
		if(flag == 1){
			cout << "NO" << endl;
		}else{
			cout << "YES" << endl;
		}
		del(root);
		root = new node;
	}

	return 0;
}
