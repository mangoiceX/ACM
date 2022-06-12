#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
 
long long hashh[2599];// ת���������͵�ʱ��͵����������ֱ���õ�ctrl+r�����£���
long long num[25];
long long dp[25][2599][60];
 
long long GCD(long long x,long long y)��// �����Լ��
{
    if(y == 0) return x;
    return GCD(y,x%y);
}
 
long long LCM(long long x,long long y)��// ����С������
{
    return x/GCD(x,y)*y;
}
 
long long dfs(long long len,long long mod,long long lcm,bool limit)// len��ֵ���ȣ�mod��2520ȡģ��ֵ��������С��������limitǰһλ�Ƿ񵽴����ֵ
{
    long long sum = 0;
    if(len <= 0) return (mod%lcm)==0;
    if(!limit && dp[len][mod][hashh[lcm] ] != -1) return dp[len][mod][hashh[lcm] ];
 
    long long over = limit?num[len]:9;
    for(int i = 0; i <= over; i++)
    {
        sum += dfs(len-1,(mod*10+i)%2520,i?LCM(lcm,i):lcm,(i==over)&&limit);��// ÿ��ȡ��һλ������ȡģ�������С������
    }
 
�� if(!limit)dp[len][mod][hashh[lcm] ] = sum;
    return sum;
}
 
long long solve(long long number)
{
 
    long long len = 0;
    while(number)
    {
        num[++len] = number%10;
        number /= 10;
    }
    return dfs(len,0,1,true);
}
 
void init()
{
    memset(dp,-1,sizeof(dp));
    long long a = 0;
    for(int i = 1; i*i < 2520; i++)����// ����2520��Լ�����У���财��
    {
        if(2520%i == 0)
        {
            hashh[i] = a++;����
            hashh[2520/i] = a++;
        }
    }
}
 
int main()
{
    long long a,b;
    init();
 
    while(~scanf("%lld%lld",&a,&b))
    {
        printf("%lld\n",solve(b)-solve(a-1));
    }
    return 0;
}

