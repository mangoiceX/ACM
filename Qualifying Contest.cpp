#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1e3;
struct node{
	string name;
	int id;
	int score;
};
node man[10001][maxn];
int num[1000];
bool cmp(node a,node b){
	if(a.score !=b.score){
		return a.score > b.score;
	}else{
		a.name < b.name;
	}
	
}
int main(){
	int n = 0,m = 0;
	while(cin >> n >> m){
		memset(num,0,sizeof(num));
		string s;
		int d = 0,sc = 0;
		for(int i = 0;i < n;++i){
			cin >> s >> d >> sc;
			//cin >> man[i].name >> man[i].id >> man[i].score;
			man[d][num[d]++].name = s;
			man[d][num[d]++].score = sc;
		}
		for(int i = 1;i <= m;++i){
			sort(man[i],man[i] + num[i],cmp);
		}
		
		for(int i = 1;i <= m;++i){
			if(man[i][2].score == man[i][1].score){
				cout << "?" << endl;
			}else{
				cout << man[i][0].name << " " << man[i][1].name << endl;
			}
		}
	}
	
	
	return 0;
}
