#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std; 
const int maxn = 100 + 10;
int data[maxn][maxn];
int r = 0,c = 0;
int solve(){
	
	if(r % 2 != 0){	//�����������ż������𰸾������� 
		return r;
	}
	int nowr = r;
	while((nowr % 2) == 0){
		for(int i = 1;i <= nowr / 2;++i){
			
			for(int j = 1;j <= c;++j){
				
				if(data[i][j] != data[nowr + 1 - i][j]){ //���������Ҫ��˵����ǰ�������Ǵ� 
					return nowr;
				}
			}
		}
		nowr /= 2; 
	}
	return nowr;		
}
int main(){
	cin >> r >> c;
	
	for(int i = 1;i <= r;++i){
		for(int j = 1;j <= c;++j){
			cin >> data[i][j];
		}
	}
	
	int ans = solve();
	cout << ans << endl;
	
	return 0;
}
