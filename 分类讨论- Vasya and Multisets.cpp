#include<iostream>
#include<cstdio>
#include<vector>
#include<bitset>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<fstream>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define pii pair<int, int>
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define PER(i,x) for(auto i=x.begin();i!=x.end();i++)
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
typedef long long LL;
const double eps=1.0e-5;
const int maxn=100 + 10;

int cnt1=0,cnt2=0,cnt3=0,n = 0,tmp = 0,a[maxn],b[maxn],c[maxn],ma=-inf,flag;
//int loc[maxn][maxn];
vector<int> loc[maxn];
set<int> st,st1;
map<int,int> mp;
int num[maxn];
int time2[maxn];
bool fg[maxn];
void solve(){
	mem(time2,0);mem(fg,true);
	int size = st.size(),flag = 0;
	set<int>::iterator it;
	int ji = 0;
	for(it = st.begin();it != st.end();it++){
		int time = 0;
		if(mp[*it] == 1){
			a[cnt1++] = *it; 
		}
		if(mp[*it] > 1){
			//per(i,0,loc[*it].size()){
			b[cnt2++] = *it;//¼ÇÂ¼Êý	
			//}
			if(mp[*it] > 2 && time == 0){
				ji = *it;
				time++;
			}
		}
	}
	//cout << "en " << cnt1 << " " << cnt2 << endl;
	if(cnt1 % 2 != 0 && cnt2 == 0){
		printf("NO\n");
		return ;
	}
	int biao = 0;
	if(cnt1 % 2 == 1 && cnt2 > 0){
		per(i,0,cnt2-1){
			if(mp[b[i]] > 2){
				biao = 1;
				break;
			}
		}
		if(biao == 0){
			printf("NO\n");
			return ;
		}
	}
	printf("YES\n");
	if(cnt1 % 2 == 0){
		//per(i,0,cnt1-1){
		//	printf("%c",(i % 2 == 0) ? 'A' : 'B');
	//	}
		int time1 = 0,flag = 1;
		per(i,0,n){
			if(mp[num[i]] == 1){
				printf("%c",(time1 % 2 == 0)?'A' : 'B');
				time1++;
			}else if(mp[num[i]] > 1){
				st.insert(num[i]);
				if(st.find(num[i]) == st.end()){
					time2[num[i]] += flag;
					flag = (flag + 1) % 2;
				}
				printf("%c",(time2[num[i]]% 2 != 0) ? 'A':'B');
			}
		}
	}else{
		int fg = 0;
		int time1 = 0;
		per(i,0,n){
			if(mp[num[i]] == 1){
				printf("%c",(time1 % 2 == 0)?'A' : 'B');
				time1++;
			}else if(mp[num[i]] > 2 && num[i] == ji){
				if(time2[num[i]]++ == 0){
					printf("%c",'B');
				}else{
					printf("%c",'A');
				}
			}else if(mp[num[i]] > 1){
				st.insert(num[i]);
				if(st.find(num[i]) == st.end()){
					time2[num[i]] += flag;
					flag = (flag + 1) % 2;
				}
				printf("%c",(time2[num[i]]% 2 != 0 / 2) ? 'A':'B');
			}
		}	
	}
	printf("\n");
	//printf("nihao\n");
}
int main(){
	//freopen("in.txt","r",stdin);
	while(~scanf("%d",&n)){
		mp.clear();
		per(i,1,100){
			loc[i].clear();
		}
		st.clear();st1.clear();
		per(i,0,n-1){
			int temp = 0;
			scanf("%d",&temp);
			num[i] = temp;
			st.insert(temp);
			mp[temp] += 1;
			loc[temp].push_back(i);
			//loc[temp][]
		}
		solve();
	}
	
	return 0; 
}
