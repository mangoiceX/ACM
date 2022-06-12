#include <cstdio>
#include <cstring>
#include <ctype.h>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <stack>
#include <set>
#include <list>
#include <numeric>
#include <sstream>
#include <iomanip>
#include <limits>

#define CLR(a, b) memset(a, (b), sizeof(a))
#define pb push_back
#define bug puts("***bug***");
#define fi first
#define se second
//#define bug 
//#define gets gets_s

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <string, int> psi;
typedef pair <string, string> pss;
typedef pair <double, int> pdi;

const double PI = acos(-1.0);
const double EI = exp(1.0);
const double eps = 1e-8;

const int INF = 0x3f3f3f3f;
const int maxn = 1e3 + 10;
const int MOD = 6;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        


struct Matrix
{
    int a[10][10];
    int n;
    Matrix() {}
    Matrix operator * (Matrix const &b)const
    {
        Matrix res;
        res.n = n;
        CLR(res.a, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    res.a[i][j] = (res.a[i][j] + this->a[i][k] * b.a[k][j]) % MOD;
        return res;
    }
};

Matrix pow_mod(Matrix base, int a, int n)
{
    Matrix ans;
    CLR(ans.a, 0);
    for (int i = 0; i < n; i++)
        ans.a[i][i] = 1;
    ans.n = n;
    while (a > 0)
    {
        if (a & 1)
            ans = ans * base;
        base = base * base;
        a >>= 1;
    }
    return ans;
}

int A[maxn][maxn], B[maxn][maxn], ans[maxn][maxn];

int main()
{
    int n, k;
    while (scanf("%d%d", &n, &k) && (n || k))
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < k; j++)
                scanf("%d", &A[i][j]);
        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &B[i][j]);
        Matrix base;
        base.n = k;
        CLR(base.a, 0);
        for (int i = 0; i < k; i++)
            for (int j = 0; j < k; j++)
                for (int l = 0; l < n; l++)
                    base.a[i][j] = (base.a[i][j] + B[i][l] * A[l][j]) % MOD;
        base = pow_mod(base, n * n - 1, k);
        CLR(ans, 0);
        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                for (int l = 0; l < k; l++)
                    ans[i][j] = (ans[i][j] + base.a[i][l] * B[l][j]) % MOD;
        CLR(B, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int l = 0; l < k; l++)
                    B[i][j] = (B[i][j] + A[i][l] * ans[l][j]) % MOD;
        int tot = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                tot += B[i][j];
        cout << tot << endl;
    }
}