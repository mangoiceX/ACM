#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <stack>
#include <cmath>
#include <string>
#include <queue>
#define INF 0xffffff
using namespace std;
const int maxn = 101;
typedef long long ll ;
int n, m, x, y, v;
int G[maxn][maxn], d[maxn];
bool vis[maxn];

int prim()
{
    int pt, ret, Min;
    memset(vis,false,sizeof(vis));
    memset(d,0x7f,sizeof(d));
    pt = 1;
    vis[1] = true;
    ret = 0;
    while( true )
	{
        for(int i=1; i<=n; i++)
            if( !vis[i] && G[pt][i] && d[i]>G[pt][i] )
                d[i] = G[pt][i];			//ѡ��СȨ�ı߼���鲢������ 
        pt = -1;
        Min = INF ;						//�൱��minһ���ᱻd[i]�滻 
        for(int i=1; i<=n; i++)
		{
            if( !vis[i] && Min > d[i] )	
			{
                Min = d[i];				//ѡ��СȨ�ı߼��� 
                pt = i;
            }
        }
        if( pt == -1 ) break;
        ret += Min;
        vis[pt] = true;				//����Ѿ��߹� 
    }
    return ret;
}

int main(){
    while( ~scanf("%d",&n) && n){
        m = n * ( n - 1 ) / 2 ;
        memset(G,0,sizeof(G));
        while( m -- ){
            scanf("%d %d %d",&x,&y,&v);
            G[x][y] = G[y][x] = v ;
        }
        printf("%d\n",prim());
    }
    return 0 ;
} 
