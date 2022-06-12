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
const int maxn = 2e5;
int n = 0;
LL b[maxn+100],a[maxn+100];
void solve(){
	a[n+1] = b[1];
	per(i,1,(n/2)){//����̰�Ľ�� 
		if(b[i] - a[n-i+1+1] >= a[i-1]){//̰��ѡ���� 
			a[n-i+1] = a[n-i+1+1];
			a[i] = b[i] - a[n-i+1];
		}else{//̰��ѡ��С�� 
			//a[n-i+1] = min(b[i]-a[i-1],a[n-i+1+1]-a[i-1]);
			//���b[i] <= a[n-i+1+1]����������AC�İ汾һ����
			//���b[i] > a[n-i+1+1],��ôa[n-i+1]��������̰��С����a[i]�����൱������
			//��ø�С�ˣ�����̰�Ķ���ʧ�ܵģ����WA8��a[85]����1e18. 
			//a[i] = b[i] - a[n-i+1];
			a[i] = a[i-1];
			a[n-i+1] = b[i] - a[i];//̰����ߣ��ұ߲��ᳬ��a[n-i+1+1],��Ϊif�����Ѿ��ж��� 
		}
	}
	per(i,1,n){
		printf("%I64d%c",a[i],(i == n) ? '\n' : ' ');
	}
}


int main(){
	while(~scanf("%d",&n)){
		per(i,1,n/2){
			scanf("%I64d",&b[i]);
		}
		solve();
	}
	
	
	return 0;
}

