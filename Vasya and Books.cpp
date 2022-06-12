#include<bits/stdc++.h>
#include<iostream>
#include<stack>
using namespace std;
const int maxn = 3e5 + 10;
typedef long long LL;
int n = 0;
stack<int> st,st1,st2;
void solve(){
	set<int> s;
	while(!st2.empty()){
		int u = st2.top();st2.pop();
		if(s.find(u) != s.end()){
			printf("0 ");
			continue;
		}
		int cnt = 0;
		//stack<int>::iterator it = st1.begin();
		//for(it = st1.begin();it != st1.end();it++){
		while(!st1.empty()){
			int v = st1.top();st1.pop();
			cnt++;
			if(v == u){
				printf("%d ",cnt);
				break;
			}
			s.insert(v);
		}
		//}
	}
	printf("\n");
}
int main(){
	while(~scanf("%d",&n)){
		int a = 0;
		for(int i = 0;i < n;++i){
			scanf("%d",&a);
			st.push(a);
		}
		for(int i = 0;i < n;++i){
			a = st.top();st.pop();
			//cout << "nima " << a << endl;
			st1.push(a);
		}
		for(int i = 0;i < n;++i){
			scanf("%d",&a);
			st.push(a);
		}
		for(int i = 0;i < n;++i){
			a = st.top();st.pop();
			//cout << "nima " << a << endl;
			st2.push(a);
		}
		solve();
	}
	
	return 0;
}
