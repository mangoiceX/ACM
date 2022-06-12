#include <cstdio>
#include <cstring>
#include <algorithm>
#define ls (o<<1)
#define rs (o<<1|1)
#define lson ls, L, M
#define rson rs, M+1, R
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 10;

ll sumv[N<<2], x[N];

void build(int o, int L, int R) {
    if(L == R) {
        sumv[o] = x[L];
        return ;
    }
    int M = (L+R)/2;
    build(lson);
    build(rson);
    sumv[o] = sumv[ls] + sumv[rs];
}

ll query(int o, int L, int R, int ql, int qr) {
    if(ql <= L && R <= qr)
        return sumv[o];
    int M = (L + R)/2;
    ll ret = 0;
    if(ql <= M) ret += query(lson, ql, qr);
    if(qr > M) ret += query(rson, ql, qr);
    return ret;
}

struct Segment {
    int L, R;
    ll sum;
} s[N];

ll maxv[N<<2];
int posv[N<<2];
void pushUp(int o) {
    if(maxv[ls] >= maxv[rs]) {
        maxv[o] = maxv[ls];
        posv[o] = posv[ls];
    }else {
        maxv[o] = maxv[rs];
        posv[o] = posv[rs];
    }
}

void build2(int o, int L, int R) {
    if(L == R) {
        maxv[o] = s[L].sum;
        posv[o] = s[L].L;
        return ;
    }
    int M = (L + R)/2;
    build2(lson);
    build2(rson);
    pushUp(o);
}

ll _maxv;
int site;
void find(int o, int L, int R, int ql, int qr) {
    if(ql <= L && R <= qr) {
        if(_maxv < maxv[o]) {
            _maxv = maxv[o];
            site = posv[o];
        }
        return ;
    }
    int M = (L+R)/2;
    if(ql <= M) find(lson, ql, qr);
    if(qr > M) find(rson, ql, qr);
}

int n, k;
int main() {
    while(scanf("%d%d", &n, &k) != EOF) {
        for(int i = 1; i <= n; i++)
            scanf("%lld", &x[i]);

        build(1, 1, n);

        for(int i = 1; i <= n - k + 1; i++) {
            s[i].L = i, s[i].R = i+k-1;
            s[i].sum = query(1, 1, n, s[i].L, s[i].R);
        }

        int last = n-k+1;
        build2(1, 1, last);

        int a, b; 
        ll maxSum = -INF;

        for(int i = 1; i < last; i++) {
            _maxv = -INF;
            find(1, 1, last, s[i].R+1, last);
            if(maxSum < s[i].sum + _maxv) {
                maxSum = s[i].sum + _maxv;  
                a = i, b = site;
            }
        }
        printf("%d %d\n", a, b);
    }
    return 0;
}

