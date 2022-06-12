#include<stdio.h>
#include<string.h>
#define M 10000
char b[100][10];
int main()
{
   int i,lenth,h,k;
   char a[M],ch[10];
   while(gets(a)&&strcmp(a,"#")!=0)
   {
      lenth=strlen(a);
      h=k=0;
      while(h<lenth)
      {
        sscanf(a+h,"%s",ch);
        h+=strlen(ch)+1;
        for(i=0;i<k;i++)
          if(!strcmp(b[i],ch)) break;
        if(i==k) strcpy(b[k++],ch);
       }
       printf("%d\n",k);
    }
    return 0;
}
