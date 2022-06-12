#include<bits/stdc++.h>
#define INF 1e6
using namespace std;
const int maxn = 1e6 + 100;
map <int ,int > mp;
struct node{
	int num;
	int time;
	node(){
		num = time = 0;
	}
};
//int data[maxn];
node oppo[maxn];
int ans[6];
bool cmp(node a,node b){
	return a.num < b.num;
}
double cal(int a,int b){
	return a/double(b ) + b/double(a);//要转化为double，否则int/int还是int 
}
int main(){
	int t = 0,n = 0;
	while(scanf("%d", &t) != EOF){
		for(int i = 0;i < t;++i){
			mp.clear();
			//memset(data,0,sizeof(data));
			scanf("%d",&n);
			int x = 0;
			for(int j = 1;j <= n;++j){
				//scanf("%d",&data[j]);
				scanf("%d",&x);
				//++mp[data[j]];
				++mp[x];
				//cout <<  "io "<< mp[data[j]] << endl;
			}
			int k = 1;
			map<int,int>::iterator it = mp.begin();
			for(it = mp.begin();it != mp.end();it++){
				if(it->second >= 2 && it->second < 4){
					oppo[k].num = it->first;
					oppo[k].time = 1;
					++k;
					//cout << "em " << endl;
				}
				if(it->second >= 4 ){
					oppo[k].num = it->first;
					oppo[k].time = 2;
					++k;
					oppo[k].num = it->first;
					oppo[k].time = 2;
					++k;
				}
			}
			sort(oppo + 1,oppo + k,cmp);
			double minv = INF;
			//cout << "m "<< oppo[1].num << endl;
			for(int h = 2;h < k;++h){
				//cout << "em " << oppo[h].num << endl;
				//if(oppo[h].num - oppo[h-1].num <= minv){
				if(cal(oppo[h].num,oppo[h-1].num) <= minv){
					minv = cal(oppo[h].num,oppo[h-1].num);
				//	minv = oppo[h].num - oppo[h-1].num;
					ans[1] = ans[2] = oppo[h-1].num ;
					ans[3] = ans[4] = oppo[h].num;
				}
			}
			cout << ans[1] << " " << ans[2] << " " << ans[3] << " " << ans[4] << endl;
		}	
	}
	
	return 0;
}
