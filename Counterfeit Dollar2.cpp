#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 14;
struct Cion{
	int num = 0;
	int sex = 0;
};
char swift(int i){
	switch(i){
		case 0:
			return 'A';
		case 1:
			return 'B';
		case 2:
			return 'C';
		case 3:
			return 'D';
		case 4:
			return 'E';
		case 5:
			return 'F';
		case 6:
			return 'G';
		case 7:
			return 'H';
		case 8:
			return 'I';
		case 9:
			return 'J';
		case 10:
			return 'K';
		case 11:
			return 'L';
	}
	
}
Cion h[maxn],l[maxn];
string str1,str2,fuhao;
int ge(char ch){
	return ch - 'A' ;
}
int main(){
	int T = 0;
	cin >> T;
	
	while(T--){
		for(int i = 0;i < maxn;++i){//初始化 
			h[i].num = l[i].num = 0;
			h[i].sex = l[i].sex = 0;
		}
		int nu = 0;
		for(int i = 0;i < 3;++i){
			cin >> str1 >> str2 >> fuhao;
			if(fuhao == "even"){
				for(size_t i = 0;i < str1.size();++i){
					h[ge(str1[i])].sex = l[ge(str1[i])].sex = -1;
					h[ge(str2[i])].sex = l[ge(str2[i])].sex = -1;
				}
				if(str1.size() == 5){	//一次判断 
					for(int i = 0;i < 11;++i){
						if(h[i].sex == 0){
							cout << swift(i) << " is the counterfeit coin and it is heavy."<< endl;
						}
						if(l[i].sex == 0){
							cout << swift(i) << " is the counterfeit coin and it is light."<< endl;
						}
					}
				}
			}else if(fuhao == "up"){
				nu++;
				for(size_t i = 0;i < str1.size();++i){
					if(h[ge(str1[i])].sex != -1){
						h[ge(str1[i])].num++;
					}
					if(h[ge(str2[i])].sex != -1){
						l[ge(str2[i])].num++;
					}
				}
			}else if(fuhao == "down"){
				nu++;
				for(size_t i = 0;i < str1.size();++i){
					if(h[ge(str1[i])].sex != -1){
						l[ge(str1[i])].num++;
					}
					if(h[ge(str2[i])].sex != -1){
						h[ge(str2[i])].num++;
					}
				}
			}
		}
	
		for(int i = 0;i < 12;++i){
			if(h[i].num == nu && h[i].sex != -1){				
				cout << swift(i) << " is the counterfeit coin and it is heavy." << endl;
				break;
			}			
			if(l[i].num == nu && l[i].sex != -1){
				cout << swift(i) << " is the counterfeit coin and it is light." << endl;
				break;
			}
		}
	} 
	
	return 0;
} 
