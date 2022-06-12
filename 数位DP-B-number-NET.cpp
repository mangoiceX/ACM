#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int bit[15];
int dp[15][15][3];
//dp[i][j][k]
//i:��λ
//j:����
//k:3�ֲ���״����0��ĩβ����1,1��ĩβ��1,2������13

int dfs(int pos,int mod,int have,int lim)//lim��¼����
{
    int num,i,ans,mod_x,have_x;
    if(pos<=0)
        return mod == 0 && have == 2;
    if(!lim && dp[pos][mod][have] != -1)//û�����޲����ѱ����ʹ�
        return dp[pos][mod][have];
    num = lim?bit[pos]:9;//�����λ��2����һλ��3����������㵽��λΪ1����ô��һλ����ȡ��9�ģ������λΪ2����һλֻ��ȡ��3
    ans = 0;
    for(i = 0; i<=num; i++)
    {
        mod_x = (mod*10+i)%13;//���Ƿ�������13�����������Ǵ�ԭ���������λ��ʼ�㣬ϸ�ĵ�ͬѧ���Է��֣���ʵ��������̾���һ����������
        have_x = have;
        if(have == 0 && i == 1)//ĩβ����1�����ڼ������1
            have_x = 1;//���Ϊĩβ��1
        if(have == 1 && i != 1)//ĩβ��1�����ڼ���Ĳ���1
            have_x = 0;//���Ϊĩβ����1
        if(have == 1 && i == 3)//ĩβ��1�����ڼ������3
            have_x = 2;//���Ϊ����13
        ans+=dfs(pos-1,mod_x,have_x,lim&&i==num);//lim&&i==num�����ʼ��ȡ����num�����λ���������i��numС����ôi����һλ�����Ե���9����i==num�ˣ�����ܵ���ľ�ֻ��,bit[pos-1]
    }
    if(!lim)
        dp[pos][mod][have] = ans;
    return ans;
}

int main()
{
    int n,len;
    while(~scanf("%d",&n))
    {
        memset(bit,0,sizeof(bit));
        memset(dp,-1,sizeof(dp));
        len = 0;
        while(n)
        {
            bit[++len] = n%10;
            n/=10;
        }
        printf("%d\n",dfs(len,0,0,1));
    }

    return 0;
}
