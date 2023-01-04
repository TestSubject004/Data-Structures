#include "binary.h"

using namespace std;


int main(){
  string file, out;
  cin>>file>>out;
  ifstream ist{file};
  ofstream ost{out};
  int c;
  binary<int> b;

  while(ist>>c){
    b.insert(c);
    //cout<<c<<"\n";
  }
  b.printTree(ost);
  cout<<"\n"<<b.findMin()<<"\n";
  cout<<b.contains(123);
  cout<<b.contains(347);
  b.remove(347);
  cout<<b.contains(347);
  cout<<b.isEmpty();
  b.makeEmpty();
  cout<<b.isEmpty();
  cout<<"\n"<<b.findMin()<<"\n";

}
