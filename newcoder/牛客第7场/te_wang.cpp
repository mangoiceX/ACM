// -*- coding: utf-8 -*-
// @Date    : 2019-08-08 12:20:21
 
#include <bits/stdc++.h>
#define greeting cerr << "What's your problem?\n"
 
using namespace std;
typedef long long ll;
 
template<typename T>
ostream& operator << (ostream& os, const vector<T>& v)
{
    for(auto i : v)
        os << i << " ";
    return os;
}
 
template<typename T>
ostream& operator << (ostream& os, const set<T>& v)
{
    for(auto i : v)
        os << i << " ";
    return os;
}
 
const int N = 300;
using pii = pair<int, int>;
 
vector<pii> v;
vector<string> ans, tmp;
bool Merge[N];
 
int getmin(string &a)
{
    int len = a.size();
    int i = 0, j = 1, k = 0;
    while(i < len && j < len && k < len)
    {
        char x = a[(i+k) % len];
        char y = a[(j+k) % len];
        if(x == y)
            k++;
        else
        {
            if(x > y)
                i += k+1;
            else
                j += k+1;
            if(i == j)
                j++;
            k = 0;
        }
    }
    return min(i, j);
}
 
//#define local
int main()
{
//#ifdef local
//  freopen("data.in", "r", stdin);
//  freopen("ans.out", "w", stdout);
//#endif   
    int T;
    scanf("%d", &T);
    while(T--)
    {
        string s;
        cin >> s;
        s += "#";
        v.clear();
        ans.clear();
        tmp.clear();
        memset(Merge, false, sizeof(Merge));
        int x, y;
        x = y = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '0')
            {
                if(y)
                {
                    v.emplace_back(x, y);
                    y = 0;
                    x = 1;
                }
                else
                    ++x;
            }
            else if(s[i] == '1')
                ++y;
            else if(s[i] == '#')
            {
                if(x || y)
                    v.emplace_back(x, y);
            }
        }
        v.emplace_back(0, 0);
        for(auto i: v)
        {
            string r = "";
            for(int j = 0; j < i.first; ++j)
                r += '0';
            for(int j = 0; j < i.second; ++j)
                r += '1';
            if(r.size())
                tmp.push_back(r);
        }
        bool flag = false;
        string r = "";
        do
        {
            flag = false;
            ans.clear();
            r = "";
            for(auto i: tmp)
            {
                string x = r + i;
                if(!getmin(x))
                {
                    if(r != "")
                        flag = true;
                    r = x;
                }
                else
                {
                    ans.push_back(r);
                    r = i;
                }
            }
            if(r.size())
                ans.push_back(r);
            // cerr << ans << endl;
            tmp = ans;
            // cout << ans << endl;
        }
        while(flag && ans.size() > 1);
        cout << ans << endl;
        // for(auto i: v)
        //  cout << i.first << " " << i.second << endl;
        // cout << endl;
        // pii cur = {0, 0};
        // bool flag = false;
        // for(int i = 0; i < v.size()-1; ++i)
        // {
        //  int x0 = v[i].first;
        //  int x1 = v[i+1].first;
        //  int y0 = v[i].second;
        //  int y1 = v[i+1].second;
        //  if(y1 && (x0 > x1 || (x0 == x1 && y0 <= y1) || (cur.first == x1 && cur.second < y1) || cur.first > x1))
        //  {
        //      if(!flag)
        //          cur = v[i];
        //      flag = true;
        //      Merge[i] = true;
        //  }
        //  else
        //  {
        //      flag = false;
        //      cur = {0, 0};
        //      Merge[i] = false;
        //  }
        // }
        // for(int i = 0; i < v.size(); ++i)
        // {
        //  for(int j = 0; j < v[i].first; ++j)
        //      printf("0");
        //  for(int j = 0; j < v[i].second; ++j)
        //      printf("1");
        //  if(i < v.size()-1 && !Merge[i])
        //      printf(" ");
        // }
        // printf("\n");
    }
    return 0;
}