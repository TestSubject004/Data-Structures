#include "fstream"
#include "string"
#include "heap.h"

using namespace std;

int main(){
  string in, out;

  cin >>in>>out;

  ifstream ist{in};
  ofstream ost{out};

  BinaryHeap<int> heap;
  int buf;
  vector<int> vec;
  cout<<"flag"<<endl;
  while(ist>>buf){
   heap.insert(buf); 
  }
  cout<<"flag 1"<<endl;
  cout<<heap.findMin()<<endl;

  ost<<heap.findMin()<<endl;
  
}
