#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

struct Cmp{
	bool operator()(const pair<string, string> &a,
                  const pair<string, string> &b) {
    if((a.first).compare(b.first) < 0){  //先比较作者 
      	return true;
      }
	if((a.first).compare(b.first) > 0){
		return false;
	}
    if((a.first).compare(b.first) == 0) { //作者相同，比较标题
      if ((a.second).compare(b.second) < 0){
      		return true;
	  }   
    }
    return false;
  }
   
};
/*
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
*/
set<pair<string,string> ,Cmp> stores;
set<pair<string,string> ,Cmp> rt_bks;
map<string,string> books;
string title,author,line;
void show(){
	set<pair<string, string> >::iterator iter1 = rt_bks.begin();
  	set<pair<string, string> >::iterator iter2 = stores.begin();
  	
	if((*iter1) == (*iter2)){//单独处理第一本书 
		cout << "Put " << (*iter1).second  << " first " << endl;
		iter1++;
		iter2++;
	}else{
		iter2++;
	}
	while(iter1 != rt_bks.end()){
		if((*iter1) != (*iter2)){
			iter2++;
		}else{
			cout << "Put " << (*iter1).second << " after " << (*(--iter2)).second << endl; 
			iter1++;
			iter2++;iter2++;
		}	
	}	
} 
void splitAT(string l){
	int index1 = l.find("\"",1);
	title = l.substr(0,index1 + 1);
	int index2 = l.find(" by ");
	author = l.substr(index2 + 4,l.length() - (index2 + 4));
}
void splitT(string l){
	int index = l.find("\"");
	title = l.substr(index,l.length() - index);
	
}
int main(){
	while(getline(cin , line) && line != "END"){
		splitAT(line);
		books.insert(make_pair(title,author));
		stores.insert(make_pair(author,title));
		
	}
	while(getline(cin , line) && line != "END"){
		if(line[0] == 'B'){
			splitT(line);
			stores.erase(make_pair(books[title],title));
		}
		if(line[0] == 'R'){
			splitT(line);
			stores.insert(make_pair(books[title],title));
			rt_bks.insert(make_pair(books[title],title));
		}
		if(line[0] == 'S'){
			show();
			rt_bks.clear();
			cout << "END" << endl; 
		}
	}
	
	return 0;
}
