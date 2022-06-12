#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 100;
vector<pair<int,string> > team[maxn];
bool cmp(pair<int,string> a,pair<int,string> b){
	if(a.first != b.first){
		return a.first > b.first;
	}else{
		return a.second < b.second;
	}
}
int main(){
	int n = 0,m = 0;
	cin >> n >> m;	
	for(int i = 0;i < n;++i){
		int region = 0,score = 0;
		string name;
		cin >> name >> region >> score;
		team[region].push_back(pair<int,string> (score,name));
	}
	for(int i = 1;i <= m;++i){
		sort(team[i].begin(),team[i].end(),cmp);
		int len = team[i].size();
		if(len > 2 && team[i][2].first == team[i][1].first){
			cout << "?" << endl;
		}else{
			cout << team[i][0].second << " " << team[i][1].second << endl;
		}
	}
	
	return 0;
}
