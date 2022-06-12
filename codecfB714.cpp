#include<iostream>
#include<cstdio> 
#include<stack>
#include<deque>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 100005;
string num;
void solve(){
	int flag = 0;
	int b_flag = 0;
	int flag_s = 0;
	
	while(b_flag == 0){
		b_flag = 1;
		while(flag == 0){
			flag = 1;
			for(size_t i = 0;i < num.size() - 1;i++){//
				if( (num[i] == '2' && num[i+1] == '1') ){
					swap(num[i],num[i+1]);
					b_flag = 0;
					flag = 0;
				}
			}
		}
		
		flag = 0;
		while(flag == 0){
			flag = 1;
			for(size_t i = 0;i < num.size() - 1;i++){//
				if((num[i] == '1' && num[i+1] == '0') && flag_s == 0){
					swap(num[i],num[i+1]);
					flag = 0;
					b_flag = 0;
				}
				if(num[i] == '0' && num[i+1] == '1' && num[i-1] == '2'){
					swap(num[i],num[i+1]);
					flag = 0;
					b_flag = 0;
					flag_s = 1;
				}
			}
		}
	
	}
	
	
	
	/*flag = 0;
	while(flag == 0){
		flag = 1;
		for(size_t i = 0;i < num.size() - 1;i++){//
			if(num[i] == '1' && num[i+1] == '0'){
				swap(num[i],num[i+1]);
				flag = 0;
			}
		}
	}
	*/
	cout << num << endl;
}

int main(){
	//int cnt = 0;
	cin >> num;
	solve();
	
	
	return 0;
}
