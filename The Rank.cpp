#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;
const int maxn = 1020;
struct Score{
	int e,g,m,h;
	int id,sum;
};
Score sc[maxn];
bool cmp(Score a,Score b){
	if(a.sum != b.sum){
		return a.sum > b.sum;
	}else{
		return a.id < b.id;
	}
}
int main(){
	int n = 0;
	cin >> n;
	for(int i = 1;i <= n;++i){
		cin >> sc[i].e >> sc[i].g >> sc[i].m >> sc[i].h;
		sc[i].sum = sc[i].e + sc[i].g + sc[i].m + sc[i].h;
		sc[i].id = i;
	}
	sort(sc+1,sc+n+1,cmp);
	for(int i = 1;i <= n;++i){
		if(sc[i].id == 1){
			cout << i << endl;
		}
	}
	
	return 0;
}
