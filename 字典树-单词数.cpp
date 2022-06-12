#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<set>
using namespace std;
const int maxn = 1e4 + 10;

struct node{
	int cnt;
	node* nex[26];
	bool used;
	node(){
		cnt = 0;
		memset(nex,0,sizeof(nex));
		used = false;
	}

}; 
node root;
void inseart(string s){
	node* p = &root;
	int len = s.size();
	for(int i = 0;i < len;++i){
		if(p->nex[s[i] - 'a'] == NULL){
			node* temp = new node;
			p->nex[s[i] - 'a'] = temp;
		}
		p = p->nex[s[i] - 'a'];
		++p->cnt;
	}
}

int search(string s){
	node* p = &root;
	//int len = strlen(s);
	int len = s.size();
	for(int i = 0;i < len;++i){
		if(p->nex[s[i] - 'a'] == NULL){
			return 0;
		}
		p = p->nex[s[i] - 'a'];
		if(i == len -1){
			//if(p->nex[s[i+1] - 'a']){
			//	return 0;
			//}
			for(int j = 0;j < 26;++j){
				if(p->nex[j] && p->used == false){
					p->used = true;
					return 0;
				}
			}
		}
	}
	return p->cnt;
}
void del(node* root){
	for(int i = 0;i < 10;++i){
		if(root->nex[i]){
			del(root->nex[i]);
		}
	}
	//del(root);
	delete root;
}
int main(){
	
	string s,str;
	int flag = 0;
	while(getline(cin , s)){
		if(s == "#"){
			break;
		}
		int ans = 0;
		for(int i = 0;i < s.size();++i){
			str = "";
			flag = 0;
			while(s[i] >= 'a' && s[i] <= 'z'){
				str += s[i];
				flag = 1;
				++i;
			}
			//cout << "em " << str << endl;
			if(flag == 1){
				/*
				if(ans == 0){
					inseart(str);
					//first = 0;
					++ans;
				}else 
				*/
				if(search(str) == 0){//原来不存在 
					inseart(str);
					++ans;
				}
			}
			//cout << "f: " << ans << endl;
		}
		cout << ans << endl;
		
		//del(&root);
	}
	
	
	return 0;
}
