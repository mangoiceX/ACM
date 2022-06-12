#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
#include<algorithm>
#define INF -100000 
using namespace std;
const int maxn = 1010;
int times_no = 0;
typedef struct NOde{
	int flag  = -1;
	int times = 0;
	int num;
}NODE;
NODE times[maxn];
int data_l[maxn],data_r[maxn];
int N = 0,K = 0,p = 0;
char fuhao;
bool cmp(NODE a,NODE b){
	return a.times > b.times;
}
int main(){
	int T = 0;
	cin >> T;
	while(T -- ){
		cin >> N >> K;
		memset(data_l, 0, sizeof(data_l));
       	memset(data_r, 0, sizeof(data_r));
		//while(cin >> N >> K){
		while(K--){
			cin >> p;
			for(int i = 0;i < p;++i){
				cin >> data_l[i];
			}	
			for(int i = 0;i < p;++i){
				cin >> data_r[i];
			}	
			
			cin >> fuhao;
			if(fuhao == '<'){
				++times_no;
				for(int i = 0;i < p;++i){
					if(times[data_l[i]].flag == 1){	//如果出现在天平的两边则一定不是假的 
						times[data_l[i]].times = INF;
						continue;
					}
					 times[data_l[i] ].times += 1;
					 times[data_l[i]].flag = 0;//flag == 0表示在天平轻的一侧 
				}
				for(int i = 0;i < p;++i){
					if(times[data_r[i]].flag == 0){	//如果出现在天平的两边则一定不是假的 
						times[data_r[i]].times = INF;
						continue;
					}
					 times[data_r[i] ].times += 1;
					 times[data_r[i]].flag = 1;//flag == 1表示在天平重的一侧 
				}		
			}
			
			if(fuhao == '>'){
				++times_no;
				for(int i = 0;i < p;++i){
					
					if(times[data_l[i]].flag == 0){	//如果出现在天平的两边则一定不是假的 
						times[data_l[i] ].times = INF;
						continue;
					}
					 times[data_l[i] ].times += 1;
					 times[data_l[i]].flag = 1;//flag == 1表示在天平重的一侧 
				}
				for(int i = 0;i < p;++i){
					if(times[data_r[i]].flag == 1){	//如果出现在天平的两边则一定不是假的 
						times[data_r[i]].times = INF;
						continue;
					}
					 times[data_r[i] ].times += 1;
					 times[data_r[i]].flag = 0;//flag == 0表示在天平轻的一侧 
				}
						
			}
			
			if(fuhao == '='){
				for(int i = 0;i < p;++i){
					times[data_l[i]].times = times[data_r[i]].times = INF;
					//直接用INF标记,不可能是假币 
					times[data_l[i]].flag = times[data_r[i]].flag = -1;
				}
				
			}
		}
		for(int i = 1;i <= N;++i){	//排序前记录编号 
			times[i].num = i;
		}
		sort(times + 1,times + N + 1,cmp);
		if(times[2].times != times[1].times && times[1].times == times_no){
			cout <<  times[1].num << endl;
		}else{
			cout << "0" << endl;
		}
		if(T){
			cout << "\n";
		} 
	}

	
	return 0;
}
