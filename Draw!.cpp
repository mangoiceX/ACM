#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

typedef long long LL;

#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
const int maxn = 1e4;
int n = 0,m = 0; 
struct node{
	int s,e;
}; 
node a[maxn+10];
void solve(){//˼ά�������ǲ��У�������ϸ��ģ�⣬���������̫���ӣ�̫ϸ�ڻ�,����Ǵ��к�����������
	LL ans = 0;
	per(i,1,n){
		if(min(a[i].s,a[i].e) < max(a[i-1].s,a[i-1].e)){
			continue;
		}
		if(a[i-1].s == a[i-1].e){//���ǰ��ıȷ���ȣ���ô������һ�μ�����Ѿ�����ˣ�ÿһ�ζ���[]�����䣬
		//�������ȣ���ô��һ���õ���min(a[i-1].s,a[i-1].e),����һ��ʹ�õ���max(a[i-1].s,a[i-1].e)
		//��Ϊa[i-1].s != a[i-1].e,�������߲���ȣ����Զϵ粻���ظ��� 
			ans += (min(a[i].s,a[i].e) - max(a[i-1].s,a[i-1].e));
		}else{
			ans += (min(a[i].s,a[i].e) - max(a[i-1].s,a[i-1].e) + 1);
		}
	}
	printf("%I64d\n",ans+1);//���+1,����0 0 
}
int main(){
	//std::ios::sync_with_stdio(false);
	while(~scanf("%d",&n)){
		a[0].s = a[0].e = 0;
		per(i,1,n){
			scanf("%d %d",&a[i].s,&a[i].e);
		}
		solve();
	}
	
	return 0;
}

