#include<iostream> 
 #include<cstring>
 #include<string>
 using namespace std;
  
  int n, k;
  int pl[505],pr[505];
  int a[1005],b[1005];
  
 int main()
 {
 	int T = 0;
 	cin >> T;
     while (T--)
    {cin >> n >> k;
         int t;
         int num = 0;
        char c;
         memset(a, 0, sizeof(a));
         memset(b, 0, sizeof(b));
         while (k--)
         {
             cin >> t;
             for (int i = 0; i < t; i++)
                cin >> pl[i];
             for (int i = 0; i < t; i++)
                 cin >> pr[i];
             cin >> c;
            if (c == '=')
             {
                 for (int i = 0; i < t; i++)
                {
                     a[pl[i]] = b[pl[i]] = -1;
                    a[pr[i]] = b[pr[i]] = -1;
                 }
            }
             else if (c == '<')
             {
                 num++;
                 for (int i = 0; i < t; i++)
                 {
                    if (a[pl[i]] != -1)   a[pl[i]]++;
                     if (a[pr[i]]!= -1)      b[pr[i]]++;
                 }
             }
             else if (c == '>')
             {
                 num++;
                 for (int i = 0; i < t; i++)
                 {
                     if (a[pl[i]] != -1)   b[pl[i]]++;
                     if (a[pr[i]] != -1)      a[pr[i]]++;

                }
             }
         }
         int ans, count=0;
         for (int i = 1; i <= n; i++)
         {
            if (a[i] == num || b[i]==num)
             {
                 ans = i;                 count++;
             }
             if (count == 2)  break;
         }
         if (count!=1)  cout << "0" << endl;
         else cout << ans << endl;
         if(T){
         	cout << endl;
		 }
         
     }
 }
