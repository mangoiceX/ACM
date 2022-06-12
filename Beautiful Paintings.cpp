#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int maxn = 1e5 + 100;
struct node{
	int num;
	int time;
	node(){
		num = 0;
		time = 1;
	}
};
map<int,int> mp;
node data[maxn];
int main(){
	int n = 0,x = 0;
	while(scanf("%d",&n) != EOF  && n){
		for(int i = 0;i < maxn;++i){
			data[i].num = -1;
			data[i].time = 0;
		}
		mp.clear();
		int ans = 0,dif = 0;
		for(int i = 1;i <= n;++i){
			scanf("%d",&x);
			++mp[x];
		}
		map<int,int>::iterator iter = mp.begin();
		int k = 1;
		while(iter != mp.end()) {
        	//cout << iter->first << " : " << iter->second << endl;
        	data[k].num = iter->first;
        	data[k].time = iter->second;
        	k++;
        	iter++;
   		}
   	//	for(int i = 1;i <= k -1;++i){
   		//	cout << "em " << data[i].num << " " << data[i].time << endl;
	//	}
   		int flag = 0;
   		while(true){
   			flag = 0;
   			dif = 0;
   			for(int i = 1;i <= k-1;++i){
	   			if(data[i].time != 0){
	   				flag = 1;
	   				--data[i].time;
	   				++dif;	
				}	
			}
			//cout << "m " << dif << endl;
			//cout << " m " << k << endl;
		
			if(flag == 0){
				break;
			}
			ans += dif - 1;	
		}
   		printf("%d\n",ans);
   		//ans = 0;
	}	
	
	
	return 0;
}
