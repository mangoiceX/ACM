#include<iostream>
#include<cstdio>
using namespace std;
long long num[100];
 
int main()
{
	int n;
	int cnt = 0;
	while (cin >> n)
	{
		long long ans = 0;
		for (int i = 0; i < n; ++i)
			cin >> num[i];
		for (int i = 1; i <= n; ++i) //i:�����г��� 
		{
			for (int j = 0; j + i <= n; ++j) //j:��������� ������֮ǰдj + i < n��ŭ�� 
			{
				long long tt = 1;
				for (int k = j; k < j + i; ++k) //�۳� 
				{
					tt *= num[k];
				}
				ans = max(ans, tt);
			}
		}
		printf("Case #%d: The maximum product is %lld.\n\n", ++cnt, ans);
	}
	return 0;
} 
