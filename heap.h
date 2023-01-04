#include "iostream"
#include "vector"

template <typename Key>
class BinaryHeap{
  public:
    explicit BinaryHeap(int capacity = 100);
    explicit BinaryHeap(const std::vector<Key> &items);


    bool isEmpty() const;
    const Key& findMin() const;

    void insert(const Key& x);
    void insert(Key&& x);

    void deleteMin();
    void deleteMin(Key& x);

    void makeEmpty();

  private:
    int currentSize;
    std::vector<Key> array;

    void buildHeap();
    void percolateDown(int hole);


};

template<typename Key>
BinaryHeap<Key>::BinaryHeap(int capacity):currentSize(0){
  array.resize(capacity);
}


template<typename Key>
bool BinaryHeap<Key>::isEmpty() const{
  if(currentSize == 0)
    return true;
  else
    return false;
}

template<typename Key>
const Key& BinaryHeap<Key>::findMin() const{
  if(isEmpty()){
    std::cout<<"is empty fuck off \n";
    return NULL;
  }

  else
    return array[1];
}

template<typename Key>
BinaryHeap<Key>::BinaryHeap(const std::vector<Key> &items):array(items.size()+10), currentSize{items.size()}{
  for(int i =0;i<items.size();i++){
    array[i+1] = items[i];
  }
  buildHeap();
}

template<typename Key>
void BinaryHeap<Key>::buildHeap(){
  for(int i = currentSize/2;i>0;--i){
    percolateDown(i);
  }
}


template<typename Key>
void BinaryHeap<Key>::insert(const Key &x){
  if(currentSize == array.size()-1)
    array.resize(2*currentSize);

  int hole = ++currentSize;
  Key copy = x;
  array[0] = std::move(copy);
  while(x < array[hole/2]){
    array[hole] = std::move(array[hole/2]);
    hole = hole/2;
   }
  array[hole] = std::move(array[0]);

}

template<typename Key>
void BinaryHeap<Key>::percolateDown(int hole){
  //currentSize = --currentSize;
  Key temp = array[hole];
  int child;

  while(2*hole <=currentSize){
    child = hole*2;
    if(child != currentSize && array[child]>array[child+1]){
      child++;
    }
    if(temp>array[child])
      array[hole] = std::move(array[child]);
    hole = child;
  }
  array[hole] = std::move(temp);


}

template <typename Key>
void BinaryHeap<Key>::deleteMin(){
  if(isEmpty()){
    std::cout << "empty" << std::endl;
    return;
  }
  array[1] = std::move(array[currentSize--]);
  percolateDown(1);
    
}

template <typename Key>
void BinaryHeap<Key>::deleteMin(Key &x){
  if(isEmpty()){
    std::cout<<"empty \n"<<std::endl;
    return;
  }

  x = std::move(array[1]);
  array[1] = std::move(array[currentSize--]);
  percolateDown(1);
}



