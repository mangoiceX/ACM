
/* POJ3321 Apple Tree */
 
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
 
using namespace std;
 
const int N = 1e5 + 1;
int a[N + 1], n;
int cnt;
 
int lowbit(int i)
{
    return i & -i;
}
 
void update(int i, int v) //更新函数
{
    while(i <= n) {
        a[i] += v;
        i += lowbit(i);
    }
}
 
int sum(int i)      //求和函数
{
    int sum = 0;
    while(i > 0) {
        sum += a[i];
        i -= lowbit(i);
    }
    return sum;
}
 
vector< vector<int> > g(N);
int start2[N], end2[N], sign[N];
 
void dfs(int u)
{
    start2[u] = cnt;
    //cout << "em " << start2[u] << endl;
    for(int i = 0; i < (int)g[u].size(); i++) {
        cnt++;
        dfs(g[u][i]);
    }
    end2[u] = cnt;
  //  cout << "mama " << end2[u] << endl;
}
 
int main()
{
    while(~scanf("%d", &n)) {
        g.clear();
        g.resize(N +1);
 
        // 构建图
        for(int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
        }
 
        // DFS处理
        cnt = 1;
        dfs(1);
 
        // 初始化
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= n; i++) {
            sign[i] = 1;
            update(i, 1);
        }
 
        int m, x;
        char cmd[8];
        scanf("%d", &m);
        for(int i = 1; i <=m; i++) {
            scanf("%s%d", cmd, &x);
            if(cmd[0] == 'Q')
                printf("%d\n", sum(end2[x]) - sum(start2[x] - 1));
            else {
                update(start2[x], sign[x] ? -1 : 1);
                sign[x] = 1 - sign[x];
            }
        }
    }
 
    return 0;
}

