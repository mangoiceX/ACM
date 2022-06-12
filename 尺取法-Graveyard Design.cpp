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
const int maxn=2e4 + 10;

int cnt1=0,cnt2=0,cnt3=0,tmp = 0,a[maxn],b[maxn],c[maxn],ma=-inf,flag;
LL n = 0; 
set<int> st[maxn];
int cal = 0;//,cnt1 = 0,cnt2 = 0;
void solve(){	//���ճ�ʱ���������䲻��set�棬�˷�ʱ�� 
	LL s = 1,e = 1;//Ҫ����ΪLL��������n�޷��Ƚϣ�s*s����int���ᱬ 
	LL sum = 0;
	set<int> temp;
	int flag = 0;
	
	while(true){
		while(e * e <= n && sum < n){
			sum += e*e;
			temp.insert(e);
			e++;
		}
		if(sum < n){
			return;
		}
		if(sum == n){
			st[cal++] = temp;
		}
		temp.erase(temp.begin());
		sum -= s*s;
		s++;
		while(sum > n){
			sum -= s*s;
			temp.erase(temp.begin());
			s++;
		}
	}

}

int main(){
	//freopen("in.txt","r",stdin);
	while(~scanf("%I64d",&n)){
		cal = 0;
		per(i,0,maxn){
			st[i].clear();
		}
		solve();
		printf("%d\n",cal);
		//cout << cnt1 << " " << cnt2 << endl;
		per(i,0,cal-1){
			set<int>::iterator it = st[i].begin();
			printf("%d ",st[i].size());
			for(it = st[i].begin();it != st[i].end();it++){
				printf("%d ",*it);
			}
			printf("\n");
		}
	}
	
	return 0; 
}
