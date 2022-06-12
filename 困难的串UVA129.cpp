#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<sstream>
#include<iterator>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<deque>
#include<queue>
#include<list>
#define Min(a, b) ((a < b) ? a : b)
#define Max(a, b) ((a < b) ? b : a)
typedef long long ll;
typedef unsigned long long llu;
const int INT_INF = 0x3f3f3f3f;
const int INT_M_INF = 0x7f7f7f7f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const ll LL_M_INF = 0x7f7f7f7f7f7f7f7f;
const int dr[] = {0, 0, -1, 1, -1, -1, 1, 1};
const int dc[] = {-1, 1, 0, 0, -1, 1, -1, 1};
const int MOD = 1e9 + 7;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int MAXN = 100 + 10;
const int MAXT = 10000 + 10;
using namespace std;
int n, L;
int S[MAXN];
int cnt = 0;

void dfs(int cur){
	if(cnt++ == n){		//cur´Ó0¿ªÊ¼ 
		for(int i = 0;i < cur;i++){
			if(i && (i % 64 == 0)) printf("\n");
            else if(i && (i % 4 == 0)) printf(" ");
			printf("%c",'A'+S[i]);
		}
		printf("\n");
		printf("%d\n", cur);
	//	return 0;
	}
	
	for(int i = 0;i < L;i++){
		S[cur] = i;
		int ok = 1;
		for(int j = 1;j * 2 <= cur+1;j++){
			int equal = 1;
			for(int k = 0;k < j;k++){
				if(S[cur-k] != S[cur-k-j]){
					equal = 0;
					break;
				}
			}
			if(equal){
				ok = 0;
				break;
			}
		}
		if(ok){
			//if(!dfs(cur+1)){
			//	return 0;
			//}
			dfs(cur+1);
		}
	}
//	return 1;
} 

int main(){
    while(scanf("%d %d", &n, &L) == 2){
        if(!n && !L) return 0;
        cnt = 0;
        memset(S, 0, sizeof(S));
        dfs(0);
    }
    return 0;
}








