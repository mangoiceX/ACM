#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<map>
using namespace std;
#define N 45
#define PI 4*atan(1.0)
#define mod 1000000007
#define met(a, b) memset(a, b, sizeof(a))
#define INF 10000000000000000
typedef long long LL;

int n;
LL a[N];

LL Abs(LL x)
{
    return x<0?-x:x;
}

int main()
{
    while(scanf("%d", &n), n)
    {
        for(int i=0; i<n; i++)
            scanf("%I64d", &a[i]);

        map<LL, int> M;
        map<LL, int>::iterator it;
        pair<LL, int> ans(Abs(a[0]), 1);

        for(int i=1; i<1<<(n/2); i++)
        {
            LL sum = 0;int cnt = 0;
            for(int j=0; j<(n/2); j++)//ѡȡ������״̬ 
            {
                if((i>>j)&1)
                {
                    sum += a[j];
                    cnt ++;
                }
            }
            ans = min(ans, make_pair(Abs(sum), cnt));///ȫ����ǰ�벿�ֵģ�
            if(M[sum])///����cntΪС�ģ�
                M[sum] = min(M[sum], cnt);
            else
                M[sum] = cnt;
        }

        for(int i=1; i<1<<(n-n/2); i++)
        {
            LL sum = 0;int cnt = 0;
            for(int j=0; j<(n-n/2); j++)
            {
                if((i>>j)&1)
                {
                    sum += a[j+n/2];
                    cnt ++;
                }
            }
            ans = min(ans, make_pair(Abs(sum), cnt));///ȫ���Ǻ�벿�ֵģ�

            it = M.lower_bound(-sum);///�ҵ���һ������-sum��λ�ã�Ȼ��ȡ�����������Сֵ��

            if(it != M.end())
                ans = min(ans, make_pair(Abs(sum+it->first), cnt+it->second));
            if(it != M.begin())
            {
                it--;
                ans = min(ans, make_pair(Abs(sum+it->first), cnt+it->second));
            }
        }
        printf("%I64d %d\n", ans.first, ans.second);
    }
    return 0;
}
