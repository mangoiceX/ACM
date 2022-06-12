#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
int cnt = 0;

void hanoi(int n,char A,char B,char C){
	if(n == 1){
		cout << A  << "->" << C << " ";
		cnt++;
	}
	if(n > 1){
		hanoi(n - 1,A,C,B);
		hanoi(1,A,B,C);
		hanoi(n - 1,B,A,C);
	}
	
}

int main(){
	int n = 0;
	char A = 'A',B = 'B',C = 'C';
	while(cin >> n ){
		cnt = 0;
		hanoi(n,A,B,C);
		cout << endl; 
		cout << "�ƶ�����Ϊ "<< cnt << endl;	
	}
	
	
	return 0;
}
