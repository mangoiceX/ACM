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
const int maxn = 100;
int n = 0,x = 0,y = 0;
int a[maxn+10];
void solve(){
	if(x > y){
		printf("%d\n",n);
		return ;
	}
	a[n+1] = INF;//����Ҫ����ĩβ�����������Ϊupper_bound(��������С��x),��ָ�����һ������
	//��һλ��,���ǻ��ʵ��λ�ö�1�������������ֻҪ����ĩβ���Ϳ��Խ��������һ�㻯���� 
	int ans = upper_bound(a+1,a+1+n,x) - a;//���ﲻ����lower_bound������upper_bound
	while(ans > 0 && a[ans] > x){
		ans--;
	}
	printf("%d\n",(ans+1)/2);
}
int main(){
	while(~scanf("%d %d %d",&n,&x,&y)){
		per(i,1,n){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		solve();
	}
	
	return 0;
}

