#define Hello the_cruel_world!
#pragma GCC optimize(2)
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<cmath>
#include<climits>
#include<deque>
#include<functional>
#include<numeric>
#define max(x,y) ((x) > (y) ? (x) : (y))
#define min(x,y) ((x) < (y) ? (x) : (y))
#define ABS(x) ((x) >= 0 ? (x) : (-(x)))
#define pb(x) push_back(x)
#define lowbit(x) ((x) & (-(x)))
#define FRIN freopen("C:\\Users\\Administrator.MACHENI-KA32LTP\\Desktop\\in.txt", "r", stdin)
#define FROUT freopen("C:\\Users\\Administrator.MACHENI-KA32LTP\\Desktop\\out.txt", "w", stdout)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define outd(x) printf("%d\n", x)
#define outld(x) printf("%I64d\n", x)
#define memset0(arr) memset(arr, 0, sizeof(arr))
#define il inline
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int maxn = 100;
const int INF = 0x7fffffff;
const int mod = 1e9 + 7;
const double eps = 1e-7;
const double Pi = acos(-1.0);
inline int read_int() {
	char c;
	int ret = 0, sgn = 1;
	do { c = getchar(); } while ((c < '0' || c > '9') && c != '-');
	if (c == '-') sgn = -1; else ret = c - '0';
	while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + (c - '0');
	return sgn * ret;
}
inline ll read_ll() {
	char c;
	ll ret = 0, sgn = 1;
	do { c = getchar(); } while ((c < '0' || c > '9') && c != '-');
	if (c == '-') sgn = -1; else ret = c - '0';
	while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + (c - '0');
	return sgn * ret;
}
int arr[maxn + 5], n, cnt0;
set<int> s;
int main()
{
	n = read_int();
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= n; ++i)arr[i] = read_int();
	sort(arr + 1, arr + 1 + n);
	for (int i = 1; i < n; ++i) {
		s.insert(arr[i + 1] - arr[i]);
		if (arr[i + 1] == arr[i])cnt0 = 1;
	}
	if (s.size() == 1) {
		int t = *s.begin();
		if (t & 1)cout << t << endl;
		else {
			if(arr[n] - arr[1] == t)cout << t / 2 << endl;
			else cout << t << endl;
		}
	}
	else if (s.size() == 2) {
		if (cnt0 == 0)cout << -1 << endl;
		else {
			int t = *s.rbegin();
			if (t & 1)cout << t << endl;
			else {
				if (arr[n] - arr[1] == t)cout << t / 2 << endl;
				else cout << t << endl;
			}
		}
	}
	else cout << -1 << endl;
	//system("pause");
	return 0;
}
