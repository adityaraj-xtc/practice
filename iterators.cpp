#include <bits/stdc++.h>
using namespace std;
class Iterator{
  public:
  virtual bool hasNext() = 0;
  virtual int next() = 0;
};
class MultipleIterator: Iterator{
  public:
  int base, limit, cur;
  MultipleIterator(int base, int limit = INT_MAX){
    cur = 0;
    if(limit < base){
      throw invalid_argument("limit cannot be less than base!");
    }
    this->base = base;
    this->limit = limit;
  }
  bool hasNext(){
    return cur <= limit - base;
  }
  int next(){
    if(!hasNext()){
      throw new out_of_range("no more elements");
    }
    cur += base;
    return cur;
  }
};

class InterleavingIterator: Iterator{
  private:
  list<MultipleIterator> iteratorList;
  list<MultipleIterator>::iterator cur;
  public:
  InterleavingIterator(vector<MultipleIterator> its){
    for(auto it: its){
      if(it.hasNext())
        iteratorList.push_back(it);
    }
    cur = iteratorList.begin();
  }
  bool hasNext(){
  	return !iteratorList.empty();
  }
  int next(){
    if(!hasNext()){
      throw out_of_range("No elements found");
    }
    int val = cur->next();
    if(!cur->hasNext()){
      cur = iteratorList.erase(cur);
    } else {
      cur++;
    }
    if(cur == iteratorList.end()){
      cur = iteratorList.begin();
    }
    return val;
  }  
};
int main() {
    MultipleIterator it1 = MultipleIterator(3, 6);
    MultipleIterator it2 = MultipleIterator(5, 5);
    InterleavingIterator it3 = InterleavingIterator(vector<MultipleIterator>{it1, it2});
	while(it3.hasNext()){
    	cout << it3.next() << " ";
	}
    
  return 0;
}
