#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
const int maxn = 1000 + 10; 
string str;
int len = 0,min_pos = 0,max_pos = 0;
int min_times = 0,max_times = 0;
void min_rep(){
	int i = 1,j = 0,k = 0,flag1 = 0;

	while(j < len && i < len){
		while(str[(i+k) % len] == str[(j+k) % len] && k < len){
			++k;
		}
		if(k == len){
			//return min(i,j);
			flag1 = 1;
			if(flag1 == 0){
				min_pos = min(i,j);
			}
			++min_times;
		}
		if(str[(i+k)%len] > str[(j+k)%len]){
			i = max(i+k+1, j+1);
		}else{
			j = max(j + k + 1, i + 1);
		}
	}
	if(flag1 == 0){
		min_pos = min(i , j);	
	}

	
}
void max_rep(){
	int i = 1,j = 0,k = 0,flag1 = 0;
	
	while(j < len && i < len){
		while(str[(i+k) % len] == str[(j+k) % len] && k < len){
			++k;
		}
		if(k == len){
			//return min(i,j);
			flag1 = 1;
			if(flag1 == 0){
				max_pos = min(i,j);
			}
			++max_times;
		}
		if(str[(i+k)%len] < str[(j+k)%len]){
			i = max(i+k+1, j+1);
		}else{
			j = max(j + k + 1, i + 1);
		}
	}
	if(flag1 == 0){
		max_pos = min(i,j);
	}
	
	
}
int main(){
	int T = 0;
	cin >> T;
	while(T--){
		cin >> len;
		cin >> str;
		//cout << min_rep() << endl;
		min_rep();
		max_rep();
		cout << min_pos << " " << min_times << " " << max_pos << " " << max_times << endl;
	}
	
	
	
	return 0;
}
