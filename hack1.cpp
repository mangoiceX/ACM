#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <fstream>
#include <stack>
#include <ctime>
#include <memory.h>
#define all(x) x.begin(), x.end()
#define rev_all(x) x.rbegin(), x.rend()
#define nline '\n'
typedef long long ll;
const ll MOD = 1000000007;
const double ZER = 1e-9;
const double PI = acos(-1);
using namespace std;
int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
#ifndef ONLINE_JUDGE
	//freopen("test.txt", "r", stdin);
#endif
	ll n, m;
	cin >> n >> m;
	ll mn = n;
	ll mx = n;
	if (m) {
		ll remove = min(m * 2, (n + 1) / 2 * 2);
		ll t = n - remove;
		mn = t;
		for (ll i = 2; i <= n; ++i) {
			if (i * (i - 1) / 2 >= m) {
				mx = n - i;
				break;
			}
		}
	}
	cout << mn << " " << mx << nline;
	return 0;
}
