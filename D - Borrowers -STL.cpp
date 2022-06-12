#include <iostream>
#include <map>
#include <set>
using namespace std;
//�Զ���set��������ʹ�Ĳ����ǾͰ���ĿҪ������������Ϣ¼���꣬������Ŀ������
struct Compare {
  bool operator()(const pair<string, string> &a,
                  const pair<string, string> &b) {
    if ((a.first).compare(b.first) < 0)  //�ȱȽ�����
      return true;
    if ((a.first).compare(b.first) == 0) { //������ͬ���Ƚϱ���
      if ((a.second).compare(b.second) < 0)
        return true;
    }
    return false;
  }
};

set<pair<string, string>, Compare> stores;//��pair��������Ŀ��Ϣ
set<pair<string, string>, Compare> rt_bks;//�������滹���ʱ��������ܵ�˳��
map<string, string> books; //�������title��author��ӳ��
string author, title, line;

void show() {
  set<pair<string, string> >::iterator iter1 = rt_bks.begin();
  set<pair<string, string> >::iterator iter2 = stores.begin();
  if ((*iter1) == (*iter2)) {//�Ȱѵ�һ���ó����������������ȣ�˵���Ƿ��ڵ�һ��
    cout << "Put " << (*iter1).second << " first" << endl;
    iter1++;
    iter2++;
  } else
    iter2++;
  while (iter1 != rt_bks.end()) {
      //����stores���������Ҫ���ϵ����title��stores���ڵ�һ�����Ͱѵ�ǰ���ǰһ����title��¼����
    if ((*iter1) != (*iter2))
      iter2++;
    else {
      cout << "Put " << (*iter1).second << " after " << (*(--iter2)).second<<endl;
      iter1++;//��Ϊ�����ʱ��iter2--�ˡ�����Ҫ++����
      iter2++;
      iter2++;
    }
  }
}

void splitAT(string l) {
    //���ַ����е�author��title��ȡ����
  int index1 = l.find("\"", 1); //�ӵڶ���λ�ÿ�ʼ�ҵ�һ��"������
  title = l.substr(0, index1 + 1);
  //ע��substr(n,m-n)���ַ����Ǵ�n��m-n-1��������m-n,�������Ҫ+1
  int index2 = l.find(" by ");
  author = l.substr(index2 + 4, line.length() - (index2 + 4));
}

void splitT(string l) {
    //���ַ����е�title��ȡ����
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
      //B��R�����ǵø�����Ӧ������
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
        //������ǵ���ռ�¼���������
      show();
      rt_bks.clear();
      cout<<"END"<<endl;
    }
  }
  return 0;
}

