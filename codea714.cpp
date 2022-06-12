#include<iostream>
#include<cstdio> 
#include<stack>
#include<deque>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 1005,maxm = 1005;
int n,m;
int cnt = 0;
//int  arr_g[maxn],arr_m[maxm];
deque<int> arr_g,arr_m;
deque<int> g_mark;
/*
void init(){
	memset(arr_g,0,sizeof(arr_g));
	memset(arr_g,0,sizeof(arr_m));
	memset(g_mark,0,sizeof(arr_m));
}*/

void solve(){
	if(arr_m.empty()){
		return;
	}
	int money = arr_m.front();
	int flag = 0;
	for(size_t i = 0;i < arr_g.size();i++){
		
		if(money >= arr_g[i] && g_mark[i] == 0){//
			for(size_t j = 0;j <= i;j++){
				g_mark[j] = 1;//
			}
			
			flag = 1;//
			arr_m.pop_front();
			break;
		}
		
	}
	if(flag == 1){
		cnt++;
		solve();
	}else{		//
		return ;
	}
	
	
}
int main(){
	cin >> n >> m;
	int temp = 0;
	
	//init();
	
	for(int i = 0;i < n;i++){//
		//cin >> arr_g[i];
		cin >> temp;
		arr_g.push_back(temp);
		g_mark.push_back(0);
	}
	for(int i = 0;i < m;i++){
		//cin >> arr_m[i];
		cin >> temp;
		arr_m.push_back(temp);
	}
	
	solve();
	printf("%d\n",cnt);
	
	return 0;
}
