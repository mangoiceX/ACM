#include<iostream> 
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#include<map>
#include<cmath>
#include<queue>
using namespace std;
const int maxn = 1000 + 10;
int n = 0,s = 0;
struct Node{
	int x,y;
	int popu;
	double dist;
};
Node city[maxn];
bool cmp(Node a,Node b){
	
	return a.dist <= b.dist;
	
}
int main(){
	
	scanf("%d %d",&n,&s);
	for(int i = 0;i < n;++i){
		//cin >> city[i].x >> city[i].y >> city[i].popu;
		scanf("%d %d %d",&city[i].x,&city[i].y,&city[i].popu);
		city[i].dist = sqrt(pow(city[i].x,2) + pow(city[i].y,2));
		//cout << city[i].dist << endl;
		//printf("%.8lf\n",city[i].dist);
	}
	
	sort(city,city + n,cmp);
	int now = s,j = 0;
	double r = 0;
	while(now < 1000000 && j < n){
		now += city[j].popu;
		r = city[j].dist;
		++j;
	}
	if(j == n && now <1000000){
		printf("-1\n"); 
	}else{
		printf("%.7lf\n",r); 
	}
	
	return 0;
} 
