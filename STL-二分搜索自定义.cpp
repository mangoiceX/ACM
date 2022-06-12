#include <bits/stdc++.h>
 
using namespace std;
struct node
{
    int x,y;
};
struct cmp1
{
    bool operator () (const node &a,const node &b) const {
        return a.x < b.x;
    }
};
int main()
{
    vector<node>pq;
    pq.push_back({1,3});
    pq.push_back({2,8});
    pq.push_back({4,3});
    node a;
    a.x = a.y = 3;
    vector<node>::iterator it = lower_bound(begin(pq),end(pq),a,cmp1());
    cout << (*it).x << endl;
}
 

