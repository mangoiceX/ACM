#include <cstdio>
#include <cmath>
//#pragma comment(linker, "/STACK:102400000, 102400000")
using namespace std;
const int maxm = 25;
const int inf = 0x3f3f3f3f;
int mins[maxm], mind[maxm];
int n, m, ans;
 
void init(){
    mins[0] = mind[0] = 0;
    for (int i=1; i<maxm; ++i){
        mins[i] = mins[i-1]+2*i*i;
        mind[i] = mind[i-1]+i*i*i;
    }
}
 
void dfs(int cur, int r, int h, int s, int d){
    if (cur == m){
        if (d==n && s<ans)
            ans = s;
        return ;
    }
    int ld = n-d;
    for (int i=r-1; i>=m-cur; --i){
        int maxh = (ld-mind[m-cur-1])/(i*i);
        if (maxh > h-1)
            maxh = h-1;
        for (int j=maxh; j>=m-cur; --j){
            int td = ld-i*i*j;
            if (td < mind[m-cur-1])
                continue;
            int ts;
            if (cur == 0)
                ts = i*i+2*i*j;
            else
                ts = s+2*i*j;
            if (ts+mins[m-cur-1]>=ans || ts+2*td/i>=ans)
                continue;
            dfs(cur+1, i, j, ts, d+i*i*j);
        }
    }
}
 
int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    init();
    while (~scanf("%d%d", &n, &m)){
        ans = inf;
        int maxh = (n-mind[m-1])/(m*m);
        int maxr = sqrt(1.0*(n-mind[m-1])/m);
        dfs(0, maxh, maxr, 0, 0);
        printf("%d\n", inf==ans ? 0 : ans);
    }
    return 0;
}

