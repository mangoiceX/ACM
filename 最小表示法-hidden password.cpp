
//最小表示法，时间复杂度O(n)
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define inf -0x3f3f3f3f
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define mem(a, b) memset(a, b, sizeof(a))
typedef long long ll;
const int MOD=1e9+7;
char str[100100];
 
int GetMin(char* s,int len){//用最小表示法求字符串S的最小字典序,返回字典序最小的串的首字母位置
    int i=0,j=1,k=0;
    while(i<len&&j<len&&k<len){
        int t=s[(i+k)%len]-s[(j+k)%len];
        if(!t)
            k++;
        else{
            if(t>0){
                if(i+k+1>j)
                    i=i+k+1;
                else
                    i=j+1;
            }
            else{
                if(j+k+1>i)
                    j=j+k+1;
                else
                    j=i+1;
            }
            k=0;
        }
    }
    return i<j?i:j;
}
 
int main(){
    int t;
    int n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",str);
        int len=strlen(str);
        printf("%d\n",GetMin(str,len));
    }
    return 0;
}

