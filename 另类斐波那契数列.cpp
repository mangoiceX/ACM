#include<iostream> 
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<cstring> 
using namespace std;
const int maxn = 1000010;
typedef unsigned long long LL;
LL F[maxn];
bool judge(int n){
	
	if(F[n] % 3 == 0){
		return true;
	}
	
	return false;
}


int main(){
	int n = 0;
	F[0] = 1,F[1] = 2;
	for(int i = 2;i < maxn;++i){
		F[i] = (F[i - 1] + F[i - 2] ) % 3;//��������%3�ǵĽ������С��3�ģ����ᵼ�����ս��̫�󣬶�WA 
		//cout << F[i] << " "; 
	}
	while(cin >> n){
	//while(scanf("%d",&n) != EOF){
		if(judge(n)){
			cout << "yes" << endl;
		}else{
			cout << "no" << endl;
		}
	}
	
	
	return 0;
} 
