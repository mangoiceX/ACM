#include <iostream>
#include <map>
#include <set>
using namespace std;
//自定义set的排序函数使的插入是就按题目要求排序，所有信息录入完，整个数目已有序
struct Compare {
  bool operator()(const pair<string, string> &a,
                  const pair<string, string> &b) {
    if ((a.first).compare(b.first) < 0)  //先比较作者
      return true;
    if ((a.first).compare(b.first) == 0) { //作者相同，比较标题
      if ((a.second).compare(b.second) < 0)
        return true;
    }
    return false;
  }
};

set<pair<string, string>, Compare> stores;//用pair来保存数目信息
set<pair<string, string>, Compare> rt_bks;//用来保存还书的时候放书回书架的顺序
map<string, string> books; //用来完成title到author的映射
string author, title, line;

void show() {
  set<pair<string, string> >::iterator iter1 = rt_bks.begin();
  set<pair<string, string> >::iterator iter2 = stores.begin();
  if ((*iter1) == (*iter2)) {//先把第一个拿出来单独处理，如果相等，说明是放在第一本
    cout << "Put " << (*iter1).second << " first" << endl;
    iter1++;
    iter2++;
  } else
    iter2++;
  while (iter1 != rt_bks.end()) {
      //遍历stores，如果发现要放上的书的title和stores现在的一样，就把当前书的前一本书title记录下来
    if ((*iter1) != (*iter2))
      iter2++;
    else {
      cout << "Put " << (*iter1).second << " after " << (*(--iter2)).second<<endl;
      iter1++;//因为输出的时候iter2--了。所以要++两次
      iter2++;
      iter2++;
    }
  }
}

void splitAT(string l) {
    //将字符串中的author和title提取出来
  int index1 = l.find("\"", 1); //从第二个位置开始找第一个"的坐标
  title = l.substr(0, index1 + 1);
  //注意substr(n,m-n)子字符串是从n到m-n-1；不包括m-n,所以最后要+1
  int index2 = l.find(" by ");
  author = l.substr(index2 + 4, line.length() - (index2 + 4));
}

void splitT(string l) {
    //将字符串中的title提取出来
  int index = l.find("\"");
  title = l.substr(index, l.length() - index);
}

int main() {
  while (getline(cin, line) && line != "END") {
    splitAT(line);
    books.insert(make_pair(title, author));
    stores.insert(make_pair(author, title));
  }
  while (getline(cin, line) && line != "END") {
      //B和R操作记得更新相应的容器
    if (line[0] == 'B') {
      splitT(line);
      stores.erase(make_pair(books[title], title));
    }
    if (line[0] == 'R') {
      splitT(line);
      rt_bks.insert(make_pair(books[title], title));
      stores.insert(make_pair(books[title], title));
    }
    if (line[0] == 'S') {
        //输出完后记得清空记录还书的容器
      show();
      rt_bks.clear();
      cout<<"END"<<endl;
    }
  }
  return 0;
}

