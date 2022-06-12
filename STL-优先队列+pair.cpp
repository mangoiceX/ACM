#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;
 
struct cmp
{
    bool operator()(const P p1, const P p2)
    {
        return p1.second > p2.second; //second的小值优先
    }
};
 
int main()
{
    priority_queue<P, vector<P>, cmp> que;
    que.push(P(10,20));
    que.push(P(15,30));
    que.push(P(20,1));
    P p;
    while(!que.empty())
    {
        p=que.top();
        que.pop();
        cout<<p.first<<" "<<p.second<<endl;
    }
}

