#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
	priority_queue<int> pque;
	
	pque.push(3);
	pque.push(5);
	pque.push(100);
	
	while(!pque.empty()){
		cout << pque.top() << endl;
		pque.pop();
	}
	
	return 0;
}
