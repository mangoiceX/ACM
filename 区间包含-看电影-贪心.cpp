#include <iostream>  
#include <algorithm>  
using namespace std;  
int m,n;  
struct node {  
    int s,e;  
}a[100010],b[100010];     
int cmp(node a,node b) {    //������������򣬰������ķǼ����������  
    if(a.e==b.e)  
        return a.s<b.s;  
    return a.e<b.e;  
}  
int fun1(node s) {          //�ö��������ķ�ʽ����<span style="font-size:10px;">��Ҫ��Ļ</span><span style="color: rgb(51, 51, 51); font-family: Full-Width-Quoration-Marks, '.SFNSText', '.SFUIText', 'Helvetica Neue', Helvetica, 'Segoe UI', Roboto, 'Open Sans', 'Lucida Grande', Arial, Verdana, 'Hiragino Sans GB', 'PingFang SC', 'Source Han Sans CN', 'Source Han Sans SC', 'Microsoft YaHei', 'Wenquanyi Micro Hei', 'WenQuanYi Zen Hei', 'ST Heiti', SimHei, 'WenQuanYi Zen Hei Sharp', FontAwesome, sans-serif; line-height: 25.6px;"><span style="font-size:10px;">��r�ڻ�е�λ�ã����ٲ��Ҵ���</span></span>  
    int num1=0, num2=0;  
    int left=1;  
    int right=m;  
    int mid;  
    while(left<right) {  
        mid=(left+right)/2;  
        if(a[mid].e==s.e)  
            return mid;  
        else if(a[mid].e>s.e)  
            right=mid-1;  
        else  
            left=mid+1;  
    }  
    return mid;  
      
}  
int main() {  
    while(cin>>m>>n) {  
    for(int i=1;i<=m;i++)  
        cin>>a[i].s>>a[i].e;  
    sort(a+1,a+1+m,cmp);  
    /*for(int i=1;i<=m;i++) 
        cout<<a[i].s<<" "<<a[i].e<<endl;*/  
        for(int j=1;j<=n;j++)  
        {  
            int num=0;  
            cin>>b[j].s>>b[j].e;  
            int t=fun1(b[j]);  
            for(int i=1;i<=t+1;i++)    //Ϊ�˱��գ�����ȡt+1 ,i=t���� 
                if(a[i].s>=b[j].s&&a[i].e<=b[j].e) {  
                    num++;  
                    b[j].s=a[i].e;  
                }  
            cout<<num<<endl;  
        }  
    }  
    return 0;  
}  
