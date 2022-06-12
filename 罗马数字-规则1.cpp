#include<iostream>
#include<cstdio>
using namespace std;


int main(){
	int N;
	int num;
	
	cin >> N;
	while( N--){
		scanf("%d",&num);
		int a_num = num / 10000;
		num = num % 10000;
		
		int w_num = num / 5000;
		int m_num = num /1000;
		num = num % 1000;
		
		int d_num = num /500;
		int c_num = num /100;
		
		int l_num = num /50;
		int x_num = num / 10;
		num /= 10;
		
		int v_num = num /5;
		int i_num = num;
		
		for(int i = 0;i < a_num;i++){
			cout << "A";
		}
		if(w_num <= 0){
			for(int i = 0;i < m_num;i++){
				cout << "M";
			}
			
		}else if(m_num > 3 && m_num < 5){
			cout << "MW";
		}else{
			for(int i = 0;i < 10 - num;i++)
				cout << "M";
			cout << "D";
		}
		
		
		if(d_num <= 0){
			for(int i = 0;i < c_num;i++){
				cout << "D";
			}
			
		}else if(c_num > 3 && c_num < 5){
			cout << "CD";
		}else{
			for(int i = 0;i < 10 - num;i++)
				cout << "V";
			cout << "C";
		}
		
		
		if(l_num <= 0){
			for(int i = 0;i < x_num;i++){
				cout << "L";
			}
			
		}else if(x_num > 3 && x_num < 5){
			cout << "XL";
		}else{
			for(int i = 0;i < 10 - num;i++)
				cout << "I";
			cout << "X";
		}
		
		
		if(v_num <= 0){
			for(int i = 0;i < i_num;i++){
				cout << "V";
			}
			
		}else if(i_num > 3 && i_num < 5){
			cout << "IV";
		}
		cout << endl;
	}
	
	
	
	
	return 0;
}
