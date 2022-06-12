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
const int maxn=1e2 + 10;

int cnt1=0,cnt2=0,cnt3=0,tmp = 0,b[maxn],c[maxn],ma=-inf,flag;
int n = 0; 
LL a[maxn];
LL Abs(LL x){
	return x < 0 ? -x : x;
} 
void solve(){
	map<LL,int> mp;
	pair<LL,int> ans(Abs(a[0]),1);
	
	per(i,1,(1<<(n/2))-1){//λ����������ȼ��ȼ��š�-���� 
		LL sum = 0; 
		int cnt = 0;
		per(j,0,n/2-1){
			if((i>>j) & 1){
				sum += a[j];
				cnt++;	
			}
		}
		//mp[sum] = cnt;
		ans = min(ans , make_pair(Abs(sum) , cnt));//ǰ�벿�� 
		if(mp[sum] != 0){//��ͬ�������������ͬ�ĺ� 
			mp[sum] = min(mp[sum],cnt);
		}else{
			mp[sum] = cnt;//�������ⲻ��ȫ�棬֮ǰ����д�� 
		}
	}
	per(i,1,(1<<(n - (n/2)))-1){//��1������ǰ��Ҫ������ȫ����Χ���� 
		LL sum = 0;
		int cnt = 0;
		per(j,0,n-n/2-1){//λ���㣬0,1��Ŷ�Ӧ����״̬��ѡ�벻ѡ�� 
			if((i>>j) & 1){//����i,j���߽�Ͽ���ö������״̬ 
				sum += a[j+n/2];
				cnt++;
			}
		}
		ans = min(ans,make_pair(Abs(sum),cnt));//��һ������Լ����� 
		map<LL,int>::iterator it;//���Ե���map���� 
		//it = lower_bound(mp.begin(),mp.end(),-sum);//����-sum 
		it = mp.lower_bound(-sum);
		if(it != mp.end()){//�պô��������� 
			ans = min(ans,make_pair(Abs(sum + it->first),cnt + it->second));
		}
		if(it != mp.begin()){//�պ�С�������� ,���������Ƚ�
			it--; 
			ans = min(ans , make_pair(Abs(sum + it->first),cnt + it->second));
		}
	} 
	//printf("%I64d %d\n",ans->first,ans->second);//����д�����﷨���� 
	printf("%I64d %d\n",ans.first,ans.second);
}
int main(){
	//freopen("a.txt","r",stdin);
	while(~scanf("%d",&n) && n){
		per(i,0,n-1){
			scanf("%I64d",&a[i]);
		} 
		solve(); 
	}
	
	return 0; 
}
