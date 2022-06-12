#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 200;
struct node{
	int num, l, r;
}a[maxn];
int main()
{
	ll n;
	while (~scanf("%lld", &n))
	{
		int cnt = 0;
		ll r = 1, sum = 0;
		for (ll i = 1;i*i<=n; i++)
		{
			while (sum < n&&r*r <= n)
			{
				sum += r*r;
				r++;
			}
			if (sum == n)
			{
				a[cnt].num = r - i; a[cnt].l = i; a[cnt].r = r - 1;
				cnt++;
			}
			sum -= i*i;
		}
		printf("%d\n", cnt);
		for (int i = 0; i < cnt; i++)
		{
			printf("%d ", a[i].num);
			for (int j = a[i].l; j <= a[i].r; j++)
				printf("%d%c", j, j == a[i].r ? '\n' : ' ');
		}
	}
	return 0;
}

